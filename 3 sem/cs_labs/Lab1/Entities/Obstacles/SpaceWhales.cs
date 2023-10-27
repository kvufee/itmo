namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public class SpaceWhales : Obstacle
{
    public SpaceWhales()
    {
        ObstacleType = this.GetType().Name;
        Damage = 1000;
    }
}