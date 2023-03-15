#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_end(Node** root, int value)
{
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL) 
	{
		exit (1);
	}
	new_node->next = NULL;
	new_node->data = value;

	if (*root == NULL) 
	{
		*root = new_node;
		return;
	}

	Node* curr = *root;
	while (curr->next != NULL) 
	{
		curr = curr->next;
	}
	curr -> next = new_node;
}

//int main(int argc, char* argv[]) {
int main(void) {
	int n = 0;
	Node* root = NULL;
	// Node* root = malloc(sizeof(Node));
	// if (root == NULL) 
	// {
	// 	exit (2);
	// }
	// root->data = 42;
	// root->next = NULL;
	
	insert_end(&root, -4);
	insert_end(&root, 177);
	insert_end(&root, 7);

	Node* curr = root;
	while (curr != NULL) {
		printf("Elemento %d: %d\n", n+1, curr->data);
		n++;
		curr = curr->next;
	}

	/* 	for (Node* curr = &root; curr != NULL; curr = curr->next) {
		printf("Elemento %d: %d\n", n+1, curr->data);
		n++;
	} */
	
	return 0;
}
