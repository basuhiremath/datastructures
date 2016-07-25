
/*
 * file: gtest.cpp
 * Author: Basu
 * Date: 07/21/2016
 *
*/

#include <gtest/gtest.h>

#include "hash_utils.h"

TEST(HASH, create_destroy_hash_table) 
{
  hash_table_t *hash_head;

  ASSERT_TRUE( hash_head = hash_table_create(HASH_TABLE_SIZE) );

  ASSERT_EQ(HASH_TABLE_DESTROYED, hash_table_destroy(hash_head) );
  
}

TEST(HASH, valid_hash_table) 
{
  hash_table_t *hash_head;

  ASSERT_TRUE( hash_head = hash_table_create(HASH_TABLE_SIZE) );

  ASSERT_EQ( HASH_TABLE_VALID, hash_table_valid(hash_head) );

  ASSERT_EQ(HASH_TABLE_DESTROYED, hash_table_destroy(hash_head) );
  
}


TEST(HASH, get_hash_key) 
{
  
  int hash_key;
  
  char *data = "Jack";
  hash_key = hash_get_key(data, HASH_TABLE_SIZE);

  /*hash key is an index*/
  ASSERT_TRUE( hash_key < HASH_TABLE_SIZE );
  ASSERT_TRUE( hash_key >= 0);
  EXPECT_EQ( 0, hash_key );  /*expected value calculated on paper*/

}


TEST(HASH, element_add_validity) 
{
  hash_table_t *hash_head;

  ASSERT_TRUE( hash_head = hash_table_create(HASH_TABLE_SIZE) );

  ASSERT_EQ( HASH_TABLE_INVALID, hash_table_add_element(NULL, 0, NULL) );

  ASSERT_EQ( HASH_TABLE_DATA_INVALID, hash_table_add_element(hash_head, 0, NULL) );

  char *data = "Jack";
 
  ASSERT_EQ( HASH_TABLE_KEY_INVALID, hash_table_add_element(hash_head, -1, data) );

  ASSERT_EQ( HASH_TABLE_KEY_INVALID, hash_table_add_element(hash_head, HASH_TABLE_SIZE, data) );

  ASSERT_EQ(HASH_TABLE_DESTROYED, hash_table_destroy(hash_head) );
  
}


TEST(HASH, add_hash_table) 
{
  hash_table_t *hash_head;
  int hash_key;

  ASSERT_TRUE( hash_head = hash_table_create(HASH_TABLE_SIZE) );

  char *data = "Jack";
  hash_key = hash_get_key(data, HASH_TABLE_SIZE);

  ASSERT_TRUE( hash_key < HASH_TABLE_SIZE );
  ASSERT_TRUE( hash_key >= 0);
  EXPECT_EQ( 0, hash_key );  /*expected value calculated on paper*/

  ASSERT_EQ( HASH_TABLE_ELEMENT_ADDED, hash_table_add_element(hash_head, hash_key, data) );

  ASSERT_EQ(HASH_TABLE_DESTROYED, hash_table_destroy(hash_head) );
  
}


TEST(HASH, trigger_collision) 
{
  hash_table_t *hash_head;
  int hash_key;

  ASSERT_TRUE( hash_head = hash_table_create(HASH_TABLE_SIZE) );

  char *data;
  char *retrieved_data[] = {"NULL", "NULL", "NULL", "NULL", "NULL"};
  int list_size;
  int num_elements = 0;

  data = "Jack";
  hash_key = hash_get_key(data, HASH_TABLE_SIZE);
  ASSERT_TRUE( hash_key < HASH_TABLE_SIZE );
  ASSERT_TRUE( hash_key >= 0);
  EXPECT_EQ( 0, hash_key );  /*expected value calculated on paper*/

  ASSERT_EQ( HASH_TABLE_ELEMENT_ADDED, hash_table_add_element(hash_head, hash_key, data) );
  num_elements++;
 
  data = "Jcak";
  hash_key = hash_get_key(data, HASH_TABLE_SIZE);
  ASSERT_TRUE( hash_key < HASH_TABLE_SIZE );
  ASSERT_TRUE( hash_key >= 0);
  EXPECT_EQ( 0, hash_key );  /*expected value calculated on paper*/

  ASSERT_EQ( HASH_TABLE_ELEMENT_ADDED, hash_table_add_element(hash_head, hash_key, data) );
  num_elements++;
  
  ASSERT_EQ(HASH_TABLE_DESTROYED, hash_table_destroy(hash_head) );
  
}


TEST(HASH, retrieve_element) 
{
  hash_table_t *hash_head;
  int hash_key;

  ASSERT_TRUE( hash_head = hash_table_create(HASH_TABLE_SIZE) );

  char *data;
  singly_list_node_t *head_node;
  int list_size;
  int num_elements = 0;

  data = "Jack";
  hash_key = hash_get_key(data, HASH_TABLE_SIZE);
  ASSERT_TRUE( hash_key < HASH_TABLE_SIZE );
  ASSERT_TRUE( hash_key >= 0);
  EXPECT_EQ( 0, hash_key );  /*expected value calculated on paper*/

  ASSERT_EQ( HASH_TABLE_ELEMENT_ADDED, hash_table_add_element(hash_head, hash_key, data) );
  num_elements++;
 
  data = "Jcak";
  hash_key = hash_get_key(data, HASH_TABLE_SIZE);
  ASSERT_TRUE( hash_key < HASH_TABLE_SIZE );
  ASSERT_TRUE( hash_key >= 0);
  EXPECT_EQ( 0, hash_key );  /*expected value calculated on paper*/

  ASSERT_EQ( HASH_TABLE_ELEMENT_ADDED, hash_table_add_element(hash_head, hash_key, data) );
  num_elements++;

  ASSERT_EQ( HASH_TABLE_ELEMENT_FOUND, hash_table_search_element(hash_head, hash_key, &head_node, &list_size) );

  ASSERT_EQ(num_elements, list_size);
  
  ASSERT_EQ(HASH_TABLE_DESTROYED, hash_table_destroy(hash_head) );
  
}




int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
