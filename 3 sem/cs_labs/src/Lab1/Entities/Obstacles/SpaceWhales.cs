namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public class SpaceWhales : Obstacle
{
    private new const string ObstacleType = "SpaceWhale";
    private new const int Damage = 50;
    public SpaceWhales()
        : base(ObstacleType, Damage)
    { }
}