#include <iostream>
#include <vector>


std::vector<int> left;
std::vector<int> right;
std::vector<int> parent;

int minel = -10000000000;
int maxel = 10000000000;
int pos = 0;
bool tree = true;


void correct(int& i, int& min, int& max)
{
    if (parent[i] >= max || parent[i] <= min)
    {
        tree = false;
    } else {
        if (left[i] != -1)
        {
            if (parent[left[i]] >= parent[i]) 
            {
                tree = false;
            }

            correct(left[i], min, parent[i]);
        }

        if (right[i] != -1)
        {
            if (parent[right[i]] <= parent[i])
            {
                tree = false;
            }

            correct(right[i], parent[i], max);
        }
    }
}


int main()
{
    int n;
    std::cin >> n;

    if (n == 1 || n == 0) 
    {
        std::cout << "YES";
    } else {
        int current;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> current;
            parent.push_back(current - 1);

            std::cin >> current;
            left.push_back(current - 1);

            std::cin >> current;
            right.push_back(current - 1);
        }

        correct(pos, minel, maxel);

        if (!tree)
        {
            std::cout << "NO";
        } else {
            std::cout << "YES";
        }
    }
}