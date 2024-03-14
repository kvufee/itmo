using Itmo.ObjectOrientedProgramming.Lab4.Displays;

namespace Itmo.ObjectOrientedProgramming.Lab4.Connections;

public interface IConnectionType
{
    void Copy(string sourcePath, string destinationPath);
    void Delete(string sourcePath);
    void Move(string sourcePath, string destinationPoint);
    void Rename(string sourcePath, string name);
    void ShowCatalog(string catalogName, string fileName, string tabSymbol, int depth, string currentPath, IDisplay display, int requiredDepth);
    void ShowFile(string sourcePath, IDisplay display);
    string GetPath(string path);
    void CatalogTreeCreator(string catalogName, string fileName, string tabSymbol, int depth, string currentPath, IDisplay display, int currDepth);
}