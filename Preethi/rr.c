#include<stdio.h>
int notEmpty(int bt[100],int n){
	int check=0,i;	
	for(i=0;i<n;i++){
		if(bt[i]>0){check=1;break;}	
	}
	return check;
}
void main()
{	int n,twt=0,ttt=0,qua;
	float avgtt,avgwt;
	int bt[100],tt[100],wt[100],p[100],wait[100],et[100];
	int i,pindex;

	//input
	printf("Enter number of processes:");
	scanf("%d",&n);
	printf("Enter time quantum:");
	scanf("%d",&qua);
	for(i=0;i<n;i++){
		printf("Enter burst time:");
		scanf("%d",&bt[i]);
	}
	for (i=0;i<n;i++)
		printf("%d\n",bt[i]);
	wt[0]=0;i=0;pindex=-1;
	do
	{	if(bt[i]>0)
		{	pindex++;
			p[pindex]=i;
			if(bt[i]>=qua)			
				wt[pindex+1]=wt[pindex]+qua;
			else
				wt[pindex+1]=wt[pindex]+bt[i];
			bt[i]=bt[i]-qua;
			if(bt[i]<=0)	et[i]=wt[i];
		}
		i++;
		if(i==n) i=0;
	}while(notEmpty(bt,n));
	printf("Chart:\n");
	for(i=0;i<=pindex+1;i++){
		printf("%d	",wt[i]);
	}
	printf("\n");
	for(i=0;i<=pindex;i++){
		printf("%d	",p[i]);
	}
	printf("\n");

	for(i=0;i<pindex;i++){
		wait[i]=0;		
		wait[p[i]]+=wt[i];printf("%d	%d\n",p[i],wait[p[i]]);
		if(i>0 && wt[i]<et[i])	
		{	wait[p[i-1]]-=wt[i];printf("%d	%d\n",p[i-1],wait[p[i-1]]);}
	}
	printf("\n");
	for(i=0;i<=pindex;i++){
		printf("%d	",wait[i]);
	}
	printf("\n");
}
