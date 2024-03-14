namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public interface IObstacle
{
    string ObstacleType { get; }
    int Damage { get; }
}