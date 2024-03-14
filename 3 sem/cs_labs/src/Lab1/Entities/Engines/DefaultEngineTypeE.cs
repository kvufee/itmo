using System;

namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public abstract class DefaultEngineTypeE : IEngine
{
    protected DefaultEngineTypeE(string engineType, int speed, int fuelCapacity, int startFuel)
    {
        EngineType = engineType;
        Speed = speed;
        FuelCapacity = fuelCapacity;
        StartFuel = startFuel;
    }

    public string EngineType { get; }
    public int Speed { get; }
    public int FuelCapacity { get; }
    public int StartFuel { get; }
    private int SpentFuel { get; set; }
    public int FuelConsumption(int distance)
    {
        SpentFuel = distance * Convert.ToInt32(Math.Exp(1));
        return SpentFuel;
    }
}