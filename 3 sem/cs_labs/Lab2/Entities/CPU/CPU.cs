using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class CPU : Component
{
    public CPU(
        string? name,
        float coreFrequency,
        int coresAmount,
        string? socketType,
        bool isIntegratedGpu,
        IEnumerable<int>? supportedRamFrequences,
        int heatProduction,
        int powerAmount)
        : base(name)
    {
        Name = name;
        CoreFrequency = coreFrequency;
        CoresAmount = coresAmount;
        SocketType = socketType;
        IsIntegratedGpu = isIntegratedGpu;
        SupportedRamFrequences = supportedRamFrequences;
        HeatProduction = heatProduction;
        PowerAmount = powerAmount;
    }

    public float CoreFrequencyProperty => CoreFrequency;
    public int CoresAmountCoreFrequencyProperty => CoresAmount;
    public string? SocketTypeProperty => SocketType;
    public bool IsIntegratedGpuProperty => IsIntegratedGpu;
    public IEnumerable<int>? SupportedRamFrequencesProperty => SupportedRamFrequences;
    public int HeatProductionProperty => HeatProduction;
    public int PowerAmountProperty => PowerAmount;
    private float CoreFrequency { get; set; }
    private int CoresAmount { get; set; }
    private string? SocketType { get; set; }
    private bool IsIntegratedGpu { get; set; }
    private IEnumerable<int>? SupportedRamFrequences { get; set; }
    private int HeatProduction { get; set; }
    private int PowerAmount { get; set; }

    public void SetCoreFrequency(float coreFreq)
    {
        CoreFrequency = coreFreq;
    }

    public void SetCoresAmount(int cores)
    {
        CoresAmount = cores;
    }

    public void SetSocketType(string socket)
    {
        SocketType = socket;
    }

    public void SetIntegratedGpu(bool isIntegrated)
    {
        IsIntegratedGpu = isIntegrated;
    }

    public void SetSupportedRamFrequences(IEnumerable<int> frequencies)
    {
        SupportedRamFrequences = frequencies;
    }

    public void SetHeatProduction(int production)
    {
        HeatProduction = production;
    }

    public void SetPowerAmount(int power)
    {
        PowerAmount = power;
    }
}