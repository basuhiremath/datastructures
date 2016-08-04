
/*
 * file: gtest.cpp
 * Author: Basu
 * Date: 07/14/2016
 *
*/

#include <gtest/gtest.h>

#include "binary_tree_utils.h"

#define SIZE 10

TEST(SORT, create_bst) 
{

  binary_tree_t *binary_tree_p = NULL;
  
  int random_numbers_p[SIZE] = {1, 5, 8, 2, 3, 7, 4, 0, 9, 6};

  binary_tree_p = create_bst(random_numbers_p[0]);
    
  ASSERT_TRUE(binary_tree_p != NULL);
  
  EXPECT_EQ( 0, destroy_bst(&binary_tree_p) );
   
  ASSERT_TRUE(binary_tree_p == NULL);

}


TEST(SORT, add_bst) 
{

  binary_tree_t *binary_tree_p = NULL;
  
  int random_numbers_p[SIZE] = {1, 5, 8, 2, 3, 7, 4, 0, 9, 6};

  binary_tree_p = create_bst(random_numbers_p[0]);
  
  ASSERT_TRUE(binary_tree_p != NULL);
  
  EXPECT_EQ( 0, add_bst(binary_tree_p, random_numbers_p[1]) );
  
  EXPECT_EQ( 0, destroy_bst(&binary_tree_p) );
   
  ASSERT_TRUE(binary_tree_p == NULL);

}


TEST(SORT, traverse_bst) 
{

  binary_tree_t *binary_tree_p = NULL;
  int *sorted_p;
  int index = 0;
  
  int random_numbers_p[SIZE] = {1, 5, 8, 2, 3, 7, 4, 0, 9, 6};
  int ref_sorted_p[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  binary_tree_p = create_bst(random_numbers_p[index]);
  
  ASSERT_TRUE(binary_tree_p != NULL);
  
  for (index = 1; index < SIZE; index++)
  {
    EXPECT_EQ( 0, add_bst(binary_tree_p, random_numbers_p[index]) );
  }
  
  sorted_p = traverse_bst(binary_tree_p, SIZE);
  ASSERT_TRUE(sorted_p != NULL);
  
  index = 0;
  EXPECT_EQ( ref_sorted_p[index], sorted_p[index] );
  index = 2;
  EXPECT_EQ( ref_sorted_p[index], sorted_p[index] );
  index = 3;
  EXPECT_EQ( ref_sorted_p[index], sorted_p[index] );
  
  EXPECT_EQ( 0, destroy_bst(&binary_tree_p) );
   
  ASSERT_TRUE(binary_tree_p == NULL);
  
  free(sorted_p);

}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
