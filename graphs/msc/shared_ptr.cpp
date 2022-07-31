#include <iostream>
#include <memory>
using namespace std;
class Student {
    public:
        int id;
        Student(int id_1=100): id(id_1) {}
        ~Student() {
            cout << "Destructor " << endl;
        }
};
shared_ptr<Student> sample(int id=100) {
         shared_ptr<Student> s1 (new Student());
         shared_ptr<Student> s2 = s1;
        s2->id = id;
        cout << "Exiting from sample " << endl;
        return s2;
}
int main() {
    sample(100);
}
