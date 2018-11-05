//Single Level Directory Organization
#include <stdio.h>
#include <string.h>
void main()
{	int i,ch,yes=1;
	char f[30];

	struct 
	{	char dname[30];
		char fname[30][30];
		int fcnt;
	}dir;
	
	dir.fcnt=0;

	printf("Enter the directory name:");
	scanf("%s",dir.dname);

	do
	{	printf("\n1.CreateFile 2.Delete File 3.Search File 4.Display Files 5.Exit\nEnter your choice:");
		scanf("%d",&ch);

		if(ch<1 || ch>4)	yes=0;

		switch(ch)
		{	case 1:
				printf("Enter filename:");
				scanf("%s",dir.fname[dir.fcnt]);
				dir.fcnt++;
				printf("File Entered\n");
				break;
			case 2:
				printf("Enter filename:");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{	if(strcmp(f,dir.fname[i])==0)
					{	printf("File %s deleted\n",f);
						strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
						break;
					}
				}
				if(i==dir.fcnt)
					printf("File %s not found\n",f);
				else
					dir.fcnt=dir.fcnt-1;
				break;
			case 3:
				printf("Enter filename:");
				scanf("%s",f);	
				for(i=0;i<dir.fcnt;i++)
				{	if(strcmp(f,dir.fname[i])==0)
					{	printf("File %s found\n",f);
						break;
					}
				}	
				if(i==dir.fcnt)
					printf("File %s not found\n",f);	
				break;
			case 4:
				if(dir.fcnt==0)
					printf("Directory Empty\n");
				else
				{	printf("Files in Directory %s:",dir.dname);
					for (i=0;i<dir.fcnt;i++)
						printf("%s\t",dir.fname[i]);
					printf("\n");		
				}
				break;
		}
	}while(yes==1);
}
