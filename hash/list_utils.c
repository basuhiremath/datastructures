
/*
 * file: list_utils.c
 * Author: Basu
 * Date: 07/15/2016
 *
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "list_utils.h"


/*Creates a singly node with the data passed
 Returns the pointer to the head
*/
singly_list_node_t *create_singly_node(char *data)
{

  singly_list_node_t* new_node = NULL;

  new_node = (singly_list_node_t*) malloc( sizeof(singly_list_node_t) );

  if (new_node != NULL)
  {
     new_node->data = data;
     new_node->next_node = NULL;
  }
 
  return(new_node);

}


/*Creates a singly list with the data passed
 Returns the pointer to the head
*/
singly_list_node_t *create_singly_list(char *data)
{

  singly_list_node_t* new_node = NULL;

  new_node = create_singly_node(data);
 
  return(new_node);

}


/*Destroy the linked list
 Return 0 if successful, Return -1 if failed
 Update the head pointer
*/
int destroy_singly_list(singly_list_node_t **node_head)
{
  singly_list_node_t *temp_head;

  if (*node_head == NULL)
  {
    return -1;
  }
  
  temp_head = *node_head;
  destroy_singly_list( &(temp_head->next_node) );

  free(temp_head);
  *node_head = NULL;

  return 0;   
 
}


/*Count the number of nodes in singly list 
 Returns number of nodes
*/
int count_singly_nodes(singly_list_node_t *node_head)
{
  
  int num_nodes;
  singly_list_node_t *temp_node;

  if (node_head == NULL)
  {
    return -1;
  }
  
  temp_node = node_head;
  num_nodes = 0;
  while (temp_node != NULL)
  {
    num_nodes++;
    temp_node = temp_node->next_node;
  }
  
  return(num_nodes);

}


/*Find the node with the data that matches the passed data
  Return 0 if found, Return -1 if not found 
*/
int find_singly_node(singly_list_node_t *node_head, char *data)
{
  if (node_head == NULL)
  {
    return -1;
  }
  
  while (node_head != NULL)
  {
    if ( strcmp(data, node_head->data) )
    {
      return 0;
    }
    node_head = node_head->next_node;
  }
  return -1;
  
}


/*Append  node to linked list
 Return 0 if successful, Return -1 if failed 
*/
int append_singly_node(singly_list_node_t *node_head, char *data)
{
  singly_list_node_t *temp_node;

  if (node_head == NULL)
  {
    return -1;
  }
  
  temp_node = node_head;
  while ( (temp_node->next_node) != NULL )
  {
    temp_node = temp_node->next_node;
  }

  temp_node->next_node = create_singly_node(data);

  if (temp_node->next_node == NULL)
  {
     return -1;
  }

  return 0;
  
}


/*Remove the first (head) node of linked list
 Return 0 if successful, Return -1 if failed
 Update the head pointer
*/
int remove_singly_head_node(singly_list_node_t **node_head)
{
  singly_list_node_t *temp_head;

  if (*node_head == NULL)
  {
    return -1;
  }
  
  temp_head = *node_head;
  *node_head = temp_head->next_node;

  free(temp_head);

  return 0;   
 
}


/*Insert node at the head.
 Return 0 if successful, Return -1 if failed
 Update the head pointer
*/
int prepend_singly_node(singly_list_node_t **node_head, char *data)
{

  singly_list_node_t *new_node;

  if (*node_head == NULL)
  {
    return -1;
  }
  
  new_node = create_singly_node(data);
  if (new_node == NULL)
  {
    return -1;
  }

  new_node->next_node = *node_head;
  *node_head = new_node;

  return 0;
}


/*Print all nodes
*/
void print_singly_list(singly_list_node_t *node_head)
{
  singly_list_node_t *temp_node;
  int node_num = 0;

  if (node_head == NULL)
  {
    return;
  }
  
  temp_node = node_head;
 
  while (temp_node != NULL)
  {
    printf("Node %d - element %s\n", node_num++, temp_node->data );
    temp_node = temp_node->next_node;
  }

  return;
}


/*Remove the tail node. If only one node, update head
*/
int remove_singly_tail_node( singly_list_node_t **node_head)
{

  singly_list_node_t *temp_node_1;
  singly_list_node_t *temp_node_2;

  if (*node_head == NULL)
  {
    return -1;
  }
  
  temp_node_1 = *node_head;
  temp_node_2 = temp_node_1->next_node;

  /*temp_node_2 is one node ahead of temp_node_1*/
  if (temp_node_2 == NULL)
  {
    *node_head = NULL;
    free(temp_node_1);
  }
  else
  {
    while ( temp_node_2->next_node != NULL )
    {
      temp_node_1 = temp_node_1->next_node;
      temp_node_2 = temp_node_2->next_node;
    }
    free(temp_node_2);
    temp_node_1->next_node = NULL;
  }

  return 0;
  
}


/*Remove node at given position.
  poistion 0 is head
*/
int remove_singly_node( singly_list_node_t **node_head, int remove_position )
{
  
  singly_list_node_t *temp_node_1;
  singly_list_node_t *temp_node_2;

  int current_position = 0;
  
  if (*node_head == NULL)
  {
    return -1;
  }
  
  if (remove_position < 0)
  {
    printf("cannot remove node at position %d\n ", remove_position);
    return -1;
  }

  /*position 0 is head*/
  if (remove_position == 0)
  {
    /*Remove head*/
    return( remove_singly_head_node(node_head) );
  }
  
  /*temp_node_2 is one node ahead of temp_node_1*/
  temp_node_1 = *node_head;
  temp_node_2 = temp_node_1->next_node;

  if ( (temp_node_2 == NULL) && 
       (current_position < remove_position) )
  {
    /*Remove tail*/
    return( remove_singly_tail_node( node_head ) );
  }

  while ( (current_position < (remove_position-1)) && 
          (temp_node_2 != NULL) )
  {
     temp_node_1 = temp_node_1->next_node;
     temp_node_2 = temp_node_2->next_node;
     current_position++;
  }

  /*remove node*/
  temp_node_1->next_node = temp_node_2->next_node;
  free(temp_node_2);
  
  return 0;
  
}


/*Insert node at given position.
  poistion 0 is head
*/
int insert_singly_node(singly_list_node_t **node_head, int insert_position, char *data)
{

  singly_list_node_t *temp_node;
  singly_list_node_t *new_node;

  int current_position = 0;
  
  if (*node_head == NULL)
  {
    return -1;
  }

  /*position 0 is head*/
  if (insert_position == 0)
  {
    /*Prepend*/
    return( prepend_singly_node(node_head, data) );
  }

  temp_node = *node_head;

  if ( (temp_node->next_node == NULL) && 
       (current_position < insert_position) )
  {
    /*Append*/
    return( append_singly_node( *node_head, data ) );
  }

  while ( (current_position < (insert_position-1)) && 
          (temp_node->next_node != NULL) )
  {
   
     temp_node = temp_node->next_node;
     current_position++;
  }

  /*insert node*/
  new_node = create_singly_node(data);
  if (new_node == NULL)
  { 
    return -1;
  }
  new_node->next_node = temp_node->next_node;
  temp_node->next_node = new_node;

  return 0;
}

/*retrieve elemets from the list*/
int retrieve_singly_data(singly_list_node_t *node_head, char **retrieved_data)
{
 
  if ((node_head == NULL) || (*retrieved_data == NULL))
  {
    return -1;
  } 

  while (node_head != NULL)
  {
    *retrieved_data = node_head->data;
    node_head = node_head->next_node;
    retrieved_data++;
  }

  return 0;
}






