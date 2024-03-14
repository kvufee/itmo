using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Command;

public abstract class Command : ICommand
{
    protected Command(IConnectionType type)
    {
        Type = type;
    }

    public IConnectionType Type { get; }

    public abstract bool Execute(string currentPath);
}