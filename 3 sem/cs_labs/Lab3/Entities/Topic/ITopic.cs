namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public interface ITopic
{
    string? Name { get; }
    ITarget Target { get; }
    void SendMessage(Message message);
}