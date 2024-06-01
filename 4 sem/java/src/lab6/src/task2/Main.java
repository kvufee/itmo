package lab6.src.task2;

public class Main
{
    public static void main(String[] args)
    {
        lab6.src.task2.Bank bankMain = new lab6.src.task2.Bank();

        lab6.src.task2.U1901Thread threadOne = new lab6.src.task2.U1901Thread(bankMain, 100, 2000);
        threadOne.setName("ThreadOne");
        threadOne.setPriority(Thread.MAX_PRIORITY);
        threadOne.start();

        lab6.src.task2.U1901Thread threadTwo = new lab6.src.task2.U1901Thread(bankMain, 50, 300);
        threadTwo.setName("ThreadTwo");
        threadTwo.setPriority(Thread.MAX_PRIORITY);
        threadTwo.start();

        System.out.println("Current Thread: " + Thread.currentThread().getName());
    }
}