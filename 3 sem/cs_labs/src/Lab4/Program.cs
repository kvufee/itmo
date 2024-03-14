namespace Itmo.ObjectOrientedProgramming.Lab4;

public static class Program
{
    public static void Main(string[] args)
    {
        IConsoleLaunch launch = new ConsoleLaunch();
        launch.Launch(args);
    }
}