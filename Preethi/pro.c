#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int mutex=1, full=0, empty=SIZE, buffer[SIZE];
int in=0, out=0;

int wait(int s){
	while(s<=0)
		;
	return --s;
}

int signal(int s){
	return ++s;
}

int is_full(){
	if(full == SIZE) 
		return 1;
	else 
		return 0;
}

int is_empty(){
	if(empty == SIZE)
		return 1;
	else
		return 0;
}

void producer(int item){
	empty = wait(empty);
	mutex = wait(mutex);
	buffer[in] = item;
	printf("\n%d item is produced\n",item);
	in = (in+1)%SIZE;
	mutex = signal(mutex);
	full = signal(full);
}

void consumer(){
	int item;
	full = wait(full);
	mutex = wait(mutex);
	item = buffer[out];
	printf("\nThe consumed item is %d\n",item);
	out = (out+1)%SIZE;
	mutex = signal(mutex);
	empty = signal(empty);
}
	
void main(){
	int item,ch;
	do{
		printf("\n1.Producer\n2.Consumer\n3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:	if(mutex && !is_full()){
					printf("\nEnter the item to be produced:");
					scanf("%d",&item);
					producer(item);
					//printf("\nF:%d	E:%d\n",full,empty);
				}
				else{
					//printf("\nF:%d	E:%d\n",full,empty);
					printf("\nBuffer is full\nCan not produce\n");
				}
				break;
			case 2: if(mutex && !is_empty()){
					consumer();
					//printf("\nF:%d	E:%d\n",full,empty);
				}
				else{
					//printf("\nF:%d	E:%d\n",full,empty);
					printf("\nBuffer is empty\nCan not consume\n");
				}
				break;
			case 3: exit(0);
				break;
			default: printf("\nInvalid Choice");
		}
	}while(1);
}
		
			
