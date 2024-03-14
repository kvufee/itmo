using System;
using Itmo.ObjectOrientedProgramming.Lab4.Command;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

public class MoveFileCommand : CommandHandler
{
    public override void Handle(string[] data, IConnectionType type)
    {
        if (data is null) throw new ArgumentNullException(nameof(data));

        if (data is [_, "Move", _, _])
        {
            Command = new MoveFile(type, data[1], data[2]);
        }
        else
        {
            CommandHandlerProperty?.Handle(data, type);
        }
    }
}