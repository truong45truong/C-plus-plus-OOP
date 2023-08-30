#include <iostream>
#include <sstream>

using namespace std;

class Teacher;
class Student;


class Student {
    friend class Teacher;
    private:
        string id , name, birth;
        double gpa;
        static int quantity;
    public:
        // constructure
        Student();
        Student(string , string, string, double);
        // method
        void input();
        void show();
        void encreaseQuantity();
        // getter

        string getId();
        string getName();
        string getBirth();
        double getGpa();

        int getQuantity();

        // setter 

        bool setId(string);
        bool setName(string);
        bool setBirt(string);
        bool setGpa(double);

        friend void standardized(Student&);
        friend istream& operator >> (istream &in, Student &a);
        friend ostream& operator << (ostream &out, Student &a);

};

istream& operator >> (istream &in, Student &a){
    cout << "\n Enter id: "; in >> a.id;
    cout << "\n Enter name: "; in.ignore(); getline(in, a.name);
    cout << "\n Enter birthday: " ; in >> a.birth;
    cout << "\n Enter GPA: "; in >> a.gpa;
    return in ;
}
ostream& operator << (ostream &out, Student &a){
    cout << "Id: " << a.id << ", Name: " << a.name << ", Birthday: " << a.birth << ", GPA: " << a.gpa << endl;
}
class Teacher {
    private:
        string department;
    public:
        void updateGpaOfStudent(Student& , double); 
};
void Teacher::updateGpaOfStudent(Student& a , double gpa){
    a.gpa = gpa;
}

int Student::quantity = 0;

void Student::encreaseQuantity(){
    ++this->quantity;
}

void standardized(Student &a){
    string res = "" ;
    stringstream ss(a.name);
    string token;

    while (ss >> token){
        res += toupper(token[0]);
        for(int i = 1 ; i < token.length(); i++){
            res += tolower(token[i]);
        }
        res += " ";
    };
    a.name = res;
}
// declare getter

string Student::getId(){
    return this->id;
}

string Student::getName(){
    return this->name;
}

string Student::getBirth(){
    return this->birth;
}

double Student::getGpa(){
    return this->gpa;
}

int Student::getQuantity(){
    return this->quantity;
}

// declare setter

bool Student::setId(string id){
    this->id = id;
    return true;
}

bool Student::setName(string name){
    this->name = name;
    return true;
}

bool Student::setGpa(double gpa){
    this->gpa = gpa;
    return true;
}

bool Student::setBirt(string birth){
    this->birth = birth;
    return true;
}

Student::Student(){
    this->id = "";
    this->name = "";
    this->birth = "";
    this->gpa = 0;
}

Student::Student(string id , string name, string birth, double gpa){
    this->id = id;
    this->name = name;
    this->birth = birth;
    this->gpa = gpa;
}

void Student::input(){
    cout << "\n Enter id: "; cin >> this->id;
    cout << "\n Enter name: "; cin.ignore(); getline(cin, this->name);
    cout << "\n Enter birthday: " ; cin >> this->birth;
    cout << "\n Enter GPA: "; cin >> this->gpa;
}

void Student::show(){
    cout << "Id: " << this->id << ", Name: " << this->name << ", Birthday: " << this->birth << ", GPA: " << this->gpa << endl;
}
int main(){
    Student sv[2];

    for(int i = 0 ; i < 1 ; i++ ){
        cin >> sv[i];
        standardized(sv[i]);
        sv[i].encreaseQuantity();
        cout << sv[i];
    }
    Teacher t;
    double gpaStudent;
    cout << "\n Update GPA Student : " ; cin >> gpaStudent;

    t.updateGpaOfStudent(sv[0],gpaStudent);
    sv[0].show();
    cout << "\n Number quantity Student entered : " << sv[0].getQuantity() << endl;
}