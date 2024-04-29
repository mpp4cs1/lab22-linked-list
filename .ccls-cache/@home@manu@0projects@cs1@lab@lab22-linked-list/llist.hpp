#include <iostream>
#include <random>
#include <string>

using namespace std;

const char printable_min = 32;
const char printable_max = 126;

random_device rd{};
mt19937 rng{rd()};
uniform_int_distribution<int> dist{printable_min, printable_max};

string random_string(int length) {
  string result{""};
  for (int i{0}; i < length; ++i) {
    result += dist(rng);
  }
  return result;
}

struct SLNode {
  string name;
  SLNode *next;
};

ostream &operator<<(ostream &os, SLNode *list) {
  SLNode *node = list;
  while (node) {
    cout << node->name;
    if (node->next) {
      os << " --> ";
    }
    node = node->next;
  }
  return os;
}

SLNode *find(string name, SLNode *list) {
  SLNode *node = list;
  while (node) {
    if (node->name == name) {
      return node;
    }
    node = node->next;
  }
  return nullptr;
}

SLNode *find_parent(string name, SLNode *list) {
  SLNode *node = list;
  SLNode *parent = nullptr;
  while (node) {
    if (node->name == name) {
      return parent;
    }
    parent = node;
    node = node->next;
  }
  return nullptr;
}

SLNode *element_at_index(int index, SLNode *list) {
  SLNode *node = list;
  int i = 0;
  while (node && i < index) {
    node = node->next;
    i++;
  }
  return node;
}

SLNode *parent_at_index(int index, SLNode *list) {
  SLNode *node = list;
  SLNode *parent = nullptr;
  int i = 0;
  while (node && i < index) {
    parent = node;
    node = node->next;
    i++;
  }
  return parent;
}

SLNode *random_list(int num_elements) {
  SLNode *list{nullptr};
  if (num_elements > 0) {
    SLNode *previous = new SLNode{random_string(1), nullptr};
    list = previous;
    for (int i{0}; i < num_elements; ++i) {
      SLNode *node = new SLNode{random_string(1), nullptr};
      previous->next = node;
      previous = node;
    }
  }
  return list;
}
