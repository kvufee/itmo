namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public class EngineTypeC : DefaultEngineTypeC
{
    private new const string EngineType = "EngineTypeC";
    private new const int Speed = 10;
    private new const int FuelCapacity = 1000;
    private new const int StartFuel = 50;

    public EngineTypeC()
        : base(EngineType, Speed, FuelCapacity, StartFuel)
    { }
}