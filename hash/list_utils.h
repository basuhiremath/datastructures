
/*
 * file: list_utils.h
 * Author: Basu
 * Date: 07/15/2016
 *
*/


#ifndef _LIST_UTILS_H_
#define _LIST_UTILS_H_

#include <stdio.h>

struct singly_list_node_t
{
 char *data;
 singly_list_node_t *next_node;
}; 


singly_list_node_t *create_singly_list( char *data );

int destroy_singly_list( singly_list_node_t **node_head );

int prepend_singly_node( singly_list_node_t **node_head, char *data );

int append_singly_node( singly_list_node_t *node_head, char *data );

int count_singly_nodes( singly_list_node_t *node_head );

void print_singly_list( singly_list_node_t *node_head );

int find_singly_node( singly_list_node_t *node_head, char *data );

int remove_singly_head_node( singly_list_node_t **node_head );

int remove_singly_tail_node( singly_list_node_t **node_head );

int remove_singly_node( singly_list_node_t **node_head, int position );

int insert_singly_node(singly_list_node_t **node_head, int insert_position, char *data);

int swap_singly_node(singly_list_node_t *node_head, int position_x, int position_y);

int retrieve_singly_data(singly_list_node_t *node_head, char **retrieved_data);

#endif 





