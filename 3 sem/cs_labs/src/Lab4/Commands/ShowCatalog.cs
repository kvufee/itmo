using System.IO;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;
using Itmo.ObjectOrientedProgramming.Lab4.Displays;

namespace Itmo.ObjectOrientedProgramming.Lab4.Command;

public class ShowCatalog : Command
{
    private string _fileName;
    private string _tabSymbol;
    private string _catalogName;
    private int _depth;
    private IDisplay _display;
    private int _requiredDepth;

    public ShowCatalog(IConnectionType type, string fileName, string tabSymbol, string catalogName, int depth, IDisplay display, int requiredDepth)
        : base(type)
    {
        _fileName = fileName;
        _tabSymbol = tabSymbol;
        _catalogName = catalogName;
        _depth = depth;
        _display = display;
        _requiredDepth = requiredDepth;
    }

    public override bool Execute(string currentPath)
    {
        string fullPath = Path.GetFullPath(currentPath);

        Type.ShowCatalog(_catalogName, _fileName, _tabSymbol, _depth, fullPath, _display, _requiredDepth);

        return true;
    }
}