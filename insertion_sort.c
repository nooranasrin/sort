#include<stdio.h>
#include "sort.h"

void perform_insertion_sort(ArrayVoid_ptr array, Matcher is_equal) {
  for (int i = 0; i < array->length; i++)
  {
    for (int j = i; j > 0 && is_equal(array->values[j], array->values[j - 1]); j--) {
      swap_array_elements(array, j, j - 1);
    }
  }
} 

void perform_list_insertion_sort(List_ptr list, Matcher is_equal) {
  Node_ptr pWalk = list->first;

  while(pWalk != NULL) {
    Node_ptr another_element = pWalk;
    while(another_element->previous != NULL && is_equal(another_element->element, another_element->previous->element)) {
      swap_node(another_element->previous, another_element);
      another_element = another_element->previous;
    }
    pWalk = pWalk->next;
  }
}

