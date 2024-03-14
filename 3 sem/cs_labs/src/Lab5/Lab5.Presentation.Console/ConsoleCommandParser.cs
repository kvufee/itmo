using Lab5.Application.Abstractions.Service;
using Lab5.Application.Models;
using Lab5.Presentation.Abstractions;

namespace Lab5.Presentation.Console;

public class ConsoleCommandParser : IConsoleCommandParser
{
    private readonly IAccount _account;

    public ConsoleCommandParser(IAccount account)
    {
        _account = account;
    }

    public void Parse(string? input)
    {
        if (input == null) throw new ArgumentNullException(nameof(input));

        string[] data = input.Split(' ');

        if (data.Length > 0)
        {
            string lowerCaseCommand = data[0].ToLower(System.Globalization.CultureInfo.CurrentCulture);

            switch (lowerCaseCommand)
            {
                case "AddMoney":
                    if (data.Length > 1)
                    {
                        int amount;

                        if (int.TryParse(data[1], out amount))
                        {
                            _account.AddMoney(amount);
                        }
                        else
                        {
                            System.Console.WriteLine("Given data type is incorrect");
                        }
                    }
                    else
                    {
                        System.Console.WriteLine("You cant add nothing to your account");
                    }

                    break;

                case "WithdrawMoney":
                    if (data.Length > 1)
                    {
                        int amount;

                        if (int.TryParse(data[1], out amount))
                        {
                            _account.WithdrawMoney(amount);
                        }
                        else
                        {
                            System.Console.WriteLine("Given data type is incorrect");
                        }
                    }
                    else
                    {
                        System.Console.WriteLine("You cant remove nothing from your account");
                    }

                    break;

                case "GetUserBalance":
                    System.Console.WriteLine(_account.GetBalance());
                    System.Console.WriteLine("Done");
                    break;

                case "GetUserLog":
                    IList<UserLog> logs = _account.GetUserLogs();
                    for (int i = 0; i < logs.Count; i++)
                    {
                        UserLog log = logs[i];
                        System.Console.WriteLine($"{log.LogId} {log.AccountId} {log.LogData}");
                    }

                    System.Console.WriteLine("Done");
                    break;

                case "FindUser":
                    if (data.Length > 1)
                    {
                        int userId;

                        if (int.TryParse(data[1], out userId))
                        {
                            Account account = _account.GetAccountByUserId(userId);
                            System.Console.WriteLine($"Account id: {account.Id}; User id: {account.UserId}; Balance: {account.Balance}");
                        }
                        else
                        {
                            System.Console.WriteLine("Given data type is incorrect");
                        }
                    }
                    else
                    {
                        System.Console.WriteLine("You can't find nothing");
                    }

                    System.Console.WriteLine("Done");
                    break;

                case "Exit":
                    Environment.Exit(0);
                    break;

                default:
                    System.Console.WriteLine("Invalid input");
                    break;
            }
        }
}
}