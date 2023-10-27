namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public class Asteroids : Obstacle
{
    public Asteroids()
    {
        ObstacleType = this.GetType().Name;
        Damage = 50;
    }
}