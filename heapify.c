#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int size=0;
void zmien(int *x,int *y)
{
    int temp=*y;
    *y=*x;
    *x=temp;
}
void heapify(int tablica[], int size, int i)
{
    if(size==1)
    {
        printf("Ta tablica posiada tylko jeden element");
    }
    else
    {
    int naj=i;
    int l=(2*i)+1;
    int p=(2*i)+2;
        if (l < size && tablica[l] > tablica[naj])
        {
            naj = l;
        }
        if(p<size && tablica[p] > tablica[naj])
        {
            naj=p;
        }
        if (naj!=i)
        {
            zmien(&tablica[i], &tablica[naj]);
            heapify(tablica,size,naj);
        }
    }
}
void insert(int tablica[], int newValue)
{
    if(size==0)
    {
        tablica[0]=newValue;
        size+=1;
    }
    else
    {
    tablica[size]=newValue;
    size+=1;
       for(int i=(size/2) - 1; i>=0; i--)
       {
           heapify(tablica,size,i);
       }
    }
}
int main()
{
    int tablica[10];
    insert(tablica,3);
    insert(tablica,11);
    insert(tablica,14);
    insert(tablica,22);
    insert(tablica,33);
    insert(tablica,21);
    insert(tablica,6);
    insert(tablica,9);
    insert(tablica,12);
    insert(tablica,5);

    for(int i=0; i<size ;i++)
    {
       printf(tablica[i]+" ");
    }
    return 0;
}
