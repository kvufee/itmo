using Itmo.ObjectOrientedProgramming.Lab4.Connections;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers;

public class CommandParser
{
    private IConnectionType _connectionType;
    private CommandHandler _commandHandler;
    private ConnectionHandler _connectionHandler;

    public CommandParser(IConnectionType connectionType, CommandHandler commandHandler, ConnectionHandler connectionHandler)
    {
        _connectionType = connectionType;
        _commandHandler = commandHandler;
        _connectionHandler = connectionHandler;
    }

    public Connection ParseConnection(string[] data)
    {
        _connectionHandler.Handle(data);
        return _connectionHandler.Connection;
    }

    public Command.Command? ParseCommand(string[] data)
    {
        _commandHandler.Handle(data, _connectionType);
        return _commandHandler.Command;
    }
}