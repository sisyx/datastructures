// import dependencies
#include <stdio.h>
#include <stdlib.h>

// define the Node structure
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void createANode(struct Node* root, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
    struct Node* current = root;
	while (current->next != NULL) {
		current = current->next;
	}
	newNode->prev = current;
	current->next = newNode;
}

struct Node* createRoot(int data) {
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root->data = data;
	root->next = NULL;
	root->prev = NULL;

	return root;
}

void printList(struct Node* root) {
	printf("\nstart printing the doubly linked list:\n");
	printf("[\n");
    struct Node* currentNode = root;
    int index = 0;
    while (currentNode->next != NULL) {
       printf("\t%d: %d", index, currentNode->data);
	   printf("\tprev: %p", currentNode->prev);
	   printf("\tnext: %p,\n", currentNode->next);
       currentNode = currentNode->next;
       index += 1;
    }
    printf("\t%d: %d", index, currentNode->data);
	printf("\tprev: %p", currentNode->prev);
	printf("\tnext: %p,\n", currentNode->next);
	printf("]\n");
	printf("finish printing the doubly linked list\n");
}

void printListBackward(struct Node* root) {
	printf("\nprint the doubly linked list backward\n");
	printf("detecting last node...\n");
	struct Node* lastNode = root;
	int index = 0;
	while (lastNode->next != NULL) {
		lastNode = lastNode->next;
		index += 1;
	}
	printf("last Node detected successfully\n");
	printf("start printing the doubly linked list:\n");
	printf("[\n");
	while (lastNode->prev != NULL) {
		printf("\t%d: %d", index, lastNode->data);
		printf("\tprev: %p", lastNode->prev);
		printf("\tnext: %p,\n", lastNode->next);
		lastNode = lastNode->prev;
		index -= 1;
	}
	printf("\t%d: %d", index, lastNode->data);
	printf("\tprev: %p", lastNode->prev);
	printf("\tnext: %p,\n", lastNode->next);
	printf("]\n");
	printf("finish printing the doubly linked list backward");

}

int main() {
	struct Node* root = createRoot(1);
	createANode(root, 2);
    createANode(root, 3);
    createANode(root, 4);
    createANode(root, 5);
    createANode(root, 6);
    createANode(root, 7);
    createANode(root, 8);
    createANode(root, 9);
    createANode(root, 10);
    printList(root);
	printListBackward(root);
}

// this code is editted by VIM Editor. a cool, Free and lightweight edior.
