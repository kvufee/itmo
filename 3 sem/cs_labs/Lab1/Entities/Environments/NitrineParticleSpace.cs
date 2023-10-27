using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

namespace Itmo.ObjectOrientedProgramming.Lab1.Environments;

public class NitrineParticleSpace : Environment
{
    private SpaceWhales _spaceWhales = new SpaceWhales();
    public NitrineParticleSpace()
    {
        EnvType = this.GetType().Name;
        Obstacles = new List<string>();

        Obstacles.Add(_spaceWhales.ObstacleType);
    }
}