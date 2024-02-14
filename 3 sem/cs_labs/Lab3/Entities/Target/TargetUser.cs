using System;
using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab3.Service.Exception;
using Itmo.ObjectOrientedProgramming.Lab3.User;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public class TargetUser : ITarget
{
    private IUser _user;

    public TargetUser(IUser user)
    {
        _user = user;
    }

    public IList<Message> RecievedMessages => _user.Messages;

    public void SendMessage(Message message)
    {
        if (message == null) throw new MessageIsEmptyException("Message is empty. Write something.");

        _user.SendMessage(message);
    }

    public void ChangeMessageStatusToRead()
    {
        if (_user.Messages[^1].IsRead == false)
        {
            _user.Messages[^1].SetIsRead(true);
        }
        else
        {
            throw new InvalidOperationException("Message was read");
        }
    }
}