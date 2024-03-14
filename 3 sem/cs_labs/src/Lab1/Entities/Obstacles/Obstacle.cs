namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public abstract class Obstacle : IObstacle
{
    protected Obstacle(string obstacleType, int damage)
    {
        ObstacleType = obstacleType;
        Damage = damage;
    }

    public string ObstacleType { get; }
    public int Damage { get; }
}