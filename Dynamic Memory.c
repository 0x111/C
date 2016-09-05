#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    unsigned int *a;
    unsigned temp;
    a=(unsigned int *)malloc(sizeof(int)*750000);

    for (i=0;i<75;i++)
    {
        a[i]=i;
    }
    free(a[0]);
    printf("%d",a[0]);
    free(a);

    return 0;
}
