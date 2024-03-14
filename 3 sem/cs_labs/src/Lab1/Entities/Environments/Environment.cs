using System;
using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;
using Itmo.ObjectOrientedProgramming.Lab1.Service;
using Itmo.ObjectOrientedProgramming.Lab1.Spaseships;

namespace Itmo.ObjectOrientedProgramming.Lab1.Environments;

public class Environment : IEnvironment
{
    protected Environment(int distance, IReadOnlyCollection<IObstacle> environmentObstacles)
    {
        Distance = distance;
        EnvironmentObstacles = environmentObstacles;
    }

    public int Distance { get; }
    public IReadOnlyCollection<IObstacle> EnvironmentObstacles { get; }

    public virtual ShipStatus IsAbleToPass(IReadOnlyCollection<IObstacle> environmentObstacles, Spaceship spaceship, Environment environment)
    {
        if (spaceship == null) throw new ArgumentNullException(nameof(spaceship));
        if (environmentObstacles == null) throw new ArgumentNullException(nameof(environmentObstacles));

        if (spaceship.SpaceshipDamage(environmentObstacles, spaceship) != ShipStatus.Okay)
        {
            return ShipStatus.ShipIsDestroyed;
        }
        else if (environment != null && spaceship.CalculatePathLength(spaceship, environment.Distance) < environment.Distance)
        {
            return ShipStatus.ShipLoss;
        }

        return ShipStatus.Success;
    }
}