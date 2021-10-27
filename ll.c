#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct node_tag node_t;
typedef struct node_tag {
	int val;
	node_t* nxt;
}node_t;

bool ll_remove(node_t** head, int pos){
	bool stat=false;

	if (head && *head && pos>=0){
		node_t* node=*head;
		node_t* prev=NULL;
		size_t cnt=0;

		while (cnt<pos){
			prev=node;
			node=node->nxt;
			cnt++;
			if (!node)
				break;
		}

		if (cnt==pos){
			stat=true;
			if (prev)
				prev->nxt=node->nxt;
			else
				*head=node->nxt;

			free(node);
		}
	}
	return stat;
}

bool ll_ins(node_t** head, int val){
	bool stat=false;

	if (head){
		node_t* new_node=malloc(sizeof(node_t));
		if (new_node){
			stat=true;
			new_node->val=val;
			new_node->nxt=NULL;

			if (*head){
				node_t* node=*head;
				while (node->nxt)
					node=node->nxt;

				node->nxt=new_node;
			}
			else{
				*head=new_node;
			}
		}
	}
	return stat;
}
int main(int argc, char** argv){
	size_t sz=argc-1;
	node_t* head=NULL;

	for (int i=0; i<sz; ++i){
		if (!ll_ins(&head, atoi(argv[i+1])))
			break;
	}

	node_t* node=head;

	while (node){
		printf("ll:%d\n", node->val);
		node=node->nxt;
	}

	ll_remove(&head, 3);
	ll_remove(&head, 1);
	ll_remove(&head, 0);

	node=head;

	while (node){
		printf("rll:%d\n", node->val);
		node=node->nxt;
	}
	return 0;
}