#include "sort.h"
void swap(listint_t **list, listint_t *node1, listint_t *node2);
/**
 * insertion_sort_list - Function to sort the doubly linked list
 * @list: The head of the list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *forward, *temp;

    if (*list == NULL || list == NULL || (*list)->next == NULL)
    {
        return;
    }
    forward = (*list)->next;
    while (forward && forward->prev != NULL)
    {
        while (forward->prev && forward && forward->n < forward->prev->n)
        {
            temp = forward->prev;
            swap(list, temp, forward);
            print_list(*list);
            forward = forward->next;
            forward = forward->prev;
        }
        forward = forward->next;
    }
}
/**
* swap - swap the two nodes
* @list: the head of the node
* @node1: The the temporary node
* @node2: The forward node
* Return: void
*/
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *next, *prev;

    next = node2->next;
    prev = node1->prev;
    if (prev != NULL)
    {
        prev->next = node2;
    }
    else
    {
        *list = node2;
    }
    node1->prev = node2;
    node1->next = next;
    node2->prev = prev;
    node2->next = node1;
    if (next)
    {
        next->prev = node1;
    }
}
