//eliminating the kth player from the last elimination and played until one player is left
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
// Insert at end using head and tail double pointers
void insertEnd(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}
void makeCircular(struct Node* head, struct Node* tail) {
    if (head == NULL || tail == NULL)
        return;

    tail->next = head;
    head->prev = tail;
}
int solveJosephus(struct Node** head, int k) {
    struct Node* current = *head;
    int count;
    while (current->next != current) {
        count = 1;
        while (count < k) {
            current = current->next;
            count++;
        }
        printf("Player %d is eliminated\n", current->data);
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (current == *head)
            *head = current->next;

        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    printf("Player %d is the winner!\n", current->data);
    int winner = current->data;
    free(current);
    return winner;
}
int main() {
    int n, k;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    printf("Enter number of players: ");
    scanf("%d", &n);
    printf("Enter value of k: ");
    scanf("%d", &k);
    for (int i = 1; i <= n; i++) {
        insertEnd(&head, &tail, i);
    }
    makeCircular(head, tail);
    solveJosephus(&head, k);
    return 0;
}
