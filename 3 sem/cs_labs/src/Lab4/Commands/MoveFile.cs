using System.IO;
using Itmo.ObjectOrientedProgramming.Lab4.Connections;

namespace Itmo.ObjectOrientedProgramming.Lab4.Command;

public class MoveFile : Command
{
    private string _sourcePath;
    private string _destinationPoint;
    public MoveFile(IConnectionType type, string sourcePath, string destinationPoint)
        : base(type)
    {
        _sourcePath = sourcePath;
        _destinationPoint = destinationPoint;
    }

    public override bool Execute(string currentPath)
    {
        string fullPath = Path.GetFullPath(Path.Combine(_sourcePath, currentPath));
        string newFullPath = Path.GetFullPath(Path.Combine(_destinationPoint, currentPath));

        Type.Move(fullPath, newFullPath);

        return true;
    }
}