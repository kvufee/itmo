using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

namespace Itmo.ObjectOrientedProgramming.Lab1.Environments;

public class HighDensitySpace : Environment
{
    private AntimatterBlast _antimatterBlast = new AntimatterBlast();
    public HighDensitySpace()
    {
        EnvType = this.GetType().Name;
        Obstacles = new List<string>();

        Obstacles.Add(_antimatterBlast.ObstacleType);
    }
}