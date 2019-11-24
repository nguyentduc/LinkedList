
struct linked_list{
    char *data;
    int index; /* position of the element in the list, normally not used with Linked Lists, just for exercise */
    struct linked_list *next;
};
typedef struct linked_list linked_list;

int add_to_list(linked_list *list, char *s);
int display_item(linked_list *list);
int display_list(linked_list *list);
linked_list * search_from_list(linked_list *list, char *s);
int delete_from_list(linked_list *list, int index);
int move(linked_list* list );