namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class PowerBlock : Component
{
    public PowerBlock(
        string? name,
        int powerCapacity)
    : base(name)
    {
        Name = name;
        PowerCapacity = powerCapacity;
    }

    public int PowerCapacityProperty => PowerCapacity;
    private int PowerCapacity { get; set; }

    public void SetPowerCapacity(int capacity)
    {
        PowerCapacity = capacity;
    }
}