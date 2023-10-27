namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public class JumpingEngineOmega : Engine
{
    public JumpingEngineOmega()
    {
        EngineType = this.GetType().Name;
        Speed = 0;
        Time = 0;
        FuelCapacity = 250;
        FuelConsumption = 5;
        PathLenght = 0;
    }
    public override int CalculateFuelConsumption()
    {
        base.CalculateFuelConsumption();
        return 0;
    }

    public override int CalculateTime()
    {
        base.CalculateTime();
        return 0;
    }

    public override bool IsPassable()
    {
        base.IsPassable();
        return false;
    }

    public override void Start()
    {
        base.Start();
    }
}