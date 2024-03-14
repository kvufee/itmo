using System;
using Itmo.ObjectOrientedProgramming.Lab4.Command;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

public class RenameFileCommand : CommandHandler
{
    public override void Handle(string[] data, IConnectionType type)
    {
        if (data is null) throw new ArgumentNullException(nameof(data));

        if (data is [_, "Rename", _, _])
        {
            Command = new RenameFile(type, data[1], data[2]);
        }
        else
        {
            CommandHandlerProperty?.Handle(data, type);
        }
    }
}