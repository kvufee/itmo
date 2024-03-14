using System;
using Itmo.ObjectOrientedProgramming.Lab1.Spaseships;
using Environment = Itmo.ObjectOrientedProgramming.Lab1.Environments.Environment;

namespace Itmo.ObjectOrientedProgramming.Lab1.Service;

public abstract class FuelPrice
{
    private const int PricePlasma = 10;
    private const int PriceGravitonMatter = 15;

    public static int PriceOfFuel(Spaceship spaceship, Environment environment)
    {
        if (environment is null) throw new ArgumentNullException(nameof(environment));
        if (spaceship is null) throw new ArgumentNullException(nameof(spaceship));

        switch (spaceship.JumpingEngine)
        {
            case null when spaceship.EngineTypeC is null && spaceship.EngineTypeE is not null:
                return spaceship.EngineTypeE.FuelConsumption(environment.Distance) * PricePlasma;
            case null when spaceship.EngineTypeE is null && spaceship.EngineTypeC is not null:
                return spaceship.EngineTypeC.FuelConsumption(environment.Distance) * PricePlasma;
            default:
            {
                if (spaceship.JumpingEngine is not null && spaceship.EngineTypeC is not null && spaceship.EngineTypeE is null)
                {
                    return (spaceship.EngineTypeC.FuelConsumption(environment.Distance) * PricePlasma) + (spaceship.JumpingEngine.FuelConsumption(environment.Distance) * PriceGravitonMatter);
                }
                else if (spaceship.JumpingEngine is not null && spaceship.EngineTypeC is null && spaceship.EngineTypeE is not null)
                {
                    return (spaceship.EngineTypeE.FuelConsumption(environment.Distance) * PricePlasma) + (spaceship.JumpingEngine.FuelConsumption(environment.Distance) * PriceGravitonMatter);
                }

                break;
            }
        }

        return 0;
    }
}