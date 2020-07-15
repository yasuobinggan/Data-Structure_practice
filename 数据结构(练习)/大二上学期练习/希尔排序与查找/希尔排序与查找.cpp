#include<stdio.h>
#include<stdlib.h>
#define m 20
#define n 20
typedef struct{
	int *elem;
	int length;
	int listsize;
}sqlist;
void creatsqlist(sqlist &l)
{
	int i;
	l.elem=(int *)malloc(m*sizeof(int));
	if(!l.elem)printf("wrong");
	l.listsize=10;l.length=0;
	printf("shuru shige zhengshu:\n");
	for(i=1;i<=10;i++)
	{
		scanf("%d",&l.elem[i-1]);
		l.length++;
	}
}
void shellsort(sqlist &l,int dk)
{
	int i,j;
	int temp;
	for(i=1;i<=l.length;i++)
	{
		j=i;
		while((j+dk)<=l.length)
		{
		if(l.elem[j-1]>l.elem[j-1+dk])
        {
     		temp=l.elem[j-1];
     		l.elem[j-1]=l.elem[j-1+dk];
     		l.elem[j-1+dk]=temp;
        }
        j=j+dk;
		}
	}
}
int main()
{
	sqlist l;int dk,dk1,dk2;int k;
	creatsqlist(l);
	printf("shuru zhengliang:\n");scanf("%d",&dk);
	shellsort(l,dk);
	for(k=1;k<=l.length;k++)
	printf("%d ",l.elem[k-1]);
	printf("\nshuru zhengliang:\n");scanf("%d",&dk1);
	shellsort(l,dk1);
	for(k=1;k<=l.length;k++)
	printf("%d ",l.elem[k-1]);
	printf("\nshuru zhengliang:\n");scanf("%d",&dk2);
	shellsort(l,dk2);
	for(k=1;k<=l.length;k++)
	printf("%d ",l.elem[k-1]);
	return 0;
}