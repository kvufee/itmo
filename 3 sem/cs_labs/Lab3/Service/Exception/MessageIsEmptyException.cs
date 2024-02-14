namespace Itmo.ObjectOrientedProgramming.Lab3.Service.Exception;

public class MessageIsEmptyException : System.Exception
{
    public MessageIsEmptyException()
    {
    }

    public MessageIsEmptyException(string? message)
        : base(message)
    {
    }

    public MessageIsEmptyException(string? message, System.Exception? innerException)
        : base(message, innerException)
    {
    }
}