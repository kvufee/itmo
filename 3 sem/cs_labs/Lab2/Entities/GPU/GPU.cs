namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class GPU : Component
{
    public GPU(
        string? name,
        int gpuHeight,
        int gpuLenght,
        string? pciEVersion,
        int gpuChipFrequency,
        int requiredPower)
        : base(name)
    {
        Name = name;
        GpuHeight = gpuHeight;
        GpuLenght = gpuLenght;
        PciEVersion = pciEVersion;
        GpuChipFrequency = gpuChipFrequency;
        RequiredPower = requiredPower;
    }

    public int GpuHeightProperty => GpuHeight;
    public int GpuLenghtProperty => GpuLenght;
    public string? PciEVersionProperty => PciEVersion;
    public int GpuChipFrequencyProperty => GpuChipFrequency;
    public int RequiredPowerProperty => RequiredPower;
    private int GpuHeight { get; set; }
    private int GpuLenght { get; set; }
    private string? PciEVersion { get; set; }
    private int GpuChipFrequency { get; set; }
    private int RequiredPower { get; set; }

    public void SetGpuHeight(int height)
    {
        GpuHeight = height;
    }

    public void SetGpuLenght(int lenght)
    {
        GpuLenght = lenght;
    }

    public void SetPciEVersion(string version)
    {
        PciEVersion = version;
    }

    public void SetGpuChipFrequency(int frequency)
    {
        GpuChipFrequency = frequency;
    }

    public void SetRequiredPower(int power)
    {
        RequiredPower = power;
    }
}