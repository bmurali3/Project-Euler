#include<iostream>
using namespace std;

int main()
{
    int spiral_width=1001,n;
    n=(spiral_width-1)/2;
    cout<<"spiral width="<<spiral_width<<" n="<<n<<endl;
    long long sum=((16*n*n*n+30*n*n+26*n)/3)+1;
    cout<<"sum = "<<sum;
    return(0);
}
