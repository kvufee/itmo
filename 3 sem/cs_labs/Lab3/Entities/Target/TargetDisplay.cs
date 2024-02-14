namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public class TargetDisplay : ITarget
{
    public void SendMessage(Message message)
    {
        DisplayDriver.Print(message);
    }
}