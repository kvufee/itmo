using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab3.Entities;

namespace Itmo.ObjectOrientedProgramming.Lab3.User;

public interface IUser
{
    IList<Message> Messages { get; }
    void SendMessage(Message message);
}