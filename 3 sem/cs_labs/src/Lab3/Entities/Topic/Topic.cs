using Itmo.ObjectOrientedProgramming.Lab3.Service.Exception;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public class Topic : ITopic
{
    public Topic(string name, ITarget target)
    {
        Name = name;
        Target = target;
    }

    public string? Name { get; private set; }
    public ITarget Target { get; private set; }

    public void SetName(string name)
    {
        Name = name;
    }

    public void SetTarget(ITarget target)
    {
        Target = target;
    }

    public void SendMessage(Message message)
    {
        if (message == null) throw new MessageIsEmptyException("Message is null. Write something.");

        Target.SendMessage(message);
    }
}