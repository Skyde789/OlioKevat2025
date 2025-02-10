#include <iostream>
#include <vector>  
#include "student.h"
#include <algorithm>

using namespace std;

int main()
{
    int selection = 0;
    vector<Student>studentList;
    string name;
    string nameToSearch;
    int age;
    vector<Student>::iterator test;

    do
    {
        age = 0;
        name = "";
        nameToSearch = "";
        system("CLS");
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection)
        {
        case 0:
            cout << "What is the students name?\n";
            cin >> name;
            cout << "How old is student " << name <<"?\n";
            cin >> age;

            studentList.push_back(Student(name, age));
            // Kysy k‰ytt‰j‰lt‰ uuden opiskelijan nimi ja ik‰
            // Lis‰‰ uusi student StudentList vektoriin.
            break;
        case 1:
            for (auto& st : studentList) {
                st.printStudentInfo();
            }
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet. 
            break;

        case 2:
            sort(studentList.begin(), studentList.end(), [](Student& x, Student& y) {
                string xName = x.getName();
                string yName = y.getName();


                transform(xName.begin(), xName.end(), xName.begin(), ::tolower);
                transform(yName.begin(), yName.end(), yName.begin(), ::tolower);

                return xName < yName;
            });

            for (auto& st : studentList) {
                st.printStudentInfo();
            }
            // J‰rjest‰ StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla j‰rjestetyt
            // opiskelijat
            break;

        case 3:
            sort(studentList.begin(), studentList.end(), [](Student& x, Student& y) {
                return x.getAge() > y.getAge();
                });

            for (auto& st : studentList) {
                st.printStudentInfo();
            }
            // J‰rjest‰ StudentList vektorin Student oliot i‰n mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla j‰rjestetyt
            // opiskelijat
            break;
        case 4:
            cout << "Who are you looking for?\n";
            cin >> nameToSearch;
            test = find_if(studentList.begin(), studentList.end(), [nameToSearch](Student& x) {
                return x.getName() == nameToSearch;
            });
            if (test != studentList.end())
                test->printStudentInfo();
            else
                cout << "Couldn't find student\n";

            // Kysy k‰ytt‰j‰lt‰ opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla lˆytyykˆ k‰ytt‰j‰n antamaa nime‰
            // listalta. Jos lˆytyy, niin tulosta opiskelijan tiedot.
            break;

        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }

        system("pause");
    }
    while (selection < 5);

    return 0;
}