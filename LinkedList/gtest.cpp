
/*
 * file: gtest.cpp
 * Author: Basu
 * Date: 07/14/2016
 *
*/

#include <gtest/gtest.h>

#include "list_utils.h"

TEST(LINKEDLIST, create_list) 
{
  singly_list_node_t *head_node = NULL;
  ASSERT_TRUE( head_node = create_singly_list(0) );

  /*Free memory*/
  free(head_node);
}


TEST(LINKEDLIST, destroy_list) 
{
  singly_list_node_t *head_node;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  ASSERT_FALSE( destroy_singly_list( &head_node ) );
  
}


TEST(LINKEDLIST, count_list) 
{
  singly_list_node_t *head_node = NULL;

  /*Create list*/
  ASSERT_TRUE( head_node = create_singly_list(0) );
  EXPECT_EQ( 1, count_singly_nodes(head_node) );

  /*Destroy list*/
  ASSERT_FALSE( destroy_singly_list( &head_node ) );
}


TEST(LINKEDLIST, find_node) 
{

  singly_list_node_t *head_node;
  /*Create list*/
  ASSERT_TRUE( head_node = create_singly_list(5) );

  EXPECT_EQ( 0, find_singly_node(head_node, 5) );

  /*Destroy list*/
  ASSERT_FALSE( destroy_singly_list( &head_node ) );

}

TEST(LINKEDLIST, delete_head) 
{
  singly_list_node_t *head_node = NULL;
  /*Create list*/
  ASSERT_TRUE( head_node = create_singly_list(5) );

  EXPECT_EQ( 0, find_singly_node(head_node, 5) );
  EXPECT_EQ( 1, count_singly_nodes(head_node) );
  ASSERT_FALSE( remove_singly_head_node( &head_node ) );
  EXPECT_EQ( -1, count_singly_nodes(head_node) );

  /*Destroy list*/
  if (NULL != head_node)
  {
    ASSERT_FALSE( destroy_singly_list( &head_node ) );
  }

}


TEST(LINKEDLIST, append_node) 
{
  singly_list_node_t *head_node = NULL;
  /*Create list*/
  ASSERT_TRUE( head_node = create_singly_list(5) );

  EXPECT_EQ( 0, find_singly_node(head_node, 5) );
  EXPECT_EQ( 1, count_singly_nodes(head_node) );

  EXPECT_EQ( 0, append_singly_node(head_node, 6) );
  EXPECT_EQ( 2, count_singly_nodes(head_node) );
  EXPECT_EQ( 0, find_singly_node(head_node, 6) );

  /*Destroy list*/
  if (NULL != head_node)
  {
    ASSERT_FALSE( destroy_singly_list( &head_node ) );
  }

}


TEST(LINKEDLIST, destroy_list_recurrsive) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 6) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 6) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 6) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 6) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 6) );
  node_cnt++;
  
  EXPECT_EQ( node_cnt, count_singly_nodes(head_node) );

  ASSERT_FALSE( destroy_singly_list( &head_node ) );
  
}

TEST(LINKEDLIST, print_nodes) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 9) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 10) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 11) );
  node_cnt++;
  
  EXPECT_EQ( node_cnt, count_singly_nodes(head_node) );
  
  print_singly_list(head_node);

  ASSERT_FALSE( destroy_singly_list( &head_node ) );
  
}


TEST(LINKEDLIST, prepend_nodes) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 9) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 10) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 11) );
  node_cnt++;
  
  EXPECT_EQ( node_cnt, count_singly_nodes(head_node) );
  
  print_singly_list(head_node);

  EXPECT_EQ( 0, prepend_singly_node(&head_node, 4) );

  print_singly_list(head_node);

  ASSERT_FALSE( destroy_singly_list( &head_node ) );
  
}

TEST(LINKEDLIST, remove_head_node) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 9) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 10) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 11) );
  node_cnt++;
  
  print_singly_list(head_node);

  EXPECT_EQ( 0, remove_singly_head_node(&head_node) );
  node_cnt--;

  EXPECT_EQ( node_cnt, count_singly_nodes(head_node) );
  print_singly_list(head_node);

  ASSERT_FALSE( destroy_singly_list( &head_node ) );
  
}


TEST(LINKEDLIST, remove_tail_node) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 9) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 10) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 11) );
  node_cnt++;
  
  print_singly_list(head_node);

  EXPECT_EQ( 0, remove_singly_tail_node(&head_node) );
  node_cnt--;

  EXPECT_EQ( node_cnt, count_singly_nodes(head_node) );
  print_singly_list(head_node);

  ASSERT_FALSE( destroy_singly_list( &head_node ) );
  
}

TEST(LINKEDLIST, remove_tail_node_with_one_node) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;
  print_singly_list(head_node);

  EXPECT_EQ( 0, remove_singly_tail_node(&head_node) );
  node_cnt--;

  print_singly_list(head_node);

  EXPECT_EQ( -1, destroy_singly_list( &head_node ) );
  
}

TEST(LINKEDLIST, remove_node_pos_head) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;
  print_singly_list(head_node);

  EXPECT_EQ( 0, remove_singly_node( &head_node, 0 ) );
  node_cnt--;

  print_singly_list(head_node);

  EXPECT_EQ( 0, destroy_singly_list( &head_node ) );
  
}


TEST(LINKEDLIST, remove_node_pos_tail) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;
  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;

  print_singly_list(head_node);

  EXPECT_EQ( 0, remove_singly_node( &head_node, 2 ) );
  node_cnt--;

  print_singly_list(head_node);

  EXPECT_EQ( 0, destroy_singly_list( &head_node ) );
  
}

TEST(LINKEDLIST, remove_node_pos) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 9) );
  node_cnt++;

  print_singly_list(head_node);

  EXPECT_EQ( 0, remove_singly_node( &head_node, 2 ) );
  node_cnt--;

  print_singly_list(head_node);

  EXPECT_EQ( 0, destroy_singly_list( &head_node ) );
  
}

TEST(LINKEDLIST, insert_node_pos_head) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;

  EXPECT_EQ( 0, insert_singly_node(&head_node, 0, 4) );
  node_cnt++;

  print_singly_list(head_node);

  EXPECT_EQ( 0, destroy_singly_list( &head_node ) );
  
}

TEST(LINKEDLIST, insert_node_pos_tail) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;

  EXPECT_EQ( 0, insert_singly_node(&head_node, node_cnt, 9) );
  node_cnt++;

  print_singly_list(head_node);

  EXPECT_EQ( 0, destroy_singly_list( &head_node ) );
  
}


TEST(LINKEDLIST, insert_node_pos) 
{
  singly_list_node_t *head_node;
  int node_cnt = 0;

  ASSERT_TRUE( head_node = create_singly_list(5) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 7) );
  node_cnt++;

  EXPECT_EQ( 0, append_singly_node(head_node, 8) );
  node_cnt++;

  EXPECT_EQ( 0, insert_singly_node(&head_node, 1, 6) );
  node_cnt++;

  print_singly_list(head_node);

  EXPECT_EQ( 0, destroy_singly_list( &head_node ) );
  
}


int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
