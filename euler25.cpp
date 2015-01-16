#include<iostream>
using namespace std;
#include<math.h>

int main()
{
    long long m=1,n=1,temp,check;
    while(1)
    {
        temp=m+n;
        m=n;
        n=temp;
        check=log10(n);
        cout<<n<<" "<<check<<endl;
        if(check==99)
        {
            cout<<n;
            break;
        }
    }
    return(0);
}
