#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int length;
}SqList;

//希尔排序

void sort(SqList *l)
{
    int i,j;
    int increment = l->length; 

    do{
        //增量 ,没有一种最好的增量序列
        increment = increment / 4 + 1;

        for(i = increment + 1; i <= l->length; i++)
        {
            if (l->data[i] < l->data[i - increment]) {
                l->data[0] = l->data[i];

                for (j = i - increment; j > 0 && l->data[j] > l->data[0]; j -= increment) {
                    l->data[j + increment] = l->data[j];
                }

                l->data[j + increment] = l->data[0];
            }
        
        }
    
    }while(increment > 1);
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
