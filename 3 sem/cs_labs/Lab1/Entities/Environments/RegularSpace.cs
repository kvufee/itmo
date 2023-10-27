using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

namespace Itmo.ObjectOrientedProgramming.Lab1.Environments;

public class RegularSpace : Environment
{
    private Asteroids _asteroids = new Asteroids();
    private Meteors _meteors = new Meteors();

    public RegularSpace()
    {
        EnvType = this.GetType().Name;
        Obstacles = new List<string>();

        Obstacles.Add(_asteroids.ObstacleType);
        Obstacles.Add(_meteors.ObstacleType);
    }
}