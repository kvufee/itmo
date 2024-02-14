using Itmo.ObjectOrientedProgramming.Lab2.Entities.CompatibilityChecks;
using Itmo.ObjectOrientedProgramming.Lab2.Service;

namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class PcBuilder
{
    private CoolingSystem? _coolingSystem;
    private CPU? _cpu;
    private GPU? _gpu;
    private HardDrive? _hardDrive;
    private Motherboard? _motherboard;
    private PcCase? _pcCase;
    private PowerBlock? _powerBlock;
    private RAM? _ram;
    private SSD? _ssd;
    private WifiAdapter? _wifiAdapter;

    public void BuildCoolingSystem(CoolingSystem? coolingSystem)
    {
        if (_pcCase != null &&
            _cpu != null &&
            !CoolingSystemCompabilityCheck.IsCoolingSystemCompatible(coolingSystem, _cpu, _pcCase))
        {
            throw new ComponentIsNotCompatibleException("Build failed on cooling system");
        }

        _coolingSystem = coolingSystem;
    }

    public void BuildCpu(CPU? cpu)
    {
        if (cpu != null &&
            _coolingSystem != null &&
            _motherboard != null &&
            _ram != null &&
            !CPUCompabilityCheck.IsCpuCompatible(cpu, _ram, _motherboard, _coolingSystem))
        {
            throw new ComponentIsNotCompatibleException("Build failed on CPU");
        }

        _cpu = cpu;
    }

    public void BuildGpu(GPU? gpu)
    {
        if (gpu != null &&
            _motherboard != null &&
            _pcCase != null &&
            !GPUCompabilityCheck.IsGpuCompatible(gpu, _pcCase, _motherboard))
        {
            throw new ComponentIsNotCompatibleException("Build failed on GPU");
        }

        _gpu = gpu;
    }

    public void BuildHardDrive(HardDrive? hardDrive)
    {
        if (hardDrive != null &&
            _motherboard != null &&
            !HardDriveCompabilityCheck.IsHardDriveCompatible(hardDrive, _motherboard))
        {
            throw new ComponentIsNotCompatibleException("Build failed on hard drive");
        }

        _hardDrive = hardDrive;
    }

    public void BuildMotherboard(Motherboard? motherboard)
    {
        if (motherboard != null &&
            _ssd != null &&
            _ram != null &&
            _cpu != null &&
            _pcCase != null &&
            !MotherboardCompabilityCheck.IsMotherboardCompatible(motherboard, _pcCase, _cpu, _ram, _ssd))
        {
            throw new ComponentIsNotCompatibleException("Build failed on motherboard");
        }

        _motherboard = motherboard;
    }

    public void BuildPcCase(PcCase? pcCase)
    {
        if (pcCase != null &&
            _motherboard != null &&
            _gpu != null &&
            !PcCaseCompabilityCheck.IsPcCaseCompatible(pcCase, _gpu, _motherboard))
        {
            throw new ComponentIsNotCompatibleException("Build failed on PC case");
        }

        _pcCase = pcCase;
    }

    public void BuildPowerBlock(PowerBlock? powerBlock)
    {
        if (powerBlock != null &&
            _wifiAdapter != null &&
            _ssd != null &&
            _ram != null &&
            _hardDrive != null &&
            _gpu != null &&
            _cpu != null &&
            !PowerblockCompabilityCheck.IsPowerblockCompatible(powerBlock, _cpu, _gpu, _hardDrive, _ram, _ssd, _wifiAdapter))
        {
            throw new ComponentIsNotCompatibleException("Build failed on power block");
        }

        _powerBlock = powerBlock;
    }

    public void BuildRam(RAM? ram)
    {
        if (ram != null &&
            _cpu != null &&
            _motherboard != null &&
            RAMCompabilityCheck.IsRamCompatible(ram, _motherboard, _cpu))
        {
            throw new ComponentIsNotCompatibleException("Build failed on RAM");
        }

        _ram = ram;
    }

    public void BuildSsd(SSD? ssd)
    {
        if (ssd != null &&
            _motherboard != null &&
            SSDCompabilityCheck.IsSsdCompatible(ssd, _motherboard))
        {
            throw new ComponentIsNotCompatibleException("Build failed on SSD");
        }

        _ssd = ssd;
    }

    public void BuildWifiAdapter(WifiAdapter? wifiAdapter)
    {
        if (_motherboard != null &&
            WifiAdapterCompabilityCheck.IsWifiAdapterCompatible(_motherboard))
        {
            throw new ComponentIsNotCompatibleException("Build failed on WiFi adapter");
        }

        _wifiAdapter = wifiAdapter;
    }

    public BuiltPc? ReturnBuiltPc()
    {
        if (_coolingSystem != null && _cpu != null && _gpu != null
            && _hardDrive != null && _motherboard != null && _pcCase != null && _powerBlock != null
            && _ram != null && _ssd != null && _wifiAdapter != null)
        {
            return new BuiltPc(_coolingSystem, _cpu, _gpu, _hardDrive, _motherboard, _pcCase, _powerBlock, _ram, _ssd, _wifiAdapter);
        }

        return null;
    }
}