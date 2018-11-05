#include <stdio.h>
#include <string.h>
char line[100];
char label[100],opcode[100],operand[100];
char locctr[100]="000000";
int pos=0;
char symbol[100];int symbolvalue;
char op[100];int opvalue;
void readLineFromFile()//read from source code file
{   strcpy(line,"");
    File fp=fopen("intermediate.txt","r");
    if(!feof(fp))
    {
        fseek(fp, pos , SEEK_CUR);
        fgets(line, sizeof(line), fp);
        pos = ftell(fp);
    }
    fp.close();
}
void breakline()
{   char word[100];int wp=0;int fieldno=0;int i;
    strcpy(word,"");strcpy(label,"");strcpy(opcode,"");strcpy(operand,"");
    for(i=0;i<strlen(line);i++)
    {   if(line[i]!='\t' && line[i]!='\n')
        {   //printf("\t at %d\n",i);
            word[wp++]=line[i];
        }
        else
        {   if(fieldno==0 && line[i]!=' ' )
            {   word[wp]='\0';
                locctr=atoi(word);
                fieldno++;
                strcpy(word,"");
                wp=0;
            }
            else if(fieldno==1&& line[i]!=' ')
            {   word[wp]='\0';
                strcpy(label,word);
                fieldno++;
                strcpy(word,"");
                wp=0;
            }
            else if(fieldno==2&& line[i]!=' ')
            {   word[wp]='\0';
                strcpy(opcode,word);
                fieldno++;
                strcpy(word,"");
                wp=0;
            }
        }
    }
    word[wp]='\0';
    if(fieldno==0)
    {
            locctr=atoi(word);
    }
    else if(fieldno==1)
     {
        strcpy(label,word);
     }
    else if(fieldno==2)
     {
        strcpy(opcode,word);
     }
    else
        strcpy(operand,word);
}
int searchSymtab()
{   int found=0;
    FILE *fp5=fopen("symtab.txt","r");
    strcpy(symbol,"");symbolvalue=0;
    while(!feof(fp5))
    {   fscanf(fp5,"%s%d",symbol,&symbolvalue);
        if(strcmp(symbol,label)==0)
        {
            found=1;break;
        }
    }
    fclose(fp5);
    return found;
}
int searchOptab()
{   int found=0;FILE *fp5=fopen("optab.txt","r");
    strcpy(op,"");opvalue=0;
    while(!feof(fp5))
    {   fscanf(fp5,"%s%d",op,&opvalue);
        if(strcmp(op,opcode)==0)
        {
            found=1;break;
        }
    }
    fclose(fp5);
    return found;
}
int main()
{   char progname[100],objname[100],blank1[100],blank2[100],blank3[100],startaddress[100],length[100];char constant[100];
    FILE *fp;
    int i;int col=0;
    fp=fopen("intermediate.txt","r");
    if(fp==NULL)//if intermediate file doe not exist
    {   printf("Intermediate file for pass 2 not found");
        fclose(fp);
    }
    else//intermediate file present
    {   fclose(fp);
        fp=fopen("symtab.txt","r");
        if(fp==NULL)//if symtab after 1st pass not present
        {   printf("Symtab not present");
            fclose(fp);
        }
        else//sytab also present
        {   fclose(fp);
            fp=fopen("details.txt","r");
            fscanf(fp,"%s%s%s",progname,startaddress,length);//read programname,start address, length of the object program
            strcpy(objname,progname);
            strcat(objname,".obj");
            fp=fopen(objname,"w");
            fclose(fp);//to clear the object file
            readLineFromFile();
            breakline();
            if(strcmp(opcode,'START')==0)
            {  //read next line
                fp=fopen("intermediate.txt","r");
                if(!feof(fp))
                {   readLineFromFile();
                    breakline();
                    printf("line=%s\n",line);
                    printf("locctr=%x label=%s opcode=%s operand=%s \n ",label,opcode,operand,rest);
                }
                fp.close();
            }//end if start

            /*write header record to object program col1=H col2-7=progname col8-13=start address in hexadecimal col14-19 length of object program in bytes(hexadecimal)*/
            strcpy(blank1,"");
            for(i=0;i<(6-strlen(progname));i++)//col2-7=6 columns.So fill rest with spaces
                strcat(blank1," ");
            strcpy(blank2,"");
            for(i=0;i<(6-strlen(startaddress));i++)//col8-13=6 columns.So fill rest with spaces
                strcat(blank2," ");
            strcpy(blank3,"");
            for(i=0;i<(6-strlen(length));i++)//col14-19=6 columns.So fill rest with spaces
                strcat(blank3," ");
            fp2=fopen(objname,"a");
            fprintf(fp2,"H%s%s%s%s%s%s\n",progname,blank1,startaddress,blank2,length,blank3);//Header record
            fprintf(fp2,"T");//initialize first text record
            col=0;strcpy(code,"");//initially temporarily collects object code

            while(strcmp(opcode,"END")==0)
            {   if(line[0]!='.')//if not a comment line
                {   if(searchOptab()==1)//if found in optab
                    {   if(strcmp(operand,"")!=0)//if there is a symbol in operand field
                        {   if(searchSymtab()==1)//if found in symtab
                            {   strcpy(operand,symbolvalue);//store symbol value as operand address
                            }
                            else//if not found in symtab
                            {   strcpy(operand,0);//store 0 as operand address
                                printf("Error:%s not found in symtab\n",symbol);
                            }
                        }//end if symbol in operand field
					else //if symbol not found in operand field
						strcpy(operand,0);//store 0 as operand address	

                        /*assemble the object code instruction*/
					
					if(col==0)//for first text record, write start address
                   		{	
				         //fill blanks for startaddress
				         strcpy(blank1,"");
				         for(i=0;i<(6-strlen(locctr));i++)//6 columns for address.So fill rest with spaces
				             strcat(blank1," ");
				         strcat(locctr,blank1);

						fprintf(fp2,"%s",locctr);	//write starting address to text record	
					}
						
					//fill blanks for symbolvalue
	                   strcpy(blank1,"");
	                   for(i=0;i<(6-strlen(symbolValue));i++)//6 columns for address.So fill rest with spaces
	                       strcat(blank1," ");
	                   strcat(symbolvalue,blank1);

					//calculate object code for one instrn in calc
	                   strcpy(calc,"");
	                   strcat(calc,opvalue);
	                   strcat(calc,symbolvalue);
					if(strlen(code)+strlen(calc)>60)
					{	strcat(code,calc);//ultimate code of one text record
						col+=strlen(calc);
					}
					else
					{	if(col<9)
							fprintf(fp2,"0%x%s\nT",col,code);
						col=0;strcpy(code,calc);
					}
						
                        	fprintf(fp2,"%s",locctr);


                    }//end if found in optab
				else if(strcmp(opcode,"BYTE")==0 || strcmp(opcode,"WORD")==0)
				{	//convert constant to object code
				}
				
				//write text record to object program				
				fprintf(fp2,"\nT");
                }//end if not comment
			
			
			//read next line from intermediate file
			if(!feof(fp))
			 {   readLineFromFile();
			     breakline();
			     printf("line=%s\n",line);
			     printf("locctr=%x label=%s opcode=%s operand=%s\n",label,opcode,operand,rest);
			 }

            }//if not END
        }//end symtab present
    }//end intermediate file present

    return 0;
}
