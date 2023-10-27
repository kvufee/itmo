using System;
using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public abstract class Spaceship
{
    private string? _spaceshipType;
    private ICollection<string>? _spaceshipEngineType;
    private string? _spaceshipDeflectorType;
    private int _spaceshipStrengthClass;
    private int _spaceshipEndurance;
    private int _spaceshipMass;
    private bool _isModifiedAntiNitrine;
    protected string SpaceshipType
    {
        get { return _spaceshipType ?? throw new InvalidOperationException(); }
        set { _spaceshipType = value; }
    }

    protected ICollection<string> SpaceshipEngineType
    {
        get { return _spaceshipEngineType ?? throw new InvalidOperationException(); }
        set { _spaceshipEngineType = value; }
    }

    protected string SpaceshipDeflectorType
    {
        get { return _spaceshipDeflectorType ?? throw new InvalidOperationException(); }
        set { _spaceshipDeflectorType = value; }
    }

    protected int SpaceshipStrengthClass
    {
        get { return _spaceshipStrengthClass; }
        set { _spaceshipStrengthClass = value; }
    }

    protected int SpaceshipEndurance
    {
        get { return _spaceshipEndurance; }
        set { _spaceshipEndurance = value; }
    }

    protected int SpaceshipMass
    {
        get { return _spaceshipMass; }
        set { _spaceshipMass = value; }
    }

    protected bool IsModifiedAntiNitrine
    {
        get { return _isModifiedAntiNitrine; }
        set { _isModifiedAntiNitrine = value; }
    }
}