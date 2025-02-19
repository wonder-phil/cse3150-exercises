#include<iostream>

using namespace std;

class Person {
    protected:
        int age;
    public:
        Person(int age) : age{age} { cout << "Person::Person(int age) called, age = " << age << endl;   }
        Person()     { cout << "Person::Person() called, age = " << age << endl;   }
};
 
class Father : public Person {
    public:
        Father(int age): Person(age)   { cout<<"Father::Father(int age) called"<< endl; }
        int getFatherAge() { return age; }
};
 
class Mother : public Person {
    public:
        Mother(int age) : Person(age) { cout<<"Mother::Mother(int age) called"<< endl; }
        int getMotherAge() { return age; }
};
 
class Child : public Father, public Mother  {
public:
    Child(int age) : Mother(age + 22), Father(age + 25)  {
        cout<<"Child::Child(int age) called"<< endl;
    }
    void printAgeOfParents() {
        cout << "Father age: " << getFatherAge() << endl;
        cout << "Mother age: " << getMotherAge() << endl;
    }
};
 
int main()  {
    Child child(10);

    child.printAgeOfParents() ;
    cout << child.getFatherAge() << endl;
    cout << child.getMotherAge() << endl;
}