package lab6.src.task2;

public class U1901Thread extends Thread
{
    private lab6.src.task2.Bank _bankWork;
    private int _intTrans;
    private long _lngSleep;

    public U1901Thread(lab6.src.task2.Bank bankWork, int intTrans, long lngSleep)
    {
        this._bankWork = bankWork;
        this._intTrans = intTrans;
        this._lngSleep = lngSleep;
    }

    @Override
    public void run()
    {
        _bankWork.calc(_intTrans, _lngSleep);
    }
}