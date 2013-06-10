#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct list_t {
  void *data;
  struct list_t *next;
};

int is_empty_list(struct list_t* list);
struct list_t* list_init();
void list_destroy(struct list_t* list);
struct list_t* list_insert_front(struct list_t* list, void *element);
struct list_t* list_insert_after(struct list_t* list, void *element, int pos);
void list_insert_rear(struct list_t* list, void *element);
struct list_t* list_remove_front(struct list_t* list);
struct list_t* list_remove_any(struct list_t* list, void *element);
struct list_t* list_remove_rear(struct list_t* list);
size_t list_size(struct list_t* list);
int search(struct list_t* list, void *element);

#endif
