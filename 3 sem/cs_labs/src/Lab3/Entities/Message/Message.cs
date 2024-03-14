namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public class Message : IMessage
{
    public Message(string header, string body, int importanceLevel, bool isRead)
    {
        Header = header;
        Body = body;
        ImportanceLevel = importanceLevel;
        IsRead = isRead;
    }

    public string? Header { get; private set; }
    public string? Body { get; private set; }
    public int ImportanceLevel { get; private set; }
    public bool IsRead { get; private set; }

    public void SetHeader(string header)
    {
        Header = header;
    }

    public void SetBody(string body)
    {
        Body = body;
    }

    public void SetImportanceLevel(int importanceLevel)
    {
        ImportanceLevel = importanceLevel;
    }

    public void SetIsRead(bool status)
    {
        IsRead = status;
    }
}