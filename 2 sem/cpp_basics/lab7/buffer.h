template<class T>
class CircularBuffer
{
private:
    int _size;
    int writeCount;
    int firstPosition;
    T *_data;
    T *_first;
    T *_last;

    T *PointerIncrease(T *pointer, bool isFirst = false);
    T *PointerDecrease(T *pointer, bool isFirst = false);
public:
    CircularBuffer(int size);
    ~CircularBuffer();

    void addFirst(T newElement);
    void addRandom(T place, T newElement);
    void addLast(T newElement);
    T first();
    T last();
    void delFirst();
    void delLast();
    T &operator[](const int pos);
    T operator[](const int pos) const;
    void changeCapacity(int newSize);
    Iterator<T> begin() const;
    Iterator<T> end() const;
    void print();
};