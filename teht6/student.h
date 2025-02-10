#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student
{
	public:
		Student(string n, int a) { name = n; age = a; }
		void setAge(int a) { age = a; }
		void setName(string n) { name = n; }
		int getAge() { return age; }
		string getName() { return name; }
		void printStudentInfo() {
			cout << "Student " << name << " Age " << age << endl;
		}
	private:
		string name;
		int age;
};
#endif // MYCLASS_H