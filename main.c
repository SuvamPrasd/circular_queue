#include <stdio.h>
#include <stdlib.h>
#define size 20
int front=-1, rear=-1, queue[size];

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
if((front==0 && rear==size-1)){
    printf("\nQueue is full");
}
else if(rear==-1){
    rear++;
    front++;
}
else{
    rear++;
}
queue[rear]=val;
}

void dequ(){
if(front==-1){
    printf("\nQueue is empty");
}
else if(front==rear){
    printf("\nDeleted element is %d",queue[front]);
    front=rear=-1;
}
else{
    printf("\ndeleted element is %d", queue[front]);
    front++;
}
}

void display(){
    int i;
if(front==-1){
    printf("\nQueue is empty !!!");
}
else{
    for(i=front; i<=rear; i++){
        printf("%d-->",queue[i]);
    }
}
}
