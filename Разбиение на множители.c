#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *arr;
void bust(int pos, int now) {
    int temp = (now>arr[pos-1])?arr[pos-1]:now;
    for (int i = temp; i > 0; i--) {
        arr[pos] = i;
        bust(pos+1, now-i);
    }
    if (now < 1){
        for (int i = 1; i < pos; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    
}
int main(int argc, char *argv[])
{
    int size;
    scanf("%d", &size);
    arr = calloc(size+3, sizeof(int));
    memset(arr, 0, sizeof(int)*(size+3));
    arr[0] = 100;
    bust(1, size);
    
    return 0;
}
