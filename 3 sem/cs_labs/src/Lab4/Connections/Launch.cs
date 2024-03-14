namespace Itmo.ObjectOrientedProgramming.Lab4.Connections;

public class Launch : ILaunch
{
    private string _pathContext;
    private IConnectionType _connectionType;
    public Launch(string pathContext, IConnectionType type)
    {
        _pathContext = pathContext;
        _connectionType = type;
    }

    public bool Execute(Command.Command? command)
    {
        if (command is null) return false;

        command.Execute(_pathContext);

        return true;
    }

    public bool ChangePath(string newPath)
    {
        _pathContext = newPath;

        return true;
    }
}