using Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.Fabrics;

public class ConnectionHandlerFabric : IConnectionHandlerFabric
{
    public ConnectionHandler AddConnectionHandler()
    {
        return new Connect()
            .SetNext(new ChangeLocation())
            .SetNext(new Disconnect());
    }
}