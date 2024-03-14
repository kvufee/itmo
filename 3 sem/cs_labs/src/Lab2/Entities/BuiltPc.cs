namespace Itmo.ObjectOrientedProgramming.Lab2.Entities;

public class BuiltPc
{
    public BuiltPc(
        CoolingSystem coolingSystem,
        CPU cpu,
        GPU gpu,
        HardDrive hardDrive,
        Motherboard motherboard,
        PcCase pcCase,
        PowerBlock powerBlock,
        RAM ram,
        SSD ssd,
        WifiAdapter wifiAdapter)
    {
        CoolingSystem = coolingSystem;
        Cpu = cpu;
        Gpu = gpu;
        HardDrive = hardDrive;
        Motherboard = motherboard;
        PcCase = pcCase;
        PowerBlock = powerBlock;
        Ram = ram;
        Ssd = ssd;
        WifiAdapter = wifiAdapter;
    }

    private CoolingSystem CoolingSystem { get; set; }
    private CPU Cpu { get; set; }
    private GPU Gpu { get; set; }
    private HardDrive HardDrive { get; set; }
    private Motherboard Motherboard { get; set; }
    private PcCase PcCase { get; set; }
    private PowerBlock PowerBlock { get; set; }
    private RAM Ram { get; set; }
    private SSD Ssd { get; set; }
    private WifiAdapter WifiAdapter { get; set; }

    public CoolingSystem GetCoolingSystem() => CoolingSystem;
    public CPU GetCpu() => Cpu;
    public GPU GetGpu() => Gpu;
    public HardDrive GetHardDrive() => HardDrive;
    public Motherboard GetMotherboard() => Motherboard;
    public PcCase GetPcCase() => PcCase;
    public PowerBlock GetPowerBlock() => PowerBlock;
    public RAM GetRam() => Ram;
    public SSD GetSsd() => Ssd;
    public WifiAdapter GetWifiAdapter() => WifiAdapter;
}