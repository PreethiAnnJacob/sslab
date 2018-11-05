#include<stdio.h>
void main(){
	int n,twt=0,ttt=0;
	float avgtt,avgwt;
	int bt[100];
	int i,small,pos,tt,wt,j,temp;

	//input
	printf("Enter number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter burst time:");
		scanf("%d",&bt[i]);
	}
	for (i=0;i<n;i++)
		printf("%d\n",bt[i]);

	for(i=0;i<n;i++)
	{	small=bt[i];
		pos=i;	
		for(j=i+1;j<n;j++){
			if(small>bt[j])	
			{	pos=j;
				small=bt[j];
			}
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
	}
	printf("Sorted:\n");
	for (i=0;i<n;i++)
		printf("%d\n",bt[i]);
	twt=0;ttt=0;wt=0;
	for(i=0;i<n-1;i++)
	{	wt=wt+bt[i];
		twt=twt+wt;
	}
	wt=0;
	for(i=0;i<n;i++)
	{	wt=wt+bt[i];
		ttt=ttt+wt;
	}
	avgtt=1.0*ttt/n;
	avgwt=1.0*twt/n;
	printf("Average turnaround time:%f\n",avgtt);
	printf("Average waiting time:%f\n",avgwt);

}
