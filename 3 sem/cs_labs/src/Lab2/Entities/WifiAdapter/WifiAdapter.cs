using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class WifiAdapter : Component
{
    public WifiAdapter(
        string? name,
        IEnumerable<string>? wifiStandart,
        bool isBluetoothModified,
        int pciEVersion,
        int requiredPower)
    : base(name)
    {
        Name = name;
        WifiStandart = wifiStandart;
        IsBluetoothModified = isBluetoothModified;
        PciEVersion = pciEVersion;
        RequiredPower = requiredPower;
    }

    public IEnumerable<string>? WifiStandartProperty => WifiStandart;
    public bool IsBluetoothModifiedProperty => IsBluetoothModified;
    public int PciEVersionProperty => PciEVersion;
    public int RequiredPowerProperty => RequiredPower;
    private IEnumerable<string>? WifiStandart { get; set; }
    private bool IsBluetoothModified { get; set; }
    private int PciEVersion { get; set; }
    private int RequiredPower { get; set; }

    public void SetWifiStandart(IEnumerable<string> standart)
    {
        WifiStandart = standart;
    }

    public void SetIsBluetoothModified(bool bluetooth)
    {
        IsBluetoothModified = bluetooth;
    }

    public void SetPciEVersion(int version)
    {
        PciEVersion = version;
    }

    public void SetRequiredPower(int power)
    {
        RequiredPower = power;
    }
}