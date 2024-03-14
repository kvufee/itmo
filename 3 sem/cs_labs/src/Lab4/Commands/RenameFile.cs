using System.IO;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Command;

public class RenameFile : Command
{
    private string _sourcePath;
    private string _name;
    public RenameFile(IConnectionType type, string sourcePath, string name)
        : base(type)
    {
        _sourcePath = sourcePath;
        _name = name;
    }

    public override bool Execute(string currentPath)
    {
        string fullPath = Path.GetFullPath(Path.Combine(_sourcePath, currentPath));

        Type.Rename(fullPath, _name);

        return true;
    }
}