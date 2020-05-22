#ifndef __DATASTRUCTURES_H_
#define __DATASTRUCTURES_H_

typedef void *Element;

typedef struct
{
  Element *values;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;

typedef struct node
{
  Element element;
  struct node *previous;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct linklist
{
  Node *first;
  Node *last;
  int length;
} LinkedList;

typedef LinkedList *List_ptr;

ArrayVoid_ptr create_array_void(int length);
List_ptr create_list(void);
Node_ptr create_node(Element value);
void add_to_list(List_ptr list, Element value);

#endif
