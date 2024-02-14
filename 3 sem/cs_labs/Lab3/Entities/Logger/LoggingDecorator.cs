using System;
using Itmo.ObjectOrientedProgramming.Lab3.Service.Exception;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities.Logger;

public class LoggingDecorator : ITarget
{
    private readonly ITarget _decoratee;

    public LoggingDecorator(ITarget decoratee)
    {
        _decoratee = decoratee;
    }

    public void SendMessage(Message message)
    {
        if (message == null) throw new MessageIsEmptyException("Message is empty. Write something.");

        Console.WriteLine(message.ToString());
        _decoratee.SendMessage(message);
    }
}