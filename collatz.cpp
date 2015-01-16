#include<iostream>
using namespace std;
#include<conio.h>
int main()
{
    static int set[1000001];
    int k=1,maxk;
    long long temp,count,max=0;
    set[1]=1;
    while(k<1000000)
    {
        k++;
        if(set[k]==1)
            continue;
        else
        {
            set[k]=1;
            count=1;
            temp=k;
            while(temp!=1)
            {
                if(temp%2==0)
                {
                    temp/=2;
                    if(temp<=1000000)
                        set[temp]=1;
                }
                else
                {
                    temp=3*temp+1;
                    if(temp<=1000000)
                        set[temp]=1;
                }
                count++;
            }
            if(count>max)
            {
                max=count;
                maxk=k;
            }
        }
    }
    cout<<"number:"<<maxk<<",terms:"<<max;
    return(0);
}
