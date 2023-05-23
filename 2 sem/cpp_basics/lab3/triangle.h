struct Vec
{
    float x, y;
};

class Triangle
{
    float x1, y1;
    float x2, y2;
    float x3, y3;
    float perimeter, square;
public:
    Triangle();
    bool operator==(const Triangle& trg) const;
    bool operator!=(const Triangle& trg) const;
    bool operator<(const Triangle& trg) const;
    bool operator>(const Triangle& trg) const;
    float heronSq(Triangle& trg);
    float perimCount(Triangle& trg);
};


