#include <stdio.h>

#define l 120

int a[l];

int ret_max_sum(int i, int level, int sum)
{
    int sum1, sum2;
    sum += a[i];

    if(level == 15)
    {
        return(sum);
    }
    else
    {
        ++level;
        sum1 = ret_max_sum(i+level-1, level, sum);
        sum2 = ret_max_sum(i+level, level, sum);
        return((sum1 > sum2)?sum1:sum2);
    }
}

int main()
{
    int i = 0;

    FILE *fptr = NULL;
    fptr = fopen("pyramid.txt", "r");

    while(i < l)
    {
        fscanf(fptr, "%d", &(a[i]));
        i++;
    }

    /*i = 0;
    while(i < l)
    {
        printf("%d ", a[i]);
        i++;
    }*/

    printf("\nMax sum is %d\n", ret_max_sum(0, 1, 0));
}
