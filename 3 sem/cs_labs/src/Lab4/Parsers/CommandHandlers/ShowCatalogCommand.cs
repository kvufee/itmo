using System;
using System.Globalization;
using Itmo.ObjectOrientedProgramming.Lab4.Command;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;
using Itmo.ObjectOrientedProgramming.Lab4.Displays;

namespace Itmo.ObjectOrientedProgramming.Lab4.Parsers.CommandHandlers;

public class ShowCatalogCommand : CommandHandler
{
    public override void Handle(string[] data, IConnectionType type)
    {
        if (data is null) throw new ArgumentNullException(nameof(data));

        if (data is [_, "ShowCatalog", _, _])
        {
            int depth = Convert.ToInt32(data[4], CultureInfo.CurrentCulture);
            Command = new ShowCatalog(type, "#", "/", "@", depth, new Display(), 1);
        }
        else
        {
            CommandHandlerProperty?.Handle(data, type);
        }
    }
}