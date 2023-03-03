#include <stdio.h>


enum Lamps
{
    Incandescent, Halogen, Fluorescent,
    LED, Quartz, Herosene
};

struct rectangle {
    int width, length;
};

union mp3player
{
    int val;
    struct
    {
        unsigned char Play : 1;
        unsigned char Stop : 1;
        unsigned char Record : 1;
    };
};

int main()
{
    enum Lamps lamp = Halogen;
    printf("%d\n", lamp);
    printf("\n");

    struct rectangle rect;
    scanf("%d", &rect.length);
    scanf("%d", &rect.width);
    int square = rect.length * rect.width;
    printf("%d\n", square);

    union mp3player pl;
    scanf("%x", &pl.val);
    printf("Play: %s || Pause: %s || Запись: %s \n",
           pl.Play ? "On" : "Off",
           pl.Stop ? "On" : "Off",
           pl.Record ? "On" : "Off");

    return 0;
}