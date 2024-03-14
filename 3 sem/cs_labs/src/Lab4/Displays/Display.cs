using System;

namespace Itmo.ObjectOrientedProgramming.Lab4.Displays;

public class Display : IDisplay
{
    public void Show(string data)
    {
        Console.WriteLine(data);
    }
}