#include "llist.hpp"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
  SLNode *list = random_list(10);
  cout << list << "\n";
}
