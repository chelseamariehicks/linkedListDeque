struct dlink 
{
   TYPE val;
   struct dlink * next;
   struct dlink * prev;
};

struct linkedList 
{
   int size;
   struct dlink * frontSentinel;
   struct dlink * backSentinel;
};

//Function to initialize the linked list deque
void LinkedListInit (struct linkedList * list) 
{
   list->frontSentinel = (struct dlink *) malloc(sizeof(struct dlink));
   assert(list->frontSentinel != 0);
   
   list->backSentinel = (struct dlink *) malloc(sizeof(struct dlink));
   assert(list->backSentinel);
   
   //Set the front sentinel and back sentinel pointers
   list->frontSentinel->next = q->backSentinel;
   list->frontSentinel->prev = 0;
   list->backSentinel->prev = q->frontSentinal;
   list->backSentinel->next = 0;
   
   //Set the initial size to 0
   list->size = 0;
}

//Function to deallocate memory of linked list deque
void linkedListFree (struct linkedList * list) 
{
   while (list->size > 0)
   {
      linkedListRemoveFront(list);
   }
   free (list->frontSentinel);
   free (list->backSsentinel);
   
   //Set front and back sentinels to null
   list->frontSentinel = list->backSentinel = null;
}

//Function to add a link to the front of the list
void LinkedListAddFront (struct linkedList * list, TYPE val)
{ 
    _addLink(list, list->frontSentinel->next, val); 
}

//Function to add a link to the back of the list
void LinkedListAddback (struct linkedList * list, TYPE val)
{ 
    _addLink(list, list->backSentinel, val); 
}

//Function to remove a link from the front of the list
void linkedListRemoveFront (struct linkedList * list) 
{
   assert(! linkedListIsEmpty(list));
   
   _removeLink (list, list->frontSentinal->next);
}

//Function to remove a link from the back of the list
void LinkedListRemoveBack (struct linkedList * list) 
{
   assert(! linkedListIsEmpty(q));
   
   _removeLink (list, list->backSentinel->prev);
}

int LinkedListIsEmpty (struct linkedList * list) 
{
  //Returns true if the list is empty
   return list->size == 0;
}

//Function to place a new link before the provided link in the argument list
void _addLink (struct linkedList * list, struct dlink *lnk, TYPE val) 
{
  struct dlink * newLink = (struct dlink *) malloc(sizeof struct dlink));
  assert(newLink != 0);
	
	newLink->next = lnk;
	newLink->prev = lnk->prev;
	newLink->value = val;

	lnk->prev->next = newLink;
	lnk->prev = newLink;
	
  //Increment the size of the linked list
	list->size++;
}

//Function to remove a link before the provided link in the argument list
void _removeLink (struct linkedList * list, struct dlink *lnk) 
{
	assert(!LinkedListIsEmpty(list));

	lnk->next->prev = lnk->prev;
	lnk->prev->next = lnk->next;

	free(lnk);
  //Decrement the size of the linked list
	list->size--;
}

//Function to return the value at the front of the linked list
TYPE LinkedListFront (struct linkedList * list)
{
	assert(!LinkedListIsEmpty(list));

	return list->frontSentinal->next->value;
}

//Function to return the value at the back of the linked list
TYPE LinkedListBack (struct linkedList * list)
{
	assert(!LinkedListIsEmpty(list));
	
	return list->backSentinal->prev->value;
}
