using System;

namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public class DefaultJumpingEngine : IEngine
{
    protected DefaultJumpingEngine(string engineType, int speed, int fuelCapacity)
    {
        EngineType = engineType;
        Speed = speed;
        FuelCapacity = fuelCapacity;
    }

    public string EngineType { get; }
    public int Speed { get; }
    public int FuelCapacity { get; }
    private int SpentFuel { get; set; }

    public int FuelConsumption(int distance)
    {
        switch (EngineType)
        {
            case "JumpingEngineOmega":
                SpentFuel = distance * Convert.ToInt32(Math.Log2(1));
                break;
            case "JumpingEngineGamma":
                SpentFuel *= distance * distance;
                break;
        }

        SpentFuel = distance;
        return SpentFuel;
    }
}