#include <stdio.h>

#define arr_len 5050
#define total_levels 100

int a[arr_len];

int main()
{
    int i = 0, j, j_init, j_final;

    FILE *fptr = NULL;
    fptr = fopen("triangle.txt", "r");

    while(i < arr_len)
    {
        fscanf(fptr, "%d", &(a[i]));
        i++;
    }

    for(i = total_levels;i > 1; i--)
    {
        printf("level: %d\n", i);
        j_init = (i-1)*i/2;
        j_final = (i+1)*i/2 - 1;
        for(j = j_init; j < j_final; j++)
        {
            a[j - i + 1] += ( (a[j] > a[j+1]) ? a[j]:a[j+1]);
        }
    }

    printf("\nMax sum is %d\n", a[0]);
}
