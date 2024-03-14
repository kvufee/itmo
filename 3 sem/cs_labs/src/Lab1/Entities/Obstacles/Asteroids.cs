namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public class Asteroids : Obstacle
{
    private new const string ObstacleType = "Asteroid";
    private new const int Damage = 10;
    public Asteroids()
        : base(ObstacleType, Damage)
    { }
}