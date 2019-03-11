#include <stdio.h>
#include <stdlib.h>

struct cqueue{
int data;
struct cqueue *next;
}*front=NULL,*rear=NULL,*temp;

void enq(int);
void dequ(void);
void display(void);

int main()
{
       int ch, val;
    while(1){
    printf("\n------------------------MENU-----------------------");
    printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit");
    printf("\n---------------------------------------------------");
    printf("\nEnter the choice: ");
    scanf("%d",&ch);
    switch(ch){
    case 1: printf("\nEnter the data: ");
    scanf("%d",&val);
    enq(val);
    break;
    case 2: dequ();
    break;
    case 3: display();
    break;
    case 4: exit(0);
    break;
    default: printf("\nInvalid Choice !!!");
    break;
    }
    }
    return 0;
}

void enq(int val){
struct cqueue *newNode = (struct cqueue*)malloc(sizeof(struct cqueue));
newNode->data=val;
newNode->next=NULL;
if(rear==NULL){
    front=rear=newNode;
}
else{
    rear->next=newNode;
    rear=newNode;
}
rear->next=front;
}

void dequ(){
temp=front;
if(front==NULL){
    printf("\nqueue is empty !!!");
}
else{
    if(front==rear){
        printf("\n%d",front->data);
        front=rear=NULL;
    }
    else{
        printf("\n%d",front->data);
        front=front->next;
        rear->next=front;
    }
    temp->next=NULL;
    free(temp);
}
}

void display(){
temp=front;
if(front==NULL && rear==NULL){
    printf("\nQueue is empty !!!");
    exit(0);
}
else{
    while(temp->next!=front){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
        printf("%d",rear->data);
}
