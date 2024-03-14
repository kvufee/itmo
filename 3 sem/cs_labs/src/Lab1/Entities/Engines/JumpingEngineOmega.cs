namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public class JumpingEngineOmega : DefaultJumpingEngine
{
    private new const string EngineType = "JumpingEngineAlpha";
    private new const int Speed = 10;
    private new const int FuelCapacity = 1000;
    public JumpingEngineOmega()
        : base(EngineType, Speed, FuelCapacity)
    { }
}