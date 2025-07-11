#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char clue[100];
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(char clue[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->clue, clue);
    newNode->next = NULL;
    return newNode;
}
void addClueAtEnd(char clue[]) {
    struct Node* newNode = createNode(clue);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%s\n added to the hunt!\n", clue);
}
void displayHunt() {
    if (head == NULL) {
        printf("\nNo clues added yet!\n");
        return;
    }
    struct Node* temp = head;
    printf("\nStarting Scavenger Hunt\n");
    while (temp != NULL) {
        printf("%s->", temp->clue);
        temp = temp->next;
    }
    printf("Treasure Found!\n");
}
int main() {
    int choice;
    char clueText[100];
    while (1) {
        printf("\nMenu:\n1. Add Clue\n2. Display Hunt Path\n3. Exit\nEnter your choice:");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter clue: ");
                fgets(clueText, sizeof(clueText), stdin);
                clueText[strcspn(clueText, "\n")] = 0;
                addClueAtEnd(clueText);
                break;
            case 2:
                displayHunt();
                break;
            case 3:
                printf("Exiting the hunt. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.");
        }
    }
}
