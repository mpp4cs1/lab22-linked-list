#include "llist.hpp"
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <vector>

using namespace std;

void print_help() {
  cout << "1) Print list: print\n";
  cout << "2) Add to beginning: push value\n";
  cout << "3) Insert at index: insert index value\n";
  cout << "4) Remove first element: pop\n";
  cout << "5) Remove element at index: remove index\n";
  cout << "6) Exit: exit\n";
}

void print_propmt() { cout << "> "; }

int main() {
  Node *list = build_list({1, 2, 3, 4, 5, 6});

  vector<string> command_line;
  string command_line_str;
  string command = "";
  string word;
  print_help();
  print_propmt();
  while (command != "exit") {
    getline(cin, command_line_str);
    istringstream iss{command_line_str};
    command_line.clear();
    while (iss >> word) {
      command_line.push_back(word);
    }
    command = command_line[0];
    if (command == "push") {
      push(list, new Node{stoi(command_line[1]), nullptr});
    } else if (command == "insert") {
      insert_at_index(list, stoi(command_line[1]), stoi(command_line[2]));
    } else if (command == "pop") {
      pop(list);
    } else if (command == "remove") {
      remove_at_index(list, stoi(command_line[1]));
    } else if (command == "print") {
      cout << list << "\n";
    } else if (command == "help") {
      print_help();
    } else {
      cout << "Unknown command\n";
      print_help();
    }
    cout << list << "\n";
    print_propmt();
  }
}
