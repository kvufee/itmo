namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class HardDrive : Component
{
    public HardDrive(
        string? name,
        float capacity,
        int spindleSpeed,
        int requiredPower)
    : base(name)
    {
        Name = name;
        Capacity = capacity;
        SpindleSpeed = spindleSpeed;
        RequiredPower = requiredPower;
    }

    public float CapacityProperty => Capacity;
    public int SpindleSpeedProperty => SpindleSpeed;
    public int RequiredPowerProperty => RequiredPower;
    private float Capacity { get; set; }
    private int SpindleSpeed { get; set; }
    private int RequiredPower { get; set; }

    public void SetCapacity(int capacity)
    {
        Capacity = capacity;
    }

    public void SetSpindleSpeed(int speed)
    {
        SpindleSpeed = speed;
    }

    public void SetRequiredPower(int power)
    {
        RequiredPower = power;
    }
}