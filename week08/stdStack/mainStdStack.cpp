#include <iostream>

#include <stack>
#include <queue>

#include "readin_return_int_stack.h"
#include "prefix_sum.h"

using namespace std;


int main() {

    stack<int> s = get_ints_from_file_as_stack("input.txt");

    int array_len = s.size();
    int array_for_prefix_sum[array_len];

    int position = 0;
    while(! s.empty()) {
        array_for_prefix_sum[position++]  = s.top();
        cout << s.top() << endl;
        s.pop();
    }

    if (non_negative_prefix_sum(array_for_prefix_sum, array_len)) {
        cout << "non-neg" << endl;
    } else {
        cout << "neg" << endl;
    }

    return 0;
}