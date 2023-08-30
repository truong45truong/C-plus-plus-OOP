#include <bits/stdc++.h>
#include "student.h"

int main(){
    Student s("NVA", "KKAKA", 3.4);
    cout << s.getName() << s.getAddress() << s.getGpa() << endl;
    s.input();

    cout << s.getName() << s.getAddress() << s.getGpa() << endl;
}