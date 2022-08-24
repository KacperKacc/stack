#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stack_node
{
	int data;
	struct stack_node *next;
};

struct stack_node *push(struct stack_node *top, int number)
{
	struct stack_node *new_node = (struct stack_node *)malloc(sizeof(struct stack_node));

	if(new_node!=NULL)
	{
		new_node->data = number;
		new_node->next = top;
		top = new_node;
	}
	return top;
}

int pop(struct stack_node **top)
{
	int result = -1;

	if(*top)
	{
		result = (*top)->data;
		struct stack_node *tmp = (*top)->next;
		free(*top);
		*top = tmp;
	}
	return result;
}

int peek(struct stack_node *top)
{
	if(top)
		return top->data;
	else
	{
		fprintf(stderr,"Stos nie istnieje.\n");
		return -1;
	}
}

int main(void)
{

	struct stack_node *top = NULL;

	srand(time(0));

	int i = 0;

	for(i=1; i<6+rand()%5; i++)
		top=push(top,i);

	printf("Wartość ze szczytu stosu: %d\n",peek(top));

	while(top)
		printf("%d ",pop(&top));

	puts("");

	return 0;
}

