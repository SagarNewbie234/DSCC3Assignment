#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 3

typedef struct queue{
    int queue[MAX];
    int front, rear;
} Queue;

Queue CreateQueue(){
    Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int Enqueue(Queue* q, int data){
    if(q->rear == MAX - 1){
        printf("EXCEPTION : Queue Full! Insertion Not Possible\n");
        return 0;
    }else{
        if(q->front == -1) q->front++;
        q->rear++;
        q->queue[q->rear] = data;
        return 1;
    }
}

int Dequeue(Queue* q){
    if(q->front == -1){
        printf("EXCEPTION : Queue Empty! Deletion Not Possible\n");
        return INT_MIN;
    }else{
        int data = q->queue[q->front];
        if(q->front == q->rear){
            q->front = -1;
            q->rear = -1;
        }else{
            q->front++;
        }
        return data;
    }
}

void Display(Queue* q){
    if(q->front == -1){
        printf("Empty Queue\n");
    }else{
        printf("F -> ");
        for(int i = q->front; i <= q->rear; i++){
            printf("%d ", q->queue[i]);
        }
        printf("<- R\n");
    }
}

int main(){
    printf("************ Queue Operations **********\n");
    int choice, temp;
    Queue queue = CreateQueue();
    while(1){
        printf("\nMENU [max size %d] -\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\nSelect Operation : ", MAX);
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Data : ");
                scanf("%d", &temp);
                if(Enqueue(&queue, temp)){
                    printf("INFO : Succesfully Inserted Data (%d)\n", temp);
                }
                break;
            case 2:
                temp = Dequeue(&queue);
                if(temp != INT_MIN){
                    printf("INFO : Succesfully Deleted Data (%d)\n", temp);
                }
                break;
            case 3:
                Display(&queue);
                break;
            case 4:
                printf("INFO : Program Exit!\n");
                exit(0);
            default:
                printf("ERROR : Invalid Operation Selected!");
        }
    }

}