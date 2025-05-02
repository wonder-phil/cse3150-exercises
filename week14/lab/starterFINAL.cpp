/*
    This is starter code - it DOES NOT FULLY solve the Final exam
        This example also does not delete its ControlTimedSharedPtr instances...

    It does show several key functions
    in the struct ControlTimedSharedPtr it shows how to work the timer
    in the calss TimedSharedPtr it shows how we invoke instances of ControlTimedSharedPtr 

*/
#include <iostream>
#include <cstddef>
#include <chrono>
#include <utility>
#include <thread>

using namespace std;

using Clock = chrono::high_resolution_clock;
typedef chrono::time_point<chrono::high_resolution_clock> clockTime;
typedef chrono::milliseconds milliSeconds;

struct ControlTimedSharedPtr {
    void *          ptr;
    long            myUseCount;
    clockTime       TimedSharedPtrStartTime;
    milliSeconds    deletePtrInMs;

    ControlTimedSharedPtr(void * p, long deleteMeInMilliseconds) : ptr(p), 
                                                        myUseCount(1),
                                                        TimedSharedPtrStartTime(Clock::now()),
                                                        deletePtrInMs{chrono::milliseconds(deleteMeInMilliseconds)}
                                                        { 
        cout << "ControlTimedSharedPtr " << static_cast<void *>(ptr)
             << " start: " << chrono::duration_cast<chrono::milliseconds>(chrono::milliseconds(0)).count() 
             << " ms " << endl;
    }

    ~ControlTimedSharedPtr() {
        cout << "ControlTimedSharedPtr " << static_cast<void *>(ptr)
             << " end: " 
             << chrono::duration_cast<chrono::milliseconds>(
                Clock::now().time_since_epoch() - TimedSharedPtrStartTime.time_since_epoch()).count() 
             << " ms " << endl;
    }
};



template<typename T>
class TimedSharedPtr {

    private:
        ControlTimedSharedPtr* _ptrToControl;

    public:

    TimedSharedPtr() : _ptrToControl(nullptr) {}

    TimedSharedPtr(T* raw, long deleteMeInMilliseconds ) 
      : _ptrToControl( new ControlTimedSharedPtr(raw, deleteMeInMilliseconds) )
    {}

    TimedSharedPtr( T * raw ) : _ptrToControl( new ControlTimedSharedPtr(raw, 1000) ) // DEFAULT to 1000 milliseconds if No second parameter given
    {}

    
    long use_count() const noexcept {
        return _ptrToControl ? _ptrToControl->myUseCount : 0;
    }

    T* get() const {
        auto milliseondsSinceStart = Clock::now().time_since_epoch() - _ptrToControl->TimedSharedPtrStartTime.time_since_epoch();
        if (milliseondsSinceStart > _ptrToControl->deletePtrInMs ) {
            cout << "Yeo! Expired " ;
            return nullptr;
        } else {
            return _ptrToControl ? static_cast<T*>(_ptrToControl->ptr) : nullptr;
        }
    }

    ~TimedSharedPtr() {   
        //delete _ptrToControl; // Must account for multiple owners!  Check myUseCount in Control...
    }
};


struct Node {
    Node(int v) : val{v} {};
    int val;
    TimedSharedPtr<Node> next;
};

int main() {

    
    TimedSharedPtr<Node> myNode(new Node(7), 100); // Node holds data of 7 and expires in 100 milliseconds
                                                   // Note: the 100 is an argument to the TimedSharedPtr constructor
    TimedSharedPtr<Node> myOtherNode = myNode;

    this_thread::sleep_until(Clock::now() + chrono::milliseconds(50)); // sleep for 50 milliseconds
    cout << "myNode.get() address: <" << myNode.get() << ">" << endl;

    cout << "myNode.use_count(): " << myNode.use_count() << endl;
    cout << "myOtherNode.use_count(): " << myOtherNode.use_count() << endl;

    this_thread::sleep_until(Clock::now() + chrono::milliseconds(25)); // sleep for 25 more milliseconds
    cout << "myNode.get() address: <" << myNode.get() << ">" << endl;

    this_thread::sleep_until(Clock::now() + chrono::milliseconds(75)); // sleep for 75 more milliseconds
    cout << "The ptr should have expired: " << endl;
    cout << "myNode.get() address: <" << myNode.get() << ">" << endl;

    cout << "-----------" << endl;
    TimedSharedPtr<int> p(new int(42));

    cout << p.get() << endl;
    cout << "p.use_count(): " << p.use_count() << endl;

    TimedSharedPtr<int> q = p;
    cout << "p.use_count(): " << p.use_count() << endl;
    cout << "q.use_count(): " << q.use_count() << endl;

    return 0;
}