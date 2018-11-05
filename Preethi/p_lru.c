#include<stdio.h>
int len,n,r=0,f=0,pf=0;

int find_min(int time[]){
	int pos = 0,min = time[0];
	for(int i=1; i<n; i++){
		if(min > time[i]){
			pos = i;
			min = time[i];
		}
	}
	return pos;
}
//return 0 if page not found. If page found in frame, return the next index 
int page_found(int frame[], int page){
	for(int j=0; j<n; j++){
		if(page == frame[j]){
			return j+1;
		}
	}
	return 0;
}

void lru(int ref[], int frame[], int time[]){
	int pos, min, count=0;
	for(r=0; r<len; r++){
		pos = page_found(frame,ref[r]);
		if(pos == 0){//page not found in frame
			frame[f] = ref[r];//add 
			time[f] = count++;
			f = (f+1)%n;
			pf++;
		}
		else{//page found in frame
			min = find_min(time);
			//printf("min:%d	",min);
			time[pos-1] = count++;
			f = find_min(time);
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
	int frame[n], time[n];
	for(int i=0; i<n; i++){
		frame[i] = -1;
		time[i] = 9999;
	}
	lru(ref,frame,time);
	printf("Total number of page faults:%d\n",pf);
}

