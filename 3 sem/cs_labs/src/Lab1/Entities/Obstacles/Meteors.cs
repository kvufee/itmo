namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public class Meteors : Obstacle
{
    private new const string ObstacleType = "Meteors";
    private new const int Damage = 20;
    public Meteors()
        : base(ObstacleType, Damage)
    { }
}