using System;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities.Messenger;

public class Viber : IMessenger
{
    public Viber(string name)
    {
        Name = name;
    }

    public string Name { get; }

    public void SendMessage(Message message)
    {
        Console.WriteLine($"[Viber] -> {message?.Header}: {message?.Body}");
    }
}