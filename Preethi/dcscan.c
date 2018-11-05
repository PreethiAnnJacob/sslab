//disk scheduling cscan
#include<stdio.h>
int mod(int x)
{	if(x<0)
		return -1*x;
	else 
		return x;
}
void main()
{	int n,q[100],i,j,temp,index,pos,count,start,end;
	printf("Enter the number of cylinders:");
	scanf("%d",&n);
	printf("Enter disk queue of cylinder no.:\n");
	for(i=0;i<n;i++)	
		scanf("%d",&q[i]);
	printf("Enter initial head position:");
	scanf("%d",&start);
	printf("Enter highest cylinder no:");
	scanf("%d",&end);

	//sort
	for(i=0;i<n;i++)
	{	pos=i;
		for(j=i+1;j<n;j++)
		{	if(q[j]<q[pos])
			{	temp=q[j];	
				q[j]=q[pos];	
				q[pos]=temp;
			}
		}
	}

	printf("Sorted array:\n");
	for(i=0;i<n;i++)
	{	printf("%d \n",q[i]);
	}	

	//find smallest big no
	for(i=0;i<n;i++)
	{	if(q[i]>start)
		{	index=i;
			break;
		}
	}
	
	printf("Starting from %d ",start);
	count=0;//total head movement
	pos=start;
//scan forward
	for(i=index;i<n;i++)
	{	
		printf("%d ",q[i]);
		count=count+mod(q[i]-pos);//printf("count=%d\n",count);
		pos=q[i];
	}

	//go to end
	
	printf("%d ",end);
	count=count+mod(end-pos);//printf("count=%d\n",count);
	pos=end;

	//go to zero
	printf("0 ");
	count=count+mod(0-pos);//printf("count=%d\n",count);
	pos=0;

//scan forward
	for(i=0;i<index;i++)
	{	
		printf("%d ",q[i]);
		count=count+mod(q[i]-pos);//printf("count=%d\n",count);
		pos=q[i];
	}
	printf("\nHead count=%d\n",count);
}
	
	
