using System;
using System.IO;
using Itmo.ObjectOrientedProgramming.Lab4.Displays;

namespace Itmo.ObjectOrientedProgramming.Lab4.Connections;

public class LocalConnection : IConnectionType
{
    public void Copy(string sourcePath, string destinationPath)
    {
        File.Copy(sourcePath, destinationPath);
    }

    public void Delete(string sourcePath)
    {
        File.Delete(sourcePath);
    }

    public void Move(string sourcePath, string destinationPoint)
    {
        File.Move(sourcePath, destinationPoint);
    }

    public void Rename(string sourcePath, string name)
    {
        DirectoryInfo? currentPath = Directory.GetParent(sourcePath);

        string finalPath = currentPath is not null ? Path.Combine(currentPath.FullName, name) : sourcePath;

        File.Move(sourcePath, finalPath);
    }

    public void ShowCatalog(string catalogName, string fileName, string tabSymbol, int depth, string currentPath, IDisplay display, int requiredDepth)
    {
        if (display is null) throw new ArgumentNullException(nameof(display));

        display.Show(currentPath);

        CatalogTreeCreator(catalogName, fileName, tabSymbol, depth, currentPath, display, requiredDepth);
    }

    public void ShowFile(string sourcePath, IDisplay display)
    {
        if (display is null) throw new ArgumentNullException(nameof(display));

        try
        {
            using var streamReader = new StreamReader(sourcePath);
            display.Show(streamReader.ReadToEnd());
        }
        catch (IOException ex)
        {
            display.Show("File is unreadable :3");
            display.Show(ex.Message);
        }
    }

    public string GetPath(string path)
    {
        return Path.GetFullPath(path);
    }

    public void CatalogTreeCreator(string catalogName, string fileName, string tabSymbol, int depth, string currentPath, IDisplay display, int currDepth)
    {
        if (display is null) throw new ArgumentNullException(nameof(display));

        string[] directories = Directory.GetDirectories(currentPath);

        if (currDepth > depth) return;
        if (directories.Length == 0) return;

        foreach (string currDirectory1 in directories)
        {
            display.Show($"{catalogName} {Path.GetFileName(currDirectory1)}");

            foreach (string currDirectory2 in Directory.GetFiles(currDirectory1))
            {
                display.Show($"{tabSymbol} {fileName} {Path.GetFileName(currDirectory2)}");
            }

            CatalogTreeCreator(catalogName, fileName, tabSymbol: tabSymbol + tabSymbol, depth: depth, currentPath: currDirectory1, display, currDepth);
        }
    }
}