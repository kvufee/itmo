using Itmo.Dev.Platform.Postgres.Extensions;
using Itmo.Dev.Platform.Postgres.Models;
using Lab5.DataAccess.Abstractions;
using Lab5.DataAccess.Repositories;
using Microsoft.Extensions.DependencyInjection;

namespace Lab5.DataAccess.Extensions;

public static class ServiceCollectionExtensions
{
    public static IServiceCollection AddDataAccess(
        this IServiceCollection services,
        Action<PostgresConnectionConfiguration> configuration)
    {
        services.ConfigurePostgres(configuration);
        services.AddPlatformMigrations();
        services.RegisterRepositories();

        return services;
    }

    private static void ConfigurePostgres(this IServiceCollection services, Action<PostgresConnectionConfiguration> configuration)
    {
        services.AddPlatformPostgres(builder => builder.Configure(configuration));
    }

    private static void AddPlatformMigrations(this IServiceCollection services)
    {
        services.AddPlatformMigrations(typeof(ServiceCollectionExtensions).Assembly);
    }

    private static void RegisterRepositories(this IServiceCollection services)
    {
        services.AddScoped<IAccountRepository, AccountRepository>();
        services.AddScoped<IUserRepository, UserRepository>();
        services.AddScoped<IUserLogRepository, IUserLogRepository>();
    }
}