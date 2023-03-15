#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//int main(int argc, char* argv[]) {
int main(void) {
	Node root;
	root.data = 42;
	root.next = malloc(sizeof(Node));
	root.next -> data = -2;
	root.next -> next = NULL;

	printf("Elemento 1: %d\n", root.data);
	printf("Elemento 2: %d\n", root.next->data);

	free(root.next);
    return 0;
}
