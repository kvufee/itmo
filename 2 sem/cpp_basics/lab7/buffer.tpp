#include <bits/stdc++.h>

#include "buffer.hpp"

using namespace std;


template<class T>
CBuffer<T>::CBuffer(int size) : _size(size), writeCount(0), firstPosition(0)
{
    _data = new T[_size + 1];
    _first = &_data[0];
    _last = &_data[1];
}


template<class T>
CBuffer<T>::~CBuffer()
{
    _first = nullptr;
    _last = nullptr;
    delete[] _data;
}

template<class T>
void CBuffer<T>::pushFront(T newElement) {
    if (writeCount != 0)
        _first = PointerDecrease(_first, true);
    *_first = newElement;
    if (_first == _last)
        _last = PointerDecrease(_last);
    else
        writeCount++;
}

template<class T>
void CBuffer<T>::pushBack(T newElement)
{
    if (writeCount == 0)
        _last = PointerDecrease(_last);
    *_last = newElement;
    _last = PointerIncrease(_last);
    if (_first == _last)
        _first = PointerIncrease(_first, true);
    else
        writeCount++;
}

template<class T>
T CBuffer<T>::front() {
    if (writeCount == 0)
        throw runtime_error("The buffer is empty");
    return *_first;
}

template<class T>
T CBuffer<T>::last() {
    if (writeCount == 0)
        throw runtime_error("The buffer is empty");
    return *PointerDecrease(_last);
}

template<class T>
void CBuffer<T>::popFront()
{
    if (_first != PointerDecrease(_last))
        _first = PointerIncrease(_first, true);
    writeCount--;
}


template<class T>
void CBuffer<T>::popBack()
{
    if (_first != PointerDecrease(_last))
        _last = PointerDecrease(_last);
    writeCount--;
}

template<class T>
T CBuffer<T>::operator[](const int pos) const {
    if (pos < 0 || pos > _size) {
        throw out_of_range("Out of range");
    } else if (pos > writeCount - 1) {
        writeCount != 0 ? cout << "Maximum index: " << writeCount - 1 : cout << "The buffer is empty\n";
        throw out_of_range("out of range");
    }
    return _data[(firstPosition + pos) % (_size + 1)];
}

template<class T>
void CBuffer<T>::changeCapacity(int newSize)
{
    T *prevData = new T[_size + 1];
    for (int i = 0; _first != _last; _first = PointerIncrease(_first), ++i)
        prevData[i] = *_first;

    _first = nullptr;
    _last = nullptr;
    delete[] _data;
    _data = new T[newSize + 1];
    _first = &_data[0];
    firstPosition = 0;

    if (newSize >= _size) {
        _last = &_data[_size];
    } else {
        if (writeCount > newSize)
            writeCount = newSize;
        _last = &_data[newSize];
    }
    for (int i = 0; i < _size + 1 && i < newSize + 1; ++i) {
        _data[i] = prevData[i];
    }

    _size = newSize;
}

template<class T>
void CBuffer<T>::print()
{
    for (int i = 0; i < _size + 1; i++)
    {
        cout << _data[i] << ' ';
    }
    cout << "\n" << *_first << "\n" << *_last << "\n";
}

template<class T>
typename iterator<random_access_iterator_tag, T>::pointer CBuffer<T>::begin()
{
    return (_data + _first);
}

template<class T>
typename iterator<std::random_access_iterator_tag, T>::pointer CBuffer<T>::end()
{
    return (_data + _size);
}