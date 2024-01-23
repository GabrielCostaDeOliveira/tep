#include <gtest/gtest.h>

#include "../../string/edit_distance.cpp"

TEST(EDIT_DISTANCE, case1){
  string a = "L";
  string b = "XXLXXXX";

  ASSERT_EQ(edit_distance(a, b), 6);

  swap(a, b);
  ASSERT_EQ(edit_distance(a, b), 6);
}

TEST(EDIT_DISTANCE, case2){
  string a = "LOVE";
  string b = "MOVIE";

  ASSERT_EQ(edit_distance(a, b), 2);

  swap(a, b);
  ASSERT_EQ(edit_distance(a, b), 2);
}

TEST(EDIT_DISTANCE, case3){
  string a = "NGPYCNPO";
  string b = "UQPXWVLGHC";

  ASSERT_EQ(edit_distance(a, b), 0);

  swap(a, b);
  ASSERT_EQ(edit_distance(a, b), 9);
}
