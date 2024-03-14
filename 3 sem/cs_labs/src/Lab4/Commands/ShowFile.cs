using Itmo.ObjectOrientedProgramming.Lab4.Connections;
using Itmo.ObjectOrientedProgramming.Lab4.Displays;

namespace Itmo.ObjectOrientedProgramming.Lab4.Command;

public class ShowFile : Command
{
    private string _path;
    private IDisplay _display;
    public ShowFile(IConnectionType type, string path, IDisplay display)
        : base(type)
    {
        _path = path;
        _display = display;
    }

    public override bool Execute(string currentPath)
    {
        Type.ShowFile(_path, _display);

        return true;
    }
}