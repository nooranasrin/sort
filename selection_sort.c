#include<stdio.h>
#include "sort.h"

void perform_selection_sort(ArrayVoid_ptr array, Matcher is_equal) {
  for (int i = 0; i < array->length; i++) {
    int index_of_min = i;
    for (int j = i + 1; j < array->length; j++) {
      if(is_equal(array->values[j], array->values[index_of_min])) {
        index_of_min = j;
      }
    }
    swap_array_elements(array, i, index_of_min);
  }
}

void perform_list_selection_sort(List_ptr list, Matcher is_equal) {
  Node_ptr pWalk = list->first;

  while(pWalk != NULL) {
    Node_ptr min = pWalk;
    Node_ptr another_element = min->next;
    while(another_element != NULL) {
      if (is_equal(another_element->element, min->element)) {
        min = another_element;
      }
      another_element = another_element->next;
    }
    swap_node(pWalk, min);
    pWalk = pWalk->next;
  }
}