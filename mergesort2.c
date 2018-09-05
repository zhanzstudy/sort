#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int length;
}SqList;

void Merge(int SR[], int TR[], int i, int m,int n)
{
    int j,k,l;
    for(j = m + 1,k = i; i <= m && j <= n; k++)
    {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m)
    {
        for(l = 0; l <= m - i;l++)
        {
            TR[k+l] = SR[i+l];
        }
    }

    if (j <= n)
    {
        for (l = 0;l <= n-j;l++)
        {
            TR[k+l] = SR[j + l];
        }
    }
}


void MergePass(int SR[], int TR[], int s, int n)
{
    int i = 1;
    int j;
    while(i <= n-2 * s + 1)
    {
        Merge(SR,TR,i,i+s-1,i + 2*s-1);
        i=i+2*s;
    }

    if (i < n-s + 1)
        Merge(SR, TR, i, i + s - 1,n);
    else
        for(j = i; j <= n; j++)
            TR[j] = SR[j];
}

void mergesort2(SqList *l)
{
    int *TR = (int *)malloc(l->length * sizeof(int));
    int k = 1;
    while (k < l->length)
    {
        MergePass(l->data,TR,k,l->length);
        k = 2 * k;
        MergePass(TR,l->data,k,l->length);
        k= 2 * k;
    }

}


void main()
{
    SqList l;
    SqList *ll;
    ll = &l;
    ll->length = 4;
    ll->data[1] = 50;
    ll->data[2] = 10;
    ll->data[3] = 90;
    ll->data[4] = 30;
    /*ll->data[5] = 70;*/
    /*ll->data[6] = 40;*/
    /*ll->data[7] = 80;*/
    /*ll->data[8] = 60;*/
    /*ll->data[9] = 20;*/

    mergesort2(ll);
    /*int i;*/
    /*for(i = 0; i <= 3; i++)*/
    /*{*/
        /*printf("%d\n", ll->data[i]);*/
    /*}*/


    int i;
    for (i = 1; i < 5; i++)
    {
        printf("%d\n", ll->data[i]);
    }

}
