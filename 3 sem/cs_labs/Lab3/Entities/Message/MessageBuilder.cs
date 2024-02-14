namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public class MessageBuilder
{
    private string? _header;
    private string? _body;
    private int _importanceLevel;
    private bool _isRead;

    public void SetHeader(string header)
    {
        _header = header;
    }

    public void SetBody(string body)
    {
        _body = body;
    }

    public void SetImportanceLevel(int importanceLevel)
    {
        _importanceLevel = importanceLevel;
    }

    public void SetIsRead(bool isRead)
    {
        _isRead = isRead;
    }

    public Message? Build()
    {
        if (_header != null && _body != null)
        {
            return new Message(_header, _body, _importanceLevel, _isRead);
        }

        return null;
    }
}