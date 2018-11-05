#include<stdio.h>
int len,n,r=0,f=0,pf=0,page[10];

void display(int frame[]){
	for(int i=0; i<n; i++){
		printf("%d	",frame[i]);
	}
	printf("\n");
}

int min_frequency(int time[], int frame[], int count){
	int pos=0, frq=page[frame[0]];
	for(int i=1; i<n; i++){
		 if(time[i] < time[pos] && frq < page[frame[i]]){ 
			pos = i;
			frq = page[i];
		}
	}
	return pos;
}

int page_found(int frame[], int page){
	for(int j=0; j<n; j++){
		if(page == frame[j]){
			return j;
		}
	}
	return -1;
}

void lfu(int ref[], int frame[], int time[]){
	int min,pos,count = 0;
	for(r=0; r<len; r++){
		pos = page_found(frame,ref[r]);
		if(pos == -1 && frame[f] == -1){
			page[ref[r]]++;
			frame[f] = ref[r];
			time[f] = count++;
			f = (f+1)%n;
			pf++;		
		}
		else if(pos == -1){
			min = min_frequency(time,frame,count);
			f = min;
			page[frame[f]] = 0;
			frame[f] = ref[r];
			time[f] = count++;
			pf++;
		}
		else{
			time[pos] = count++;
			page[frame[pos]]++;
		}
	}
}

void main(){
	printf("Enter the length of reference string:");
	scanf("%d",&len);
	int ref[len];
	printf("Enter the reference string:");
	for(int i=0; i<len; i++){
		scanf("%d",&ref[i]);
	}
	printf("Enter the number of frames:");
	scanf("%d",&n);
	int frame[n],time[n],i;
	for(i=0; i<n; i++){
		frame[i] = -1;
		time[i] = 9999;
	}
	for(i=0; i<10; i++){
		page[i] = 0;
	}
	lfu(ref,frame,time);
	printf("Total number of page faults:%d\n",pf);
}

