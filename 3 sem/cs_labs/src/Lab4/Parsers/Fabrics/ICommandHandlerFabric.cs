using Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.Fabrics;

public interface ICommandHandlerFabric
{
    CommandHandler AddCommandHandler();
}