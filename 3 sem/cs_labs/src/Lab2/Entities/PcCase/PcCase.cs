using System.Collections.Generic;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class PcCase : Component
{
    public PcCase(
        string? name,
        int maxGpuLength,
        int maxGpuWidth,
        IEnumerable<string>? supportedMotherboardFormfactors,
        int caseHeight,
        int caseWidth,
        int caseLength)
        : base(name)
    {
        Name = name;
        MaxGpuLength = maxGpuLength;
        MaxGpuWidth = maxGpuWidth;
        SupportedMotherboardFormfactors = supportedMotherboardFormfactors;
        CaseHeight = caseHeight;
        CaseWidth = caseWidth;
        CaseLength = caseLength;
    }

    public int MaxGpuLengthProperty => MaxGpuLength;
    public int MaxGpuWidthProperty => MaxGpuWidth;
    public IEnumerable<string>? SupportedMotherboardFormfactorsProperty => SupportedMotherboardFormfactors;
    public int CaseHeightProperty => CaseHeight;
    public int CaseWidthProperty => CaseWidth;
    public int CaseLengthProperty => CaseLength;
    private int MaxGpuLength { get; set; }
    private int MaxGpuWidth { get; set; }
    private IEnumerable<string>? SupportedMotherboardFormfactors { get; set; }
    private int CaseHeight { get; set; }
    private int CaseWidth { get; set; }
    private int CaseLength { get; set; }

    public void SetMaxGpuLength(int lenghth)
    {
        MaxGpuLength = lenghth;
    }

    public void SetMaxGpuWidth(int width)
    {
        MaxGpuWidth = width;
    }

    public void SetSupportedMotherboardFormfactors(IEnumerable<string> formFactors)
    {
        SupportedMotherboardFormfactors = formFactors;
    }

    public void SetCaseHeight(int height)
    {
        CaseHeight = height;
    }

    public void SetCaseWidth(int width)
    {
        CaseWidth = width;
    }

    public void SetCaseLength(int length)
    {
        CaseLength = length;
    }
}