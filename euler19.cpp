#include<iostream>
using namespace std;

int main()
{
    int carry=1,count=0;//starts from monday
    for(int i=1900;i<2001;i++)
    {
        carry+=31;//jan
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        if((i%400==0)||((i%100!=0)&&(i%4==0)))
            carry+=29;//feb,leap year
        else
            carry+=28;//feb,not leap year
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=31;//mar
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=30;//apr
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=31;//may
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=30;//jun
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=31;//jul
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=31;//aug
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=30;//sep
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=31;//oct
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=30;//nov
        if(carry%7==0)
        {
            carry=0;
            if(i!=1900)
                count++;
        }
        carry+=31;//dec
        if(carry%7==0)
        {
            carry=0;
            if((i!=1900)&&(i!=2000))
                count++;
        }
    }
    cout<<count;
    return(0);
}