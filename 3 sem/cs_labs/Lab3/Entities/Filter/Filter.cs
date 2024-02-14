using System;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities.Filter;

public class Filter : ITarget
{
    private readonly ITarget _decoratee;

    public Filter(ITarget decoratee, int filterlevel)
    {
        _decoratee = decoratee;
        FilterLevel = filterlevel;
    }

    public int FilterLevel { get; }

    public void SendMessage(Message message)
    {
        if (message == null)
        {
            throw new ArgumentNullException(nameof(message));
        }

        if (message.ImportanceLevel < FilterLevel)
        {
            _decoratee.SendMessage(message);
        }
    }
}