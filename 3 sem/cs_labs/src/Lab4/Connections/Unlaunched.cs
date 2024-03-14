namespace Itmo.ObjectOrientedProgramming.Lab4.Connections;

public class Unlaunched : ILaunch
{
    public bool Execute(Command.Command? command)
    {
        return false;
    }

    public bool ChangePath(string newPath)
    {
        return false;
    }
}