#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node_tag node_t;
typedef struct node_tag{
	int val;
	node_t* nxt;	
}node_t;


static bool ll_reverse(node_t** head, node_t** tail){
	bool stat=false;

	if (head && tail){
		if (*head){
			*tail=*head;
			node_t* prev=NULL;
			node_t* nxt=NULL;
			node_t* node=*head;

			while (node){
				nxt=node->nxt;
				node->nxt=prev;
				prev=node;
				node=nxt;
			}
			*head=prev;
			stat=true;
		}
	}
	return stat;
}

static bool ll_ins(node_t** head, node_t** tail, int val){
	bool stat=false;

	if (head && tail){
		node_t* new_node=malloc(sizeof(node_t));
		if (new_node){
			new_node->val=val;
			new_node->nxt=NULL;
			if (*tail)
				(*tail)->nxt=new_node;
			else
				(*head)=new_node;

			(*tail)=new_node;
			stat=true;
		}
	}
	return stat;
}

int main(int argc, char** argv){
	node_t* head=NULL;
	node_t* tail=NULL;
	node_t* node=NULL;

	for (int i=0; i<(argc-1); ++i){
		if (!ll_ins(&head, &tail, atoi(argv[i+1])))
			break;
	}

	node=head;

	while (node){
		printf("val:%d\n", node->val);
		node=node->nxt;
	}

	if (ll_reverse(&head, &tail)){
		node=head;
		
		while (node){
			printf("val:%d\n", node->val);
			node=node->nxt;
		}	
	}

	return 0;
}