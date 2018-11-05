//Two Level Directory Organization
#include <stdio.h>
#include <string.h>
void main()
{	int i,k,ch,yes=1,dcnt;
	char f[30],d[30];

	struct 
	{	char dname[30];
		char fname[30][30];
		int fcnt;
	}dir[30];
	
	dcnt=0;

	do
	{	printf("\n1.Create Directory 2.Create File 3.Delete File 4.Search File 5.Display Files 6.Exit\nEnter your choice:");
		scanf("%d",&ch);

		if(ch<1 || ch>5)	yes=0;

		switch(ch)
		{	
			case 1:
				printf("Enter the directory name:");
				scanf("%s",dir[dcnt].dname);
				dir[dcnt].fcnt=0;
				dcnt++;
				printf("Directory created\n");
				break;			
			case 2:
				printf("Enter the directory name:");
				scanf("%s",d);
				for(i=0;i<dcnt;i++)
				{	if(strcmp(d,dir[i].dname)==0)
					{	printf("Enter filename:");
						scanf("%s",dir[i].fname[dir[i].fcnt]);
						dir[i].fcnt++;
						printf("File Created\n");
						break;
					}				
				}
				if(i==dcnt)
					printf("Directory not Found\n");
				break;
			case 3:
				printf("Enter the directory name:");
				scanf("%s",d);				
				for(i=0;i<dcnt;i++)
				{	if(strcmp(d,dir[i].dname)==0)
					{	printf("Enter filename:");
						scanf("%s",f);
						for(k=0;k<dir[i].fcnt;k++)
						{	if(strcmp(f,dir[i].fname[k])==0)
							{	printf("File Deleted\n");
								dir[i].fcnt--;
								strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
								goto label;
							}
						}
					}
				}
				printf("Directory not found\n");
				label: break;
			case 4:
				printf("Enter the directory name:");
				scanf("%s",d);	
				for(i=0;i<dcnt;i++)
				{	if(strcmp(d,dir[i].dname)==0)
					{	printf("Enter filename:");
						scanf("%s",f);
						for(k=0;k<dir[i].fcnt;k++)
						{	if(strcmp(f,dir[i].fname[k])==0)
							{	printf("File Found\n");
								goto label1;
							}
						}
					}
				}
				printf("File not found\n");
				label1: break;
			case 5:
				if(dcnt==0)
					printf("No directories\n");
				else
				{	printf("\nDirectory\t: Files\n");
					for (i=0;i<dcnt;i++)
					{	printf("%s\t: ",dir[i].dname);
						for(k=0;k<dir[i].fcnt;k++)
							printf("%s\t",dir[i].fname[k]);
						printf("\n");
					}	
				}
				break;
		}
	}while(yes==1);
}
