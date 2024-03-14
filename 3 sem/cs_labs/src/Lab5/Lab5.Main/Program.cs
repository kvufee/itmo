using Itmo.Dev.Platform.Postgres.Models;
using Lab5.Application.Abstractions.Service;
using Lab5.Application.Extensions;
using Lab5.Application.Models;
using Lab5.Application.Service;
using Lab5.DataAccess.Abstractions;
using Lab5.DataAccess.Extensions;
using Lab5.Presentation.Abstractions;
using Lab5.Presentation.Console;
using Microsoft.Extensions.DependencyInjection;

namespace Lab5.Main;

public static class Program
{
    public static void Main()
    {
        var dataAccessConfiguration = new PostgresConnectionConfiguration
        {
            Host = "localhost",
            Port = 5432,
            Database = "postgres",
            Username = "postgres",
            Password = "postgres",
            SslMode = "Prefer",
            Pooling = false,
        };

        var serviceCollection = new ServiceCollection();
        serviceCollection.AddNewApplication().AddDataAccess(configuration =>
        {
            configuration.Host = dataAccessConfiguration.Host;
            configuration.Port = dataAccessConfiguration.Port;
            configuration.Database = dataAccessConfiguration.Database;
            configuration.Username = dataAccessConfiguration.Username;
            configuration.Password = dataAccessConfiguration.Password;
            configuration.SslMode = dataAccessConfiguration.SslMode;
            configuration.Pooling = dataAccessConfiguration.Pooling;
        });

        ServiceProvider serviceProvider = serviceCollection.BuildServiceProvider();
        using IServiceScope serviceScope = serviceProvider.CreateScope();
        serviceScope.UseAddedDataAccess();

        IUserRepository? userRepository = serviceScope.ServiceProvider.GetService<IUserRepository>();
        if (userRepository == null) return;

        IAccountRepository? accountRepository = serviceScope.ServiceProvider.GetService<IAccountRepository>();
        if (accountRepository == null) return;

        IUserLogRepository? userLogRepository = serviceScope.ServiceProvider.GetService<IUserLogRepository>();
        if (userLogRepository == null) return;

        IUser userService = new UserService(userRepository);
        var login = new Login(userService);
        User? user = login.Start();
        if (user == null) return;

        IAccount accountService = new AccountService(user, accountRepository, userLogRepository);

        var parser = new ConsoleCommandParser(accountService);
        while (user.Role == UserRole.Default)
        {
            IConsole consoleCommandParser = new UserCommand(parser);
            consoleCommandParser.Start();
        }

        while (user.Role == UserRole.Admin)
        {
            IConsole consoleCommandParser = new AdminConsole(parser);
            consoleCommandParser.Start();
        }
    }
}