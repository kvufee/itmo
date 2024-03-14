using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;

public abstract class ConnectionHandler
{
    public Connection Connection { get; protected set; } = new Connection();
    protected ConnectionHandler? ConnectionHandlerProperty { get; private set; }
    public abstract void Handle(string[] data);
    public ConnectionHandler SetNext(ConnectionHandler connectionHandler)
    {
        if (ConnectionHandlerProperty is null)
        {
            ConnectionHandlerProperty = connectionHandler;
        }
        else
        {
            ConnectionHandlerProperty.SetNext(connectionHandler);
        }

        return this;
    }
}