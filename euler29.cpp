#include<iostream>
using namespace std;

int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

int main()
{
    int i,j,a[1000];
    cout<<ipow(2,3)<<" "<<ipow(7,2)<<" "<<ipow(11,2);
}
