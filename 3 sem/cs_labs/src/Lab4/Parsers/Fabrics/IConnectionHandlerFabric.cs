using Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.Fabrics;

public interface IConnectionHandlerFabric
{
    ConnectionHandler AddConnectionHandler();
}