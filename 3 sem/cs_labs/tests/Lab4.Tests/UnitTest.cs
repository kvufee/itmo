using Itmo.ObjectOrientedProgramming.Lab4.Connections;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;
using Itmo.ObjectOrientedProgramming.Lab4.Parsers.Fabrics;
using Xunit;

namespace Itmo.ObjectOrientedProgramming.Lab4.Tests;

public class UnitTest
{
    private readonly string[] _commandLineFirst = { "Connect", "C:\\software", "-m", "local" };
    private readonly string[] _commandLineSecond = { "File", "Delete", "C:\\software\\a.txt" };
    private readonly string[] _commandLineThird = { "File", "Move", "C:\\software\\a.txt", "C:\\software\\BASEPC.win" };

    [Fact]
    public void SuccessConnectionCommand()
    {
        ICommandHandlerFabric commandHandlerFabric = new CommandHandlerFabric();
        CommandHandler commandHandler = commandHandlerFabric.AddCommandHandler();
        IConnectionHandlerFabric connectionHandlerFabric = new ConnectionHandlerFabric();
        ConnectionHandler connectionHandler = connectionHandlerFabric.AddConnectionHandler();
        IConnectionType type = new LocalConnection();

        var commandParser = new CommandParser(type, commandHandler, connectionHandler);
        Command.Command? command = commandParser.ParseCommand(_commandLineFirst);

        if (command is not null)
        {
            Assert.True(command.GetType().Name == nameof(Connection));
        }
    }

    [Fact]
    public void SuccessDeleteCommand()
    {
        ICommandHandlerFabric commandHandlerFabric = new CommandHandlerFabric();
        CommandHandler commandHandler = commandHandlerFabric.AddCommandHandler();
        IConnectionHandlerFabric connectionHandlerFabric = new ConnectionHandlerFabric();
        ConnectionHandler connectionHandler = connectionHandlerFabric.AddConnectionHandler();
        IConnectionType type = new LocalConnection();

        var commandParser = new CommandParser(type, commandHandler, connectionHandler);
        Command.Command? command = commandParser.ParseCommand(_commandLineSecond);

        if (command is not null)
        {
            Assert.True(command.GetType().Name == nameof(DeleteCommand));
        }
    }

    [Fact]
    public void SuccessMoveCommand()
    {
        ICommandHandlerFabric commandHandlerFabric = new CommandHandlerFabric();
        CommandHandler commandHandler = commandHandlerFabric.AddCommandHandler();
        IConnectionHandlerFabric connectionHandlerFabric = new ConnectionHandlerFabric();
        ConnectionHandler connectionHandler = connectionHandlerFabric.AddConnectionHandler();
        IConnectionType type = new LocalConnection();

        var commandParser = new CommandParser(type, commandHandler, connectionHandler);
        Command.Command? command = commandParser.ParseCommand(_commandLineThird);

        if (command is not null)
        {
            Assert.True(command.GetType().Name == nameof(MoveFileCommand));
        }
    }
}