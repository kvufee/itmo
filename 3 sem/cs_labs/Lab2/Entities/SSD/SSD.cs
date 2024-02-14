namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class SSD : Component
{
    public SSD(
        string? name,
        bool isSataConnection,
        int memoryCapacity,
        int maxWriteSpeed,
        int maxReadSpeed,
        int requiredPower)
    : base(name)
    {
        Name = name;
        IsSataConnection = isSataConnection;
        MemoryCapacity = memoryCapacity;
        MaxWriteSpeed = maxWriteSpeed;
        MaxReadSpeed = maxReadSpeed;
        RequiredPower = requiredPower;
    }

    public bool IsSataConnectionProperty => IsSataConnection;
    public int MemoryCapacityProperty => MemoryCapacity;
    public int MaxWriteSpeedProperty => MaxWriteSpeed;
    public int MaxReadSpeedProperty => MaxReadSpeed;
    public int RequiredPowerProperty => RequiredPower;
    private bool IsSataConnection { get; set; }
    private int MemoryCapacity { get; set; }
    private int MaxWriteSpeed { get; set; }
    private int MaxReadSpeed { get; set; }
    private int RequiredPower { get; set; }

    public void SetIsSataConnection(bool sataConnection)
    {
        IsSataConnection = sataConnection;
    }

    public void SetMemoryCapacity(int capacity)
    {
        MemoryCapacity = capacity;
    }

    public void SetMaxWriteSpeed(int speed)
    {
        MaxWriteSpeed = speed;
    }

    public void SetMaxReadSpeed(int speed)
    {
        MaxReadSpeed = speed;
    }

    public void SetRequiredPower(int power)
    {
        RequiredPower = power;
    }
}