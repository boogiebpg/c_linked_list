#include <stdio.h>
#include <stdlib.h>

struct list_t {
  int data;
  struct list_t *next;
};

int is_empty_list(struct list_t* list);
struct list_t* list_init();
struct list_t* list_insert_front(struct list_t* list, int element);
struct list_t* list_insert_after(struct list_t* list, int element, int pos);
void list_insert_rear(struct list_t* list, int element);
struct list_t* list_remove_front(struct list_t* list);
struct list_t* list_remove_any(struct list_t* list, int element);
struct list_t* list_remove_rear(struct list_t* list);

int main()
{
    struct list_t *root;
    
    root = list_init();
    list_insert_rear(root, 43);
    list_insert_rear(root, 63);
    root = list_insert_after(root,99,3);
    list_insert_rear(root, 70);
    
    root = list_insert_front(root, 25);
    root = list_insert_front(root, 17);
    
    list_insert_rear(root, 57);
    root = list_remove_front(root);
    
    list_insert_rear(root, 69);
    
    root = list_insert_after(root,111,5);
    root = list_insert_after(root,120,120);
    
    root = list_remove_any(root,70);

    root = list_remove_front(root);
    list_insert_rear(root, 73);
    root = list_remove_any(root,73);
    list_insert_rear(root, 75);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    list_insert_rear(root, 77);

    return 0;
}

// check if specified list is empty
int is_empty_list(struct list_t* list)
{
    if (list->data == 0 && list->next == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// initialize linked list
struct list_t* list_init()
{
    struct list_t *root;

    root = malloc( sizeof(struct list_t) );
    root->next = 0;
    root->data = 0;

    return root;
}

// insert an item in the front of the linked list
struct list_t* list_insert_front(struct list_t* list, int element)
{
    struct list_t *first_elem;

    if ( is_empty_list(list) )
    {
        list->data = element;
    }
    else
    {
        first_elem = malloc( sizeof(struct list_t) );
        first_elem->next = list;
        first_elem->data = element;
    }

    return first_elem;
}

// insert an item on specified position or to the end if position>lenght(list)
struct list_t* list_insert_after(struct list_t* list, int element, int pos)
{
    struct list_t *walker, *next_element, *new_element;
    int i = 1;

    if ( pos == 1)
    {
        list = list_insert_front(list, element);
    }
    else if ( !is_empty_list(list) && pos > 1 )
    {
        walker = list;

        while ( walker->next != 0 && ++i<pos)
        {
            walker = walker->next;
        }
        // can insert record instead of the last element or after it
        if ( i == pos || i == (pos - 1) )
        {
            new_element = malloc( sizeof(struct list_t) );

            next_element = walker->next;

            walker->next = new_element;
            new_element->next = next_element;
            new_element->data = element;
        }
    }

    return list;
}

// insert an item to the end of the linked list
void list_insert_rear(struct list_t* list, int element)
{
    struct list_t *walker;

    if ( is_empty_list(list) )
    {
        list->data = element;
        printf( "[%d]\n",list->data);
    }
    else
    {
        walker = list;

        // DEBUG_INFO: print root elem
        printf( "[%d] ",walker->data);

        while ( walker->next != 0)
        {
            
            walker = walker->next;
            // DEBUG_INFO: print every next elem
            printf( "%d ",walker->data);
        }

        /* Creates a list_t at the end of the list */
        walker->next = malloc( sizeof(struct list_t) );

        walker = walker->next; 

        if ( walker == 0 )
        {
            printf( "Out of memory" );
            //return 0;
        }

        walker->next = 0;
        walker->data = element;

        // DEBUG_INFO: print inserted elem - the last one in list
        printf( "(%d)\n", walker->data );
    }
}

struct list_t* list_remove_front(struct list_t* list)
{
    struct list_t *new_root;

    // nothing to do
    if ( is_empty_list(list) )
    {
        return list;
    }
    // we have only one element, deleting it
    else if ( list->next == 0 )
    {
        list->data = 0;
        list->next = 0;
        return list;
    }
    // we have at least 2 elements
    else
    {
        new_root = list->next;
        free(list);
        return new_root;
    }
}

// delete all nodes where data == element
struct list_t* list_remove_any(struct list_t* list, int element)
{
    struct list_t *walker, *prev_item, *next_item;
    int need_to_del_first = 1;

    if ( is_empty_list(list) )
    {
        return list;
    }
    else if ( !is_empty_list(list) )
    {
        while ( need_to_del_first == 1)
        {
            if ( list->data == element )
            {
                list = list_remove_front(list);
                need_to_del_first = 1;
            }
            else
            {
                need_to_del_first = 0;
            }
        }
        walker = list;

        while ( walker->next != 0 )
        {
            prev_item = walker;
            walker = walker->next;
            if ( walker->data == element ) {
                next_item = walker->next;
                free(walker);
                prev_item->next = next_item;
            }
            
        }
        
    }

    return list;
}

struct list_t* list_remove_rear(struct list_t* list)
{
    // an empty list
    if ( is_empty_list(list) )
    {
        return list;
    }
    // one element in list
    else if ( list->next == 0 )
    {
        list->data = 0;
        list->next = 0;

        return list;
    }
    else
    {
        struct list_t *walker, *prev_item;
        walker = list;

        while ( walker->next != 0)
        {
            prev_item = walker;
            walker = walker->next;
        }

        prev_item->next = 0;
        free(walker);

        return list;
    }

}