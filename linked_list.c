
#include "linked_list.h"

/* check if specified list is empty */
int is_empty_list(struct list_t* list)
{
    if (list->data == NULL && list->next == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* initialize linked list */
struct list_t* list_init()
{
    struct list_t *root;

    root = malloc( sizeof(struct list_t) );
    root->next = 0;
    root->data = NULL;

    return root;
}

void list_destroy(struct list_t* list)
{
    struct list_t *item_to_destroy;
    while (list->next != 0)
    {
        item_to_destroy = list;
        list = list->next;
        free(item_to_destroy);
    }
    free(list);
}

/* insert an item in the front of the linked list */
struct list_t* list_insert_front(struct list_t* list, void *element)
{
    struct list_t *first_elem;

    if ( is_empty_list(list) )
    {
        list->data = element;
        return list;
    }
    else
    {
        first_elem = malloc( sizeof(struct list_t) );
        first_elem->next = list;
        first_elem->data = element;
    }

    return first_elem;
}

/* insert an item on specified position or to the end if position>lenght(list) */
struct list_t* list_insert_after(struct list_t* list, void *element, int pos)
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
        /* can insert record instead of the last element or after it */
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

/* insert an item to the end of the linked list */
void list_insert_rear(struct list_t* list, void *element)
{
    struct list_t *walker;

    if ( is_empty_list(list) )
    {
        list->data = (char*)element;
    }
    else
    {
        walker = list;
        while ( walker->next != 0)
        {
            walker = walker->next;
        }
        walker->next = malloc( sizeof(struct list_t) );
        walker = walker->next; 

        if ( walker == 0 )
        {
            printf( "Out of memory" );
            exit(0);
        }

        walker->next = 0;
        walker->data = element;
    }
}

struct list_t* list_remove_front(struct list_t* list)
{
    struct list_t *new_root;

    /* nothing to do */
    if ( is_empty_list(list) )
    {
        return list;
    }
    /* we have only one element, deleting it */
    else if ( list->next == 0 )
    {
        list->data = 0;
        list->next = 0;
        return list;
    }
    /* we have at least 2 elements */
    else
    {
        new_root = list->next;
        free(list);
        return new_root;
    }
}

/* delete all nodes where data == element */
struct list_t* list_remove_any(struct list_t* list, void *element)
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
                prev_item->next = next_item;
                
                free(walker);
            }
        }
        
    }

    return list;
}

struct list_t* list_remove_rear(struct list_t* list)
{
    /* an empty list */
    if ( is_empty_list(list) )
    {
        return list;
    }
    /* one element in list */
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

size_t list_size(struct list_t* list)
{
    struct list_t *walker;
    size_t i = 0;

    if ( !is_empty_list(list) )
    {
        i = 1;
        walker = list;

        /* DEBUG_INFO: print root elem */
        printf( "%d ",*((int*)walker->data));
        /*
        char word[100];
        sprintf(word,"%d", *((int*)walker->data));
        printf("%s ", word);
        */

        while (walker->next != 0)
        {
            ++i;
            walker = walker->next;
            /* DEBUG_INFO: print every next elem */
            printf( "%d ",*((int*)walker->data));
        }
    }
    /* DEBUG_INFO */
    printf("; Size: %d.\n", (int)i );
    return i;
}

int search(struct list_t* list, void *element)
{
    struct list_t *walker;
    size_t i = 0;
    int find = 0;

    if ( !is_empty_list(list) )
    {
        i = 1;
        walker = list;
        while ( walker->next != 0 )
        {
            if ( walker->data == element )
            {
                find = 1;
                break;
            }
            ++i;
            walker = walker->next;
        }
    }
    if ( !find )
    {
        i = 0;
    }
    return i;
}