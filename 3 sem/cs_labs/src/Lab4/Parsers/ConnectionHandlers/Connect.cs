using System;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;

public class Connect : ConnectionHandler
{
    public override void Handle(string[] data)
    {
        if (data is null) throw new ArgumentNullException(nameof(data));

        if (data is ["Connect", _, "local", _])
        {
            Connection.CreateConnection(data[1], new LocalConnection());
        }
        else
        {
            ConnectionHandlerProperty?.Handle(data);
        }
    }
}