using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public class TargetGroup : ITarget
{
    private readonly List<ITarget> _targets = new List<ITarget>();

    public void AddTarget(ITarget target)
    {
        _targets.Add(target);
    }

    public void SendMessage(Message message)
    {
        foreach (ITarget target in _targets)
        {
            target.SendMessage(message);
        }
    }
}