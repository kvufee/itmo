using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Engines;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;
using Itmo.ObjectOrientedProgramming.Lab1.Service;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public interface ISpaceship
{
    string SpaceshipType { get; }
    int Health { get; }
    int DeflectorType { get; }
    int StrengthClass { get; }
    bool IsModifiedAntiNeutronAbsorber { get; }
    bool IsModifiedPhotonicDeflector { get; }
    DefaultEngineTypeC? EngineTypeC { get; }
    DefaultEngineTypeE? EngineTypeE { get; }
    DefaultJumpingEngine? JumpingEngine { get; }
    ShipStatus SpaceshipDamage(IReadOnlyCollection<IObstacle> environmentObstacles, Spaceship spaceship);
    public int CalculatePathLength(Spaceship spaceship, int distance);
}