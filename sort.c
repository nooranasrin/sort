#include<stdio.h>
#include<stdlib.h>
#include "sort.h"

void swap_array_elements(ArrayVoid_ptr array, int first_index, int second_index) {
  Element temp = array->values[first_index];
  array->values[first_index] = array->values[second_index];
  array->values[second_index] = temp;
}

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

void perform_bubble_sort(ArrayVoid_ptr array,  Matcher is_equal) {
  for (int i = 0; i < array->length; i++) {
    int is_swapped = 0;
    for (int j = i + 1; j < array->length; j++)
    {
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

void perform_insertion_sort(ArrayVoid_ptr array, Matcher is_equal) {
  for (int i = 0; i < array->length; i++)
  {
    for (int j = i; j > 0 && is_equal(array->values[j], array->values[j - 1]); j--) {
      swap_array_elements(array, j, j - 1);
    }
  }
} 

void swap_node(Node_ptr node1, Node_ptr node2) {
  Element temp = node1->element;
  node1->element = node2->element;
  node2->element = temp;
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

void perform_list_bubble_sort(List_ptr list, Matcher is_equal) {
  Node_ptr pWalk = list->first;

  while(pWalk != NULL) {
    Node_ptr another_element = pWalk->next;
    while(another_element != NULL) {
      if (is_equal(another_element->element, pWalk->element))
      {
        swap_node(pWalk, another_element);
      }
      another_element = another_element->next;
    }
    pWalk = pWalk->next;
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

