#include <stdio.h>
#include <malloc.h>
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

//直接插入排序
void insertsort(SqList *l)
{
    int i,j;

    for (i = 2; i <= l->length; i++)
    {
        if(l->data[i] < l->data[i - 1])
        {
            l->data[0] = l->data[i];

            for (j = i - 1; l->data[0] < l->data[j]; j--)
            {
                l->data[j + 1] = l->data[j];
            }

            l->data[j + 1] = l->data[0];
        }
    }
}


int piviotion(SqList *l, int low, int high)
{
    int mid,piviokey;
    mid = (low + high) / 2;

    if (l->data[low] > l->data[high])
    {
        temp(l, low, high);
    }

    if (l->data[mid] > l->data[high])
    {
        temp(l, mid , high);
    }

    if (l->data[low] < l->data[mid])
    {
        temp(l, low, mid);
    }

    piviokey = l->data[low];

    while (low < high)
    {
        while(low < high && l->data[high] > piviokey)
        {
            high--;
        }

        l->data[low] = l->data[high];

        while (low < high && l->data[low] < piviokey)
        {
            low++;
        }

        l->data[high] = l->data[low];

    }

    l->data[low] = piviokey;

    return low;

    
}


void quicksort(SqList *l, int low, int high)
{

    int pivio;

    if (high > 4)
    {

        while (low < high)
        {
            pivio = piviotion(l, low, high);

            quicksort(l, low, pivio - 1);
            low = pivio + 1;

        }
         
    }else {
    
        insertsort(l);
    }

}




void main()
{
    SqList l;
    SqList *ll;

    ll = &l;

    ll->length = 9;
    ll->data[1] = 2;
    ll->data[2] = 1;
    ll->data[3] = 8;
    ll->data[4] = 6;
    ll->data[5] = 7;
    ll->data[6] = 5;
    ll->data[7] = 3;
    ll->data[8] = 4;
    ll->data[9] = 9;

    
    quicksort(ll, 1, 9);

    int i;
    for (i = 1; i <= 9; i++)
    {
    
        printf("%d\n", ll->data[i]);
    }





}














