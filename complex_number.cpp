#include <iostream>

using namespace std;

using ll = long long;
ll gcd(int a , int b){
    if(b == 0) return a;
    gcd(b, a % b);
};

class ComplexNumber {

    private:
        int real_part, virtual_part;

    public:
        
        ComplexNumber();
        ComplexNumber(ll,ll);
        ComplexNumber compact();
        friend istream& operator >> (istream &in , ComplexNumber &a);
        friend ostream& operator << (ostream &out, ComplexNumber &a);

};
ComplexNumber::ComplexNumber(ll real_part , ll virtual_part) {
    this->real_part = real_part;
    this->virtual_part = virtual_part;
}

ComplexNumber::ComplexNumber(){
    this->real_part = 0;
    this ->virtual_part = 0;
};

ComplexNumber ComplexNumber::compact(){
    int gcdValue = gcd(this->real_part , this->virtual_part);
    this->real_part /= gcdValue;
    this->virtual_part /= gcdValue;
}

istream& operator >> (istream &in, ComplexNumber &a){
    cout << "Enter real part: " ; in >> a.real_part;
    cout << "Enter virtual part: "; in >> a.virtual_part;
    return in;
};

ostream& operator << (ostream &out, ComplexNumber &a){
    out << "Complex number: " << a.real_part << " " << a.virtual_part << endl;
    return out;
};

int main(){
    ComplexNumber a;
    cin >> a;
    cout << a;
    a.compact();
    cout << " Compact: " << a << endl; 
};