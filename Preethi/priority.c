//Priority scheduling
#include <stdio.h>


void main()
{	int i,j,n,temp1,temp2,pos;
	int bt[100],wt[100],tt[100],p[100],twt=0,ttt=0;
	float awt,att;
	printf("Enter no of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("Enter burst time for process %d : ",i);
		scanf("%d",&bt[i]);
		printf("Enter priority for process %d : ",i);
		scanf("%d",&p[i]);
	}

	for(i=0;i<n;i++)
	{	pos=i;
		for(j=i+1;j<n;j++)
		{	if(p[j]<p[pos])
			{	temp1=p[j];	temp2=bt[j];
				p[j]=p[pos];	bt[j]=bt[pos];
				p[pos]=temp1;	bt[pos]=temp2;
			}
		}
	}
	
	/*printf("Sorted array:\n");
	for(i=0;i<n;i++)
	{	printf("%d %d\n",bt[i],p[i]);
	}
*/
	wt[0]=0;
	for(i=1;i<n;i++)
		wt[i]=wt[i-1]+bt[i-1];
	for(i=0;i<n;i++)
		tt[i]=wt[i]+bt[i];

	printf("wt and tt array:\n");
	for(i=0;i<n;i++)
	{	printf("%d %d\n",wt[i],tt[i]);
	}


	for(i=0;i<n;i++)
	{	ttt=ttt+tt[i];
		twt=twt+wt[i];
	}
	att=1.0*ttt/n;
	awt=1.0*twt/n;
	printf("Average turnaround time=%f\n",att);
	printf("Average waiting time=%f\n",awt);
}
