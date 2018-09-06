#include <stdio.h>


#define MAXSIZE 10
typedef struct{

    int data[MAXSIZE];
    int length;
}SqList;
//交换i,j位置
void temp(SqList *l, int i, int j){
    int temp = l->data[i];

    l->data[i] = l->data[j];
    l->data[j] = temp;
}

int Partition(SqList *l, int low, int high)
{   
    int pivotkey;
    pivotkey = l->data[low];

    while (low < high)
    {
        while(low < high && l->data[high] >= pivotkey)
            high--;
        temp(l,low,high);

        while (low < high && l->data[low] <= pivotkey)
            low++;
        temp(l,low, high);
    }
    return low;
}

void QSort(SqList *l, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(l, low, high);

        QSort(l, low, pivot - 1);
        QSort(l, pivot + 1, high);
    }
}

void QuickSort(SqList *l)
{
    QSort(l, 1 , l->length);
}


void main()
{
    //测试

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
   
    QuickSort(ll);

    int i;

    for (i = 1; i <= 6; i++)
    {
        printf("%d\n", ll->data[i]);
    }
}
