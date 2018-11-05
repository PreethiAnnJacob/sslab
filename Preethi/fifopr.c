//FIFO Page Replacement
#include <stdio.h>
void main()
{	int str[30],frame[30];
	int size,rsize,pf,ch;
	int index,i,j,found;//count;

	printf("Enter the size of the reference string:");
	scanf("%d",&rsize);
	printf("Enter the reference string : ");
	for(i=0;i<rsize;i++)
		scanf("%d",&str[i]);
	printf("Enter size of page frame:");
	scanf("%d",&size);
	pf=0;//page fault count
	
	//initialize all frames with -1 dummy value
	for(i=0;i<size;i++)
		frame[i]=-1;
	//i=0;
	for(index=0;index<rsize;index++)//Search through reference string using index
	{	ch=str[index];//printf("%d",ch);
		found=0;//count=0;

		//Search through frame for ch		
		//for(j=i;count<=size;count++,j=(j+1)%size)
		for(j=0;j<size;j++)
		{	if(frame[j]==ch)//found
			{	found=1;//continue searching reference string
				break;
			}
		}
		if (found==0)//not found
		{	frame[i]=ch;
			i=(i+1)%size;
			pf=pf+1;
		}
	}
	printf("No of page faults=%d\n",pf);
}
