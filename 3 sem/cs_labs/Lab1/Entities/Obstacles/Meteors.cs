namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public class Meteors : Obstacle
{
    public Meteors()
    {
        ObstacleType = this.GetType().Name;
        Damage = 100;
    }
}