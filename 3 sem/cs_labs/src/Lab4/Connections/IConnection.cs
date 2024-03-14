namespace Itmo.ObjectOrientedProgramming.Lab4.Connections;

public interface IConnection
{
    int ExecuteCommand(Command.Command command);
    void CreateConnection(string path, IConnectionType type);
    void ChangePath(string path);
    void RemoveConnection();
}