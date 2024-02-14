using System;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public static class DisplayDriver
{
    private static ConsoleColor _textColor;

    public static void ClearDisplay()
    {
        Console.Clear();
    }

    public static void SetColor(ConsoleColor color)
    {
        _textColor = color;
    }

    public static void Print(Message message)
    {
        Console.ForegroundColor = _textColor;
        Console.WriteLine(message);
        Console.ResetColor();
    }
}