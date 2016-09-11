#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
maxi(int a, int b)
{
    return a > b ? a : b;
}

int
mini(int a, int b)
{
    return a < b ? a : b;
}

void
build(int *arr, int *maxmas, int now, int le, int ri)
{
    if (le == ri) {
        maxmas[now] = arr[le];
    } else {
        int m = (le + ri) / 2;
        build(arr, maxmas, now * 2, le, m);
        build(arr, maxmas, now * 2 + 1, m + 1, ri);
        maxmas[now] = maxi(maxmas[now * 2], maxmas[now * 2 + 1]);
    }
    return;
}

void push(int *sum, int now, int *max)
{
    max[now]=maxi(max[now * 2] + sum[now], max[now * 2 + 1] + sum[now]);
    if (sum[now] != 0) {
        sum[now * 2] += sum[now];
        sum[now * 2 + 1] += sum[now];
        sum[now] = 0;
    }
}

int
showmax(int *max, int now, int tle, int tri, int le, int ri, int *sum)
{
    if (le > ri) {
        return 0;
    }
    if (le == tle && ri == tri){
        return max[now]+sum[now];
    }
    int tm = (tle + tri) / 2;
    push(sum, now, max);
    return maxi(showmax(max, now * 2, tle, tm, le, mini(ri, tm), sum),
                showmax(max, now * 2 + 1, tm + 1, tri, maxi(le, tm+1), ri, sum));
}

void //adding sum on the section
update(int *sum, int now, int tl, int tr, int l, int r, int add, int *max)
{
    if (l > r) {
        return;
    }
    if (l == tl && tr == r){
        sum[now] += add;
        return;

    } else {
        push(sum, now, max);
        int tm = (tl + tr) / 2;
        update (sum, now * 2, tl, tm, l, mini(r, tm), add, max);
        update (sum, now * 2 + 1, tm + 1, tr, maxi(l, tm + 1), r, add, max);
    }
    max[now]=maxi(max[now * 2]+sum[now*2], max[now * 2 + 1]+ sum[now*2+1]);
    return;
}


int
main(int argc, char *argv[])
{
    int size;
    scanf("%d", &size);
    int *max = calloc(size * 4 +4, sizeof(int));
    int *change = calloc(size * 4 + 4, sizeof(int));
    int *arr = calloc(size, sizeof(int));
    memset(change, 0, sizeof(int) * (size * 4 + 4));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    build(arr, max, 1, 0, size - 1);
    int req_num;
    scanf("%d", &req_num);
    int left, right, ad;
    char temp;
    for (int i = 0; i < req_num; i++) {
        getchar();
        scanf("%c%d%d", &temp, &left, &right);
        if (temp == 'a') {
            scanf("%d", &ad);
            update(change, 1, 0, size-1, left-1, right-1, ad, max);
        } else if (temp == 'm') {
            printf("%d ", showmax(max, 1, 0, size-1, left-1, right-1, change));
        }
    }

    return 0;
}
