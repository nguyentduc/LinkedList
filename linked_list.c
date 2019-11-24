#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

int add_to_list(linked_list *list, char *s){

    // Check if pointer is NULL - return -1
    if(list == NULL || s == NULL)
        return -1;
    
    //find end of list
    linked_list* last = list;
	while(last->next != NULL)
		last = last->next;
	
    //Create a new element 
    linked_list* node;
    node = (struct linked_list*)malloc(sizeof(linked_list));
    
    //make link from last element to new element
    last->next = node;
    
    //add s to data item of new element
    node->data = s;

    //add NULL to new elements next
    node->next = NULL;

    //write new index (last+1) to new elements index
    node->index = last->index + 1;

    return node->index;
}

int display_item(linked_list *list){
    linked_list* node;
    node = list;

    if(list == NULL)
        return -1;
    
    printf("Index: %d \n", node->index);
    printf("Data: %s \n", node->data);
    
    return 0;
}

int display_list(linked_list *list){

    int count;

    if(list == NULL)
        return -1;

    //Print the head
    printf("Display List:\n");
    printf("Index: %d \n", list->index);
    printf("Data: %s \n", list->data);

    //Print elements    
    while( list != NULL){
        count = list->index;
        list = list->next;
        if(list == NULL)
            break;
        printf("Index: %d \n", list->index);
        printf("Data: %s \n", list->data);
    }
    return count;
}

linked_list* search_from_list(linked_list *list, char *s){
    linked_list* found = NULL;
    if(list == NULL)
        linked_list* found = NULL;
    
    if(list->next == NULL)
        return NULL;
    
    list = list->next;  // skip the head
    while(list != NULL){
        if(strcmp(s, list->data) == 0){
            found = list;
        }
        list = list->next;
    }
    return found;
}

int delete_from_list(linked_list* list, int index){
    int len = -1;

    if(list == NULL)
        return -1;
    
    //find delete node based on index
    
    while(list->next != NULL){
        if(list->next->index == index){
            len = 1;
            break;
        }
        list = list->next;
    }   // now list = previous node of delete node
    
    if(len == 1){
        //Link previous to after node
        list->next = list->next->next;
        len = list->index;  //in case delete last node
        //TODO: free meory of delete node
        //change index
        list = list->next;
        while(list != NULL){
            list->index -= 1;
            len = list->index;
            list = list->next;
        }
    }
    return len;
}
