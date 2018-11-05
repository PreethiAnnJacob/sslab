//Disk scheduling fcfs
#include<stdio.h>
int mod(int x)
{	if(x<0)
		return -1*x;
	else 
		return x;
}
void main()
{	int n,queue[100],i,pos,count;
	printf("Enter the number of cylinders:");
	scanf("%d",&n);
	printf("Enter disk queue of cylinder no.:\n");
	for(i=0;i<n;i++)	
		scanf("%d",&queue[i]);
	printf("Enter initial head position:");
	scanf("%d",&pos);
	printf("Starting from %d ",pos);
	count=0;//total head movement
	for(i=0;i<n;i++)
	{	printf("%d ",queue[i]);
		count=count+mod(queue[i]-pos);
		pos=queue[i];
	}
	printf("Head count=%d\n",count);
}
