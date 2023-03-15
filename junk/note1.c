#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
	struct node *left;
	struct node *right;
}
node;

bool search(node *tree, int number)
{
	if (tree == NULL)
	{
		return false;
	}
	else if (number < tree->number)
	{
		return search(tree->left, number);
	}
	else if (number > tree->number)
	{
		return search(tree->right, number);
	}
	else
	{
		return true;
	}
}

int	main(int argc, char **argv)
{
	node *list = NULL;
	int i = 1;
	while (i < argc)
	{
		int number = atoi(argv[i]);
		
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			return 1;
		}
		n->number = number;
		n->next = NULL;
		
		n->next = list;
		list = n;
		i++;
	}

	//for (node *tmp = list; tmp != NULL; tmp = tmp->next)
	node *tmp = list;
	while (tmp != NULL)
	{
		printf("%i\n", tmp->number);
		tmp = tmp->next;
	}

	tmp = list;
	while (tmp != NULL)
	{
		node *next = tmp->next;
		free(tmp);
		tmp = next;
	}
}