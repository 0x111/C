#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int size;
    scanf("%d", &size);
    int *arr=calloc(size+3, sizeof(int));
    for (int i = 0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    int bestscore = 1, nowscore = 1, bestone = arr[0];
    for (int i = 1; i<size; i++) {
        if (arr[i] == arr[i-1]) {
            nowscore++;
        } else {
            nowscore=1;
        }
        if (nowscore > bestscore) {
            bestscore = nowscore;
            bestone=arr[i];
        }
        printf("%d %d %d\n", bestscore, bestone, nowscore);
    }
    printf("%d %d\n", bestone, bestscore);
    return 0;
}
