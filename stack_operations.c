#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_tag node_t;
typedef struct node_tag {
	int val;
	node_t* prev;
}node_t;

void stack_print(node_t* stack){
	while (stack){
		printf("value : %d \n", stack->val);
		stack=stack->prev;
	}
}
bool stack_push(node_t** stack, int val){
	bool stat=false;
	if (stack){
		node_t* new_node=malloc(sizeof(node_t));
		if (new_node){
			stat=true;
			new_node->val=val;
			new_node->prev=*stack;
			*stack=new_node;
		}
	}
	return stat;
}

bool stack_pop(node_t** stack, int* val){
	bool stat=false;
	if (stack && *stack){
		*val=(*stack)->val;
		node_t* node=(*stack)->prev;
		free (*stack);
		*stack=node;
		stat=true;
	}
	return stat;
}

/*
  args comes as numbers, POP, DUP, +, -, *, /,
*/
int main(int argc, char** argv){
	size_t sz=argc-1;
	int v1;
	int v2;
	size_t str_sz_mx=5;
	char* str=malloc(sizeof(char)*str_sz_mx);
	node_t* stack=NULL;

	if (!str)
		return -1;

	for (int i=0; i<sz; ++i){
		strncpy (str, argv[i+1], str_sz_mx);
		char sample=str[0];
		if (sample=='+' ||
			sample=='-' ||
			sample=='^' ||
			sample=='/'){
			printf("test point symbols\n");
			if (stack_pop(&stack, &v1) &&
				stack_pop(&stack, &v2)){
				if (sample=='+')
					stack_push(&stack, v1+v2);
				else if (sample=='-')
					stack_push(&stack, v1-v2);
				else if (sample=='^')
					stack_push(&stack, v1*v2);
				else if (sample=='/'){
					if (v2!=0)
						stack_push(&stack, v1/v2);
					else
						return -1;
				}
				else
					return -1;
			}
			else
				return -1;
		}
		else if(sample<'9'&&sample>'0')
			stack_push(&stack, atoi(argv[i+1]));
		else if (sample=='P')//POP
			stack_pop(&stack, &v1);
		else if (sample=='D'){//DUP
			if (stack_pop(&stack, &v1)){
				stack_push(&stack, v1);
				stack_push(&stack, v1);
			}
			else
				return -1;
		}
		else
			return -1;
	}
	stack_pop(&stack, &v1);
	printf("value is %d\n", v1);

	stack_print(stack);
	return 0;
}
