
/*
 * file: binary_tree_utils.h
 * Author: Basu
 * Date: 08/03/2016
 *
*/

#include <stdio.h>


struct binary_tree_t
{
  int value;
  binary_tree_t *right;
  binary_tree_t *left;
  binary_tree_t *parent; /*optional*/
};


binary_tree_t* create_bst(int value);

int destroy_bst(binary_tree_t **binary_tree_head);

int add_bst(binary_tree_t *binary_tree_p, int value);

int* traverse_bst(binary_tree_t *binary_tree_p, int size);




