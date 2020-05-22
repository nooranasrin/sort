#include "datastructures.h"

#ifndef __SORT_H_
#define __SORT_H_

typedef enum
{
  Failure,
  Success
} Status;

typedef Status (*Matcher)(Element, Element);

void perform_selection_sort(ArrayVoid_ptr array, Matcher is_equal);
void perform_bubble_sort(ArrayVoid_ptr array, Matcher is_equal);
void perform_insertion_sort(ArrayVoid_ptr array, Matcher is_equal);
void perform_list_selection_sort(List_ptr list, Matcher is_equal);
void perform_list_bubble_sort(List_ptr list, Matcher is_equal);
void perform_list_insertion_sort(List_ptr list, Matcher is_equal);

#endif