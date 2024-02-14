using System;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities.Messenger;

public class Odnoklassniki : IMessenger
{
    public Odnoklassniki(string name)
    {
        Name = name;
    }

    public string Name { get; }

    public void SendMessage(Message message)
    {
        Console.WriteLine($"[Odnoklassniki]: {message?.Header}, {message?.Body}");
    }
}