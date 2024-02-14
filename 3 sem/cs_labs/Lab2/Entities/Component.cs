namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public abstract class Component
{
    protected Component(string? name)
    {
        Name = name;
    }

    protected internal string? Name { get; set; }

    public void SetName(string name)
    {
        Name = name;
    }
}