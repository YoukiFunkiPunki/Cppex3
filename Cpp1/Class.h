#include <vector>
#include <algorithm>
#include "student.h"
using namespace std;
class myclass {
private:
    vector<student> students;
public:
    //Constructor and Destructor
    myclass();
    virtual ~myclass();
    //Methods
    void add_student(student);
    void remove_student(int);
    void display_students();
    double calculate_class_average();
    void display_class_average();
    void display_class_rankings();
};

myclass::myclass() {}
myclass::~myclass() {}

void myclass::add_student(student s) {
    students.push_back(s);
}

void myclass::remove_student(int index) {
    students.erase(students.begin() + index);
}

void myclass::display_students() {
    for (int i = 0; i < students.size(); i++) {
        cout << students[i] << endl;
    }
}

double myclass::calculate_class_average() {
    double sum = 0.0;
    for (int i = 0; i < students.size(); i++) {
        sum += students[i].calculate_average();
    }
    return sum / students.size();
}

void myclass::display_class_average() {
    cout << "The class average is: " << calculate_class_average() << endl;
}

void myclass::display_class_rankings() {
    vector<double> averages;
    for (int i = 0; i < students.size(); i++) {
        averages.push_back(students[i].calculate_average());
    }
    sort(averages.begin(), averages.end(), greater<double>());
    for (int i = 0; i < averages.size(); i++) {
        cout << "Rank " << i+1 << ": " << averages[i] << endl;
    }
}
