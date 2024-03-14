using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class RAM : Component
{
    public RAM(
        string? name,
        int memoryCapacity,
        string? ramFormfactor,
        string? ramMemoryStandart,
        int requiredPower,
        IEnumerable<int>? availableMemoryProfiles,
        string? ramTimings,
        double xmpVoltage)
    : base(name)
    {
        Name = name;
        MemoryCapacity = memoryCapacity;
        RamFormfactor = ramFormfactor;
        RamMemoryStandart = ramMemoryStandart;
        RequiredPower = requiredPower;
        AvailableMemoryProfiles = availableMemoryProfiles;
        RamTimings = ramTimings;
        XmpVoltage = xmpVoltage;
    }

    public int MemoryCapacityProperty => MemoryCapacity;
    public string? RamFormfactorProperty => RamFormfactor;
    public string? RamMemoryStandartProperty => RamMemoryStandart;
    public int RequiredPowerProperty => RequiredPower;
    public IEnumerable<int>? AvailableMemoryProfilesProperty => AvailableMemoryProfiles;
    public string? RamTimingsProperty => RamTimings;
    public double XmpVoltageProperty => XmpVoltage;
    private int MemoryCapacity { get; set; }
    private string? RamFormfactor { get; set; }
    private string? RamMemoryStandart { get; set; }
    private int RequiredPower { get; set; }
    private IEnumerable<int>? AvailableMemoryProfiles { get; set; }
    private string? RamTimings { get; set; }
    private double XmpVoltage { get; set; }

    public void SetMemoryCapacity(int capacity)
    {
        MemoryCapacity = capacity;
    }

    public void SetRamFormfactor(string form)
    {
        RamFormfactor = form;
    }

    public void SetRamMemoryStandart(string standart)
    {
        RamMemoryStandart = standart;
    }

    public void SetRequiredPower(int power)
    {
        RequiredPower = power;
    }

    public void SetAvailableMemoryProfiles(IEnumerable<int> memoryProfiles)
    {
        AvailableMemoryProfiles = memoryProfiles;
    }

    public void SetRamTimings(string timings)
    {
        RamTimings = timings;
    }

    public void SetXmpVoltage(double voltage)
    {
        XmpVoltage = voltage;
    }
}