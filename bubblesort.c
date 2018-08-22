#include <stdio.h>


#define MAXSIZE 10
typedef struct{

    int data[MAXSIZE];
    int length;
}SqList;

//交换i,j位置
void temp(SqList *l, int i, int j)
{
    int temp = l->data[i];

    l->data[i] = l->data[j];
    l->data[j] = temp;
}
//冒泡排序
void BubbleSort(SqList *l)
{
    int i,j;

    for (i = 1; i < l->length; i++)
    {
        //依次比较相邻两位，根据大小调换位置
        for (j = i + 1; j <= l->length; j++) {
            if (l->data[i] > l->data[j]) {
                temp(l, i , j);
             }
         }
    } 
}

//改进冒泡排序，从数组最后一位开始
void BubblerSort1(SqList *l)
{
    int i,j,flag;
    //标识，如果没有在交换，不需要在循环比较了
    flag = 1;
    for (i = 1; i <= l->length && flag;i++)
    {
        flag = 0;
        //从最后开始，依次比较两位，改变顺序
        for(j = l->length - 1; j >= i; j--) {

            if (l->data[j] > l->data[j+1]) {
                flag = 1;
                temp(l, j, j+1);
            }
        }
    }


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
    /*int i;*/
    /*for (i = 1; i <= 6; i++) {*/
        /*ll->data[i] = i;*/
    /*}*/

    //冒泡排序
    /*BubbleSort(ll);*/
    BubblerSort1(ll);

    int i;
    for (i = 1; i <= 6; i++) {
        printf("%d\n",ll->data[i]);
    }
    
}
