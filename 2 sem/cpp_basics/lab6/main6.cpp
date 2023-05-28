#include <bits/stdc++.h>

using namespace std;

template <typename iterator, typename predicate>
bool my_all_of(iterator first, iterator last,  predicate pred)
{
    for (iterator start = first; start != last; start++)
    {
        if (pred(*start))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}


auto check_real = [](const complex<double> &c){return c.real() > 0;};


template <typename iterator, typename predicate>
bool my_is_sorted(iterator first, iterator last, predicate pred)
{
    if (first == last)
    {
        return true;
    }
    auto prev = first;
    first++;
    for (; first != last; first++, prev++)
    {
        if (pred(*prev, *first))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

auto check_is_sorted_complx = [](const complex<double> &a, const complex<double> &b)
{
    return a.real() > b.real() && a.imag() > b.imag();
};


template <typename iterator, typename predicate>
iterator my_find_backward(iterator first, iterator last, const predicate pred)
{
    for (auto end = last - 1; end != first - 1; --end)
    {
        if (pred(*end))
        {
            return end;
        }
    }
    return last;
}


int main()
{
    vector<int> numbers1 = {7, 8, 9, 10};
    vector<double> numbers2 {2.14, -47.12, 4.45};
    vector<int> numbers3 {1, 2, 3, 4, 5};

    vector<complex<double>> complex1 = { {1,2}, {-3,4}, {5,-6} };
    vector<complex<double>> complex2 {3.14, -2.47, 15.35};
    vector<complex<double>> complex3 {1.78, 3.47, -12.12};


    bool check_all_of = my_all_of(numbers1.begin(),
                                  numbers1.end(),
                                  [](int i){ return i > 5; });
    cout << check_all_of << "\n";

    bool check_if_sorted = my_is_sorted(numbers2.begin(),
                                        numbers2.end(),
                                        [](int i, int j){ return i < j; });
    cout << check_if_sorted << "\n";

    auto check_backward = my_find_backward(numbers3.begin(),
                                           numbers3.end(),
                                           [](int x) { return x == 5; });
    cout << *check_backward << "\n";

    /////////////////////////////////////////////////////////////

    bool check_all_of_complex = my_all_of(complex1.begin(), complex1.end(), check_real);
    cout << check_all_of_complex << "\n";

    bool check_if_sorted_complex = my_is_sorted(complex2.begin(),complex2.end(), check_is_sorted_complx);
    cout << check_if_sorted_complex << "\n";

    auto check_backward_complex = my_find_backward(complex3.begin(),
                                                   complex3.end(),
                                                   [](const complex<double>& x) { return x.real() == -12.12; });
    cout << *check_backward_complex << "\n";
}