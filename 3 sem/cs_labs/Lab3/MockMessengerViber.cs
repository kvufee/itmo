using Itmo.ObjectOrientedProgramming.Lab3.Entities;

namespace Itmo.ObjectOrientedProgramming.Lab3.Tests;

public class MockMessengerViber
{
    private IMessage _message;
    public MockMessengerViber(IMessage message)
    {
        _message = message;
    }

    public static string SendMessage(Message message)
    {
        return $"[Viber] -> {message?.Header}: {message?.Body}";
    }
}