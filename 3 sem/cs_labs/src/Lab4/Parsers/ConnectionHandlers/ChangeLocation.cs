using System;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.ConnectionHandlers;

public class ChangeLocation : ConnectionHandler
{
    public override void Handle(string[] data)
    {
        if (data is null) throw new ArgumentNullException(nameof(data));

        if (data is [_, "goto", _])
        {
            Connection.ChangePath(data[3]);
        }
        else
        {
            ConnectionHandlerProperty?.Handle(data);
        }
    }
}