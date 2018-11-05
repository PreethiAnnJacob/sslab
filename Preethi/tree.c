#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[20];
	struct node* next[5];
	int non;
	int type;
};
typedef struct node hi;
hi *root;
hi* search(char path[50],char name[20],int type)
{	
	if(strcmp(path,"/")==0)
	{
		for(int i=0;i<root->non;i++)
		{
			if(strcmp(root->next[i]->name,name)==0&&root->next[i]->type==type){
				printf("\n found at /");
				return root;
			}
		}
		printf("\n not found");
		return NULL;
	}
	char path_split[10][10];
	int j=-1,k=0;
	for(int i=0;i<strlen(path);i++)
	{
		if(path[i]=='/')
		{		
			j++;
			k=0;
			continue;
		}	
		path_split[j][k++]=path[i];
		path_split[j][k]='\0';
	}
	int len_path=j+1;
	hi *cur=root;
	int f=0;
	hi *found=NULL;
	for(int i=0;i<len_path;i++)
	{
		for(int j=0;j<cur->non;j++)
		{
			//printf("\n%s",path_split[i]);
			if(strcmp((cur->next[j])->name,path_split[i])==0&& (cur->next[j])->type==0&&cur->next[j]!=NULL)
			{	f=1;
				found=cur->next[j];
				break;
			}
			else
				f=0;
		}
		if(f==0)
		{		
			printf("\n Invalid path");
			return NULL;
		}
		else
		{	
			cur=found;
		}
	}
	for(int i=0;i<cur->non;i++)
	{
		if(strcmp(cur->next[i]->name,name)==0&& cur->next[i]->type==type)
		{	printf("\n found at %s",path);
			return cur;
		}
	}
	printf("\n not found");
	return NULL;
}

hi* search2(char path[50],char name[20],int type)
{	
	if(strcmp(path,"/")==0)
	{
		for(int i=0;i<root->non;i++)
		{
			if(strcmp(root->next[i]->name,name)==0&&root->next[i]->type==type){
				//printf("\n found at /");
				return root;
			}
		}
		//printf("\n not found");
		return NULL;
	}
	char path_split[10][10];
	int j=-1,k=0;
	for(int i=0;i<strlen(path);i++){
		if(path[i]=='/'){
		
			j++;
			k=0;
			continue;
		}
		path_split[j][k++]=path[i];
		path_split[j][k]='\0';
	}
	int len_path=j+1;		
	hi *cur=root;
	int f=0;
	hi *found;
	for(int i=0;i<len_path;i++){
		for(int j=0;j<cur->non;j++){
			//printf("\n%s",path_split[i]);
			if(strcmp((cur->next[j])->name,path_split[i])==0&& (cur->next[j])->type==0&&cur->next[j]!=NULL){
			
				f=1;
				found=cur->next[j];
				break;
			}
			else
				f=0;
		}
		if(f==0){	
			printf("\n Invalid path");
			return NULL;
		}
		else{	
			cur=found;		
		}
	}
	for(int i=0;i<cur->non;i++){
		if(strcmp(cur->next[i]->name,name)==0&& cur->next[i]->type==type)
		{	//printf("\n found at %s",path);
			return cur;
		}
	}
	//printf("\n not found");
	return NULL;
}

int insert(hi *f,char path[50]){
	int ef,ed;
	if(root->non<4){
	if(f->type==0){
		hi* pos=search2(path,f->name,f->type);
			if(pos!=NULL){
				printf("\n Directory already exists");ed=1;
			}
			else
				{//root->next[((*root).non)++]=f;
				ed=0;
				}
	}
	else{
		hi* pos=search2(path,f->name,f->type);
			if(pos!=NULL){
				printf("\n File already exists");
				ef=1;
			}
			else
				{//root->next[((*root).non)++]=f;
				ef=0;
				}
	}

	if(strcmp(path,"/")==0){
		
		
		if(f->type==0){



			//hi* pos=search2(path,f->name,f->type);
			if(ed==1){
				//printf("\n Directory already exists")
				;
			}
			else
				{root->next[((*root).non)++]=f;
				printf("\n Directory created");}
//
			
			
		}
		else{//hi* pos=search2(path,f->name,f->type);
			if(ef==1){
				//printf("\n File already exists")
				;
			}else{
			root->next[((*root).non)++]=f;
			
			printf("\n File created");}
		}
		return 1;
	}
}
else{
	printf("\n maximum reached");
		return 0;
}
char path_split[10][10];
int j=-1,k=0;
for(int i=0;i<strlen(path);i++){
	if(path[i]=='/'){
		j++;
		k=0;
		continue;
	}
	path_split[j][k++]=path[i];
	path_split[j][k]='\0';
}
int len_path=j+1;
hi *cur=root;
int f1;
hi *found=NULL;
for(int i=0;i<len_path;i++){
	for(int j=0;j<(*cur).non;j++){
		if(strcmp((cur->next[j])->name,path_split[i])==0&& cur->next[j]->type==0&&cur->next[j]!=NULL){
			f1=1;
			found=cur->next[j];
			break;
		}
		else{
			f1=0;}//hhhhhhhhh
	}
	if(f1==0){
		printf("\n Invalid path");
		return 0;
	}
	else{
		cur=found;
	}
}
if(cur->non>=4){
	printf("\n maximum reached");
	return 0;
}
else{
	
	
	if(f->type==0){if(ed==0){
			cur->next[(cur->non)++]=f;
			printf("\n Directory created");}}
			
	else{if(ef==0){cur->next[(cur->non)++]=f;
			printf("\n File created");}}
	return 1;
	}

}


int delete(char path[50],char name[20],int type){
hi* pos=search(path,name,type);
if(pos!=NULL){
	char y;
	printf("\n Are you sure to delete this(y/n)?");
	scanf("%s",&y);
	if(y=='y'){
	int pp=-1;
	for(int i=0;i<pos->non;i++){
		if(strcmp(pos->next[i]->name,name)==0){
			pp=i;
			break;
		}
	}
	for(int j=pos->non-1;j>pp;j--){
		pos->next[j-1]=pos->next[j];
	}
	pos->non--;
	
	printf("\n deleted");}
}
else
	printf("\n not deleted");
}
/*
void rename_(char path[50],char name[20],int type){
hi* pos=search(path,name,type);
char new[20];
if(pos!=NULL){
	int pp=-1;
	for(int i=0;i<pos->non;i++){
		if(strcmp(pos->next[i]->name,name)==0){
			pp=i;
			printf("\n Enter new name:");
			scanf("%s",new);
			hi* pos2=search(path,new,type);
			if(pos2==NULL){
			strcpy(pos->next[i]->name,new);
			printf("\n Rename sucessfull");
			
			}
			else
				{printf("\n The new name already exists!");printf("\n Rename unsucessfull");}
			
			break;
		}
	}
	
	
	
}
else
	printf("\n Rename unsucessfull");
}
	
*/	
void main(){
hi *el;
root=(hi *)malloc(sizeof(hi));
int c=-1,type;
char name[20],path[50];
while(c!=7){
printf("\n 1.create a file 2.create a directory 3. delete a file 4.delete a directory 5.search a file 6. search a directory  7. Exit\nEnter your choice:");
scanf("%d",&c);
if(c==1){
	el=(hi *)malloc(sizeof(hi));
	printf("\n Enter name of file:");
	scanf("%s",el->name);
	el->type=1;
	printf("\n Enter path to insert:");
	scanf("%s",path);
	insert(el,path);
}
else if(c==2){
	el=(hi *)malloc(sizeof(hi));
	printf("\n Enter name of Directory:");
	scanf("%s",el->name);
	el->type=0;
	printf("\n Enter path to insert:");
	scanf("%s",path);
	insert(el,path);
}
else if(c==3){
	printf("\n Enter name of file:");
	scanf("%s",name);
	printf("\n Enter the path of file");
	scanf("%s",path);
	delete(path,name,1);
}
else if(c==4){
	printf("\n Enter name of directory:");
	scanf("%s",name);
	printf("\n Enter the path of directory:");
	scanf("%s",path);
	delete(path,name,0);
}
else if(c==5){
	fflush(stdin);
	printf("\n Enter name of file:");
	scanf("%s",name);
	printf("\n Enter the path of file:");
	scanf("%s",path);
	search(path,name,1);
}
else if(c==6){
	printf("\n Enter name of directory:");
	scanf("%s",name);
	printf("\n Enter the path of directory:");
	scanf("%s",path);
	search(path,name,0);
}
/*else if(c==7){
printf("\n Enter name of the file:");
scanf("%s",name);
printf("\n Enter the path of file:");
scanf("%s",path);
rename_(path,name,1);
}
else if(c==8){
printf("\n Enter name of the Directory:");
scanf("%s",name);
printf("\n Enter the path of directory:");
scanf("%s",path);
rename_(path,name,0);
}*/

}
}


	
	
	

	

	


