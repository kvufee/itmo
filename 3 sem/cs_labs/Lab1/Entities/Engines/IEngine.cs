namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public interface IEngine
{
    int CalculateFuelConsumption();
    int CalculateTime();
    bool IsPassable();
    void Start();
}