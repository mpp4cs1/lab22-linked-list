#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node *next;
};

Node *build_list(vector<int> v) {
  if (v.size() > 0) {
    Node *node = new Node{v[0], nullptr};
    v.erase(v.begin(), v.begin() + 1);
    node->next = build_list(v);
    return node;
  } else {
    return nullptr;
  }
}

ostream &operator<<(ostream &os, Node *list) {
  Node *node = list;
  while (node) {
    cout << node->value;
    if (node->next) {
      os << " --> ";
    }
    node = node->next;
  }
  return os;
}

string stringify(Node *list, string separator = " ") {
  ostringstream oss{""};
  Node *node = list;
  while (node) {
    oss << node->value;
    if (node->next) {
      oss << separator;
    }
    node = node->next;
  }
  return oss.str();
}

Node *find(int value, Node *list) {
  Node *node = list;
  while (node) {
    if (node->value == value) {
      return node;
    }
    node = node->next;
  }
  return nullptr;
}

Node *find_parent(int value, Node *list) {
  Node *node = list;
  Node *parent = nullptr;
  while (node) {
    if (node->value == value) {
      return parent;
    }
    parent = node;
    node = node->next;
  }
  return nullptr;
}

Node *element_at_index(int index, Node *list) {
  Node *node = list;
  int i = 0;
  while (node && i < index) {
    node = node->next;
    i++;
  }
  return node;
}

Node *parent_at_index(int index, Node *list) {
  Node *node = list;
  Node *parent = nullptr;
  int i = 0;
  while (node && i < index) {
    parent = node;
    node = node->next;
    i++;
  }
  return parent;
}

Node *random_list(int num_elements, int min_value, int max_value) {
  random_device rd{};
  mt19937 rng{rd()};
  uniform_int_distribution<int> dist{min_value, max_value};
  Node *list{nullptr};
  if (num_elements > 0) {
    Node *previous = new Node{dist(rng), nullptr};
    list = previous;
    for (int i{0}; i < num_elements; ++i) {
      Node *node = new Node{dist(rng), nullptr};
      previous->next = node;
      previous = node;
    }
  }
  return list;
}

int length(Node *list) {
  int count = 0;
  while (list) {
    count++;
    list = list->next;
  }
  return count;
}

Node *insert_after(Node *node, Node *new_node) {}

Node *push(Node *&list, Node *new_node) {}

Node *insert_at_index(Node *&list, int index, int value) {}

Node *remove_after(Node *node) {}

Node *pop(Node *&list) {}

Node *remove_at_index(Node *&list, int index) {}
