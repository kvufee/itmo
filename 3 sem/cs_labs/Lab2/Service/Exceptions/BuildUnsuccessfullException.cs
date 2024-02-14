using System;

namespace Itmo.ObjectOrientedProgramming.Lab2.Service;

public class BuildUnsuccessfullException : Exception
{
    public BuildUnsuccessfullException()
    { }

    public BuildUnsuccessfullException(string message)
        : base(message)
    { }

    public BuildUnsuccessfullException(string message, Exception innerException)
        : base(message, innerException)
    { }
}