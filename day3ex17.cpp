#include<stdio.h>
int main()
{
	int n,i,j,r,k,al[3][3],m[3][3],nd[3][3],ava[3],op[3],cop[3],copm=0;
	printf("enter the no of processes:");
	scanf("%d",&n);
	printf("enter the no of resources:");
	scanf("%d",&r);
	for(i=0;i<n;i++)
	{
		cop[i]=0;
	}
	printf("\n \n --------allocation of resource------- ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("\n enter the allocation of resource %d %d:",i,j);
			scanf("%d",&al[i][j]);
		}
	}
	
	printf("\n \n --------max of resource------- ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("\n enter the max of resource %d %d:",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			nd[i][j]=m[i][j]-al[i][j];
		}
	}
	
	for(i=0;i<r;i++)
	{
		printf("\n enter the avaliable resource %d:",i);
		scanf("%d",&ava[i]);
	}
		
	while(copm<n)
	{
		j=0;
		for(i=0;i<n;i++)
	    {
	    	if(cop[i]!=1 && nd[i][j]<=ava[j] && nd[i][j+1]<=ava[j+1] && nd[i][j+2]<=ava[j+2])
	    	{
	    		ava[0]=al[i][0]+ava[0];
	    		ava[1]=al[i][1]+ava[1];
	    		ava[2]=al[i][2]+ava[2];
	    		copm++;
	    		cop[i]=1;
	    		op[k++]=i;
			}
		}
	}
	
	for(i=0;i<r;i++)
	{
		printf("\n the resource %d is %d :",i,ava[i]);
	}
	printf("\n the order of process is:");
	for(i=0;i<n;i++)
	{
		printf("\t ->%d",op[i]);
		
	}

}
