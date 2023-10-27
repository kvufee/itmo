using System;
using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab1.Environments;

public abstract class Environment
{
    private string? _envType;
    private ICollection<string>? _obstacles;

    public string EnvType
    {
        get { return _envType ?? throw new InvalidOperationException(); }
        set { _envType = value; }
    }

    protected ICollection<string> Obstacles
    {
        get { return _obstacles ?? throw new InvalidOperationException(); }
        set { _obstacles = value; }
    }
}