using System;
using Itmo.ObjectOrientedProgramming.Lab4.Command;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

public class CopyCommand : CommandHandler
{
    public override void Handle(string[] data, IConnectionType type)
    {
        if (data is null) throw new ArgumentNullException(nameof(data));

        if (data is [_, "Copy", _, _])
        {
            Command = new CopyFile(type, data[2], data[3]);
        }
        else
        {
            CommandHandlerProperty?.Handle(data, type);
        }
    }
}