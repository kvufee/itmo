using System;
using Itmo.ObjectOrientedProgramming.Lab4.Command;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

public class DeleteCommand : CommandHandler
{
    public override void Handle(string[] data, IConnectionType type)
    {
        if (data is null) throw new ArgumentNullException(nameof(data));

        if (data is [_, "Delete", _])
        {
            Command = new DeleteFile(type, data[1]);
        }
        else
        {
            CommandHandlerProperty?.Handle(data, type);
        }
    }
}