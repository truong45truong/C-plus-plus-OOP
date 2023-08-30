#include <bits/stdc++.h>
#include "person.h"

using namespace std;

string Person::getName(){
    return this->name;
}

string Person::getAddress(){
    return this->address;
}

void Person::setName(string name){
    this->name = name;
}

void Person::setAdress(string address){
    this->address = address;
}

void Person::input(){
    cout << "Enter Name: "; getline(cin,this->name);
    cout << "Enter Adress: "; getline(cin, this->address);
}

Person::Person(string name, string address){
    this->name = name;
    this->address = address;
}