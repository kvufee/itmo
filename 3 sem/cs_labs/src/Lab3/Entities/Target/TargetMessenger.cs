using Itmo.ObjectOrientedProgramming.Lab3.Entities.Messenger;

namespace Itmo.ObjectOrientedProgramming.Lab3.Entities;

public class TargetMessenger : ITarget
{
    private ITarget _target;
    private IMessenger _messenger;
    private Viber _viber = new Viber("Viber");
    private Odnoklassniki _odnoklassniki = new Odnoklassniki("Odnoklassniki");

    public TargetMessenger(ITarget target, IMessenger messenger)
    {
        _target = target;
        _messenger = messenger;
    }

    public void SendMessage(Message message)
    {
        switch (_messenger.Name)
        {
            case "Viber":
                _viber.SendMessage(message);
                break;
            case "Odnoklassniki":
                _odnoklassniki.SendMessage(message);
                break;
        }
    }
}