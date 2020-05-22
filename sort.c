#include<stdio.h>
#include<stdlib.h>
#include "sort.h"

void swap_array_elements(ArrayVoid_ptr array, int first_index, int second_index) {
  Element temp = array->values[first_index];
  array->values[first_index] = array->values[second_index];
  array->values[second_index] = temp;
}

void swap_node(Node_ptr node1, Node_ptr node2) {
  Element temp = node1->element;
  node1->element = node2->element;
  node2->element = temp;
}
