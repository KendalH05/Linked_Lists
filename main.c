

#include <stdio.h>
#include "list.h"

int main() {
	printf("Tests for linked list implementation.\n");
    printf("We assume index starts from 0.\n\n");
	list_t *list = list_alloc();
	list_add_to_front(list,4);
    printf("Add %d to the front of the list: ", 4);
    list_print(list);
    
	list_add_to_front(list,9);
    printf("Add %d to the front of the list: ", 9);
    list_print(list);
    
	list_add_to_back(list,3);
    printf("Add %d to the back of the list: ", 3);
    list_print(list);
    
	list_add_to_back(list,7);
    printf("Add %d to the back of the list: ", 7);
    list_print(list);
    
	list_add_at_index(list,7,3);
    printf("Add %d at index %d: ",7,3);
    list_print(list);
    
	list_add_to_back(list, 4);
    printf("Add %d to the back of the list: ", 4);
    list_print(list);
    
	list_add_to_front(list,12);
    printf("Add %d to the front: ", 12);
    list_print(list);
    
	list_add_at_index(list,8,1);
    printf("Add %d at index %d: ", 8,1);
    list_print(list);
    
	
	elem element1 = list_remove_from_front(list);
    printf("\nRemoved %d from the front: ", element1);
    list_print(list);
    
	elem element2 = list_remove_at_index(list, 5);
    printf("Removed %d from the index, %d: ", element2, 5);
    list_print(list);
    
	elem element3 = list_remove_from_back(list);
    printf("Removed %d from the back: ", element3);
	list_print(list);
	
	int len = list_length(list);
	printf("\nLength of the list is: %d.\n", len);
	
	elem num = 10;
	bool exist = list_is_in(list, num);
	if (exist){
		printf("%d is in the list.\n", num);
	} else {
		printf("%d is not in the list.\n", num);
	}
	
	int index1 = 2;
	elem element4 = list_get_elem_at(list, index1);
	printf("Element at index %d is: %d. \n", index1, element4);
	
	elem element5 = 6;
	int index2 = list_get_index_of(list,element5);
	printf("Element %d is at index: %d. \n", element5, index2);
	
	list_free(list);
	return 0;
}


