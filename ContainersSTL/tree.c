#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node *left;
	struct Node *right;	
};

void tree_print(struct Node *p)
{
	if (p == NULL)
		return ;
	tree_print(p->left);
	printf("%d, ", p->val);
	tree_print(p->right);
}

void free_tree(struct Node *p)
{
	if (p == NULL)
		return ;
	free_tree(p->left);
	free_tree(p->right);
	free(p);
}

struct Node *tree_add(struct Node *p, int x)
{
	if (p == NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		if (p == NULL)
			return NULL;
		p->val = x;
		p->left = NULL;
		p->right = NULL;
	}
	else if (x < p->val)
		p->left = tree_add(p->left, x);
	else if (x > p->val)
		p->right = tree_add(p->right, x);
	return p;
}

int main(void) {
	struct Node *tree = NULL;
	tree = tree_add(tree, 7);
	tree = tree_add(tree, 3);
	tree = tree_add(tree, 5);
	tree = tree_add(tree, 4);
	tree = tree_add(tree, 1);
	tree = tree_add(tree, 6);
	tree = tree_add(tree, 2);
	tree = tree_add(tree, 8);
	tree = tree_add(tree, 10);
	tree = tree_add(tree, 9);
	tree_print(tree);
	free_tree(tree);

}
