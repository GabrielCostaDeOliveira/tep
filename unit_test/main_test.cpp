#include <gtest/gtest.h>

#include "./data-structures/UFDS.cpp"
#include "./data-structures/SegTree.cpp"

#include "./MD/fast_pow.cpp"
#include "./MD/sieve.cpp"
#include "./MD/fat.cpp"

#include "./graph/hasCycleDirectedGraph.cpp"

#include "./string/edit_distance.cpp"

int main(int argc, char** argv){

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}
