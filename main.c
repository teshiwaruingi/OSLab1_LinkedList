#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  // allocate a new list
list_t* list1 = list_alloc();

// add 4 elements to the back of the list
list_add_to_back(list1, 1);
list_add_to_back(list1, 2);
list_add_to_back(list1, 3);
list_add_to_back(list1, 4);

// print the list
list_print(list1);

// print the length of the list
printf("The length of list1 is %d\n\n", list_length(list1));

// add 4 elements to the front of the list
list_add_to_front(list1, 8);
list_add_to_front(list1, 7);
list_add_to_front(list1, 6);
list_add_to_front(list1, 5);

// print the list
list_print(list1);

// print the length of the list
printf("The length of list1 is %d\n\n", list_length(list1));



  // add 3 elements at specific indices in the list
list_add_at_index(list1, 22, 1);
list_add_at_index(list1, 23, 0);
list_add_at_index(list1, 27, 3);

// print the elements at indices 1, 0, and 3
printf("my_list at index 1: %d\n", list_get_elem_at(list1, 1));
printf("my_list at index 0: %d\n", list_get_elem_at(list1, 0));
printf("my_list at index 3: %d\n", list_get_elem_at(list1, 3));

// print the entire list
list_print(list1);

// print the length of the list
printf("The length of list1 is %d\n\n", list_length(list1));

// print the indices of elements 22, 23, 27, and 44
printf("index of 22: %d\n", list_get_index_of(list1, 22));
printf("index of 23: %d\n", list_get_index_of(list1, 23));
printf("index of 27: %d\n", list_get_index_of(list1, 27));
printf("index of 44: %d\n", list_get_index_of(list1, 44));

// print whether -1, 20, and 27 are in the list
printf("-1 is in my_list: %d\n", list_is_in(list1, -1));
printf("20 is in my_list: %d\n", list_is_in(list1, 20));
printf("27 is in my_list: %d\n", list_is_in(list1, 27));


// remove 3 elements from the back of the list
elem end1 = list_remove_from_back(list1);
elem end2 = list_remove_from_back(list1);
elem end3 = list_remove_from_back(list1);

// print the removed elements
printf("I removed %d, %d, and %d in that order from the back of list1\n", end1, end2, end3);

// print the list
list_print(list1);

// print the length of the list
printf("The length of list1 is: %d after removing from the back\n", list_length(list1));

// remove 3 elements from the front of the list
elem start1 = list_remove_from_front(list1);
elem start2 = list_remove_from_front(list1);
elem start3 = list_remove_from_front(list1);

// print the removed elements
printf("I removed %d, %d, and %d in that order from the front of list1\n", start1, start2, start3);

// print the list
list_print(list1);

// print the length of the list
printf("The length of list1 is: %d after removing from the back\n", list_length(list1));

  // remove 3 elements from the list at indices 1, 2, and 1
elem value1 = list_remove_at_index(list1, 1);
elem value2 = list_remove_at_index(list1, 2);
elem value3 = list_remove_at_index(list1, 1);

// print the removed elements
printf("I removed %d, %d, and %d in that order from list1\n", value1, value2, value3);

// print the list
list_print(list1);

// print the length of the list
printf("The length of list1 is: %d after removing with indexes\n", list_length(list1));

// free the list
list_free(list1);

// print the list (should be empty)
list_print(list1);

// print the length of the list (should be 0)
printf("\nThe length of list1 is: %d after freeing it\n", list_length(list1));

return 0;

}
