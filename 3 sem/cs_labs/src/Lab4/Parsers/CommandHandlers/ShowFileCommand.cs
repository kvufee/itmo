using System;
using Itmo.ObjectOrientedProgramming.Lab4.Command;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;
using Itmo.ObjectOrientedProgramming.Lab4.Displays;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

public class ShowFileCommand : CommandHandler
{
    public override void Handle(string[] data, IConnectionType type)
    {
        if (data is null)
        {
            throw new ArgumentNullException(nameof(data));
        }

        if (data is [_, "ShowFile", _, _])
        {
            Command = new ShowFile(type, data[1], new Display());
        }
        else
        {
            CommandHandlerProperty?.Handle(data, type);
        }
    }
}