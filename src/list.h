#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

typedef struct list List;

/*
 * Description
 * ----------------------------
 *  Create a new list that has been dynamically allocated memory on the heap
 *
 * Returns
 * ----------------------------
 *  List (Pointer To List)
 */
List *List_new();

/*
 * Description
 * ----------------------------
 *  Retrieve an element from the list at the given index
 *
 * Params
 * ----------------------------
 *  *list       the list to append onto
 *  index       the index of the list to retrieve
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_get(List *list, int index);

/*
 * Description
 * ----------------------------
 *  Append an element onto the end of the list
 *
 * Params
 * ----------------------------
 *  *list       the list to append onto
 *  element     the element to insert into the list
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_append(List *list, int element);

/*
 *
 * Description
 * ----------------------------
 *  Append multiple elements into the given list
 *
 * Params
 * ----------------------------
 *  *list               the list to append onto
 *  element_count       number of elements to append into the given list
 *  ...                 variable list of integers to append into the given list
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_append_all(List *list, int element_count, ...);

/*
 *
 * Description
 * ----------------------------
 *  Insert the given element into a valid index of the list
 *
 * Params
 * ----------------------------
 *  *list       the list to insert into
 *  index       the index to insert the given value
 *  element     the element to insert into the list
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_insert(List *list, int index, int element);

/*
 *
 * Description
 * ----------------------------
 *  Remove the first occurrence of the given element from the given list
 *
 * Params
 * ----------------------------
 *  *list       the list to remove given element from
 *  element     the element to remove from the given list
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_remove(List *list, int element);

/*
 *
 * Description
 * ----------------------------
 *  Sort the given list into ascending/descending order
 *  =======================================
 *  WARNING: This is an in-place operation
 *  =======================================
 *
 * Params
 * ----------------------------
 *  *list       the list to sort
 *  reverse     true if wanting list to be sorted in descending order, false for ascending order
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_sort(List *list, bool reverse);

/*
 *
 * Description
 * ----------------------------
 *  Reverse the elements in the list
 *  =======================================
 *  WARNING: This is an in-place operation
 *  =======================================
 *
 * Params
 * ----------------------------
 *  *list       the list to reverse elements in
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_reverse(List *list);

/*
 *
 * Description
 * ----------------------------
 *  Return a shallow copy of the given list
 *
 * Params
 * ----------------------------
 *  *list       the list to copy
 *
 * Returns
 * ----------------------------
 *  List (Pointer to List)
 */
List *List_copy(List *list);

/*
 *
 * Description
 * ----------------------------
 *  Empty the given list
 *  =======================================================================
 *  WARNING: This does NOT free the allocated memory for elements cleared.
 *  =======================================================================
 *
 * Params
 * ----------------------------
 *  *list       the list to clear
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_clear(List *list);

/*
 *
 * Description
 * ----------------------------
 *  Return a sublist of the given list according to given indexes
 *
 * Params
 * ----------------------------
 *  *list           the list to slice
 *  start_index     the starting index to slice from (inclusive)
 *  end_index       the ending index to slice until (exclusive)
 *
 * Example
 * ----------------------------
 *  Given List -> [0, 1, 2, 3, 4, 5]
 *  When List_slice(list, 1, 4);
 *  Then List Returned -> [1, 2, 3]
 *
 * Returns
 * ----------------------------
 *  List (Pointer To List)
 */
List *List_slice(List *list, int start_index, int end_index);

/*
 *
 * Description
 * ----------------------------
 *  Extend the given list_to_extend with elements from given input_list
 *
 * Params
 * ----------------------------
 *  *list_to_extend     the list to extend with elements from input_list
 *  *input_list         the list containing elements to insert into list_to_extend
 *
 *  Example
 * ----------------------------
 *  Given list1 -> [1, 2] AND list2 -> [3, 4, 5]
 *  When List_extend(list1, list2);
 *  Then list1 -> [1, 2, 3, 4, 5]
 *
 * Returns
 * ----------------------------
 *  int (0 for success, Non-0 for error)
 */
int List_extend(List *list_to_extend, List *input_list);

/*
 *
 * Description
 * ----------------------------
 *  Return the length of the given list
 *
 * Params
 * ----------------------------
 *  *list       the list to get the length of
 *
 * Returns
 * ----------------------------
 *  int
 */
int List_length(List *list);

/*
 *
 * Description
 * ----------------------------
 *  Return the maxLength (current maximum length allocated in memory) of the given list
 *
 * Params
 * ----------------------------
 *  *list       the list to get the maximum length of
 *
 * Returns
 * ----------------------------
 *  int
 */
int List_max_length(List *list);

/*
 *
 * Description
 * ----------------------------
 *  Print out the current elements within the given list
 *
 * Params
 * ----------------------------
 *  *list       the list to print out
 *  new_line    true if wanting to print on a new line, false if not
 *
 * Returns
 * ----------------------------
 *  void
 */
void List_print(List *list, bool new_line);

/*
 *
 * Description
 * ----------------------------
 *  Free the memory allocated to the list
 *
 * Params
 * ----------------------------
 *  **list      a pointer to the list to free in memory
 *
 * Returns
 * ----------------------------
 *  void
 */
void List_destroy(List **list);