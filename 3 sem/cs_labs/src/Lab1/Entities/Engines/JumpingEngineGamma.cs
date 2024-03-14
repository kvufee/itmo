namespace Itmo.ObjectOrientedProgramming.Lab1.Engines;

public class JumpingEngineGamma : DefaultJumpingEngine
{
    private new const string EngineType = "JumpingEngineAlpha";
    private new const int Speed = 10;
    private new const int FuelCapacity = 1000;
    public JumpingEngineGamma()
        : base(EngineType, Speed, FuelCapacity)
    { }
}