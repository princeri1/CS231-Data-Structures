/*
 * This file contains the implementation of a priority queue.
 *
 * You must complete the implementations of these functions:
 *   pq_insert()
 *   pq_first()
 *   pq_remove_first()
 */

#include <stdlib.h>
#include <assert.h>

#include "dynarray.h"
#include "pq.h"

// This is the initial capacity that will be allocated for the heap.
#define INITIAL_HEAP_CAPACITY 16

/*
 * This is the definition of the structure we will use to represent the
 * priority queue.  It contains only a dynamic array, which will be used to
 * store the heap underlying the priority queue.
 */
struct pq {
  struct dynarray* heap;
};


/*
 * This is an auxiliary structure that we'll use to represent a single element
 * in the priority queue.  It contains two fields:
 *
 *   priority - the priority value assigned to the item
 *   item - the pointer to the data item represented by this element
 *
 * Both of these will come directly from the corresponding values passed to
 * pq_insert().
 */
struct pq_elem {
  int priority;
  void* item;
};


/*
 * This function allocates and initializes a new priority queue.
 *
 * You should not modify this function.
 */
struct pq* pq_create() {
  struct pq* pq = malloc(sizeof(struct pq));
  assert(pq);
  pq->heap = dynarray_create(INITIAL_HEAP_CAPACITY);
  return pq;
}


/*
 * This function frees the memory associated with a priority queue.
 *
 * You should not modify this function.
 */
void pq_free(struct pq* pq) {
  assert(pq);
  while (!pq_isempty(pq)) {
    pq_remove_first(pq);
  }
  dynarray_free(pq->heap);
  free(pq);
}

/*
 * This function returns 1 if the given priority queue is empty or 0
 * otherwise.
 *
 * You should not modify this function.
 */
int pq_isempty(struct pq* pq) {
  assert(pq);
  return dynarray_size(pq->heap) == 0;
}


/*
 * This function inserts a new item with a specified priority into a priority
 * queue.
 *
 * You should complete the implementation of this function.  The first part
 * is done for, where a new element is created to be placed into the dynamic
 * array underlying the priority queue.
 */
void pq_insert(struct pq* pq, void* item, int priority) {
	assert(pq);
	struct pq_elem * newItem = malloc(sizeof(struct pq_elem));	//allocate new element
	newItem->priority = priority;
	newItem->item = item;
	int idx = -1;							// go to last value in dynarray fucntion
	dynarray_insert(pq->heap, idx, newItem);			// insety value
	int child = dynarray_size(pq->heap) - 1;			// get last child 
	struct pq_elem * tempItem = NULL;
	for ( int parent = 0; parent >= 0;)	// loop for ascending heap
	{
		parent = (child - 1) / 2;	//equation for parent from slides
		tempItem = dynarray_get( pq->heap, parent );
		if (tempItem->priority > newItem->priority)
		{
			dynarray_set(pq->heap, parent, newItem);	//switch
			dynarray_set(pq->heap, child, tempItem);	//switch
			child = parent;					//child equals parent (ascending tree)
		}
		else
		{
			parent = -1;	//break 
		}
	}
	return;

  /* FIX ME: Complete this function */
  /*
   * Restore the heap so that it has the property that every node's priority
   * value is less than the priority values of its children.  This can be
   * done by "percolating" the newly added element up in the heap array.  To
   * perform the percolation, you will have to compare the priority values of
   * the struct pq_elems in the heap array (i.e. by comparing the
   * elem->priority values).
   */

}


/*
 * This function returns the first (highest-priority) item from a priority
 * queue without removing it.
 *
 * You should complete the implementation of this function.
 */
void* pq_first(struct pq* pq) {
	assert(pq);
	assert(dynarray_size(pq->heap) > 0);
	struct pq_elem * tempItem = (struct pq_elem *)dynarray_get(pq->heap, 0);	//get element
	if (tempItem == NULL)
	{
		return NULL;
	}
	else
	{
		return tempItem->item;	//return item
	}

  /* FIXME: Complete this function */
}


/*
 * This function removes the first (highest-priority) element from a priority
 * queue and returns its value.
 *
 * You should complete this function.
 */
void* pq_remove_first(struct pq* pq) {
	assert(pq);
	assert(dynarray_size(pq->heap) > 0);
	struct pq_elem * first_elem = (struct pq_elem *)dynarray_get(pq->heap, 0);	//get first element
	struct pq_elem * last_elem = (struct pq_elem *)dynarray_get(pq->heap,-1);	//get last element
	dynarray_set(pq->heap, 0, last_elem);						// set the last element to the initial spot
	dynarray_remove(pq->heap,-1);							//remove the last element
	int lchild = 0;
	int rchild = 0;
	struct pq_elem * tempI1 = NULL;
	struct pq_elem * tempI2 = NULL;
	for ( int parent = 0; parent != -1; )	// loop for "percolating"
	{
		lchild = (2 * parent) + 1;	// use equation to find children
		rchild = (2 * parent) + 2;
		if ( dynarray_size(pq->heap) - 1 < lchild )	// if new child value is larger than size of array break fucntion
		{
			parent = -1;
		}
		else if ( dynarray_size(pq->heap) - 1 == lchild )	// if left child is last element do not compare left and right child
		{	// compare priority
			if ( ((struct pq_elem *)dynarray_get(pq->heap, parent))->priority > ((struct pq_elem *)dynarray_get(pq->heap, lchild))->priority )
			{
				tempI1 = (struct pq_elem *)dynarray_get(pq->heap, parent);	//get parent
				tempI2 = (struct pq_elem *)dynarray_get(pq->heap, lchild);	//get child
				dynarray_set(pq->heap, parent, tempI2);				// switch items
				dynarray_set(pq->heap, lchild, tempI1);				
				parent = lchild;						//parent = child for future tests
			}
			else
			{
				parent = -1;

			}
		}
		else
		{ 	// compare priority of children
			if ( ((struct pq_elem *)dynarray_get(pq->heap, lchild))->priority < ((struct pq_elem *)dynarray_get(pq->heap, rchild))->priority )
			{	// comapre priority to parent
				if ( ((struct pq_elem *) dynarray_get(pq->heap, parent))->priority > ((struct pq_elem *)dynarray_get(pq->heap, lchild))->priority )
				{
					tempI1 = (struct pq_elem *)dynarray_get(pq->heap, parent);	//get parent
					tempI2 = (struct pq_elem *)dynarray_get(pq->heap, lchild);	//get child
					dynarray_set(pq->heap, parent, tempI2);				//switch items
					dynarray_set(pq->heap, lchild, tempI1);				//parent = child for future tests
					parent = lchild;
				}
				else	//break loop
				{
					parent = -1;
				}
			}
			else
			{
				if ( ((struct pq_elem *)dynarray_get(pq->heap, parent))->priority > ((struct pq_elem *)dynarray_get(pq->heap, rchild))->priority )
				{
					tempI1 = (struct pq_elem *)dynarray_get(pq->heap, parent);	//get parent item
					tempI2 = (struct pq_elem *)dynarray_get(pq->heap, rchild);	//get child item
					dynarray_set(pq->heap, parent, tempI2);				//switch items
					dynarray_set(pq->heap, rchild, tempI1);
					parent = rchild;						//parent = child for future tests
				}
				else	// exit loop
				{
					parent = -1;

				}
			}
		}
	}
	if ( first_elem != NULL )	// It cannot be NULL
	{	
		return first_elem->item;
	}
	else
	{
		return NULL;
	}


  /* FIXME: Complete this function */
  /*
   * Determine what index in the heap array corresponds to the highest-priority
   * element (i.e. the one with the lowest priority value), and store the
   * value there in first_elem.
   */

  /*
   * Replace the highest-priority element with the appropriate one from within
   * the heap array.  Remove that replacement element from the array after
   * copying its value to the location of the old highest-priority element..
   */

  /*
   * Restore the heap so that it has the property that every node's priority
   * value is less than the priority values of its children.  This can be
   * done by "percolating" the element that replaced the highest-priority
   * element down in the heap array.  To perform the percolation, you will
   * have to compare the priority values of the struct pq_elems in the heap
   * array (i.e. by comparing the elem->priority values).  It may be helpful
   * to write a helper function to accomplish this percolation down.
   */

  /*
   * Return the extracted item, if the element taken out of the priority
   * queue is not NULL.
   */
}
