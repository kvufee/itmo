namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public abstract class Obstacle
{
    private string? _obstacleType;
    private int _damage;
    public string? ObstacleType
    {
        get { return _obstacleType; }
        set { _obstacleType = value; }
    }

    public int Damage
    {
        get { return _damage; }
        set { _damage = value; }
    }
}