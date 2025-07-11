//congo line
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char line[100];
    struct Node *next;
    struct Node *prev;
};
struct Node* head=NULL;
struct Node* tail=NULL;
struct Node* createNode(char line[]){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->line, line);
    newNode->next=NULL;
    return newNode;
}
void addperson(char line[]){
    struct Node* newNode=createNode(line);
    newNode->prev=tail;
    newNode->next=NULL;
    if(tail==NULL)
    {
        head=newNode;
    }
    else
    {
        tail->next=newNode;
    }
    tail=newNode;
}
void display(){
    if(head==NULL)
    {
        printf("\n No songs to play...");return;}
    struct Node* temp=tail;
    while(temp!=NULL){
        printf("%s ->",temp->line);
        temp=temp->prev;
    }printf("NULL");
}
int main()
{
    int choice;char person[100];
    while(1){printf("\nChoice 1: Add a person\nChoice 2: Display person\nChoice 3: Exit\nEnter your choice: ");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
            printf("Enter the person\n");
            fgets(person, sizeof(person), stdin);
            person[strcspn(person, "\n")] = 0; 
            addperson(person);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Exit the queues");
            exit(0);
        default:
            printf("Enter valid choice");
    }}
  return 0;
}
