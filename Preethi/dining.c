#include<stdio.h>
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int mutex = 1;
int state[5],self[5];

int wait(int s){
	while(s<=0)
		;
	return --s;
}

int signal(int s){
	return ++s;
}

void test(int i){
	if( state[(i+4)%5] != EATING && state[i] == HUNGRY && state[(i+1)%5] != EATING){
		state[i] = EATING;
		printf("Philosopher %d takes fork %d and %d\n",i+1,(i+4)%5+1,(i+1)%5);
		printf("Philosopher %d is eating\n",i+1);
		self[i] = signal(self[i]);
	}
}

void initialize(){
	for(int i=0; i<5; i++){
		state[i] = THINKING;
		//printf("Philosopher %d is thinking\n",i+1);
	}
}

void pickup(int i){
	mutex = wait(mutex);
	state[i] = HUNGRY;
	test(i);
	if(state[i] != EATING){
		self[i] = wait(self[i]);
	}
	mutex = signal(mutex);
}

void putdown(int i){
	mutex = wait(mutex);
	state[i] = THINKING;
	test((i+4)%5);
	test((i+1)%5);
	mutex = signal(mutex);
}

/*void philosoper(int i){
	pickup(i);
	putdown(i);
}*/

void main(){
	initialize();
	for(int i=0; i<5; i++){
		pickup(i);
		putdown(i);
	}
}
