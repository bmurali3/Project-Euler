#include<iostream>
using namespace std;
#include<math.h>

long long fact(int n)
{
    long long p=1;
    for(int i=n;i>1;i--)
    {
        p*=i;
    }
    return(p);
}

long ncr(int n,int r)
{
    int nmr=n-r;
    long long p=1;
    for(int i=n;i>nmr;i--)
    {
        p*=i;
    }
    long temp=p/fact(r);
    return(temp);
}

int main()
{
    int x,count=0,i,icount;
    long temp;
    for(x=23;x<=100;x++)
    {
        cout<<x<<":";
        int k=x/2;
        for(i=4;i<=k;i++)
        {
            temp=ncr(x,i);
            cout<<i<<":"<<temp<<",";
            if(temp>999999)
                break;
        }
        if(x%2==0)
        {
            icount=2*(k-i)+1;
            count+=icount;
        }
        else
        {
            icount=2*(k+1-i);
            count+=icount;
        }
        cout<<"   "<<icount<<endl;
    }
    cout<<endl<<"total count:"<<count;
    return(1);
}
