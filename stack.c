#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_tag node_t;
typedef struct node_tag
{
  int value;
  node_t* prevP;
}node_t;

bool push(int value, node_t** stack_hdlr)
{
  bool stat=false;

  if (stack_hdlr)
  {
    node_t* nodeP=malloc(sizeof(node_t));

    if (nodeP)
    {
      nodeP->value=value;
      nodeP->prevP=NULL;

      if (*stack_hdlr!=NULL)
        nodeP->prevP=*stack_hdlr;
      *stack_hdlr=nodeP;
      stat=true;
    }
  }
  return stat;
}

bool pop(int* valueP, node_t** stack_hdlr)
{
  bool stat=false;

  if (valueP && stack_hdlr)
  {
    if (*stack_hdlr)
    {
      *valueP=(*stack_hdlr)->value;
      node_t* nodeP=*stack_hdlr;
      *stack_hdlr=(*stack_hdlr)->prevP;
      free(nodeP);
      stat=true;
    }
  }
  return stat;
}

bool peek(int* valueP, const node_t* stack_hdlr)
{
  bool stat=false;

  if (valueP && stack_hdlr)
  {
    *valueP=stack_hdlr->value;
    stat=true;
  }
  return stat;
}

bool is_empty(const node_t* stack_hdlr)
{
  bool stat=true;

  if (stack_hdlr)
  {
    stat=false;
  }
  return stat;
}


int main(int argc, char** argv)
{
  node_t* stackP=NULL;
  int value;
  size_t cnt;
  size_t sz=argc-1;
  
  for (cnt=0; cnt<sz; ++cnt)
  {
    push(atoi(argv[cnt+1]), &stackP);
    printf("pushed value:%d\n", atoi(argv[cnt+1]));
  }
  printf("\n");
  
  for (cnt=0; cnt<sz; ++cnt)
  {
    if (peek(&value, stackP))
      printf("peeked value:%d\n", value);
    else
      break;
  }
  
  printf("\n");
  
  while (!is_empty(stackP) && pop(&value, &stackP))
    printf("popped value:%d\n", value);

  return 0;
}