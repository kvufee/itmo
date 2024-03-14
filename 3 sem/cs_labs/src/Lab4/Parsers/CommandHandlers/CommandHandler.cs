using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

public abstract class CommandHandler
{
    public Command.Command? Command { get; protected set; }
    protected CommandHandler? CommandHandlerProperty { get; private set; }

    public abstract void Handle(string[] data, IConnectionType type);

    public CommandHandler SetNext(CommandHandler commandHandler)
    {
        if (CommandHandlerProperty is null)
        {
            CommandHandlerProperty = commandHandler;
        }
        else
        {
            CommandHandlerProperty.SetNext(commandHandler);
        }

        return this;
    }
}