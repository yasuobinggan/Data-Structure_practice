#include<stdio.h>
#include<stdlib.h>
int g(int value,int v[])
{
	int i=0;
	while(value>0)
	{
		v[i]=value%10;
		value=value/10;
		i++;
	}
	return i;
}
int jie10(int i)
{
	if(i==0)
	return 1;
	if(i>0)
	return 10*jie10(i-1); 
}
int jie9(int i)
{
	if(i==0||i==-1)
	return 1;
	if(i>0)
	return 9*jie9(i-1); 
}
void print(int b[])
{
	int j;
	printf("输出各数字使用频率:\n");
	for(j=0;j<=9;j++)
	printf("%d\t%d\n",j,b[j]);
}
int main()
{
	int value,v[10];
	int i,j,k;
	int d;//获取位数 
	int b[10]={0,0,0,0,0,0,0,0,0,0};
	int sum1=0,sum2=0; 
	printf("输入字典的页数:\n");
	scanf("%d",&value);
	d=g(value,v);
	printf("位数%d\n",d);
	//计数主体 
	//记录头，进行分组 
	for(i=0;i<d;i++)
	{
		for(j=i+1;j<d;j++)
		{
			for(k=0;k<=9;k++)
			{
				if(v[j]==k)
					{
						b[k]+=v[i]*jie10(i);
					}
			}	
		}
	}
	//
	for(i=1;i<d;i++)
	{
		for(k=1;k<=9;k++)
		{
			b[k]+=v[i]*jie9(i-1);
		}
	}
	for(i=1;i<d;i++)
	{
		for(k=1;k<=9;k++)
			if(b[k]<v[i])
			{
				b[k]++;
			}
	}
	//
	//补全带零数的非零位 
	for(i=1;i<d;i++)
	{
		for(k=1;k<=9;k++)
		{
			b[k]+=v[i]*jie9(i-2);
		}
	}
	for(i=1;i<d;i++)
	{
		for(k=1;k<=9;k++)
			if(b[k]<=v[i])
			{
				b[k]++;
			}
	}
	//获取零的个数
/*	for(k=0;k<9;k++)
		sum1+=b[k];//抛去0的数目
	printf("%d\n",sum1);
	for(i=0;i<d-1;i++)
		sum2+=(i+1)*(9*jie10(i));
	sum2+=d*(value-jie10(d-1)+1);//包括零的数目
	b[0]=(sum2-sum1);
*/	 
	print(b);
	return 0;
}