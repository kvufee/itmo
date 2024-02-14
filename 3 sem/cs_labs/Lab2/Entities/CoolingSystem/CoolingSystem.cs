using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class CoolingSystem : Component
{
    public CoolingSystem(
        string? name,
        int coolerWidth,
        int coolerHeight,
        int coolerLength,
        IEnumerable<string>? supportedCpuSockets,
        int maxTdp)
        : base(name)
    {
        Name = name;
        CoolerWidth = coolerWidth;
        CoolerHeight = coolerHeight;
        CoolerLength = coolerLength;
        SupportedCpuSockets = supportedCpuSockets;
        MaxTdp = maxTdp;
    }

    public int CoolerWidthProperty => CoolerWidth;
    public int CoolerHeightProperty => CoolerHeight;
    public int CoolerLenghtProperty => CoolerLength;
    public IEnumerable<string>? SupportedCpuSocketsProperty => SupportedCpuSockets;
    public int MaxTdpProperty => MaxTdp;
    private int CoolerWidth { get; set; }
    private int CoolerHeight { get; set; }
    private int CoolerLength { get; set; }
    private IEnumerable<string>? SupportedCpuSockets { get; set; }
    private int MaxTdp { get; set; }

    public void SetCoolerWidth(int coolerWidth)
    {
        CoolerWidth = coolerWidth;
    }

    public void SetCoolerHeight(int coolerHeight)
    {
        CoolerHeight = coolerHeight;
    }

    public void SetCoolerLength(int coolerLength)
    {
        CoolerLength = coolerLength;
    }

    public void SetSupportedCpuSockets(IEnumerable<string> listOfSockets)
    {
        SupportedCpuSockets = listOfSockets;
    }

    public void SetMaxTdp(int tdp)
    {
        MaxTdp = tdp;
    }
}