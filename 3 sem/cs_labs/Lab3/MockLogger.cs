using Itmo.ObjectOrientedProgramming.Lab3.Entities;
using Itmo.ObjectOrientedProgramming.Lab3.Service.Exception;

namespace Itmo.ObjectOrientedProgramming.Lab3.Tests;

public class MockLogger
{
    private readonly ITarget _decoratee;

    public MockLogger(ITarget decoratee)
    {
        _decoratee = decoratee;
    }

    public string? SendMessage(Message message)
    {
        if (message == null) throw new MessageIsEmptyException("Message is empty. Write something.");

        string? log = message.Body?.ToString();
        _decoratee.SendMessage(message);

        return log;
    }
}