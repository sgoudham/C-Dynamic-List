#include "list.h"
#include "pthread.h"

/*
 * -- ERROR CODES --
 *
 * [ERRNO 2147483646] -> Cannot Allocate Memory To Backing Array
 * [ERRNO 2167483645] -> Cannot Reallocate Memory To Backing Array
 * [ERRNO 2147483644] -> Index Out Of Bounds For Retrieving Element
 * [ERRNO 2147483643] -> Values 2147483646 -> 2147483642 Cannot Be Inserted Into List
 * [ERRNO 2147483642] -> Element Does Not Exist Within List
 */

List *List_createList(int maxSize, int currentSize);

int List_merge(List *list, int start_index, int mid_index, int end_index);

int List_mergeSort(List *list, int start_index, int end_index);

typedef struct list {
    int *_array;
    int _currentSize;
    int _maxSize;
    pthread_mutex_t simpleMutex;
} List;

int errorCodes[ERRNO_SIZE] = {
        ERRNO_001,
        ERRNO_002,
        ERRNO_003,
        ERRNO_004,
        ERRNO_005
};

List *List_new() {
    List *list = List_createList(10, -1);
    if (!list) {
        return NULL;
    }
    pthread_mutex_init(&list->simpleMutex, NULL);
    return list;
}

int List_get(List *list, int index) {
    if (index < 0 || index > list->_currentSize) {
        return ERRNO_003;
    }
    return list->_array[index];
}

int List_append(List *list, int element) {
    for (int i = 0; i < ERRNO_SIZE; i++) {
        if (element == errorCodes[i]) {
            return ERRNO_004;
        }
    }

    // Beginning of Critical Section
    pthread_mutex_lock(&(list->simpleMutex));
    printf("\nMutex Locked!");

    if (list->_currentSize + 1 == list->_maxSize) {
        list->_maxSize *= 2;
        int *temp = realloc(list->_array, list->_maxSize * sizeof(int));
        if (!temp) {
            return ERRNO_002;
        }
        list->_array = temp;
    }
    list->_array[++list->_currentSize] = element;

    // End of Critical Section
    pthread_mutex_unlock(&(list->simpleMutex));
    printf("\nMutex Unlocked!");

    return 0;
}

int List_insert(List *list, int index, int element) {
    if (index < 0 || index > list->_currentSize) {
        return ERRNO_003;
    }
    int previous_element = list->_array[index];
    list->_array[index] = element;
    return previous_element;
}

int List_remove(List *list, int element) {
    int positionToDelete = -1;
    for (int i = 0; i < list->_currentSize + 1; i++) {
        if (list->_array[i] == element) {
            positionToDelete = i;
        }
    }

    if (positionToDelete == -1) {
        return ERRNO_005;
    }

    for (int i = positionToDelete; i < list->_currentSize + 1; i++) {
        list->_array[i] = list->_array[i + 1];
    }
    list->_currentSize--;

    return 0;
}

int List_merge(List *list, int start_index, int mid_index, int end_index) {
    List *left = List_slice(list, start_index, mid_index + 1);
    if (!left) {
        return 1;
    }
    List *right = List_slice(list, mid_index + 1, end_index + 1);
    if (!right) {
        return 1;
    }

    int leftSuccessCode = List_append(left, INT_MAX);
    if (leftSuccessCode != 0) {
        return 1;
    }
    int rightSuccessCode = List_append(right, INT_MAX);
    if (rightSuccessCode != 0) {
        return 1;
    }

    int left_index = 0;
    int right_index = 0;

    for (int i = start_index; i < end_index + 1; i++) {
        if (left->_array[left_index] < right->_array[right_index]) {
            list->_array[i] = left->_array[left_index];
            left_index++;
        } else {
            list->_array[i] = right->_array[right_index];
            right_index++;
        }
    }

    List_destroy(&left);
    List_destroy(&right);

    return 0;
}

int List_mergeSort(List *list, int start_index, int end_index) {
    if (start_index < end_index) {
        int mid_index = (start_index + end_index) / 2;
        if (List_mergeSort(list, start_index, mid_index) != 0) {
            return 1;
        }
        if (List_mergeSort(list, mid_index + 1, end_index) != 0) {
            return 1;
        }
        if (List_merge(list, start_index, mid_index, end_index) != 0) {
            return 1;
        }
    }

    return 0;
}


int List_sort(List *list) {
    return List_mergeSort(list, 0, list->_currentSize);
}

List *List_copy(List *list) {
    List *listCopy = List_createList(list->_maxSize, list->_currentSize);
    if (!listCopy) {
        return NULL;
    }

    for (int i = 0; i < list->_currentSize + 1; i++) {
        listCopy->_array[i] = list->_array[i];
    }

    return listCopy;
}

List *List_slice(List *list, int start_index, int end_index) {
    if (start_index >= end_index) {
        return NULL;
    }

    int slicedCurrentSize = end_index - start_index;
    int slicedMaxSize = slicedCurrentSize * 2;
    List *slicedList = List_createList(slicedMaxSize, slicedCurrentSize - 1);
    if (!slicedList) {
        return NULL;
    }

    int i = 0;
    for (int j = start_index; j < end_index; j++) {
        slicedList->_array[i] = list->_array[j];
        i++;
    }

    return slicedList;
}

int List_length(List *list) {
    return list->_currentSize + 1;
}

void List_print(List *list) {

    // Beginning Of Critical Section
    pthread_mutex_lock(&(list->simpleMutex));

    printf("[");
    for (int i = 0; i < list->_currentSize + 1; i++) {
        if (i == list->_currentSize) {
            printf("%i", list->_array[i]);
        } else {
            printf("%i, ", list->_array[i]);
        }
    }
    printf("]");

    // End Of Critical Section
    pthread_mutex_unlock(&(list->simpleMutex));
}

void List_destroy(List **list) {
    free((*list)->_array);
    (*list)->_array = NULL;
    free(*list);
    *list = NULL;
}

List *List_createList(int maxSize, int currentSize) {
    List *list = malloc(sizeof(List));
    if (!list) {
        return NULL;
    }

    list->_array = calloc(maxSize, sizeof(int));
    if (!list->_array) {
        free(list);
        return NULL;
    }

    list->_maxSize = maxSize;
    list->_currentSize = currentSize;

    return list;
}