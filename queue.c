#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


#define Q_SZ (10)

bool queue_ins(int* queue, size_t* head, size_t* tail, int val){
	bool stat=false;
	if (queue && head && tail){
		if ((*head==*tail)||//empty
			((*head>*tail)&&((Q_SZ-(*head-*tail))>0))||
			((*head<*tail)&&((*tail-*head)>0))){
			stat=true;
			queue[*head]=val;
			(*head)++;

			if (*head==Q_SZ)
				*head=0;
		}
	}
	return stat;
}

bool queue_remove(int* queue, size_t* head, size_t* tail, int* val){
	bool stat=false;
	if (queue && head && tail && val){
		if (*head!=*tail){
			stat=true;
			*val=queue[*tail];
			(*tail)++;

			if (*tail==Q_SZ)
				*tail=0;
		}
	}
	return stat;
}




int main(int argc, char** argv){
	int queue[Q_SZ]={0};
	size_t head=0;
	size_t tail=0;
	int val;

    for (int i=0; i<(argc-1); ++i)
		queue_ins(queue, &head, &tail, atoi(argv[i+1]));

	while (queue_remove(queue, &head, &tail, &val))
		printf("value fetched is %d\n", val);

	return 0;
}
