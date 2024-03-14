using Lab5.Presentation.Abstractions;

namespace Lab5.Presentation.Console;

public class UserCommand : IConsole
{
    private readonly ConsoleCommandParser _consoleCommandParser;

    public UserCommand(ConsoleCommandParser consoleCommandParser)
    {
        _consoleCommandParser = consoleCommandParser;
    }

    public void Start()
    {
        System.Console.WriteLine("Welcome!\n");
        System.Console.WriteLine("0. Exit\n");
        System.Console.WriteLine("1. AddMoney : amount\n");
        System.Console.WriteLine("2. WithdrawMoney : amount\n");
        System.Console.WriteLine("3. GetUserBalance\n");
        System.Console.WriteLine("4. GetUserLog\n\n");
        System.Console.WriteLine("Enter command:");

        string? command = System.Console.ReadLine();

        _consoleCommandParser.Parse(command);
    }
}