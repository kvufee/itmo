namespace Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

public class AntimatterBlast : Obstacle
{
    private new const string ObstacleType = "AntimatterBlast";
    private new const int Damage = 100;
    public AntimatterBlast()
        : base(ObstacleType, Damage)
    { }
}