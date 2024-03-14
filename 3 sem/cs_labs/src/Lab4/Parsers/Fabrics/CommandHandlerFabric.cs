using Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.Fabrics;

public class CommandHandlerFabric : ICommandHandlerFabric
{
    public CommandHandler AddCommandHandler()
    {
        return new CopyCommand()
            .SetNext(new DeleteCommand())
            .SetNext(new MoveFileCommand())
            .SetNext(new RenameFileCommand())
            .SetNext(new ShowCatalogCommand())
            .SetNext(new ShowFileCommand());
    }
}