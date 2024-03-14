using System;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public class TopicBuilder
{
    private string? _name;
    private ITarget? _target;

    public void SetName(string name)
    {
        _name = name;
    }

    public void SetTarget(ITarget target)
    {
        _target = target ?? throw new ArgumentNullException(nameof(target));
    }

    public Topic? Build()
    {
        if (_name != null && _target != null)
        {
            return new Topic(_name, _target);
        }

        return null;
    }
}