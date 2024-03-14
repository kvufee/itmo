using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab2.Entities;

namespace Itmo.ObjectOrientedProgramming.Lab2.Tests;

public class RepositoryData
{
    private DataBase _dataBase;

    public RepositoryData(DataBase dataBase)
    {
        _dataBase = dataBase;
    }

    public void CoolingSystemRepository()
    {
        var airCooler = new CoolingSystem(
            "Cooler Master Hyper 212 RGB",
            120,
            108,
            159,
            new List<string> { "LGA1200", "AM4", "LGA1151" },
            150);
        _dataBase.CoolingSystemRepository.Add(airCooler);

        var liquidCooler = new CoolingSystem(
            "NZXT Kraken X63",
            143,
            315,
            30,
            new List<string> { "LGA1700", "AM4", "sTRX4" },
            280);
        _dataBase.CoolingSystemRepository.Add(liquidCooler);

        var lowProfileCooler = new CoolingSystem(
            "Noctua NH-L9i",
            95,
            37,
            95,
            new List<string> { "LGA1200", "AM4", "LGA1151" },
            65);
        _dataBase.CoolingSystemRepository.Add(lowProfileCooler);
    }

    public void CpuRepository()
    {
        var intelCPU = new CPU(
            "Intel Core i9-12900K",
            3.2f,
            16,
            "LGA1700",
            true,
            new List<int> { 3200, 3600, 4000 },
            125,
            150);
        _dataBase.CpuRepository.Add(intelCPU);

        var amdCPU = new CPU(
            "AMD Ryzen 7 5800X",
            3.8f,
            8,
            "AM4",
            true,
            new List<int> { 3200, 3600, 4000 },
            105,
            105);
        _dataBase.CpuRepository.Add(amdCPU);

        var amdThreadripperCPU = new CPU(
            "AMD Ryzen Threadripper 3990X",
            2.9f,
            64,
            "sTRX4",
            false,
            new List<int> { 3200, 3600, 4000 },
            280,
            280);
        _dataBase.CpuRepository.Add(amdThreadripperCPU);
    }

    public void GpuRepository()
    {
        var nvidiaGPU = new GPU(
            "Nvidia RTX 3080",
            140,
            290,
            "PCIe 4.0",
            1710,
            320);
        _dataBase.GpuRepository.Add(nvidiaGPU);

        var amdGPU = new GPU(
            "AMD RX 6900 XT",
            128,
            267,
            "PCIe 4.0",
            2015,
            300);
        _dataBase.GpuRepository.Add(amdGPU);

        var intelGPU = new GPU(
            "Intel Xe-HPG",
            160,
            280,
            "PCIe 4.0",
            2400,
            350);
        _dataBase.GpuRepository.Add(intelGPU);
    }

    public void HardDriveRepository()
    {
        var samsungHDD = new HardDrive(
            "Samsung 870 EVO",
            1000,
            7200,
            5);
        _dataBase.HardDriveRepository.Add(samsungHDD);

        var wdHDD = new HardDrive(
            "WD Blue",
            2000,
            5400,
            7);
        _dataBase.HardDriveRepository.Add(wdHDD);

        var seagateHDD = new HardDrive(
            "Seagate BarraCuda",
            4000,
            7200,
            10);
        _dataBase.HardDriveRepository.Add(seagateHDD);
    }

    public void MotherboardRepository()
    {
        var asusB550F = new Motherboard(
            "ASUS ROG Strix B550-F Gaming",
            "Socket AM4",
            new List<string> { "PCIe 4.0" },
            6,
            "AMD B550",
            new List<int> { 2133, 2400, 2666, 2800, 3000, 3200, 3600, 4000, 4400 },
            true,
            "DDR4",
            "ATX",
            4,
            "DIMM",
            "ATX",
            "UEFI",
            true);
        _dataBase.MotherboardRepository.Add(asusB550F);

        var msiZ590 = new Motherboard(
            "MSI MPG Z590 Gaming Carbon WiFi",
            "LGA 1200",
            new List<string> { "PCIe 4.0", "PCIe 3.0" },
            6,
            "Intel Z590",
            new List<int> { 2133, 2400, 2666, 2800, 3000, 3200, 3600, 4000, 4400, 4800 },
            true,
            "DDR4",
            "ATX",
            4,
            "DIMM",
            "ATX",
            "UEFI",
            true);
        _dataBase.MotherboardRepository.Add(msiZ590);

        var gigabyteB450 = new Motherboard(
            "Gigabyte B450 AORUS M",
            "Socket AM4",
            new List<string> { "PCIe 3.0" },
            4,
            "AMD B450",
            new List<int> { 2133, 2400, 2666, 2933, 3200, 3333, 3466, 3600 },
            true,
            "DDR4",
            "Micro ATX",
            4,
            "DIMM",
            "Micro ATX",
            "UEFI",
            false);
        _dataBase.MotherboardRepository.Add(gigabyteB450);
    }

    public void PcCaseRepository()
    {
        var masterBoxMB311L = new PcCase(
            "Cooler Master MasterBox MB311L",
            344,
            166,
            new List<string> { "Micro ATX", "Mini ITX" },
            366,
            211,
            411);
        _dataBase.PcCaseRepository.Add(masterBoxMB311L);

        var meshifyC = new PcCase(
            "Fractal Design Meshify C",
            315,
            141,
            new List<string> { "ATX", "Micro ATX", "Mini ITX" },
            453,
            233,
            413);
        _dataBase.PcCaseRepository.Add(meshifyC);

        var nzxtH510 = new PcCase(
            "NZXT H510",
            325,
            144,
            new List<string> { "ATX", "Micro ATX", "Mini ITX" },
            435,
            210,
            428);
        _dataBase.PcCaseRepository.Add(nzxtH510);
    }

    public void PowerblockRepository()
    {
        var corsairPowerBlock = new PowerBlock(
            "Corsair CX550M",
            550);
        _dataBase.PowerblockRepository.Add(corsairPowerBlock);

        var evgaPowerBlock = new PowerBlock(
            "EVGA SuperNOVA 750 G5",
            750);
        _dataBase.PowerblockRepository.Add(evgaPowerBlock);

        var accordPowerBlock = new PowerBlock(
            "Accord ACC-TFX150",
            150);
        _dataBase.PowerblockRepository.Add(accordPowerBlock);
    }

    public void RamRepository()
    {
        var corsairRam = new RAM(
            "Corsair Vengeance LPX",
            16,
            "DIMM",
            "DDR4",
            1,
            new List<int> { 3200 },
            "16-18-18-36",
            1.2);
        _dataBase.RamRepository.Add(corsairRam);

        var crucialRam = new RAM(
            "Crucial Ballistix MAX",
            64,
            "DIMM",
            "DDR4",
            1,
            new List<int> { 4000 },
            "18-19-19-39",
            1.4);
        _dataBase.RamRepository.Add(crucialRam);

        var gskillRam = new RAM(
            "G.Skill Trident Z RGB",
            32,
            "DIMM",
            "DDR4",
            1,
            new List<int> { 3600 },
            "16-16-16-36",
            1.35);
        _dataBase.RamRepository.Add(gskillRam);
    }

    public void SsdRepository()
    {
        var kingstonSSD = new SSD(
            "Kingston A2000",
            false,
            1000,
            2000,
            2200,
            5);
        _dataBase.SsdRepository.Add(kingstonSSD);

        var samsungSSD = new SSD(
            "Samsung 970 EVO Plus",
            false,
            2000,
            3500,
            3300,
            6);
        _dataBase.SsdRepository.Add(samsungSSD);

        var westernDigitalSSD = new SSD(
            "Western Digital WD Blue SN550",
            false,
            500,
            1750,
            2400,
            3);
        _dataBase.SsdRepository.Add(westernDigitalSSD);
    }

    public void WifiAdapterRepository()
    {
        var tpLinkAdapter = new WifiAdapter(
            "TP-Link Archer T2U",
            new List<string> { "802.11ac", "802.11n" },
            false,
            3,
            2);
        _dataBase.WifiAdapterRepository.Add(tpLinkAdapter);

        var asusAdapter = new WifiAdapter(
            "ASUS PCE-AC68",
            new List<string> { "802.11ac", "802.11n", "802.11a" },
            true,
            3,
            3);
        _dataBase.WifiAdapterRepository.Add(asusAdapter);

        var netgarAdapter = new WifiAdapter(
            "Netgear Nighthawk A7000",
            new List<string> { "802.11ac", "802.11n" },
            true,
            3,
            4);
        _dataBase.WifiAdapterRepository.Add(netgarAdapter);
    }
}