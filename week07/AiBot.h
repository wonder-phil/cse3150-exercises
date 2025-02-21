#ifndef _MOVE_CLASS_INSTANCE_H
#define _MOVE_CLASS_INSTANCE_H

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;


class AiBot {
    private: 
        string name;
        vector<int> values;

    public:
        AiBot(const string & _name) : name(_name) {
            assert(!name.empty());
        }

        string getName() const {
            return name;
        }

        void addValue(int _value) {
            values.push_back(_value);
        }

        friend ostream & operator<<(ostream & os, const AiBot & aiBot) {
            os << aiBot.name << ": ";
            for (auto val : aiBot.values) {
                os << val << " ";
            }
            os << "]";

            return os;
        }

};


#endif
