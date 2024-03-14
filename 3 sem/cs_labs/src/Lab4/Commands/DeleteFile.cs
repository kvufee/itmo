using System.IO;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Command;

public class DeleteFile : Command
{
    private string _sourcePath;
    public DeleteFile(IConnectionType type, string sourcePath)
        : base(type)
    {
        _sourcePath = sourcePath;
    }

    public override bool Execute(string currentPath)
    {
        string fullPath = Path.GetFullPath(Path.Combine(_sourcePath, currentPath));

        Type.Delete(fullPath);

        return true;
    }
}