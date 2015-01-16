#include<iostream>
using namespace std;
#include<conio.h>
#include<math.h>
int power(int a,int b)
{
    int res=1;
    for(int i=1;i<=b;i++)
    {
        res*=a;
    }
    return res;
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

void factor_sum(int num,int& div,int& sum)
{
    int n=num,count;
    sum=1;
    div=1;
    if(num==0)
    {
        sum=0;
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
        div*=count;
        sum*=(pow(2,count)-1);
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
        div*=count;
        sum*=(pow(3,count)-1)/2;
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
                div*=count;
                int temp=(power(i,count)-1)/(i-1);
                sum*=temp;
                if(n==1)
                {
                    return;
                }
                else if(isprime(n))
                {
                    div*=2;
                    sum*=(n+1);
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
                div*=count;
                int temp=(power(i,count)-1)/(i-1);
                sum*=temp;
                if(n==1)
                {
                    return;
                }
                else if(isprime(n))
                {
                    div*=2;
                    sum*=(n+1);
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
    int div,sum_x,sum_y,count,x,y,sum_total=0;
    for(x=1; x<=10000; x++)
    {
        factor_sum(x,div,sum_x);
        y=sum_x-x;
        factor_sum(y,div,sum_y);
        if((sum_x==sum_y)&&(x!=y))
        {
            cout<<"("<<x<<","<<y<<")"<<endl;
            sum_total+=sum_x;
        }
    }
    cout<<endl<<sum_total<<","<<sum_total/2;
    return(0);
}
