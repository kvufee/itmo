namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public class EngineTypeE : DefaultEngineTypeE
{
    private new const string EngineType = "EngineTypeE";
    private new const int Speed = 10;
    private new const int FuelCapacity = 1000;
    private new const int StartFuel = 75;

    public EngineTypeE()
        : base(EngineType, Speed, FuelCapacity, StartFuel)
    { }
}