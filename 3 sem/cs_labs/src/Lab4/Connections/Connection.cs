namespace Itmo.ObjectOrientedProgramming.Lab4.Connections;

public class Connection : IConnection
{
    private ILaunch _launch;

    public Connection()
    {
        _launch = new Unlaunched();
    }

    public int ExecuteCommand(Command.Command command)
    {
        _launch.Execute(command);
        return 1;
    }

    public void CreateConnection(string path, IConnectionType type)
    {
        _launch = new Launch(path, type);
    }

    public void ChangePath(string path)
    {
        _launch.ChangePath(path);
    }

    public void RemoveConnection()
    {
        _launch = new Unlaunched();
    }
}