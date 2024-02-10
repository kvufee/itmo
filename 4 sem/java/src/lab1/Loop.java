package lab1;

public class Loop
{
    public static void main(String[] args)
    {
        for (char i = 97; i < 123; i++)
        {
            System.out.print(i + " ");
        }
        System.out.println();


        long begin = new java.util.Date().getTime();

        for (int i = 0; i < 100000001; i++)
        {
            i += 1;
        }

        long end = new java.util.Date().getTime();
        System.out.println(end - begin);
    }
}