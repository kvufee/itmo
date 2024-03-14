namespace Itmo.ObjectOrientedProgramming.Lab3.Entities.Messenger;

public interface IMessenger
{
    string Name { get; }
    void SendMessage(Message message);
}