#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
    int val;
    struct stack *next;
} stack_node;


void push_stack(stack_node **top, int val)
{
    stack_node *newTop = malloc(sizeof(stack_node));
    newTop->next = *top;
    newTop->val = val;
    *top = newTop;
}

int pop_stack(stack_node **top)
{
    if (*top == NULL)
        exit(0);
    stack_node *tmp ;
    int val;
    tmp = *top;
    *top = (*top)->next;
    val = tmp->val;
    free(tmp);
    return val;
}

void print_stack(stack_node *top)
{
  while(top != NULL)
  {
    printf("%d\n", top->val);
    top = top->next;
  }
}


int main()
{
	int n;
    printf("Write the initial stack size ");
    scanf("%d", &n);

    stack_node *top = NULL;

    for(int i = 0; i < n; ++i)
    {
        int val;
        scanf("%d", &val);
        push_stack(&top, val);
    }

    for(;;)
    {
        printf("\nMenu:\n");
		printf("1.Push stack\n");
		printf("2.Pop stack\n");
		printf("3.Print stack\n");
		printf("4.Exit\n");
		int a;
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Write a new value for the stack\n");
				int val;
				scanf("%d", &val);
				push_stack(&top, val);
				break;
			case 2:
				printf("Pop stack: %d\n", pop_stack(&top));
				break;
			case 3:
				printf("stack: %d\n");
				print_stack(top);
				break;
		}
		if (a == 4)
			break;
    }
    return 0;
}
