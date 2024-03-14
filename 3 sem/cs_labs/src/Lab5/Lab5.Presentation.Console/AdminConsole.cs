using Lab5.Presentation.Abstractions;

namespace Lab5.Presentation.Console;

public class AdminConsole : IConsole
{
    private readonly ConsoleCommandParser _consoleCommandParser;

    public AdminConsole(ConsoleCommandParser consoleCommandParser)
    {
        _consoleCommandParser = consoleCommandParser;
    }

    public void Start()
    {
        System.Console.WriteLine("ADMIN CONSOLE\n");
        System.Console.WriteLine("0. Exit\n");
        System.Console.WriteLine("1. AddMoney : amount\n");
        System.Console.WriteLine("2. WithdrawMoney : amount\n");
        System.Console.WriteLine("3. GetUserBalance\n");
        System.Console.WriteLine("4. GetUserLog\n");
        System.Console.WriteLine("5. FindUser : id\n\n");
        System.Console.WriteLine("Enter command:");

        _consoleCommandParser.Parse(System.Console.ReadLine());
    }
}