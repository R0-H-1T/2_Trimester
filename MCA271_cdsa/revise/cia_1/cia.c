#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

List remove_dead_processes(List **head) {
	List *current = *head;
	List *previous = NULL;

	while(current != NULL) {
		if(strcmp(current->process.process_state, "dead") == 0) {
			if(previous == NULL) {
				*head = current = current->next;
			}else {
				previous->next = current->next;
				free(current);
				current = previous = previous->next;
			}
		}else {
			previous = current;
			current = current->next;
		}
	}
}


void free_nodes(List *head){
    List *next;

    while(head != NULL) {
        List *next = head->next;
        free(head);
        head = next;
    }
    free(next);

}

int main() {
	List *head;
	head = createList();
	display_processes(head);
	
	printf("\n\nProcess having highest priority:");
	print_process(*process_having_highest_prority(head));

	printf("\n\nRemoving all the dead process ...");	
    remove_dead_processes(&head);
	display_processes(head);

    free_nodes(head);
	return 0;
}



