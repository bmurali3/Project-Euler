#include<iostream>
using namespace std;
#include<math.h>
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
int isprime(int a)
{
    if((a==2)||(a==3))
        return(1);
    if((a<=1)||(a%2==0)||(a%3==0))
        return(0);
    int limit=sqrt(a);
    for(int i=5; i<=limit; i=i+4)
    {
        if(a%i==0)
            return(0);
        i+=2;
        if(a%i==0)
            return(0);
    }
    return(1);
}
int isRTLTrunc(int n)
{
    while(n!=0)
    {
        if(!isprime(n))
            return(0);
        else
            n/=10;
    }
    return(1);
}
int isLTRTrunc(int n)
{
    int digit_length;
    while(n!=0)
    {
        if(!isprime(n))
            return(0);
        else
        {
            digit_length=log10(n);
            n=n%(ipow(10,digit_length));
        }
    }
    return(1);
}
int main()
{
    long x=11,flag=0,count=0,sum=0;
    while(count<11)
    {
        if((isRTLTrunc(x))&&(isLTRTrunc(x)))
        {
            count++;
            cout<<x<<endl;
            sum+=x;
        }
        x+=2;
        if((isRTLTrunc(x))&&(isLTRTrunc(x)))
        {
            count++;
            cout<<x<<endl;
            sum+=x;
        }
        x+=4;
    }
    cout<<endl<<"sum="<<sum;
    return(0);
}
