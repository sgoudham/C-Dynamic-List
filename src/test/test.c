#include "src/list.h"
#include "string.h"
#include "assert.h"

void printSuccess(const char method[]) {
    unsigned long strLength = 18 + strlen(method);
    char message[strLength];

    printf("\n------------------------------");
    strcpy(message, "\n");
    strcat(message, method);
    strcat(message, " --> TEST PASSED");
    printf("%s", message);
    printf("\n------------------------------");
}

void shouldReturnListLengthZero() {
    // Arrange
    List *list = List_new();

    // Act -> Assert
    assert(List_length(list) == 0);
    List_destroy(&list);

    printSuccess(__func__);
}

void shouldReturnListLengthTwo() {
    // Arrange
    List *list = List_new();
    List_append(list, 1);
    List_append(list, 2);

    // Act -> Assert
    assert(List_length(list) == 2);
    List_destroy(&list);

    printSuccess(__func__);
}

void shouldReturnSortedList() {
    // Arrange
    List *list = List_new();
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
    for (int i = 0; i < List_length(list); i++) {
        assert(List_get(list, i) == i);
    }
    List_destroy(&list);

    printSuccess(__func__);
}

void shouldClearList() {
    // Arrange
    List *list = List_new();
    List_append(list, 0);
    List_append(list, 1);
    List_append(list, 2);
    List_append(list, 3);

    // Act
    List_clear(list);

    // Assert
    assert(List_length(list) == 0);
    List_destroy(&list);

    printSuccess(__func__);
}

void shouldReturnListMaxLengthTwenty() {
    // Arrange
    List *list = List_new();
    List_append(list, 0);
    List_append(list, 1);
    List_append(list, 2);
    List_append(list, 3);
    List_append(list, 4);
    List_append(list, 5);
    List_append(list, 6);
    List_append(list, 7);
    List_append(list, 8);
    List_append(list, 9);

    // Mid-Assert
    assert(List_maxLength(list) == 10);

    // Act
    List_append(list, 10);

    // Assert
    assert(List_maxLength(list) == 20);
    List_destroy(&list);

    printSuccess(__func__);
}

void shouldCopyPopulatedList() {
    // Arrange
    List *list = List_new();
    List_append(list, 0);
    List_append(list, 1);
    List_append(list, 2);
    List_append(list, 3);
    List_append(list, 4);

    // Act
    List *copiedList = List_copy(list);

    // Assert
    assert(List_length(copiedList) == List_length(list));
    assert(List_maxLength(copiedList) == List_maxLength(list));
    for (int i = 0; i < List_length(copiedList); i++) {
        assert(List_get(list, i) == List_get(copiedList, i));
    }
    List_destroy(&list);
    List_destroy(&copiedList);

    printSuccess(__func__);
}

int main() {
    shouldReturnListLengthZero();
    shouldReturnListLengthTwo();
    shouldReturnSortedList();
    shouldClearList();
    shouldReturnListMaxLengthTwenty();
    shouldCopyPopulatedList();
    return 0;
}

