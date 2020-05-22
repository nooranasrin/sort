#include<stdio.h>
#include<stdlib.h>
#include "sort.h"
#include "datastructures.h"

Status is_int_smaller(Element num1, Element num2) {
  return *(int *)num1 < *(int *)num2;
}

Status is_char_smaller(Element num1, Element num2) {
  return *(char *)num1 < *(char *)num2;
}

void display_int_array(ArrayVoid_ptr list) {
  for (int index = 0; index < list->length; index++) {
    printf("%d\n", *(int *)list->values[index]);
  }
}

void display_int_list(List_ptr list) {
  Node_ptr pWalk = list->first;

  while (pWalk != NULL) {
    printf("%d\n", *(int *)pWalk->element);
    pWalk = pWalk->next;
  }
}

void display_char_list(List_ptr list) {
  Node_ptr pWalk = list->first;

  while (pWalk != NULL) {
    printf("%c\n", *(char *)pWalk->element);
    pWalk = pWalk->next;
  }
}

int main(void) {
  ArrayVoid_ptr numbers = create_array_void(4);
  printf("Selection Sort\n");
  int num1 = 4, num2 = 3, num3 = 2, num4 = 1;
  numbers->values[0] = &num1;
  numbers->values[1] = &num2;
  numbers->values[2] = &num3;
  numbers->values[3] = &num4;
  perform_selection_sort(numbers, &is_int_smaller);
  display_int_array(numbers);

  numbers = create_array_void(4);
  printf("\nBubble Sort\n");
  num1 = 4, num2 = 3, num3 = 2, num4 = 1;
  numbers->values[0] = &num1;
  numbers->values[1] = &num2;
  numbers->values[2] = &num3;
  numbers->values[3] = &num4;
  perform_bubble_sort(numbers, &is_int_smaller);
  display_int_array(numbers);

  numbers = create_array_void(4);
  printf("\nInsertion Sort\n");
  num1 = 4, num2 = 3, num3 = 2, num4 = 1;
  numbers->values[0] = &num1;
  numbers->values[1] = &num2;
  numbers->values[2] = &num3;
  numbers->values[3] = &num4;
  perform_insertion_sort(numbers, &is_int_smaller);
  display_int_array(numbers);

  printf("\nselection Sort list :\n");
  List_ptr list = create_list();
  num1 = 4, num2 = 3, num3 = 2, num4 = 1;
  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  add_to_list(list, &num4);
  perform_list_selection_sort(list, &is_int_smaller);
  display_int_list(list);

  printf("\nBubble Sort list :\n");
  list = create_list();
  num1 = 1, num2 = 2, num3 = 3, num4 = 4;
  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  add_to_list(list, &num4);
  perform_list_bubble_sort(list, &is_int_smaller);
  display_int_list(list);

  printf("\nInsertion Sort list :\n");
  list = create_list();
  char char1 = 'a', char2 = 'B', char3 = 'v', char4 = 'm';
  add_to_list(list, &char1);
  add_to_list(list, &char2);
  add_to_list(list, &char3);
  add_to_list(list, &char4);
  perform_list_insertion_sort(list, &is_char_smaller);
  display_char_list(list);
}