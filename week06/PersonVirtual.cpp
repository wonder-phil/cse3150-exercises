#include<iostream>

using namespace std;

class Person {
    int age;
    public:
        Person(int age) : age{age} { cout << "Person::Person(int age) called, age = " << age << endl;   }
        Person()  { cout << "Person::Person() called, age = " << age << endl;   }
};
 
class Father : virtual public Person {
    public:
        Father(int age): Person(age)   { cout<<"Father::Father(int age) called, age = " << age << endl; }
};
 
class Mother : virtual public Person {
public:
    Mother(int age) : Person(age) { cout<<"Mother::Mother(int age) called, age = " << age << endl; }
};
 
class Child : public Father, public Mother  {
public:
    Child(int age) : Mother(age + 22), Father(age + 25) {
        cout<<"Child::Child(int age) called"<< endl;
    }
};
 
int main()  {
    
    Child child(10);
}