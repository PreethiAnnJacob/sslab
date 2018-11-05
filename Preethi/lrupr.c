//LRU page replacement
#include <stdio.h>
void main()
{	int str[30],frame[30],time[30];
	int n,length;
	int count=0,f=0,pf=0;
	int min,i,r,j,found,filled=0;

	printf("Enter the size of the reference string:");
	scanf("%d",&length);
	printf("Enter the reference string : ");
	for(i=0;i<length;i++)
		scanf("%d",&str[i]);
	printf("Enter no of frames:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{	frame[i]=-1;
		time[i]=9999+i;
	}

	for(r=0;r<length;r++,count++)
	{	found=0;
		for(j=0;j<n;j++)
		{	if(frame[j]==str[r])//found
			{	found=1;//continue searching reference string
				time[j]=count;
				break;
			}
		}		

		//if page not found
		if(found==0)
		{	if(filled<n)
			{	frame[filled]=str[r];
				filled++;
				pf++;printf("Page fault at index%d\n",r);
			}
			else
			{
				printf("Page fault at index%d\n",r);
				//find least recently used item's index
				min=0;
				for(i=1;i<n;i++)
				{	if(time[min]>time[i])
						min=i;
				}
			
				frame[min]=str[r];
				time[min]=count;
				pf++;
			}
		}	
	}
		printf("No of page faults=%d\n",pf);
}
