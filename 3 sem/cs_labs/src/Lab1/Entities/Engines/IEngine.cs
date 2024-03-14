namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public interface IEngine
{
    string EngineType { get; }
    int Speed { get; }
    int FuelConsumption(int distance);
}