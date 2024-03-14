using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

namespace Itmo.ObjectOrientedProgramming.Lab1.Environments;

public class HighDensitySpace : Environment
{
    public HighDensitySpace(int distance, IReadOnlyCollection<IObstacle> environmentObstacles)
        : base(distance, environmentObstacles)
    { }
}