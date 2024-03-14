using System;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;

public class Disconnect : ConnectionHandler
{
    public override void Handle(string[] data)
    {
        if (data is null) throw new ArgumentNullException(nameof(data));

        if (data is ["Disconnect"])
        {
            Connection.RemoveConnection();
        }
        else
        {
            ConnectionHandlerProperty?.Handle(data);
        }
    }
}