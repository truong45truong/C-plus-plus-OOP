#include <bits/stdc++.h>

using namespace std;

class Person {
    private:
        string name;
        string address;
    public:
        Person(string,string);
        string getName();
        string getAddress();
        void setName(string);
        void setAdress(string);
        void input();
};