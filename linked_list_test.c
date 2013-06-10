#include "linked_list.h"

int main()
{
    struct list_t *root;
    size_t s;
    int a=43,b=63,c=99,d=70,e=25,f=17,g=57,h=69,i=111,j=120,k=70,l=73,m=75;
    /* char z[100]="test"; */
    /* z = "test"; */

    root = list_init();

	root = list_remove_rear(root);
    root = list_remove_any(root,&k);
    root = list_remove_front(root);

    list_insert_rear(root, &a);
    list_insert_rear(root, &b);
    
    root = list_insert_after(root,&c,3);
    list_insert_rear(root, &d);
    
    root = list_insert_front(root, &e);
    root = list_insert_front(root, &f);
    
    list_insert_rear(root, &g);
    root = list_remove_front(root);
    
    list_insert_rear(root, &h);
    
    root = list_insert_after(root,&i,5);
    root = list_insert_after(root,&j,120);
    
    root = list_remove_any(root,&k);

    root = list_remove_front(root);
    list_insert_rear(root, &l);
    root = list_remove_any(root,&l);

    list_insert_rear(root, &m);
    
    
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    
    s = list_size(root);
    printf( "%d\n", (int)s);
    printf( "%d\n", search(root, &g) );

    list_destroy(root);

    return 0;
}