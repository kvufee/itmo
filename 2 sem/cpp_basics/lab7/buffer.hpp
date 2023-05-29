#include <iterator>

using namespace std;


template<class T>
class CBuffer
{
private:
    int _size;
    int writeCount;
    int firstPosition;
    T *_data;
    T *_first;
    T *_last;


    T CBuffer<T>::*PointerIncrease(T *pointer, bool isFirst = false)
    {
        if (isFirst)
            pointer == &_data[_size] ? firstPosition = 0 : firstPosition++;
        return (pointer == &_data[_size] ? &_data[0] : pointer + 1);
    }

    T *PointerDecrease(T *pointer, bool isFirst = false)
    {
        if (isFirst)
            pointer == &_data[0] ? firstPosition = _size : firstPosition--;
        return (pointer == &_data[0] ? &_data[_size] : pointer - 1);
    }
public:
    CBuffer(int size);
    ~CBuffer();

    void pushFront(T newElement);
    void pushBack(T newElement);
    T front();
    T last();
    void popFront();
    void popBack();
    T operator[](const int pos) const;
    void changeCapacity(int newSize);
    typename iterator<random_access_iterator_tag, T>::pointer begin();
    typename iterator<random_access_iterator_tag, T>::pointer end();
    void print();
};