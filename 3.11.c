#include <stdio.h>
#include <stdlib.h>
int vozv(int a, int b, int c, int m);
int main(void)
{
    int i,l,k,a[3],m;
    int temp, max=0;
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&m);
    for (i=0;i<3;i++)
    {
        for (l=0;l<3;l++)
        {
            for (k=0;k<3;k++)
            {
                if (k!=i && l!=i && l!=k)
                {
                    temp=vozv(a[i],a[k],a[l],m);
                    //printf("%ld %d %d %d\n",temp,i,k,l);
                    if (temp>max) max=temp;
                }
            }
        }
    }
    printf("%d", max);
    return 0;
}

int vozv(int a, int b, int c, int m)
{
    int temp,s=1;
    int i;
    for (i=0;i<c;i++)
    {
        s=s*b;
    }
    //temp-степень, a-основание
    temp=s;
    s=1;
    for (i=temp;i>0;i>>=1)
    {
        if (i%2==1) s=s*a%m;
        a=a*a%m;
    }
    return s;
}
