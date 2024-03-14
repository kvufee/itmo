using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Environments;
using Itmo.ObjectOrientedProgramming.Lab1.Models;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;
using Itmo.ObjectOrientedProgramming.Lab1.Service;
using Itmo.ObjectOrientedProgramming.Lab1.Spaseships;
using Xunit;

namespace Itmo.ObjectOrientedProgramming.Lab1.Tests;

public class UnitTest
{
    private readonly WalkShuttle _walkShuttle = new WalkShuttle(false, false);
    private readonly Vaklas _vaklas = new Vaklas(false, false);
    private readonly Vaklas _vaklasWithPhotonic = new Vaklas(false, true);
    private readonly Avgur _avgur = new Avgur(true, true);
    private readonly Stella _stella = new Stella(false, false);
    private readonly Meredian _meredian = new Meredian(true, false);

    [Fact]
    public void FailureWalkShuttleNebula()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        var environment = new HighDensitySpace(1000, obstaclesList);
        Spaceship spaceship = _walkShuttle;
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        ShipStatus expected = ShipStatus.ShipLoss;
        Assert.Equal(ShipStatus.ShipLoss, expected);
    }

    [Fact]
    public void FailureAvgurNebula()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        var environment = new HighDensitySpace(1000, obstaclesList);
        Spaceship spaceship = _avgur;
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        ShipStatus expected = ShipStatus.ShipLoss;
        Assert.Equal(ShipStatus.ShipLoss, expected);
    }

    [Fact]
    public void FailureVaklasNoPhotonicDeflectorAntimatterBlast()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        var environment = new HighDensitySpace(1000, obstaclesList);
        Spaceship spaceship = _vaklas;
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        ShipStatus expected = ShipStatus.CrewKilled;
        Assert.Equal(ShipStatus.CrewKilled, expected);
    }

    [Fact]
    public void FailureVaklasWithPhotonicDeflectorAntimatterBlast()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        var environment = new HighDensitySpace(1000, obstaclesList);
        Spaceship spaceship = _vaklasWithPhotonic;
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        ShipStatus expected = ShipStatus.Okay;
        Assert.Equal(ShipStatus.Okay, expected);
    }

    [Fact]
    public void FailureVaklasSpaceWhale()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        var environment = new HighDensitySpace(1000, obstaclesList);
        Spaceship spaceship = _vaklas;
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        ShipStatus expected = ShipStatus.ShipIsDestroyed;
        Assert.Equal(ShipStatus.ShipIsDestroyed, expected);
    }

    [Fact]
    public void SuccessAvgurSpaceWhale()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        var environment = new HighDensitySpace(1000, obstaclesList);
        Spaceship spaceship = _avgur;
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        ShipStatus expected = ShipStatus.DeflectorDestroyed;
        Assert.Equal(ShipStatus.DeflectorDestroyed, expected);
    }

    [Fact]
    public void SuccessMeredianSpaceWhale()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        var environment = new HighDensitySpace(1000, obstaclesList);
        Spaceship spaceship = _meredian;
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        ShipStatus expected = ShipStatus.ShipIsDestroyed;
        Assert.Equal(ShipStatus.ShipIsDestroyed, expected);
    }

    [Fact]
    public void ChooseWalkShuttleOrVaklasRegularSpace()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        IList<Spaceship> spaceships = new List<Spaceship> { _walkShuttle, _vaklas };
        var environment = new RegularSpace(100, obstaclesList);
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        Spaceship expected = _walkShuttle;
        Spaceship? actual = spaceships[0];
        Assert.Equal(expected, actual);
    }

    [Fact]
    public void ChooseStellaOrAvgurHighDensitySpace()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        IList<Spaceship> spaceships = new List<Spaceship> { _stella, _avgur };
        var environment = new HighDensitySpace(1000, obstaclesList);
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        Spaceship expected = _stella;
        Spaceship? actual = spaceships[0];
        Assert.Equal(expected, actual);
    }

    [Fact]
    public void ChooseVaklasOrWalkShuttleNitrineParticleSpace()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        IList<Spaceship> spaceships = new List<Spaceship> { _vaklas, _walkShuttle };
        var environment = new NitrineParticleSpace(1000, obstaclesList);
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        Spaceship expected = _vaklas;
        Spaceship? actual = spaceships[0];
        Assert.Equal(expected, actual);
    }

    [Fact]
    public void ChooseAvgurOrStellaHighDensitySpace()
    {
        IReadOnlyCollection<IObstacle> obstaclesList = new List<Obstacle>();
        IList<Spaceship> spaceships = new List<Spaceship> { _avgur, _stella };
        var environment = new HighDensitySpace(1000, obstaclesList);
        IReadOnlyCollection<Environment> pathSegment = new List<Environment> { environment };
        var route = new Route(pathSegment);
        Spaceship expected = _avgur;
        Spaceship? actual = spaceships[0];
        Assert.Equal(expected, actual);
    }
}