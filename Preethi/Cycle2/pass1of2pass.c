#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char label[50],opcode[50],operand[50],curr_label[50],curr_opcode[50];
int locctr,startaddress,value;
FILE *f1=fopen("Input","r");
FILE *f2=fopen("Symtab","w");
FILE *f3=fopen("Intermediate","w");
FILE *f4=fopen("Optab","r");
/*int search_symtab()
{	//search symtab
	int labelfound=0,labelValue;		
	while(!feof(f2))
	{	fscanf(f2,"%s\t%x",curr_label,&labelValue);
		if(strcmp(curr_label,label)==0)//if label found
		{	printf(label+" is duplicate symbol");
			labelfound=1;
			break;
		}
	}
	return labelfound;
}
int search_optab()
{	int opcodefound=0,opvalue[;		
	while(!feof(f4))
	{	fscanf(f4,"%s\t%x",curr_opcode,&opvalue);
		if(strcmp(curr_opcode,opcode)==0)//if opcode found
		{	printf(label+" is duplicate symbol");
			labelfound=1;
			break;
		}
	}
	return opcodefound;
}*/
void main()
{	/*int labelfound,opcodefound;
	//Read first line
	fscanf(f1,"%s\t%s",label,opcode);
	if(strcmp(opcode,"START")==0)
	{	fscanf(f1,"%x",staraddress);//save operand as start address
		locctr=startaddress;
		fprintf(fp3,"%s\t%s\t%s\t%x\n",locctr,label,opcode,locctr);
		fscanf(f1,"%s\t%s",label,opcode);//read next line
	}
	else 
	{	locctr=0;
		startaddress=0;
		fscanf(f1,"%s\t%s",label,opcode);//read next line
	}
	while(strcmp(opcode,"END")!=0)//while opcode is not end
	{	if(strcmp(label,"")!=0)//if label is present
		{	opcodefound=search_symtab();//search symtab for symbol
			if(opcodefound==0)//label not present in Symtab
				fprintf(f2,"%s\t%x\n",label,locctr);
		}//end if symbol
		opcodefound=search_optab();
		if(opcodefound)
			locctr+=3;//locctr+instrn length
		else if (strcmp(opcode,"WORD")==0)
			locctr+=3;
		else if (strcmp(opcode,"RESW")==0)
		{	fscanf(f1,"%s",operand);
			locctr+=3*atoi(operand);
		}
		else if(strcmp(opcode,"RESB")==0))
		{	fscanf(f1,"%s",operand);
			locctr+=atoi(operand);
		}
		else if (strcmp(opcode,"BYTE")==0)
		{	fscanf(f1,"%s",operand);
			int len=strlen(operand);
			if(operand[0]=='C')
				len=len-1;
			else if (operand[0]=='X')
				len=(len-1)/2;
			else
				printf("Error:Define byte as X or C");
			locctr+=len;
		}
		else
			printf("Error:Invalid opcode");
		
		//Write to intermediate file
		fprintf(fp3,"%s\t%s\t%s\t%x\n",locctr,label,opcode,locctr);
		fscanf(f1,"%s\t%s",label,opcode);//read next line
	}
	fprintf(fp3,"%s\t%s\t%s\t%x\n",locctr,label,opcode,locctr);//write last line to intermediate file
	int program_length=locctr-startaddress;
	printf("program_length=%x\n"+program_length);*/
	fcloseall();
}
