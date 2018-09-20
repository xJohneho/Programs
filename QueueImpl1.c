/*
 * C Program to Implement a Queue using an Array
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * The queue adds to the end of the array
 * Dequeue - the element at the start of the queue is serviced
 * This queue does not fill serviced queue positions
 * Dumb queue
 *
 */


#define MAX 5
int queue_array[MAX];
int end = - 1;
int start = - 1;

void enqueue()
{
    int add_item;
    if (end == MAX - 1){
    	printf("Queue Overflow \n");
    }
    else
    {
        if (start == - 1){
        /*If queue is initially empty */
        	start = 0;
        }
        printf("Enter integer to add to queue : ");
        scanf("%d", &add_item);
        end = end + 1;
        queue_array[end] = add_item;
    }
} /*End of insert()*/

void dequeue()
{
    if (start == - 1 || start > end)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[start]);
        start = start + 1;
    }
} /*End of delete() */
void display()
{
    int i;
    if (start == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = start; i <= end; i++)
        	printf(" %d:  %d \t", i, queue_array[i]);
        printf("\n");
    }
} /*End of display() */

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } /*End of switch*/
    } /*End of while*/
    return 1;
} /*End of main()*/
