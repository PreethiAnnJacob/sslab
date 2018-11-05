//round robin
#include <stdio.h>
int rem_bt[100];//remaining burst time
int n;//no of processes

/*Function return 0 if all processes are finished else return 1*/
int notFinished()
{	int i;
	for(i=0;i<n;i++)
		if(rem_bt[i]>0)
			return 1;
	return 0;
}
void main()
{	int i,t;
	int bt[100],wt[100],tt[100],quantum,twt=0,ttt=0;
	float awt,att;
	printf("Enter no of processes:");
	scanf("%d",&n);
	printf("Enter time slice:");
	scanf("%d",&quantum);
	for(i=0;i<n;i++)
	{	printf("Enter burst time for process %d : ",i);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
		rem_bt[i]=bt[i];
	
	i=0;t=0;
	while(notFinished())
	{	if(rem_bt[i]>quantum)
		{	t=t+quantum;
			rem_bt[i]=rem_bt[i]-quantum;
		}
		else if (rem_bt[i]!=0)
		{	t=t+rem_bt[i];
			rem_bt[i]=0;
			wt[i]=t-bt[i];
		}
		i=(i+1)%n;
	}

	for(i=0;i<n;i++)
		tt[i]=wt[i]+bt[i];

	for(i=0;i<n;i++)
	{	ttt=ttt+tt[i];
		twt=twt+wt[i];
	}
	att=1.0*ttt/n;
	awt=1.0*twt/n;
	printf("Average turnaround time=%f\n",att);
	printf("Average waiting time=%f\n",awt);
}
