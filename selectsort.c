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

//简单选择排序
void sort(SqList *l)
{
    int i,j,min;

    for (i = 1; i <= l->length; i++) {
        min = i;
        for (j = i + 1; j <= l->length; j++) {
            if (l->data[min] > l->data[j]) {
                min =j;
            }
        }
        
        temp(l, i, min);

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
