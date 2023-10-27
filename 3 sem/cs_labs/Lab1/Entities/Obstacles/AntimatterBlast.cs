using Microsoft.VisualBasic;

namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public class AntimatterBlast : Obstacle
{
    public AntimatterBlast()
    {
        ObstacleType = this.GetType().Name;
        Damage = 1000000000;
    }
}