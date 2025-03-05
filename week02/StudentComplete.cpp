#include <iostream>
#include <string>

// Assuming a simple Student structure.
struct Student {
    std::string name;
    int number;
    int total_homeworks;
    int* homeworks; // Assuming this is a dynamically allocated array of homework scores.
};

// Overloaded operator<< for Student.
std::ostream & operator<<(std::ostream& os, const Student& student) {
    os << student.name << " " << student.number << " ";
    
    // Loop over homeworks if there are any.
    for (int i = 0; i < student.total_homeworks; i++) {
        os << student.homeworks[i] << " ";
    }
    
    return os;
}

int main() {
    // Example usage:
    int hw[] = {85, 92, 78};
    Student student = {"Alice", 12345, 3, hw};
    
    std::cout << student << std::endl;
    return 0;
}
