#include<iostream>
using namespace std;
#include<math.h>
int isprime(int a)
{
    if((a%2==0)||(a%3==0))
        return(0);
    int limit=sqrt(a);
    for(int i=5;i<=limit;i=i+4)
    {
        if(a%i==0)
            return(0);
        i+=2;
        if(a%i==0)
            return(0);
    }
    return(1);
}
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
int isCircularPrime(int n)
{
    int flag=0,r;
    int digit_count=log10(n);
    for(int i=0;i<=digit_count;i++)
    {
        if(!isprime(n))
        {
            flag=1;
            return(0);
        }
        else
        {
            r=n%10;
            n/=10;
            n=r*ipow(10,digit_count)+n;
        }
    }
    if(flag==0)
    {
        return(1);
    }
}
int main()
{
    int n=5,count=2;
    while(n<1000000)
    {
        if(isCircularPrime(n))
        {
            cout<<n<<" ";
            count++;
        }
        n+=2;
        if(isCircularPrime(n))
        {
            cout<<n<<" ";
            count++;
        }
        n+=4;
    }
    cout<<endl<<"count="<<count;
    return(0);
}
