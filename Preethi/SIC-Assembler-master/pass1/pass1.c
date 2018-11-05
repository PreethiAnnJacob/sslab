//Implement a two pass SIC assembler
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

char src[100],label[100],opcode[100],operand[100],line[100],rest[100];
FILE *fp1,*fp2,*fp3,*fp4;
int i,op;
long pos=0;
int power(int num,int count)
{	int j;int pow=1;
	for(j=1;j<=count;j++)
		pow=pow*num;
	return pow;
}
int hexadecimal_to_decimal(int x)
{
      int decimal_number, remainder, count = 0;
      while(x > 0)
      {
            remainder = x % 10;
            decimal_number = decimal_number + remainder * power(16, count);
            x = x / 10;
            count++;
      }
      return decimal_number;
}
void readLineFromFile()//read from source code file
{   strcpy(line,"");
    fp1=fopen("src.txt","r");
    if(!feof(fp1))
    {
        fseek(fp1 , pos , SEEK_CUR);
        fgets(line, sizeof(line), fp1);
        pos = ftell(fp1);
    }
}
void breakline()
{   char word[100];int wp=0;int fieldno=0;
    strcpy(word,"");strcpy(label,"");strcpy(opcode,"");strcpy(operand,"");strcpy(rest,"");
    for(i=0;i<strlen(line);i++)
    {   if(line[i]!='\t' && line[i]!='\n')
        {   //printf("\t at %d\n",i);
			if(fieldno<3 && line[i]==' ')
				;
			else
            		word[wp++]=line[i];
        }
        else
        {   if(fieldno==0 && line[i]!=' ' )
            {   word[wp]='\0';
                strcpy(label,word);
                fieldno++;
                strcpy(word,"");
                wp=0;
            }
            else if(fieldno==1&& line[i]!=' ')
            {   word[wp]='\0';
                strcpy(opcode,word);
                fieldno++;
                strcpy(word,"");
                wp=0;
            }
            else if(fieldno==2&& line[i]!=' ')
            {   word[wp]='\0';
                strcpy(operand,word);
                fieldno++;
                strcpy(word,"");
                wp=0;
            }
        }
    }
    word[wp]='\0';
    if(fieldno==0)
    {
            strcpy(label,word);
    }
    else if(fieldno==1)
     {
        strcpy(opcode,word);
     }
    else if(fieldno==2)
     {
        strcpy(operand,word);
     }
    else
        strcpy(rest,word);
}
int searchSymtab()
{   int found=0;//printf("symtab ethi thappunnu\n");
	FILE *fp5=fopen("symtab.txt","r");
    char symbol[100];int value;//printf("symtab thurannu");
    while(!feof(fp5))
    {   fscanf(fp5,"%s%d",symbol,&value);
        if(strcmp(symbol,label)==0)
        {   //printf("same aaa\n");
            found=1;break;
        }
    }
    fclose(fp5);
    return found;
}
int searchOptab()
{   int found=0;FILE *fp5=fopen("optab.txt","r");
    char symbol[100];int value;
    while(!feof(fp5))
    {   fscanf(fp5,"%s%d",symbol,&value);
        if(strcmp(symbol,opcode)==0)
        {   //printf("same aaa\n");
            found=1;break;
        }
    }
    fclose(fp5);
    return found;
}
/*
int main()
{   fp1=fopen("src.txt","r");
    while(!feof(fp1))
    {   readLineFromFile();
        breakline();
        printf("line=%s\n",line);
        printf("label=%s opcode=%s operand=%s rest=%s\n",label,opcode,operand,rest);
    }
    return 0;
}
*/
int main()
{
    int startaddress,locctr;
    char progname[10];
    int proglength;
    fp1=fopen("src.txt","r");//Open source code file in read mode
    fp2=fopen("optab.txt","r");
    fp3=fopen("intermediate.txt","w");//open intermediate file
    fp4=fopen("symtab.txt","w");
    fclose(fp2);fclose(fp3);fclose(fp4);
    if(fp1==NULL)
    {   printf("Source code not found\n");
        fclose(fp1);
    }
    else
    {   fclose(fp1);
        fp2=fopen("optab.txt","r");//Open optab
        if(fp2==NULL)
        {   printf("OPTAB not found");
            fclose(fp2);
        }
        else
        {   fclose(fp2);
            //read first line
            if(!feof(fp1))
            {   readLineFromFile();
                breakline();
                //printf("line=%s\n",line);
                //printf("label=%s opcode=%s operand=%s rest=%s\n",label,opcode,operand,rest);
            }
            if(strcmp(opcode,"START")==0)
            {   startaddress=hexadecimal_to_decimal(atoi(operand));
                locctr=startaddress;
                strcpy(progname,label);
                fp3=fopen("intermediate.txt","a");//open intermediate file
                fprintf(fp3,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);//write to intermediate file
                //printf("%x\t%s\t%s\t%s into intermediate\n",locctr,label,opcode,operand);
                fclose(fp3);
                strcpy(progname,label);//store program name

                //read next file
                if(!feof(fp1))
                {   readLineFromFile();
                    breakline();
                    //printf("line=%s\n",line);
                    //printf("label=%s opcode=%s operand=%s rest=%s\n",label,opcode,operand,rest);
                }
            }
            else
            {   locctr=0;
                startaddress=0;
                strcpy(progname,"");
            }
            while(strcmp(opcode,"END")!=0)
            {   if(label[0]!='.')//if not comment
                {   //printf("not comment\n");
                    if(strcmp(label,"")!=0)//if label not null
                    {   //printf("label present\n");
                        if(searchSymtab()==1)//if found in symtab
                        {
                            printf("Error:Found in Symtab\n");
                        }
                        else
                        {   //printf("Not found in symtab\n");
                            fp4=fopen("symtab.txt","a");
                            fprintf(fp4,"%s\t%x\n",label,locctr);//insert into symtab
                            fclose(fp4);
                           // printf("%s\t%x into symtab\n",label,locctr);
                        }
                    }
                    fp3=fopen("intermediate.txt","a");//open intermediate file
                    fprintf(fp3,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);//write to intermediate file
                    //printf("%x\t%s\t%s\t%s into intermediate\n",locctr,label,opcode,operand);
                    fclose(fp3);
                    if(searchOptab()==1)//found
                        locctr+=3;
                    else if(strcmp(opcode,"WORD")==0)
                        locctr+=3;
                    else if(strcmp(opcode,"RESW")==0)
                        locctr=locctr+atoi(operand)*3;
                    else if(strcmp(opcode,"RESB")==0)
                        locctr=locctr+atoi(operand);
                    else if(strcmp(opcode,"BYTE")==0)
                    {   if(operand[0]=='C')
                        {	locctr+=strlen(operand)-4;
					}
                        else if(operand[0]=='X')
                        {	locctr+=(strlen(operand)-3)/2;
					}
                    }
                    else
                        printf("Error:BYTE with invalid operand");
                   // printf("Changed locctr=%d\n",locctr);
                }
                else//if comment
                {   fp3=fopen("intermediate.txt","a");//open intermediate file
                    fprintf(fp3,"%x\t%s\t%s\t%s\t%s\n",locctr,label,opcode,operand,rest);//write to intermediate file
                    //printf("%x\t%s\t%s\t%s\t%s into intermediate\n",locctr,label,opcode,operand,rest);
                    fclose(fp3);
                }
                //read next line
               if(!feof(fp1))
                {   readLineFromFile();
                    breakline();
                    //printf("line=%s\n",line);
                    //printf("label=%s opcode=%s operand=%s rest=%s\n",label,opcode,operand,rest);
                }
            }
            //writing last end record to intermediate file
            fp3=fopen("intermediate.txt","a");//open intermediate file
            fprintf(fp3,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);//write to intermediate file
            //printf("%x\t%s\t%s\t%s into intermediate \n",locctr,label,opcode,operand);//write to intermediate file
            fclose(fp3);
        }
    }
    proglength=locctr-startaddress;
    printf("Intermediate file,Symtab and Details created. Program Name=%s and Program length=%x\n",progname,proglength);
    fp3=fopen("Details.txt","w");
    fprintf(fp3,"%s\n%x\n%x",progname,startaddress,proglength);
    fflush(stdin);
    fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);
    return 0;
}
