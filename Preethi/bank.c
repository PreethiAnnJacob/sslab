//Bankers algorithm
#include<stdio.h>
int m,n,i,j,k,available[100],max[100][100],allocation[100][100],need[100][100];
int work[100],finish[100],countCompleted,FoundIinOneRound,needLessThanWork;

int pno,requestLessThanNeed,request[100],requestLessThanAvailable;
	
/*Safety algorithm*/
void safetyAlgorithm()
{	//count completed processes
		countCompleted=0;

	//need matrix
		for(i=0;i<n;i++)
		{	for(j=0;j<m;j++)
			{	need[i][j]=max[i][j]-allocation[i][j];
			}
		}

	//work=available
		for(i=0;i<m;i++)
			work[i]=available[i];

	//None finished
		for(i=0;i<n;i++)
			finish[i]=0;

		FoundIinOneRound=1;
	//Repeat finding i until no such i exists
		while(countCompleted<n && FoundIinOneRound==1)
		{	FoundIinOneRound=0;

			for(i=0;i<n;i=i+1)//Process index
			{
				//If process not finished and need<=work
				if(finish[i]==0)
				{
					//check if need.i<work
					needLessThanWork=1;
					for(j=0;j<m;j++)//Resource index
					{	if(need[i][j]>work[j])
						{	needLessThanWork=0;
							break;
						}
					}
	
					//need<=Work and not finished...So process completed and return allocated resources 
					if (needLessThanWork==1)
					{	
						//work=work+allocation
						for(k=0;k<m;k++)//Resource index
							work[k]=work[k]+allocation[i][k];

						//Process Pi completed
						finish[i]=1;
						countCompleted++;
						FoundIinOneRound=1;

					}
				}
			}
		}
}

/*Resource Request Algorithm*/
void resourceRequestAlgorithm()
{	//Read request
	printf("Request for which process no:");
	scanf("%d",&pno);

	for(i=0;i<m;i++)
		printf("R%d\t",i);
	printf("\n");
	for(i=0;i<m;i++)
	{	scanf("%d",&request[i]);
		//printf("\t");
	}
	printf("\n");
	
//check if request.pno<need.pno
	requestLessThanNeed=1;
	for(j=0;j<m;j++)//Resource index
	{	if(request[j]>need[pno][j])
		{	requestLessThanNeed=0;
			break;
		}
	}

	if(requestLessThanNeed==1)
	{	
//check if request.pno<available
		requestLessThanAvailable=1;
		for(j=0;j<m;j++)//Resource index
		{	if(request[j]>available[j])
			{	requestLessThanAvailable=0;
				break;
			}
		}	

		if(requestLessThanAvailable==1)//System pretends to have allocated memory
		{	
			//available=available-request
			for(j=0;j<m;j++)			
				available[j]=available[j]-request[j];

			//Allocation=allocation+request
			for(j=0;j<m;j++)
				allocation[pno][j]=allocation[pno][j]+request[j];

			//need.i=need.i-request.i
			for(j=0;j<m;j++)			
				need[pno][j]=need[pno][j]-request[j];

			safetyAlgorithm();

		}
		else //Wait
			printf("Wait since resources are not available.");
	}

	else
		printf("Error: Process Exceeded Maximum Claim");
}

void main()
{	
	printf("How many types of resources? ");
	scanf("%d",&m);
	printf("Enter number of processes:");
	scanf("%d",&n);

//reading available
	printf("Enter the number of available resources of each type:\n");
	for(i=0;i<m;i++)
		printf("R%d\t",i);
	printf("\n");
	for(i=0;i<m;i++)
	{	scanf("%d",&available[i]);
		//printf("\t");
	}
	printf("\n");

//reading max
	printf("Enter the maximum demand of each process:\n");
	for(i=0;i<m;i++)
		printf("\tR%d",i);
	printf("\n");
	for(i=0;i<n;i++)
	{	printf("P%d\t",i);	
		for(j=0;j<m;j++)
		{	scanf("%d",&max[i][j]);
			//printf("\t");
		}
	}
	printf("\n");

//reading allocation
	printf("Enter the resources allocated for each process:\n");
	for(i=0;i<m;i++)
		printf("\tR%d",i);
	printf("\n");
	for(i=0;i<n;i++)
	{	printf("P%d\t",i);	
		for(j=0;j<m;j++)
		{	scanf("%d",&allocation[i][j]);
			//printf("\t");
		}
	}
	printf("\n");

	safetyAlgorithm();
	//Check if all processes Completed   //Declare Safety
	if(countCompleted==n)
		printf("Safe State\n");
	else
		printf("No safe state\n");

	resourceRequestAlgorithm();
	if(countCompleted==n)
		printf("Request granted\n");
	else
		printf("Request not granted\n");
}

