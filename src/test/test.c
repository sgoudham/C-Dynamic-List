#include "src/list.h"
#include "string.h"
#include "assert.h"

void printSuccess(const char method[]) {
    unsigned long strLength = 18 + strlen(method);
    char message[strLength];

    strcpy(message, "\n");
    strcat(message, method);
    strcat(message, " --> TEST PASSED");
    printf("%s", message);
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

void shouldInsertElementIntoListIndexZero() {
    // Arrange
    List *list = List_new();
    List_append(list, 1);

    // Act
    List_insert(list, 0, 0);

    // Assert
    assert(List_get(list, 0) == 0);
    List_destroy(&list);

    printSuccess(__func__);
}

void shouldCopyEmptyList() {
    // Arrange
    List *list = List_new();

    // Act
    List *copiedList = List_copy(list);

    // Assert
    assert(List_length(copiedList) == 0);
    assert(List_maxLength(copiedList) == 10);
    List_destroy(&list);
    List_destroy(&copiedList);

    printSuccess(__func__);
}

void shouldRemoveElementFromList() {
    // Arrange
    List *list = List_new();
    List_append(list, 0);
    List_append(list, 1);
    List_append(list, 2);
    List_append(list, 0);

    // Act
    List_remove(list, 0);

    // Assert
    assert(List_length(list) == 3);
    assert(List_get(list, 0) == 1);
    assert(List_get(list, 1) == 2);
    assert(List_get(list, 2) == 0);
    List_destroy(&list);

    printSuccess(__func__);
}

int main() {
    printf("============================================");
    printf("\nSTART TESTING");
    printf("\n============================================\n");
    shouldReturnListLengthZero();
    shouldReturnListLengthTwo();
    shouldReturnSortedList();
    shouldClearList();
    shouldReturnListMaxLengthTwenty();
    shouldCopyPopulatedList();
    shouldCopyEmptyList();
    shouldInsertElementIntoListIndexZero();
    shouldRemoveElementFromList();
    printf("\n\n============================================");
    printf("\nFINISH TESTING");
    printf("\n============================================");
    return 0;
}


