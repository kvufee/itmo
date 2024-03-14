using System;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers.Fabrics;

namespace Itmo.ObjectOrientedProgramming.Lab4;

public class ConsoleLaunch : IConsoleLaunch
{
    public void Launch(string[] args)
    {
        ICommandHandlerFabric commandHandlerFabric = new CommandHandlerFabric();
        CommandHandler commandHandler = commandHandlerFabric.AddCommandHandler();

        IConnectionHandlerFabric connectionHandlerFabric = new ConnectionHandlerFabric();
        ConnectionHandler connectionHandler = connectionHandlerFabric.AddConnectionHandler();

        IConnectionType type = new LocalConnection();

        var commandParser = new CommandParser(type, commandHandler, connectionHandler);
        Connection connection = commandParser.ParseConnection(args);

        string? parameter = Console.ReadLine();

        while (parameter is not "Disconnect")
        {
            if (parameter is not null)
            {
                string[] data = parameter.Split(" ");
                Command.Command? command = commandParser.ParseCommand(data);

                if (command is not null)
                {
                    connection.ExecuteCommand(command);
                }
                else
                {
                    Console.WriteLine("ERROR: invalid command");
                }
            }

            parameter = Console.ReadLine();
        }
    }
}