#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

struct LinkedList* createLinkedList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (list) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

void append(struct LinkedList* list, int item) {
    struct Node* newNode = createNode(item);
    if (newNode) {
        if (list->head == NULL) {
            list->head = newNode;
        } else {
            struct Node* current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        list->size++;
    } else {
        printf("Error: Memory allocation failed while appending.\n");
    }
}

void insert(struct LinkedList* list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Error: Invalid index for insertion.\n");
        return;
    }
    struct Node* newNode = createNode(item);
    if (newNode) {
        if (index == 0) {
            newNode->next = list->head;
            list->head = newNode;
        } else {
            struct Node* current = list->head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        list->size++;
        printf("Inserting an element at index %d: %d\n", index, item);
    } else {
        printf("Error: Memory allocation failed while inserting.\n");
    }
}

int getSize(struct LinkedList* list) {
    return list->size;
}

void removeElement(struct LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: Invalid index for removal.\n");
        return;
    }
    if (index == 0) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else {
        struct Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    list->size--;
    printf("Removing an element at index %d\n", index);
}

void set(struct LinkedList* list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Error: Invalid index for replacement.\n");
        return;
    }
    struct Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = item;
    printf("Replacing an element at index %d with %d\n", index, item);
}

int get(struct LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: Invalid index for retrieval.\n");
        return -1;
    }
    struct Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void printList(struct LinkedList* list) {
    printf("List: ");
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    struct LinkedList* list = createLinkedList();
    append(list, 10);
    append(list, 20);
    append(list, 30);
    append(list, 40);
    printList(list);
    insert(list, 2, 25);
    insert(list, 0, 5);
    printList(list);
    printf("Size of the list: %d\n", getSize(list));
    removeElement(list, 3);
    removeElement(list, 0);
    printList(list);
    set(list, 1, 15);
    printList(list);
    int value = get(list, 2);
    printf("Value at index 2: %d\n", value);
    printList(list);
    freeList(list);
    return 0;
}
