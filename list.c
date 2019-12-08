

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc() {
    list_t *list;
    list = malloc(sizeof(list_t));
	list->head = NULL;
    return list;
}

void list_free(list_t *list) {
    if (list == NULL)
    {
        return;
    }
    node_t *curr_node = list->head;
    node_t *next_node = NULL;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    list->head = NULL;
    free(list);
}

/* Prints the list in some format. */
void list_print(list_t *list) {
    node_t *curr_node = list->head;
    node_t *next_node = NULL;
    while (curr_node->next != NULL)
    {
        printf("%d -> ", curr_node->value);
        next_node = curr_node->next;
        curr_node = next_node;
    }
	printf("%d", curr_node->value);
	printf("\n");
}

/* Returns the length of the list. */
int list_length(list_t *list) { 
    
    node_t *curr_node = list->head;
    int len = 0;
    
    while (curr_node != NULL)
    {
        len ++;
        curr_node = curr_node->next;
    }
    return len; 
}

/* Methods for adding to the list. */
void list_add_to_back(list_t *list, elem value) {
    node_t *back_node = malloc(sizeof(node_t));
    back_node->value = value;
    back_node->next = NULL;
    node_t *curr_node = list->head;
    
    while (curr_node->next != NULL)
    {
        curr_node = curr_node->next;
    }
    curr_node->next = new_node;
}

void list_add_to_front(list_t *list, elem value) {
    
    node_t *front_node = malloc(sizeof(node_t));
    front_node->value = value;
    front_node->next = list->head;
	list->head = front_node;
    
}

void list_add_at_index(list_t *list, elem value, int index) {
    int count = 1;
    node_t *index_node = malloc(sizeof(node_t));
    index_node->value = value;
    index_node->next = NULL;
    node_t * curr_node = list->head;
    node_t* next_node = NULL;
    
    while (curr_node != NULL && count < (index))
    {
        count++;
        next_node = curr_node->next;
        curr_node = next_node;
    }
    next_node = curr_node->next;
    curr_node->next = index_node;
    index_node->next = next_node;
}

/* Methods for removing from the list. Returns the removed element. */
elem list_remove_from_back(list_t *list) { 
    
    node_t *prev_node = list->head;
	node_t *curr_node = prev_node->next;
    
    while (curr_node->next != NULL)
    {
		prev_node = curr_node;
        curr_node = curr_node->next;
    }
    
	prev_node->next = NULL;
    elem value = curr_node->value;
    free(curr_node);
    return value; 
}

elem list_remove_from_front(list_t *list) { 
    node_t *curr_node = list->head;
    list->head = curr_node->next;
    elem value = curr_node->value;
    free(curr_node);
    return value;
}

elem list_remove_at_index(list_t *list, int index) { 
    int count = 0;
    node_t *prev_node = list->head;
	node_t *curr_node = prev_node->next;
    while (curr_node->next != NULL && count < (index - 1))
    {
        count++;
		prev_node = curr_node;
        curr_node = curr_node->next;
    }
    node_t *temp = curr_node;
    prev_node->next = curr_node->next;
    elem value = temp->value;
    free(temp);
    return value;
}

/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *list, elem value) {
	bool exist;
    node_t *curr_node = list->head;
    while (curr_node->next != NULL && !exist)
    {
		if (curr_node->value == value){
			exist = true;
		}
        curr_node = curr_node->next;
    }
    return exist; 
}

/* Returns the element at the given index. */
elem list_get_elem_at(list_t *list, int index) {
	int count = 0;
	elem value = 0;
	node_t *curr_node = list->head;
    while (curr_node->next != NULL && count < (index))
    {
		count++;
        curr_node = curr_node->next;
    }
	if (curr_node != NULL){
		value = curr_node->value;
	}
	return value; 
}

/* Returns the index at which the given element appears. */
int list_get_index_of(list_t *list, elem value) {
	int count = 0;
	node_t *curr_node = list->head;
    while (curr_node->next != NULL)
    {
		if (curr_node->value == value){
			return count;
		} else {
			count++;
			curr_node = curr_node->next;
		}
    }
	return count; 
}