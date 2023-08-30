#include <bits/stdc++.h>

using namespace std;

struct Point {
    public:
        int a,b;
    Point(int, int);
    void show();
};

Point::Point(int x, int y){
    this->a = x;
    this->b = x;
};
void Point::show(){
    cout << "Point: " << this->a << " " << this->b << endl;
};

struct PointChill : public Point {
    PointChill(int , int);
};

PointChill::PointChill(int x , int y) : Point(x,y){
};

class A{
    public:
        A(){
            cout<< "Create Class A" << endl;
        };

        virtual void call() = 0;
};

class B : public A{
    public:
        B(){
            cout << "Create class B" << endl;
        }
        void call(){
            cout << "Call Class B" << endl;
        };
};

class C :public A {
    public:
        void call(){
            cout << "Call class C" << endl;
        }
};
int main(){
    // struct Point p = {1,3};
    // p.show();
    // struct PointChill pc = {1,4};
    // pc.show();

    A* a = new B();
    a->call();
    B b;
    a = &b;
    a->call();
    B ab;
    
}