#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/*
 create a new circular list deque
 
	pre:    none
 	post:	returns pointer to allocated deque q, q->Sentinel is allocated and q->size equals zero
 
 */

struct cirListDeque *createCirListDeque()
{
	/* FIXME: you must write this */
	struct cirListDeque * q = malloc(sizeof(struct cirListDeque));
	q->Sentinel = malloc(sizeof(struct DLink));
	q->Sentinel->next = NULL;
	q->Sentinel->prev = NULL;
	q->size = 0;
	return q;
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
	struct DLink * link = malloc(sizeof(struct DLink));
	link->next = NULL;
	link->prev = NULL;
	link->value = val;
	/*temporary return value..you may need to change it*/
	return link;

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */ 
	q->size += 1;							//
	struct DLink* new = _createLink(v);
	if ( lnk == q->Sentinel->prev) 
	{
		q->Sentinel->prev = new;
		new->next = q->sentinel;
	}
	new->prev = lnk;
	lnk->next = new;
	
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	if (q->size == 0)
	{
		struct DLink * new = _createLink(val);
		q->size += 1;
		q->Sentinel->next = new;
		q->Sentinel->prev = new;
		new->next = q->Sentinel;
		new->prev = q->Sentinel;
	}
	else
	{
		struct DLink * new = _createLink(val);
		q->size += 1;
		new->next = q->Sentinel;
		new->prev = q->Sentinel->prev;
		q->Sentinel->prev = new;
	}
	/* FIXME: you must write this */	 

}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	if (q->size == 0)
	{
		struct DLink * new = _createLink(val);
		q->size += 1;
		q->Sentinel->next = new;
		q->Sentinel->prev = new;
		new->next = q->Sentinel;
		new->prev = q->Sentinel;
	}
	/* FIXME: you must write this */
	q->size += 1;
	struct DLink * new = _createLink(val);
	new->next = q->Sentinel->next;
	q->Sentinel->next = new;
	new->prev = q->Sentinel;
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIXME: you must write this */	 
	/*temporary return value..you may need to change it*/
	return(q->Sentinel->next->value);
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	/*temporary return value..you may need to change it*/
	return(q->Sentinel->prev->value);
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	q->size -= 1;			
	
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	lnk->next = NULL;
	lnk->prev = NULL;
	free(lnk);
	/* FIXME: you must write this */	 

}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	struct DLink* tempptr = q->Sentinel->next;	//This is the link being deleted
	tempptr->next->prev = q->Sentinel;	// the back pointer for the link after the one being deleted is assigned
	q->Sentinel->next = tempptr->next;			//Assigns sentinel to the link after the one being deleted
	q->size -= 1;
	tempptr->next = NULL;
	tempptr->prev = NULL;
	free(tempptr);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	struct DLink* tempptr = q->Sentinel->prev;		// tempptr created referencing the last node
	tempptr->prev->next = q->Sentinel;			// sentinel's prev is set equal to the second to last node
	q->Sentinel->prev = tempptr->prev;			// node ptrs are set  to make sure nothing is set to tempptr
	tempptr->next = NULL;					// temp ptr set to null and free'd
	tempptr->prev = NULL:
	free(tempptr);
	q->size -= 1;
  	/* FIXME: you must write this */	 
}

/* De-allocate all links of the deque, and the deque itself

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	struct DLink * tempptr = q->Sentinel->next;
	struct DLink * tempptr2 = q->Sentinel->next;
	for (int i = 0; tempptr != q->Sentinel; i++)
	{
		tempptr2 = tempptr;			// tempptr 2 is used to free memory while
		tempptr = tempptr->next;		// tempptr is used to locate the sentinel
		tempptr2->next = NULL;			// all values are changed to NULL before being free'd
		tempptr2->prev = NULL;
		free(tempptr2);
	}
	q->Sentinel->prev = NULL;
	q->Sentinel->next = NULL;
	free(q->Sentinel);
	free(q);
	/* FIXME: you must write this */
	
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	if (q->size == 0)				// Checks size of array to see if empty
	{
		return(1);
	}
  	/* FIXME: you must write this */
	/*temporary return value..you may need to change it*/
	else
	{
		return(0);
	}
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{

	/* FIXME: you must write this */	 
	
}
