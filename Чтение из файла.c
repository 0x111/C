#include <stdio.h>


int main(void){
    FILE *opened=fopen("input.txt","r");
    int n,m,sd;
    fscanf(opened,"%d %d",&n,&m);
    for (int i=0;i<m;i++)
        fscanf(opened,"%d",&sd);
    fclose(opened);
    opened=fopen("output.txt","w");
    for (int i=sd;i<=n;i++)
        fprintf(opened,"%d ",i);
    for (int i=1;i<sd;i++)
        fprintf(opened,"%d ",i);
    fclose(opened);
    return 0;
}
