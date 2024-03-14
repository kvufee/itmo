using System;
using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab3.Entities;

namespace Itmo.ObjectOrientedProgramming.Lab3.User;

public class User : IUser
{
    private List<Message> _messages = new List<Message>();

    public User()
    {
        Messages = _messages;
    }

    public IList<Message> Messages { get; }

    public void SendMessage(Message message)
    {
        _messages.Add(message);
    }

    public void ChangeMessageStatusToRead()
    {
        if (_messages[^1].IsRead == false)
        {
            _messages[^1].SetIsRead(true);
        }
        else
        {
            throw new InvalidOperationException("Message was read");
        }
    }
}