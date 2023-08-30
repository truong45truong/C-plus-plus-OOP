#include <iostream>

using namespace std;

using ll = long long;
ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b , a % b);
}
ll lcm(ll denominator_1 ,ll denominator_2){
    return denominator_1 / gcd(denominator_1, denominator_2) * denominator_2;
}
class Fraction {

    private:
        ll numerator , denominator;
    
    public:
        Fraction();
        Fraction(ll , ll);

        friend istream& operator >> (istream& in, Fraction& a);
        friend ostream& operator << (ostream& out, Fraction& a);

        Fraction operator + (Fraction a);
};

Fraction::Fraction(){
    this->numerator = 0;
    this->denominator = 0;
}

Fraction::Fraction(ll numerator , ll denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

istream& operator >> (istream& in, Fraction& a){
    cout << "Enter numerator: "; in >> a.numerator;
    cout << "Enter denominator: "; in >> a.denominator;
    return in;
}

ostream& operator << (ostream& out, Fraction& a){
    out << "Fraction: " << a.numerator << " " << a.denominator << endl ;
}

Fraction Fraction::operator + (Fraction a){
    ll numerator , denominator;
    ll lcmValue = lcm(this->denominator , a.denominator);
    numerator = lcmValue/this->denominator*this->numerator + lcmValue/a.denominator*a.numerator;
    denominator = lcmValue;

    return Fraction(
        numerator/ gcd(numerator,denominator), 
        denominator/gcd(numerator, denominator)
    );
}

int main(){
    Fraction a, b, c;
    cin >> a;
    cout << a;
    cin >> b;
    cout << b;
    
    c = a + b;
    cout << c;
}