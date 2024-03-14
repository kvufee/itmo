using System.Collections.Generic;
using Itmo.ObjectOrientedProgramming.Lab1.Obstacles;

namespace Itmo.ObjectOrientedProgramming.Lab1.Environments;

public class RegularSpace : Environment
{
    public RegularSpace(int distance, IReadOnlyCollection<IObstacle> environmentObstacles)
        : base(distance, environmentObstacles)
    { }
}