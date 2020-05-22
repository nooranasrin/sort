#include<stdio.h>
#include "sort.h"

void perform_bubble_sort(ArrayVoid_ptr array,  Matcher is_equal) {
  for (int i = 0; i < array->length; i++) {
    int is_swapped = 0;
    for (int j = i + 1; j < array->length; j++) {
      if (is_equal(array->values[j], array->values[i])) {
        swap_array_elements(array, i, j);
        is_swapped = 1;
      }
    }
    if(!is_swapped) {
      return;
    }
  }
}

void perform_list_bubble_sort(List_ptr list, Matcher is_equal) {
  Node_ptr pWalk = list->first;

  while(pWalk != NULL) {
    int is_swapped = 0;
    Node_ptr another_element = pWalk->next;
    while(another_element != NULL) {
      if (is_equal(another_element->element, pWalk->element)) {
        swap_node(pWalk, another_element);
        is_swapped = 1;
      }
      another_element = another_element->next;
    }
    if(!is_swapped) {
      return;
    }
    pWalk = pWalk->next;
  }
}