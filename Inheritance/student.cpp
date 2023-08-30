#include <bits/stdc++.h>
#include "student.h"

using namespace std;


double Student::getGpa(){
    return this->gpa;
}

void Student::setGpa(double gpa){
    this->gpa = gpa;
}

void Student::input(){
    Person::input();
    cout << "Enter GPA: "; cin >> this->gpa;
}

Student::Student(string name , string address , double gpa) : Person(name, address){
    this->gpa = gpa;
}