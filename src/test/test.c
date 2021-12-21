#include "src/list.h"
#include "string.h"
#include "assert.h"

void printSuccess(const char method[]) {
    printf("\n------------------------------");
    char message[100] = "\n";
    strcat(message, method);
    strcat(message, " --> TEST PASSED");
    printf("%s", message);
    printf("\n------------------------------");
}

void shouldReturnListLengthZero() {
    // Arrange
    List *list = newList();

    // Act -> Assert
    assert(List_length(list) == 0);
    List_destroy(&list);

    printSuccess(__func__);
}

void shouldReturnListLengthTwo() {
    // Arrange
    List *list = newList();
    List_append(list, 1);
    List_append(list, 2);

    // Act -> Assert
    assert(List_length(list) == 2);
    List_destroy(&list);

    printSuccess(__func__);
}

void shouldReturnSortedList() {
    // Arrange
    List *list = newList();
    List_append(list, 10);
    List_append(list, 9);
    List_append(list, 8);
    List_append(list, 7);
    List_append(list, 6);
    List_append(list, 5);
    List_append(list, 4);
    List_append(list, 3);
    List_append(list, 2);
    List_append(list, 1);
    List_append(list, 0);

    // Act
    int returnCode = List_sort(list);

    // Assert
    assert(returnCode == 0);
    for (int i = 0; i < 11; i++) {
        assert(List_get(list, i) == i);
    }
    List_destroy(&list);

    printSuccess(__func__);
}

int main() {
    shouldReturnListLengthZero();
    shouldReturnListLengthTwo();
    shouldReturnSortedList();
    return 0;
}


