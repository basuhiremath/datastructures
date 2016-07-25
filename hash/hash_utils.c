
/*
 * file: hash_utils.c
 * Author: Basu
 * Date: 07/21/2016
 *
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "list_utils.h"
#include "hash_utils.h"


#define HASH_KEY_MOD_CONSTANT 29

/*create hash table with the given size.
 return NULL if failed*/
hash_table_t* 
hash_table_create(int hash_table_size)
{

  int i;
  
  /*check for valid size*/
  if (hash_table_size <= 0)
  {
    printf("Invalid size %d for hash table. \
            Cannot create table\n", hash_table_size);
    return NULL;  
  }

  hash_table_t *hash_head;

  /*allocate memory for the hash table*/
  hash_head = (hash_table_t*)malloc(sizeof(hash_table_t));

  if (hash_head)
  {
    hash_head->elements = (hash_table_element_t*)malloc(hash_table_size * sizeof(hash_table_element_t));

    if (hash_head->elements)
    {
      /*necessary memory allocated. Initialize and return*/
     
      for (i = 0; i < hash_table_size; i++)
      {
        hash_head->elements[i].list_size = 0;
        hash_head->elements[i].head_node = NULL; 
      }    
      
      /*used while destroying the hash table*/
      hash_head->table_size = hash_table_size;

      return hash_head;
    }
    else
    {
      free(hash_head); 
    }
  }

  return NULL;
}


/*destroy hash table.
 return INVALID if failed*/
hash_table_status_t 
hash_table_destroy(hash_table_t* hash_head)
{
  int i;

  if (hash_head == NULL)
  {
    printf("Hash head is null\n");
    return HASH_TABLE_INVALID; 
  } 
  
  for (i = 0; i < hash_head->table_size; i++)
  {
    if (hash_head->elements[i].list_size != 0)
    {
     destroy_singly_list( &(hash_head->elements[i].head_node) );
    } 
  }
  
  free(hash_head);

  return HASH_TABLE_DESTROYED;
}


/*check if hash table exists*/
hash_table_status_t hash_table_valid(hash_table_t* hash_head)
{
  if (hash_head == NULL)
  {
    printf("Hash head is null\n");
    return HASH_TABLE_INVALID; 
  } 

  return HASH_TABLE_VALID;
}


/*add element to the hash table*/
hash_table_status_t 
hash_table_add_element(hash_table_t *hash_head, int hash_key, char *data)
{
  if (hash_head == NULL)
  {
    printf("Hash head is null\n");
    return HASH_TABLE_INVALID; 
  }

  if (data == NULL)
  {
    printf("data is null\n");
    return HASH_TABLE_DATA_INVALID; 
  } 

  if (hash_key < 0)
  {
    printf("Hash key is invalid\n");
    return HASH_TABLE_KEY_INVALID; 
  }

  if (hash_key >= hash_head->table_size)
  {
    printf("Hash key is invalid. Expected < %d, actual %d\n", hash_head->table_size, hash_key );
    return HASH_TABLE_KEY_INVALID; 
  }

  /*all good, add element*/
  if (hash_head->elements[hash_key].head_node == NULL)  
  {
    hash_head->elements[hash_key].head_node = create_singly_list( data );
    
    if (hash_head->elements[hash_key].head_node == NULL)
    {
       return HASH_TABLE_ELEMENT_ADD_FAILED;
    }
  }
  else
  {
    if ( append_singly_node( hash_head->elements[hash_key].head_node, data ) < 0)
    {
      return HASH_TABLE_ELEMENT_ADD_FAILED;
    }
  }

  hash_head->elements[hash_key].list_size ++ ;
  
  return HASH_TABLE_ELEMENT_ADDED;
}


/*find the element at key. return the linked list head node*/
hash_table_status_t 
hash_table_search_element(hash_table_t *hash_head, int hash_key, singly_list_node_t **head_node, int *list_size)
{

  int i;

  if (hash_head == NULL)
  {
    printf("Hash head is null\n");
    return HASH_TABLE_INVALID; 
  }

  if (hash_key < 0)
  {
    printf("Hash key is invalid\n");
    return HASH_TABLE_KEY_INVALID; 
  }

  if (hash_key >= hash_head->table_size)
  {
    printf("Hash key is invalid. Expected < %d, actual %d\n", hash_head->table_size, hash_key );
    return HASH_TABLE_KEY_INVALID; 
  }

  /*all good, index the hash table*/
  if (hash_head->elements[hash_key].head_node != NULL)  
  {
    *head_node = hash_head->elements[hash_key].head_node;
    *list_size = hash_head->elements[hash_key].list_size;
  }
  else
  {
    return HASH_TABLE_ELEMENT_EMPTY;
  }

  return HASH_TABLE_ELEMENT_FOUND;
  
}



/*get hash value for the given data
  return -1 is invalid data.
  hash value: very basic hashing. add the ascii value of each char in the string, mod with a constant and mod with the size of the table
*/
int 
hash_get_key(char *data, int hash_table_size)
{

  if (data == NULL)
  {
    printf("Invalid data. Cannot hash\n");
    return -1;
  }

  char c;
  int temp = 0;
  c = *data++;  
  while (c != '\0')
  {
    temp += c;
    //printf("sum = %d\n", temp);
    c = *data++;
  }
 
  temp = temp % HASH_KEY_MOD_CONSTANT;
  //printf("temp %d\n", temp);
  
  int hash_key;

  hash_key = temp % hash_table_size;
  printf("hash_key %d\n", hash_key);

  return (hash_key);

  return -1;
}
































