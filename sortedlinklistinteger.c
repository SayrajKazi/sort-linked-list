
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

//  PURPOSE:  
const int	LINE_LEN	= 256;

#define		STOP_CMD	"quit"

const int	STOP_CMD_LEN	= sizeof(STOP_CMD) - 1;


//  PURPOSE:  To hold a node in a linked list of integers.
struct		Node
{
  int		integer_;
  struct Node*	nextPtr_;
};


//  PURPOSE:  To print the 'integer_' values found in 'list'.  No return value.
void		print		(const struct	Node*	list
				)
{
  const struct Node*	run;

  printf("The list currently is:\n");
	if (list == NULL)
	{
  //  YOUR CODE to printf() all nodes of list.
	}else
	{
		run=list;
		while(run!=NULL)
	{
		printf("%d\n",run->integer_);
		run= run->nextPtr_;
}
}
}


//  PURPOSE:  To insert the Node pointed to by 'newNodePtr' into the list
//	pointed to by 'listPtr' so that the list is arranged in ascending order
//	by 'integer_'.  Returns new beginning of list.
struct Node*	insert		(struct Node*	listPtr,
				 struct Node*	newNodePtr
				)
{
  //  YOUR CODE HERE:
	struct Node*  ptr;
        if( listPtr == NULL || listPtr->integer_ >= newNodePtr->integer_ )	{
		newNodePtr->nextPtr_ =  listPtr;
		listPtr = newNodePtr;
	}
	else
	{
		ptr= listPtr;
	while(ptr->nextPtr_!=NULL && ptr->nextPtr_->integer_ < newNodePtr->integer_)
	{
		ptr= ptr->nextPtr_;
	}
	newNodePtr->nextPtr_ =ptr->nextPtr_;
	ptr->nextPtr_=newNodePtr;
	}

		

	
  //  One way of breaking it down is into 4 cases:
  //  (1) When listPtr is empty (what should you do?)
  //  (2) When newNodePtr comes before listPtr (what should you do?)
  //  (3) Run thru nodes of listPtr.
  //      When newNodePtr comes before the next node of the current (run)
  //      what should you do?
  //  (4) When newNodePtr goes at the very end (what should you do?)
  return(listPtr);
}


//  PURPOSE:  To create and return a linked list of integers.
struct Node*	makeList	()
{
  struct Node*	list	= NULL;
  int		integer;
  char		line[LINE_LEN];
  
  while  (1)
  {
    struct Node*	next;

    print(list);

    printf("Integer (or %s) to quit: ",STOP_CMD);
    fgets(line,LINE_LEN,stdin);

    if  ( strncmp(line,STOP_CMD,STOP_CMD_LEN) == 0)
      break;

    integer		= strtol(line,NULL,10);
	
	next= (struct Node*)malloc(sizeof(struct Node));
	next->integer_ = integer;
	next->nextPtr_= NULL;
    //  YOUR CODE to:
    //  (1) make next point to enough memory for a new struct Node
    //  (2) set integer_ of this node to integer
    //  (3) set nextPtr_ of this node to NULL

    list   		= insert(list,next);
  }

  return(list);
}


//  PURPOSE:  To do nothing if 'list' is NULL.  Otherwise to print the
//	integer and 'free()' 'nextPtr_' for 'list',
//	and all of 'nextPtr_' successors.  No return value.
void		release		(struct Node*	list
				)
{
  struct Node* temp;
	while(list != NULL)
{
	temp = list;
	list = list->nextPtr_;
	printf("Freeing %d\n", temp->integer_);
	free(temp); 
}
}


//  PURPOSE:  To create, print, and 'free()' a linked list of integers.
//	Returns 'EXIT_SUCCESS' to OS.
int		main		(int		argc,
				 char*		argv[]
				)
{
  //  I. Application validity check:

  //  II.  Do work of program:
  struct Node*	list;

  list	= makeList();
  print(list);
  release(list);

  //  III.  Finished:
  return(EXIT_SUCCESS);
}
 
