#ifndef __SORT_H_
#define __SORT_H_

typedef enum
{
  Failure,
  Success
} Status;

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

typedef Status (*Matcher)(Element, Element);

ArrayVoid_ptr create_array_void(int length);
void perform_selection_sort(ArrayVoid_ptr array, Matcher is_equal);
void perform_bubble_sort(ArrayVoid_ptr array, Matcher is_equal);
void perform_insertion_sort(ArrayVoid_ptr array, Matcher is_equal);
List_ptr create_list(void);
Node_ptr create_node(Element value);
void add_to_list(List_ptr list, Element value);
void perform_list_selection_sort(List_ptr list, Matcher is_equal);
void perform_list_bubble_sort(List_ptr list, Matcher is_equal);
void perform_list_insertion_sort(List_ptr list, Matcher is_equal);

#endif