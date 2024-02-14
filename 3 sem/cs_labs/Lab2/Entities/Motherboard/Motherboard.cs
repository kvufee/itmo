using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class Motherboard : Component
{
    public Motherboard(
        string? name,
        string? socketType,
        IEnumerable<string>? pciELines,
        int sataSlotsAmount,
        string? chipsetType,
        IEnumerable<int>? supportedRamFrequency,
        bool isXmpSupported,
        string? supportedDdrType,
        string? motherboardType,
        int ramSlotsAmount,
        string? ramFormfactor,
        string? motherboardFormfactor,
        string? biosType,
        bool isWifiModified)
    : base(name)
    {
        Name = name;
        SocketType = socketType;
        PciELines = pciELines;
        SataSlotsAmount = sataSlotsAmount;
        ChipsetType = chipsetType;
        SupportedRamFrequency = supportedRamFrequency;
        IsXmpSupported = isXmpSupported;
        SupportedDdrType = supportedDdrType;
        MotherboardType = motherboardType;
        RamSlotsAmount = ramSlotsAmount;
        RamFormfactor = ramFormfactor;
        MotherboardFormfactor = motherboardFormfactor;
        BiosType = biosType;
        IsWifiModified = isWifiModified;
    }

    public string? SocketTypeProperty => SocketType;
    public IEnumerable<string>? PciELinesProperty => PciELines;
    public int SataSlotsAmountProperty => SataSlotsAmount;
    public string? ChipsetTypeProperty => ChipsetType;
    public IEnumerable<int>? SupportedRamFrequencyProperty => SupportedRamFrequency;
    public bool IsXmpSupportedProperty => IsXmpSupported;
    public string? SupportedDdrTypeProperty => SupportedDdrType;
    public string? MotherboardTypeProperty => MotherboardType;
    public int RamSlotsAmountProperty => RamSlotsAmount;
    public string? RamFormfactorProperty => RamFormfactor;
    public string? MotherboardFormfactorProperty => MotherboardFormfactor;
    public string? BiosTypeProperty => BiosType;
    public bool IsWifiModifiedProperty => IsWifiModified;
    private string? SocketType { get; set; }
    private IEnumerable<string>? PciELines { get; set; }
    private int SataSlotsAmount { get; set; }
    private string? ChipsetType { get; set; }
    private IEnumerable<int>? SupportedRamFrequency { get; set; }
    private bool IsXmpSupported { get; set; }
    private string? SupportedDdrType { get; set; }
    private string? MotherboardType { get; set; }
    private int RamSlotsAmount { get; set; }
    private string? RamFormfactor { get; set; }
    private string? MotherboardFormfactor { get; set; }
    private string? BiosType { get; set; }
    private bool IsWifiModified { get; set; }

    public void SetSocketType(string type)
    {
        SocketType = type;
    }

    public void SetPciELines(IEnumerable<string> lines)
    {
        PciELines = lines;
    }

    public void SetSataSlotsAmount(int amount)
    {
        SataSlotsAmount = amount;
    }

    public void SetChipsetType(string type)
    {
        ChipsetType = type;
    }

    public void SetSupportedRamFrequency(IEnumerable<int> supportedRamFrequency)
    {
        SupportedRamFrequency = supportedRamFrequency;
    }

    public void SetIsXmpSupported(bool flag)
    {
        IsXmpSupported = flag;
    }

    public void SetSupportedDdrType(string type)
    {
        SupportedDdrType = type;
    }

    public void SetMotherboardType(string type)
    {
        MotherboardType = type;
    }

    public void SetRamSlotsAmount(int amount)
    {
        RamSlotsAmount = amount;
    }

    public void SetRamFormfactor(string form)
    {
        RamFormfactor = form;
    }

    public void SetMotherboardFormfactor(string form)
    {
        MotherboardFormfactor = form;
    }

    public void SetBiosType(string type)
    {
        BiosType = type;
    }

    public void SetIsWifiModified(bool flag)
    {
        IsWifiModified = flag;
    }
}