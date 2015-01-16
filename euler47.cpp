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

void factor_sum(int num,int& div)
{
    int n=num,count;
    div=0;
    if(num==0)
    {
        div=0;
        return;
    }

    count=1;                //power of 2
    while(n!=1)
    {
        if(n%2==0)
        {
            n/=2;
            count++;
        }
        else
            break;
    }
    if(count>1)
    {
        div++;
    }
    if(n==1)
    {
        return;
    }

    count=1;                   //power of 3
    while(n!=1)
    {
        if(n%3==0)
        {
            n/=3;
            count++;
        }
        else
            break;
    }

    if(count>1)
    {
        div++;
    }
    if(n==1)
    {
        return;
    }

    int i=5;
    while(n!=1)
    {
        if(isprime(i))
        {
            count=1;                   //power of other primes
            while(n!=1)
            {
                if(n%i==0)
                {
                    n/=i;
                    count++;
                }
                else
                    break;
            }
            if(count>1)
            {
                div++;
                if(n==1)
                {
                    return;
                }
                else if(isprime(n))
                {
                    div++;
                    return;
                }
            }
        }
        i+=2;
        if(isprime(i))
        {
            count=1;
            while(n!=1)
            {
                if(n%i==0)
                {
                    n/=i;
                    count++;
                }
                else
                    break;
            }
            if(count>1)
            {
                div++;
                if(n==1)
                {
                    return;
                }
                else if(isprime(n))
                {
                    div++;
                    return;
                }
            }
        }
        i+=4;
    }
    cout<<endl;
}
int main()
{
    int x,buffer[4],div,count=0,save=0,flag=0;
    for(x=100000; x<=1000000; x++)
    {
        factor_sum(x,div);
        cout<<x<<" "<<div<<" ";
        if(div!=4)
        {
            count=0;
            cout<<count<<endl;
            continue;
        }
        if(save==div)
        {
            count++;
            if(count==4)
            {
                flag=1;
                cout<<count<<endl;
                break;
            }
        }
        else
        {
            save=div;
            count=1;
        }
        cout<<count<<endl;
    }
    if(flag==0)
        cout<<"Solution not found";
    else
        cout<<x-3;
    return(0);
}
