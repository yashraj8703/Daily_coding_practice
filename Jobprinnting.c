#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Job{
    char doc_name[50];
    int pages;
};

struct Job* createJob(char doc_name[], int pages)
{
    struct Job* newJob=(struct Job*)malloc(sizeof(struct Job));
    strcpy(newJob->doc_name,doc_name);
    newJob->pages=pages;
    return newJob;
}
struct Queue{
    int size;
    int front;
    int rear;
    struct Job*jobarray;
};
struct Queue* createQueue(int size){
    struct Queue * Queue=(struct Queue*)malloc(sizeof(struct Queue));
    Queue->front=-1;
    Queue->size=size;
    Queue->rear=-1;
    Queue->jobarray=(struct Job*)malloc(size*sizeof(struct Job));
    return Queue;
}
int isFull(struct Queue* Queue)
{
    return Queue->rear==Queue->size-1;
}
int isEmpty(struct Queue * Queue)
{
    return Queue->front==-1;
}

void enqueue(struct Queue * Queue,struct Job* newJob)
{
    if(isFull(Queue))
    {
        return;
    }
    if(Queue->front==-1)
    {
        Queue->front=0;
    }
    Queue->rear++;
    
    Queue->jobarray[Queue->rear]=*newJob;
}
struct Job dequeue(struct Queue * Queue)
{
    if (isEmpty(Queue)) {
        printf("Queue is empty\n");
        struct Job emptyJob = {"", 0};
        return emptyJob;
    }
    struct Job val = Queue->jobarray[Queue->front];
    Queue->front++;
    if (Queue->front > Queue->rear) {
        Queue->front = Queue->rear = -1;
    }
    return val;
}
struct Job peek(struct Queue * Queue)
{
   if (isEmpty(Queue)) {
        printf("Queue is empty\n");
        struct Job emptyJob = {"", 0};
        return emptyJob;
    }
    struct Job value=Queue->jobarray[Queue->front];
    return value;
}
void viewPendingJobs(struct Queue* Queue)
{
    if(isEmpty(Queue))
    {
        return;
    }
    for (int i = Queue->front; i <= Queue->rear; i++) {
        printf("Doc Name: %s, Pages: %d\n", Queue->jobarray[i].doc_name, Queue->jobarray[i].pages);
    }
}
void UpdateJob(struct Queue* Queue,int index,char newDocname[],int pages)
{
    strcpy(Queue->jobarray[index].doc_name,newDocname);
    Queue->jobarray[index].pages=pages;
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Add job\n");
    printf("2. Update job\n");
    printf("3. View pending jobs\n");
    printf("4. Dequeue job\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Queue* queue = createQueue(5);
    int choice, pages, index;
    char doc_name[50];

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc_name);
                printf("Enter number of pages: ");
                scanf("%d", &pages);
                {
                    struct Job* newJob = createJob(doc_name, pages);
                    enqueue(queue, newJob);
                }
                break;

            case 2:
                printf("Enter job index to update (0-based): ");
                scanf("%d", &index);
                printf("Enter new document name: ");
                scanf("%s", doc_name);
                printf("Enter new number of pages: ");
                scanf("%d", &pages);
                UpdateJob(queue, index, doc_name, pages);
                break;

            case 3:
                printf("Pending jobs:\n");
                viewPendingJobs(queue);
                break;

            case 4:
                {
                    struct Job removedJob = dequeue(queue);
                    if (removedJob.pages != 0) {
                        printf("Dequeued job - Doc Name: %s, Pages: %d\n", removedJob.doc_name, removedJob.pages);
                    }
                }
                break;

            case 5:
                printf("Exiting the program.\n");
                free(queue->jobarray);
                free(queue);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
