#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
	char nama[100];
	int number;
	struct Data *next;
}*head, *tail;

void pushHead(char nama[], int nomor){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	strcpy(node->nama, nama);
	node->number = nomor;
	node->next = NULL;
	
	if(head == NULL){
		// head = tail = node;
		head = node;
		tail = node;
	}else{
		node->next = head;
		head = node;
	}
}

void pushTail(char nama[], int nomor){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	strcpy(node->nama, nama);
	node->number = nomor;
	node->next = NULL;
	
	if(head == NULL){
		head = node;
		tail = node;
	}else{
		tail->next = node;
		tail = node;
	}
}

void pushMid(char nama[], int nomor){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	strcpy(node->nama, nama);
	node->number = nomor;
	node->next = NULL;
	
	if(head == NULL){
		head = node;
		tail = node;
	}else{
		if(nomor < head->number){
			node->next = head;
			head = node;
		}else if(nomor >= tail->number){
			tail->next = node;
			tail = node;
		}else{
			struct Data *curr = head;
			while(curr->next->number < nomor){
				curr = curr->next;
			}
			
			node->next = curr->next;
			curr->next = node;
		}
	}
}

void popHead(){
	if(head != NULL){
		if(head == tail){
			free(head);
			head = NULL;
			tail = NULL;
			//  head = tail = NULL;
		}else{
			struct Data *curr = head;
			head = curr->next;
			free(curr);
			curr = NULL;
		}
	}
	
}
 
void popTail(){
	if(head != NULL){
		if(head == tail){
			free(head);
			head = tail = NULL;
		}else{
			struct Data *curr = head;
			while(curr->next != tail){
				curr = curr->next;
			}
			tail = curr;
			free(tail->next);
			tail->next = NULL;
		}
	}
}

void popMid(int nomor){
	if(head != NULL){
		if(head == tail) {
			if(nomor == head->number){
			free(head);
			head = tail = NULL;
			}else{
				printf("%d Not found\n", nomor);
			}
		}else{
			if(nomor == head->number){
				struct Data *curr = head;
				head = curr->next;
				free(curr);
				curr = NULL;
			}else if(nomor == tail->number){
				struct Data *curr = head;
				while(curr->next != tail){
					curr = curr->next;
				}
				tail = curr;
				free(tail->next);
				tail->next = NULL;
			}else{
				struct Data *curr = head;
				while(curr->next->number < nomor && curr->next != tail){
					curr = curr->next;			
				}
				if(curr->next->number == nomor){
					struct Data *del = curr->next;
					curr->next = del->next;
					free(del);
					del = NULL;
				}else{
					printf("%d Not found\n", nomor);
				}
			}
		}
	}
}

void popAll(){
	while(head != NULL)popHead();
}


void printOut(){
	if(head != NULL){
		struct Data *curr = head;
		while(curr != NULL){
			printf("%s-%d", curr->nama, curr->number);
			curr = curr->next;
			printf("\n");
		}
	}else{
		printf("Data is empty");
	}
} 
 
int main(){
	// # Push
	// pushHead("Aldy", 21);
	// pushHead("Revi", 03);
	// pushHead("Gustian", 2005);
	pushMid("Aldy", 21);
	pushMid("Revi", 03);
	pushMid("Gustian", 2005);
	pushMid("User Test", 100);
	// pushTail("Aldy", 21);
	// pushTail("Revi", 03);
	// pushTail("Gustian", 2005); 
	
	// # Pop
	// popHead();
	// popTail();		
//	popMid(100);		
//	popMid(21);		
//	popMid(03);		
//	popMid(100);
//	pushMid("User Test 2", 100);
	popAll();
	// # Print
	printOut();
	return 0;
}
