
/*
 * file: binary_tree_utils.c
 * Author: Basu
 * Date: 08/03/2016
 *
*/


#include<stdio.h>
#include<stdlib.h>

#include "binary_tree_utils.h"


binary_tree_t* find_insert_branch_bst(binary_tree_t *binary_tree_root, int value)
{

  if(binary_tree_root)  
  {
    if ( value < binary_tree_root->value )
    {
      if (binary_tree_root->left)
      {
        return ( find_insert_branch_bst(binary_tree_root->left, value) );
      }
    }
    else
    {
      if (binary_tree_root->right)
      {
        return ( find_insert_branch_bst(binary_tree_root->right, value) );
      }
    }
  }
  
  return (binary_tree_root);
 
}

/*---------------------------------------------------------------------------*/
binary_tree_t* create_bst(int value)
{
  binary_tree_t *binary_tree_root;
  
  binary_tree_root = (binary_tree_t*)malloc( sizeof(binary_tree_t) );
  
  if (!binary_tree_root)
  {
    return NULL;
  }
  
  binary_tree_root->value = value;
  binary_tree_root->right = NULL;
  binary_tree_root->left = NULL;
  binary_tree_root->parent = NULL;
  
  //printf("%s : %d : binary_tree_root %p\n", __func__, __LINE__, binary_tree_root);
  
  return binary_tree_root;

}


/*---------------------------------------------------------------------------*/
void delete_bst_branch(binary_tree_t *binary_tree_head)
{
  if (binary_tree_head)
  {
    delete_bst_branch(binary_tree_head->left);
    delete_bst_branch(binary_tree_head->right);
    //printf("%s : %d : binary_tree_branch %p, value %d\n", __func__, __LINE__, binary_tree_head,  binary_tree_head->value);
  }
}


int destroy_bst(binary_tree_t **binary_tree_head)
{

  if( !(*binary_tree_head) )
  {
    return -1;
  }

  delete_bst_branch(*binary_tree_head);

  free(*binary_tree_head);
  
  *binary_tree_head = NULL;
  
  return 0;
}


/*---------------------------------------------------------------------------*/
int add_bst(binary_tree_t *binary_tree_root, int value)
{

  binary_tree_t *binary_tree_branch;
  binary_tree_t *temp_tree_branch;
  
  if (!binary_tree_root)
  {
    return -1;
  }

  //printf("%s : %d : binary_tree_root %p\n", __func__, __LINE__, binary_tree_root);
  //printf("%s : %d : binary_tree_root value %d\n", __func__, __LINE__, binary_tree_root->value);
  
  /*Find the correct branch to insert the value*/  
  binary_tree_branch = find_insert_branch_bst(binary_tree_root, value);
  //printf("%s : %d : binary_tree_branch %p\n", __func__, __LINE__, binary_tree_branch);
  //printf("%s : %d : binary_tree_branch value %d\n", __func__, __LINE__, binary_tree_branch->value);
  
  temp_tree_branch = create_bst( value );
  
  if (!temp_tree_branch)
  {
    return -1;
  }
  
  /*update the parent in the child*/
  temp_tree_branch->parent = binary_tree_branch;
  
  if (value < binary_tree_branch->value)
  {
    binary_tree_branch->left = temp_tree_branch;
  }
  else
  {
    binary_tree_branch->right = temp_tree_branch;    
  }
  
  return 0;
  
}


/*---------------------------------------------------------------------------*/
void traverse_bst_inorder(binary_tree_t *binary_tree_p, int *sorted_p)
{
  static int cnt = 0;
  if (binary_tree_p)
  {
    traverse_bst_inorder(binary_tree_p->left, sorted_p);
    sorted_p[cnt++] = binary_tree_p->value;
    traverse_bst_inorder(binary_tree_p->right, sorted_p);
  }
  
}

int* traverse_bst(binary_tree_t *binary_tree_p, int size)
{

  int *sorted_p = (int*)malloc( size * sizeof(int) );
  if (!binary_tree_p)
  {
    return NULL;
  }

  traverse_bst_inorder(binary_tree_p, sorted_p);
  
  return sorted_p;
}


/*---------------------------------------------------------------------------*/
