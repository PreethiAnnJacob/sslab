#include<stdio.h>
void main()
{	int n,twt=0,ttt=0;
	float avgtt,avgwt;
	int bt[100],tt[100],wt[100];
	int i;

	//input
	printf("Enter number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter burst time:");
		scanf("%d",&bt[i]);
	}
	/*for (i=0;i<n;i++)
		printf("%d\n",bt[i]);*/
	wt[0]=0;
	for(i=1;i<n;i++)
	{	wt[i]=wt[i-1]+bt[i-1];
	}
	for(i=0;i<n;i++)
	{	tt[i]=wt[i]+bt[i];
	}
	printf("waiting time:\n");
	for(i=0;i<n;i++)
		printf("%d\n",wt[i]);

	printf("turnaround time:\n");
	for(i=0;i<n;i++)
		printf("%d\n",tt[i]);

	for(i=0;i<n;i++)
	{	ttt+=tt[i];
		twt+=wt[i];
	}
	//printf("TTT=%d	twt=%d n=%d\n",ttt,twt,n);
	avgtt=1.0*ttt/n;
	avgwt=1.0*twt/n;
	printf("Average turnaround time:%f\n",avgtt);
	printf("Average waiting time:%f\n",avgwt);
}
/*void main(){
	input();
}*/
