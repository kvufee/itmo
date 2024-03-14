using System;
using System.Collections.Generic;
using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab1.Service;
using Itmo.ObjectOrientedProgramming.Lab1.Spaseships;
using Environment = Itmo.ObjectOrientedProgramming.Lab1.Environments.Environment;

namespace Itmo.ObjectOrientedProgramming.Lab1.Models;

public class Route
{
    public Route(IReadOnlyCollection<Environment>? segments)
    {
        PathSegments = segments;
    }

    private static IReadOnlyCollection<Environment>? PathSegments { get; set; }
    private int Time { get; set; }
    private int Money { get; set; }

    public static Spaceship? ChooseOptimalShip(IList<Spaceship> spaceships, Route route)
    {
        if (spaceships is null) throw new ArgumentNullException(nameof(spaceships));

        var requiredShip = spaceships.Select(spaceship =>
        {
            route.RouteSpends(spaceship);

            return new { Spaceship = spaceship, RouteResult = RouteResult(spaceship), route.Time, route.Money, };
        }).Where(result => result.RouteResult is not ShipStatus.ShipIsDestroyed and
            not ShipStatus.CrewKilled and
            not ShipStatus.ShipLoss and
            not ShipStatus.ShipIsDestroyed).MinBy(result => result.Money);

        return requiredShip?.Spaceship;
    }

    public static ShipStatus RouteResult(Spaceship spaceship)
    {
        if (PathSegments != null)
        {
            return PathSegments
                .Select(environment =>
                    environment.IsAbleToPass(environment.EnvironmentObstacles, spaceship, environment))
                .FirstOrDefault();
        }

        return ShipStatus.Okay;
    }

    private static int TimeSpent(Spaceship spaceship, int distance)
    {
        if (spaceship is null) throw new ArgumentNullException(nameof(spaceship));

        if (spaceship.EngineTypeC is not null)
        {
            return distance / spaceship.EngineTypeC.Speed;
        }
        else if (spaceship.EngineTypeE is not null)
        {
            return distance / spaceship.EngineTypeE.Speed;
        }

        throw new InvalidOperationException("Unable to calculate time");
    }

    private void RouteSpends(Spaceship spaceship)
    {
        if (spaceship is null) throw new ArgumentNullException(nameof(spaceship));

        if (PathSegments == null) return;
        Time = PathSegments.Sum(environment => TimeSpent(spaceship, environment.Distance));
        Money = Time * PathSegments.Sum(environment => FuelPrice.PriceOfFuel(spaceship, environment));
    }
}