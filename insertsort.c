
#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int length;
}SqList;

void temp(SqList *l, int i, int j)
{
    int temp;
    temp = l->data[i];
    l->data[i] = l->data[j];
    l->data[j] = temp;
}

void sort(SqList *l)
{
    int i,j;
    
    for (i = 2;i <= l->length; i++)
    {
        if (l->data[i] < l->data[i - 1])  {
            l->data[0] = l->data[i];
            for (j = i - 1; l->data[j] > l->data[0]; j--)
            {
                l->data[j+1] = l->data[j];
            }

            l->data[j + 1] =l->data[0];
        }
    }
}

void main()
{
    SqList l;
    SqList *ll;
    ll = &l;

    ll->length = 6;
    ll->data[1] = 6;
    ll->data[2] = 2;
    ll->data[3] = 5;
    ll->data[4] = 4;
    ll->data[5] = 3;
    ll->data[6] = 1;
    
    sort(ll);
    int i;
    for (i = 1; i <= 6; i++) {
        printf("%d\n",ll->data[i]);
    }


}
