#include <stdio.h>


#define MAXSIZE 10
typedef struct{

    int data[MAXSIZE];
    int length;
}SqList;


void temp(SqList *l, int i, int j)
{
    int temp = l->data[i];

    l->data[i] = l->data[j];
    l->data[j] = temp;
}

void BubbleSort(SqList *l)
{
    int i,j;

    for (i = 1; i < l->length; i++)
    {
        for (j = i + 1; j <= l->length; j++) {
            if (l->data[i] > l->data[j]) {
                temp(l, i , j);
            }
        }
    }
}

