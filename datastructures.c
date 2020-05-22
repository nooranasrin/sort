#include<stdlib.h>
#include<stdio.h>
#include "datastructures.h"

ArrayVoid_ptr create_array_void(int length) {
  ArrayVoid *array = malloc(sizeof(ArrayVoid));
  array->length = length;
  array->values = malloc(sizeof(Element) * array->length);
  return array;
}

List_ptr create_list(void) {
  List_ptr list =  malloc(sizeof(LinkedList));

  if(list == NULL) {
    return list;
  }

  list->first = NULL;
  list->last = list->first;
  list->length = 0;
  return list;
}

Node_ptr create_node(Element value) {
  Node_ptr new_node = malloc(sizeof(Node));

  if(new_node == NULL) {
    return new_node;
  }

  new_node->element = value;
  new_node->previous = NULL;
  new_node->next = NULL;
  return new_node;
}

void add_to_list(List_ptr list, Element value) {
  Node_ptr new_node = create_node(value);

  if(new_node == NULL) {
    return;
  }

  if(list->first == NULL) {
    list->first = new_node;
  } else {
    list->last->next = new_node;
    new_node->previous = list->last;
  }

  list->last = new_node;
  list->length++;
}