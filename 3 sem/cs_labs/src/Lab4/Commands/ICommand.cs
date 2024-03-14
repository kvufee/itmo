using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Command;

public interface ICommand
{
    IConnectionType Type { get; }
}