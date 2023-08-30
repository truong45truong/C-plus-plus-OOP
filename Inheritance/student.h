#include <bits/stdc++.h>
#include "person.h"

using namespace std;


class Student : public Person{
    private:
        double gpa;
    public:
        Student(string,string,double);
        double getGpa();
        void setGpa(double);
        // function overriding
        void input();
};