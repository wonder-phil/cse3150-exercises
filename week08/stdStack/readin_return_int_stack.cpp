#include <iostream>

#include <fstream>
#include <stack>

#include "readin_return_int_stack.h"

using namespace std;


stack<int> get_ints_from_file_as_stack(string file_name) {

  ifstream input_file;
  input_file.open("input.txt");

  stack<int> int_stack;

    while (!input_file.eof()) {
      string in_str;
      input_file >> in_str;
      cout << in_str << endl;
      int in_int;
      if (in_str == " " || in_str == "\n") 
        break;
      in_int = stoi(in_str);
      int_stack.push(in_int);
      //cout << in_int << endl;
    }

  input_file.close();   

  return int_stack;
}