namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public class JumpingEngineAlpha : Engine
{
    public JumpingEngineAlpha()
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
    }

    public override int CalculateTime()
    {
        base.CalculateTime();
    }

    public override bool IsPassable()
    {
        base.IsPassable();
    }

    public override void Start()
    {
        base.Start();
    }
}