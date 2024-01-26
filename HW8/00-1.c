/*
 * провекрка решения задачи E9 
 * короче это решение к задачи номер E8
*/
 
#include <stdio.h>
 
void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    printf("%d ",arr[i]);;
}
 
void reverseArray(int * array, int num)
{
    for ( int i = 0, j = num - 1; i < j; i++, j--)
    {
    int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}
 
int main()
{
enum {aSize = 12};
int array[aSize] = {0};
    for(int i=0; i < aSize; i++)
        scanf("%d", &array[i]);
    for(int i=0;i<3;i++)
        reverseArray(array +i*aSize/3, aSize/3);
 
    aPrint(array, aSize);
    return 0;
} 

