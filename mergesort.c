

#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int length;
}SqList;
//排序
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
//递归拆分数组，排序
void MSort(int SR[], int TR1[], int s , int t)
{
    int m;


    int TR2[MAXSIZE + 1];
    //递归结束条件
    if (s == t)
    {
        TR1[s] = SR[s];
    }
    else 
    {
        m = (s + t) / 2;
        //递归拆分数组左半部分  
        MSort(SR, TR2, s, m);
        //递归拆分右半部分
        MSort(SR, TR2, m + 1, t);
        //归并
        Merge(TR2, TR1, s, m, t);
  
    } 
}

void MergeSort(SqList *l)
{
    MSort(l->data,l->data,1,4);
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

    MergeSort(ll);


}
