
/*
 * file: hash_utils.h
 * Author: Basu
 * Date: 07/21/2016
 *
*/

#ifndef _HASH_UTILS_H_
#define _HASH_UTILS_H_


#include <stdio.h>

#include "list_utils.h"

#define HASH_TABLE_SIZE 10

typedef enum
{
  HASH_TABLE_INVALID = -1,
  HASH_TABLE_VALID = 0,
  HASH_TABLE_FULL,

  HASH_TABLE_CREATED,
  HASH_TABLE_DESTROYED,

  HASH_TABLE_KEY_INVALID,
  HASH_TABLE_KEY_FOUND,
  HASH_TABLE_KEY_NOT_FOUND,

  HASH_TABLE_ELEMENT_EMPTY,
  HASH_TABLE_ELEMENT_OCCUPIED,

  HASH_TABLE_ELEMENT_ADDED,
  HASH_TABLE_ELEMENT_REMOVED,

  HASH_TABLE_ELEMENT_ADD_FAILED,

  HASH_TABLE_ELEMENT_FOUND,
  HASH_TABLE_ELEMENT_RETRIEVE_FAILED,

  HASH_TABLE_DATA_INVALID
} hash_table_status_t;

typedef struct
{
  int list_size;
  singly_list_node_t *head_node;
}hash_table_element_t;

typedef struct 
{
  int table_size;
  hash_table_element_t *elements;
}hash_table_t;


hash_table_t* 
hash_table_create(int hash_table_size);

hash_table_status_t 
hash_table_destroy(hash_table_t* hash_head);

hash_table_status_t 
hash_table_valid(hash_table_t* hash_head);

hash_table_status_t 
hash_table_add_element(hash_table_t *hash_head, int hash_key, char *data);

hash_table_status_t 
hash_table_search_element(hash_table_t *hash_head, int hash_key, singly_list_node_t **head_node, int *list_size);

int 
hash_get_key(char *data, int hash_table_size);




#endif 



