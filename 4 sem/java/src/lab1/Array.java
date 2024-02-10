package lab1;

public class Array
{
    public static void main(String[] args)
    {
        int[] mas = {12,43,12,-65,778,123,32,76};
        int max = 0;

        for (int i = 0; i < mas.length; i++)
        {
            if (mas[i] > max)
            {
                max = mas[i];
            }
        }
        System.out.println(max);

        
    }
}
