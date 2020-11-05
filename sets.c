#include<stdio.h>
#include<stdlib.h>
//function to removes duplicate and prints unique sets that satisfies condition a+b+c=0 
int sets(int a[],int n)					
{
	int i,j,k,b[100][3],x=0;
	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
		{
		for(k=j+1;k<n;k++)
			{
			//checks wheather a+b+c=0 and compares the values with previous sets
			if(a[i]+a[j]+a[k]==0 && (b[x-1][0]!=a[i] || b[x-1][1]!=a[j] || b[x-1][2]!=a[k]))
				{
					b[x][0]=a[i];
					b[x][1]=a[j];
					b[x][2]=a[k];
					x++;
				}
			}
		}
	}
	printf("The sets that gives 0 as output:\n");
	for(i=0;i<x;i++)
	{
		printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
	}
}
int main()
{
	int n,j,i,temp;
	printf("enter the length of array:");
	scanf("%d",&n);
	int *a=malloc(sizeof(int)*n);
	printf("enter elements into array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
		{
		if(a[i]>a[j])
			{
			temp=a[i];a[i]=a[j];a[j]=temp;
			}
		}	
	}	
	//calling the function sets by passing th parameters array and no of elements in array
	sets(a,n);				
	//free the memory allocated dynamically to an array 'a' 
	free(a);
	return 0;
}
