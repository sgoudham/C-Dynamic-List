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

void shouldReturnSortedListInAscendingOrder() {
    // Arrange
    List *list = List_new();
    List_append_all(list, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);

    // Act
    int returnCode = List_sort(list, false);

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
    List_append_all(list, 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

    // Mid-Assert
    assert(List_max_length(list) == 10);

    // Act
    List_append(list, 10);

    // Assert
    assert(List_max_length(list) == 20);

    List_destroy(&list);
    printSuccess(__func__);
}

void shouldCopyPopulatedList() {
    // Arrange
    List *list = List_new();
    List_append_all(list, 5, 0, 1, 2, 3, 4);

    // Act
    List *copiedList = List_copy(list);

    // Assert
    assert(List_length(copiedList) == List_length(list));
    assert(List_max_length(copiedList) == List_max_length(list));
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
    assert(List_max_length(copiedList) == 10);

    List_destroy(&list);
    List_destroy(&copiedList);
    printSuccess(__func__);
}

void shouldRemoveElementFromList() {
    // Arrange
    List *list = List_new();
    List_append_all(list, 4, 0, 1, 2, 0);

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

void shouldReverseList() {
    // Arrange
    List *list = List_new();
    List_append_all(list, 5, 50, 100, 75, 200, 300);

    // Act
    int returnCode = List_reverse(list);

    // Assert
    assert(returnCode == 0);
    assert(List_get(list, 0) == 300);
    assert(List_get(list, 1) == 200);
    assert(List_get(list, 2) == 75);
    assert(List_get(list, 3) == 100);
    assert(List_get(list, 4) == 50);

    List_destroy(&list);
    printSuccess(__func__);
}

void shouldExtendList() {
    // Arrange
    List *list_to_extend = List_new();
    List *input_list = List_new();
    List_append_all(list_to_extend, 2, 1, 2);
    List_append_all(input_list, 3, 3, 4, 5);

    // Act
    int returnCode = List_extend(list_to_extend, input_list);

    // Assert
    assert(returnCode == 0);
    assert(List_length(list_to_extend) == 5);
    for (int i = 0; i < 5; i++) {
        assert(List_get(list_to_extend, i) == i + 1);
    }

    List_destroy(&list_to_extend);
    List_destroy(&input_list);
    printSuccess(__func__);
}

void shouldDeleteElementFromList() {
    // Arrange
    List *list = List_new();
    List_append_all(list, 6, 0, 1, 2, 3, 4, 5);

    // Act
    int deletedElement = List_delete(list, 1);

    // Assert
    assert(deletedElement == 1);
    assert(List_length(list) == 5);
    assert(List_get(list, 0) == 0);
    assert(List_get(list, 1) == 2);
    assert(List_get(list, 2) == 3);
    assert(List_get(list, 3) == 4);
    assert(List_get(list, 4) == 5);

    List_destroy(&list);
    printSuccess(__func__);
}

void shouldPopElementFromList() {
    // Arrange
    List *list = List_new();
    List_append_all(list, 6, 0, 1, 2, 3, 4, 5);

    // Act
    int poppedElement = List_pop(list);

    // Assert
    assert(poppedElement == 5);
    assert(List_length(list) == 5);
    for (int i = 0; i < 5; i++) {
        assert(List_get(list, i) == i);
    }

    List_destroy(&list);
    printSuccess(__func__);
}

void shouldCountElementsInList() {
    // Arrange
    List *list = List_new();
    List_append_all(list, 5, 0, 1, 1, 3, 4, 5);

    // Act
    int count = List_count(list, 1);

    // Assert
    assert(count == 2);

    List_destroy(&list);
    printSuccess(__func__);
}

int main() {
    printf("============================================");
    printf("\nSTART TESTING");
    printf("\n============================================\n");
    shouldReturnListLengthZero();
    shouldReturnListLengthTwo();
    shouldReturnSortedListInAscendingOrder();
    shouldClearList();
    shouldReturnListMaxLengthTwenty();
    shouldCopyPopulatedList();
    shouldCopyEmptyList();
    shouldInsertElementIntoListIndexZero();
    shouldRemoveElementFromList();
    shouldReverseList();
    shouldExtendList();
    shouldDeleteElementFromList();
    shouldPopElementFromList();
    shouldCountElementsInList();
    printf("\n\n============================================");
    printf("\nFINISH TESTING");
    printf("\n============================================");
    return 0;
}


