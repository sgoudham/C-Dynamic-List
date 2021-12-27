#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

typedef struct list List;

/*
 * Function: List_new()
 * ----------------------------
 *  Return a new list that has been dynamically allocated memory on the heap
 *
 *  returns: List (Pointer To List)
 */
List *List_new();

/*
 * Function: List_get(List *list, int index)
 * ----------------------------
 *  Retrieve an element from the list at the given index
 *
 *  *list: the list to append onto
 *  index: the index of the list to retrieve
 *
 *  returns: int (0 for success, Non-0 for error)
 */
int List_get(List *list, int index);

/*
 * Function: List_append(List *list, int element)
 * ----------------------------
 *  Append an element onto the end of the list
 *
 *  *list: the list to append onto
 *  element: the element to insert into the list
 *
 *  returns: int (0 for success, Non-0 for error)
 */
int List_append(List *list, int element);

/*
 * Function: List_append_all(List *list, int element_count, ...)
 * ----------------------------
 *  Append multiple elements into the given list
 *
 *  *list: the list to append onto
 *  element_count: number of elements to append into the given list
 *  ...: variable list of integers to append into the given list
 *
 *  returns: int (0 for success, Non-0 for error)
 */
int List_append_all(List *list, int element_count, ...);

/*
 * Function: List_insert(List *list, int index, int element)
 * ----------------------------
 *  Insert the given element into a valid index of the list
 *
 *  *list: the list to insert into
 *  index: the index to insert the given value
 *  element: the element to insert into the list
 *
 *  returns: int (0 for success, Non-0 for error)
 */
int List_insert(List *list, int index, int element);

/*
 * Function: List_remove(List *list, int element)
 * ----------------------------
 *  Remove the first occurrence of the given element from the given list
 *
 *  *list: the list to remove given element from
 *  element: the element to remove from the given list
 *
 *  returns: int (0 for success, Non-0 for error)
 */
int List_remove(List *list, int element);

/*
 * Function: List_sort(List *list, bool reverse)
 * ----------------------------
 *  Sort the given list into ascending/descending order
 *
 *  ==============================
 *  WARNING: This is an in-place operation
 *  ==============================
 *
 *  *list: the list to sort
 *  reverse: true if wanting list to be sorted in descending order, false for ascending order
 *
 *  returns: int (0 for success, Non-0 for error)
 */
int List_sort(List *list, bool reverse);

/*
 * Function: List_copy(List *list)
 * ----------------------------
 *  Return a shallow copy of the given list
 *
 *  *list: the list to copy
 *
 *  returns: List (Pointer to List)
 */
List *List_copy(List *list);

/*
 * Function: List_clear
 * ----------------------------
 *  Empty the given list
 *
 *  =======================================================================
 *  WARNING: This does NOT free the allocated memory for elements cleared.
 *  =======================================================================
 *
 *  *list: the list to clear
 *
 *  returns: int (0 for success, Non-0 for error)
 */
int List_clear(List *list);

/*
 * Function: List_slice(List *list, int start_index, int end_index)
 * ----------------------------
 *  Return a sublist of the given list according to given indexes
 *
 *  *list: the list to slice
 *  start_index: the starting index to slice from (inclusive)
 *  end_index: the ending index to slice until (exclusive)
 *
 *  =================================
 *  E.g
 *  Given List -> [0, 1, 2, 3, 4, 5]
 *  When List_slice(list, 1, 4);
 *  Then List Returned -> [1, 2, 3]
 *  =================================
 *
 *  returns: List (Pointer To List)
 */
List *List_slice(List *list, int start_index, int end_index);

/*
 * Function: List_length(List *list)
 * ----------------------------
 *  Return the length of the given list
 *
 *  *list: the list to get the length of
 *
 *  returns: int
 */
int List_length(List *list);

/*
 * Function: List_max_length(List *list)
 * ----------------------------
 *  Return the maxLength (current maximum length allocated in memory) of the given list
 *
 *  *list: the list to get the maximum length of
 *
 *  returns: int
 */
int List_max_length(List *list);

/*
 * Function: List_print(List *list)
 * ----------------------------
 *  Print out the current elements within the given list
 *
 *  *list: the list to print out
 *
 *  returns: void
 */
void List_print(List *list);

/*
 * Function: List_destroy(List *list)
 * ----------------------------
 *  Free the memory allocated to the list
 *
 *  **list: a pointer to the list to free in memory
 *
 *  returns: void
 */
void List_destroy(List **list);