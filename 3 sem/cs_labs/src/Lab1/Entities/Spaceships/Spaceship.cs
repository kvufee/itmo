using System;
using System.Collections.Generic;
using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab1.Engines;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;
using Itmo.ObjectOrientedProgramming.Lab1.Service;

namespace Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

public abstract class Spaceship : ISpaceship
{
    protected Spaceship(DefaultEngineTypeC? engineTypeC, DefaultEngineTypeE? engineTypeE, DefaultJumpingEngine? jumpingEngine, string spaceshipType, int health, int deflectorType, int strengthClass, bool isModifiedAntiNeutronAbsorber, bool isModifiedPhotonicDeflector)
    {
        EngineTypeC = engineTypeC;
        EngineTypeE = engineTypeE;
        JumpingEngine = jumpingEngine;
        SpaceshipType = spaceshipType;
        Health = health;
        DeflectorType = deflectorType;
        StrengthClass = strengthClass;
        IsModifiedAntiNeutronAbsorber = isModifiedAntiNeutronAbsorber;
        IsModifiedPhotonicDeflector = isModifiedPhotonicDeflector;
    }

    public DefaultEngineTypeC? EngineTypeC { get; }
    public DefaultEngineTypeE? EngineTypeE { get; }
    public DefaultJumpingEngine? JumpingEngine { get; }
    public string SpaceshipType { get; }
    public int Health { get; private set; }
    public int DeflectorType { get; private set; }
    public int StrengthClass { get; }
    public bool IsModifiedAntiNeutronAbsorber { get; private set; }
    public bool IsModifiedPhotonicDeflector { get; }

    public void SetHealth(int health)
    {
        Health = health;
    }

    public void SetDeflectorType(int deflectorType)
    {
        DeflectorType = deflectorType;
    }

    public int CalculatePathLength(Spaceship spaceship, int distance)
    {
        if (spaceship == null) throw new ArgumentNullException(nameof(spaceship));

        if (spaceship.EngineTypeC != null)
        {
            int lengthTypeC = spaceship.EngineTypeC.FuelConsumption(distance) * spaceship.EngineTypeC.Speed / distance;
            return lengthTypeC;
        }
        else if (spaceship.EngineTypeE != null)
        {
            int lengthTypeE = spaceship.EngineTypeE.FuelConsumption(distance) * spaceship.EngineTypeE.Speed / distance;
            return lengthTypeE;
        }

        if (spaceship.JumpingEngine != null)
        {
            int lengthJumpingEngine = spaceship.JumpingEngine.FuelConsumption(distance) * spaceship.JumpingEngine.Speed / distance;
            return lengthJumpingEngine;
        }

        return 0;
    }

    public ShipStatus SpaceshipDamage(IReadOnlyCollection<IObstacle> environmentObstacles, Spaceship spaceship)
    {
        if (spaceship == null) throw new ArgumentNullException(nameof(spaceship));
        if (environmentObstacles == null) throw new ArgumentNullException(nameof(environmentObstacles));

        if (spaceship.IsModifiedPhotonicDeflector == false && environmentObstacles is SpaceWhales && spaceship.DeflectorType != 3)
        {
            return ShipStatus.ShipIsDestroyed;
        }
        else if (spaceship.IsModifiedPhotonicDeflector == false && environmentObstacles is SpaceWhales && spaceship.DeflectorType == 3)
        {
            return ShipStatus.DeflectorDestroyed;
        }
        else if (spaceship.IsModifiedPhotonicDeflector == true && environmentObstacles is SpaceWhales)
        {
            return ShipStatus.Okay;
        }
        else if (environmentObstacles.ElementAt(0).Damage <= spaceship.Health)
        {
            spaceship.SetHealth(spaceship.Health - environmentObstacles.ElementAt(0).Damage);
            return ShipStatus.Okay;
        }
        else if (environmentObstacles is AntimatterBlast && spaceship.IsModifiedAntiNeutronAbsorber == false)
        {
            return ShipStatus.CrewKilled;
        }
        else if (environmentObstacles.ElementAt(0).Damage >= spaceship.Health)
        {
            spaceship.SetHealth(0);
            return ShipStatus.ShipIsDestroyed;
        }
        else
        {
            return ShipStatus.Okay;
        }
    }
}