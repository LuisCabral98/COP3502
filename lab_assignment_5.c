#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function will return "abc"
char* toCString(node* head) {
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char)); // +1 for null terminator
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len; i++) {
        str[i] = head->letter;
        head = head->next;
    }
    str[len] = '\0'; // Null terminator
    return str;
}

// inserts character to the linkedlist
// If the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {
    if (*pHead == NULL) {
        *pHead = (node*)malloc(sizeof(node));
        if (*pHead == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        (*pHead)->letter = c;
        (*pHead)->next = NULL;
    } else {
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (node*)malloc(sizeof(node));
        if (current->next == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        current->next->letter = c;
        current->next->next = NULL;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {
    node* current = *pHead;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    *pHead = NULL; // Update the head to NULL after deleting all nodes
}

int main(void) {
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);

    return 0;
}
