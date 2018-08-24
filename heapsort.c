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

//堆调整
void heap(SqList *l, int s, int len)
{
    int temp,j;

    temp = l->data[s];

    //安全二叉树如如果有左右孩子 则最左右孩子一定时2i, 2i+1
    for (j = 2 * s; j <= len; j *= 2)
    {
        //比较左右孩子大小
        if (j < len && l->data[j] < l->data[j+1]) {
            ++j;
        }
        //结点已经最大
        if (temp >= l->data[j]) {
            break;
        }
        l->data[s] = l->data[j];
        s = j;
    }
    l->data[s] = temp;
}

void sort(SqList *l)
{
    int i;
    //堆调整就是对有孩子的结点调整 使其比孩子结点大
    for (i = l->length / 2; i > 0; i--) {
        heap(l, i, l->length);
    }

    for (i = l->length; i > 1; i--)
    {
        temp(l, 1, i);

        heap(l, 1, i - 1);
    }
}

void main()
{
    SqList l;
    SqList *ll;
    ll = &l;
    
    
    ll->length = 9;
    ll->data[1] = 50;
    ll->data[2] = 10;
    ll->data[3] = 90;
    ll->data[4] = 30;
    ll->data[5] = 70;
    ll->data[6] = 40;
    ll->data[7] = 80;
    ll->data[8] = 60;
    ll->data[9] = 20;
    
    sort(ll);
    int i;
    for (i = 1; i <= 9; i++) {
        printf("%d\n",ll->data[i]);
    }
}
