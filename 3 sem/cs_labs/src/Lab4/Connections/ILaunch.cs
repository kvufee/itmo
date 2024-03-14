namespace Itmo.ObjectOrientedProgramming.Lab4.Connections;

public interface ILaunch
{
    bool Execute(Command.Command? command);
    bool ChangePath(string newPath);
}