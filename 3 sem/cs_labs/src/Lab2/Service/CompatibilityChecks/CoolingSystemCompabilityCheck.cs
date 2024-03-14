using System;
using System.Linq;
using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;

public abstract class CoolingSystemCompabilityCheck
{
    public static bool IsCoolingSystemCompatible(CoolingSystem? coolingSystem, CPU cpu, PcCase pcCase)
    {
        if (cpu is null || coolingSystem is null || pcCase is null)
            throw new NullParameterException("One of the parameters is null");
        if (coolingSystem.SupportedCpuSocketsProperty is not null &&
            coolingSystem.SupportedCpuSocketsProperty.Contains(cpu.SocketTypeProperty) &&
            pcCase.CaseWidthProperty > coolingSystem.CoolerHeightProperty &&
            coolingSystem.MaxTdpProperty > cpu.HeatProductionProperty)
        {
            return true;
        }

        return false;
    }
}