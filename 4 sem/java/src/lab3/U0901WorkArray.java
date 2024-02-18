package lab3;

public class U0901WorkArray<T extends Number>
{
    T[] arrNums;

    U0901WorkArray(T[] numP)
    {
        arrNums = numP;
    }

    double sum()
    {
        double doubleWork = 0;
        for (T num : arrNums)
        {
            doubleWork += num.doubleValue();
        }
        return doubleWork;
    }

    public static void main(String[] args)
    {
        Integer[] intArr = {10, 20, 15};
        Float[] floatArr = new Float[10];

        for (int i = 0; i < floatArr.length; i++)
        {
            floatArr[i] = (float) Math.random();
        }

        U0901WorkArray<Integer> insWorkArrayInt = new U0901WorkArray<>(intArr);
        U0901WorkArray<Float> insWorkArrayFloat = new U0901WorkArray<>(floatArr);

        System.out.println("Сумма массива intArr: " + insWorkArrayInt.sum());
        System.out.println("Сумма массива floatArr: " + insWorkArrayFloat.sum());
    }
}