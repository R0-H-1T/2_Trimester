#include<stdio.h>
#include<stdlib.h>

#define PROCESS_SIZE 64



typedef struct {
	int process_id;
	char process_state[PROCESS_SIZE];
	int process_priority;	
} PCB;


typedef struct List{
	PCB process;
	struct List *next;
} List;

PCB* process_having_highest_prority(List* head);

PCB* getPCB() {
	PCB* newPCB = (PCB*) malloc (sizeof(PCB));
	
	printf("\nEnter process fields --");
	printf("\nProcess ID: ");
	scanf("%d", &newPCB->process_id);
	getchar();
	
	printf("Enter process state: ");
	scanf("%s", newPCB->process_state);
	getchar();
	
	printf("Enter process priority: ");
	scanf("%d", &newPCB->process_priority);
	if(newPCB->process_priority < 0) {
		fprintf(stderr, "\nFatal: Process priority cannot negative");
		exit(EXIT_FAILURE);
	}
	
	getchar(); // Eat the trailing newline in the input buffer
	
	return newPCB;
}

List* createNode() {
	List* newnode = (List*) malloc (sizeof(List));
	
	newnode->next = NULL;
	PCB *newprocess = getPCB();
	newnode->process = *newprocess;
	
	return newnode;
}



List* createList() {
	List* newnode = createNode();
	
	char ch;
	printf("Add another process? (y/n): ");
	scanf("%c", &ch);
	getchar();
	
	if(ch == 'y') {
		newnode->next = createList();
	}
	
	return newnode;
}

void print_process(PCB process){
	printf("\n%d\t%d\t\t%s", process.process_id, process.process_priority,  process.process_state);
}

void display_processes(List *temp) {
	printf("\nProcess\nPID\tPrority\t\tState");
	while(temp != NULL) {
		print_process(temp->process);
		temp = temp->next;
	}
}

PCB* process_having_highest_prority(List* head) {
	List* temp = head;
	PCB* highest_process;
	int highest_priority = head->process.process_priority;
	highest_process = &head->process;
	
	
	while(temp != NULL) {
		if(highest_process->process_priority < temp->process.process_priority) {
			highest_process = &temp->process;
		}
		temp = temp->next;
	} 	
	
	return highest_process;
}


List* remove_dead_processes(List *head) {
	List *temp = head;
	List *newlist = NULL;
	
	while(temp != NULL && temp->process.process_state != "dead") {
		if ( temp->process.process_state != "dead"){
			if(newlist == NULL){
				newlist = temp;
			}
			newlist->next = temp;
			temp = temp->next;	
		}		
	}
	
	display_processes(newlist);
	return newlist;
}

int main() {
	List *head;
	head = createList();
	display_processes(head);
	
	printf("\n\nProcess having highest priority:");
	print_process(*process_having_highest_prority(head));
 	
	printf("\n\nRemoving all the dead process ...");
	List *revisedList = remove_dead_processes(head);
	
	
	
	return 0;
}

