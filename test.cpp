#include "llist.hpp"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cctype>
#include <cmath>
#include <random>
#include <vector>

using namespace std;

TEST_CASE("insert_after") {
  Node *list = build_list({1, 2, 3, 4});
  Node *inserted = insert_after(list->next, new Node{5, nullptr});
  REQUIRE(stringify(list) == "1 2 5 3 4");
}

TEST_CASE("push") {
  Node *list = build_list({1, 2, 3, 4});
  Node *inserted = push(list, new Node{7, nullptr});
  REQUIRE(stringify(list) == "7 1 2 3 4");
}

TEST_CASE("insert_at_index") {
  Node *list = build_list({1, 2, 3, 4});
  Node *inserted = insert_at_index(list, 2, 9);
  REQUIRE(stringify(list) == "1 2 9 3 4");
}

TEST_CASE("remove_after") {
  Node *list = build_list({1, 2, 3, 4});
  Node *removed = remove_after(list->next);
  REQUIRE(stringify(list) == "1 2 4");
}

TEST_CASE("pop") {
  Node *list = build_list({1, 2, 3, 4});
  Node *removed = pop(list);
  REQUIRE(stringify(list) == "2 3 4");
}

TEST_CASE("remove_at_index") {
  Node *list = build_list({1, 2, 3, 4});
  Node *removed = remove_at_index(list, 2);
  REQUIRE(stringify(list) == "1 2 4");
}
