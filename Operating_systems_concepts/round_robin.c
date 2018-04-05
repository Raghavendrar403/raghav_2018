#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(A,B) ((A)<(B) ? (A) : (B))
int rr_array[200];
int arrival_time[5];
int remaining_burst_time[5];
int total_bt = 0;
int quantum_time = 0;
int period = 0;
int input_pointer = 0;
void round_robin();
void print_rr_stack();
void print_rbt();
void period_inc(int i); 
int get_input_pointer(int i);
int check_remaining_bt();

int main(int argc, char *argv[]) {
	int i = 0;
	printf("------------------- ROUND ROBIN -----------------------\n");
	printf("Enter 5 process: process_name arrival_time burst_time in order..\n");
	for(i = 0; i<5; i++) {
		printf("process %d: ", i+1);
		scanf("%d %d", &arrival_time[i], &remaining_burst_time[i]);
	}
	printf("\nEnter the quantum_time: ");
	scanf("%d", &quantum_time);
	printf("\n");	
	rr_array[0] = 0;
	round_robin();
	print_rr_stack();
	print_rbt();
}

void round_robin() {
	int i = 0, x = 0;
	period = 0;
	for(i = 0; x != 1 && i <= 200; i += period) {
		if(!get_input_pointer(i)) period ++;
		if(remaining_burst_time[input_pointer] > 0 && arrival_time[input_pointer] <= i) {
			period = max(remaining_burst_time[input_pointer], quantum_time);
			remaining_burst_time[input_pointer] -= period;
			period_inc(i);
		}
		input_pointer = (input_pointer+1)%5;
		x = check_remaining_bt();
	}
	total_bt = i;
}

int check_remaining_bt() {
	int i = 0; 
	for(i = 0; i<5; i++) {
		if(remaining_burst_time[i] != 0)	
			return 0;
	}
	return 1;
}

void print_rr_stack() {
	int i = 0;
	printf("{");
	for(i = 0; i < total_bt; i++) {
		printf("%d ", rr_array[i]);
		if(((i+1) % quantum_time) == 0) printf("} \n{"); 
		else if(rr_array[i] != rr_array[i+1] && (i+1) != total_bt) printf("|");
	}
	printf("}");
	printf("\n");
}

void print_rbt() {
	int i = 0;
	for(i = 0; i != 5; i++) {
		printf("process %d, remaining burst time: %d\n", i, remaining_burst_time[i]);
	}
}

int get_input_pointer(int i) {
	while(1) {
		if(arrival_time[input_pointer] <= i && remaining_burst_time[input_pointer] != 0) {
			return 1;
		}
		else if(input_pointer == 4) {
			return 0;
		}
		input_pointer = (input_pointer + 1) % 5;
	}
}

void period_inc(int i) {
	int p = 0;
	while(p < period)	 {
		rr_array[i + p] = input_pointer + 1;
		p++;
	}
}
