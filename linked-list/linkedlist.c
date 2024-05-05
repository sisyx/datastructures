// import dependencies
#include <stdio.h>
#include <stdlib.h>

// define the Node structure
struct Node {
	int data;
	struct Node* next;
};

void createANode(struct Node* root, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
    struct Node* current = root;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
}

struct Node* createRoot(int data) {
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root->data = data;
	root->next = NULL;

	return root;
}

void printList(struct Node* root) {
	printf("start printing the link list:\n");
	printf("[");
    struct Node* currentNode = root;
    int index = 0;
    while (currentNode->next != NULL) {
       printf("%d: %d\n", index, currentNode->data);
       currentNode = currentNode->next;
       index += 1;
    }
    printf("%d: %d", index+1, currentNode->data);
	printf("]");
	printf("finish printing the linked list");
}

int main() {
	struct Node* root = createRoot(1);
	createANode(root, 2);
    createANode(root, 3);
    printList(root);
}

// resources: 
//  https://www.geeksforgeeks.org/how-to-create-a-linked-list-in-c/

// this code is editted by VIM Editor. a cool, Free and lightweight edior.
