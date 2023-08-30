#include <bits/stdc++.h>
#include <stack>
#include <string>

using namespace std;
using ll = long long;

class NumberRepresentation {
    private:
        ll number;
        string binary_value;
    public:
        NumberRepresentation();
        NumberRepresentation(ll);

        void binaryRepresentation();
        friend istream& operator >> (istream& in , NumberRepresentation& a);
        friend ostream& operator << (ostream& out, NumberRepresentation& a);
};

istream& operator >> (istream& in, NumberRepresentation& a){
    cout << "Enter number representation: " ; in >> a.number;
    return in;
}

ostream& operator << (ostream& out, NumberRepresentation& a){
    if(a.binary_value != ""){
        cout << "Binary representation: " << a.binary_value << endl;
    }
    return out;
}
NumberRepresentation::NumberRepresentation(){
    cout << "create Number representation" << endl ;
    this->binary_value = "";
};

NumberRepresentation::NumberRepresentation(ll number) {
    this->number = number;
}

void NumberRepresentation::binaryRepresentation(){
    int redundant;
    stack<int> st;
    string binaryValue = "";
    do {
       st.push(this->number % 2);
    }
    while ((this->number /= 2) != 0);
    while (!st.empty())
    {   
        binaryValue += to_string(st.top());
        st.pop();
    }
    
    this->binary_value =  binaryValue;
}

void checkBrackets(){
    string brackets;
    stack<char> st;
    cout << "Emter any brackets: "; cin >> brackets;
    for(char bracket : brackets){
        if( bracket == '(' ){
            st.push(bracket);
        } else {
            if(st.empty()){
                cout << "INVALID" << endl ;
                return;
            }
            st.pop();
        }
    }
    if(st.empty()){
        cout << "VALID" << endl;
    } else {
        cout << "INVALID" << endl;
    }
}
int main(){
    int actionSelect;
    NumberRepresentation number;
    do{
        cout << "============================================================" << endl;
        cout << "=======================SELECT ACTION========================" << endl;
        cout << "==     1. Number Presentation                             ==" << endl;
        cout << "==     2. Check Brackets                                  ==" << endl;
        cout << "======================ENTER 0 TO EXIT=======================" << endl;
        cout << "Enter action: "; cin >> actionSelect;
        switch (actionSelect)
        {
            case 1:
                cin >> number;
                number.binaryRepresentation();
                cout << number;
                break;
            case 2:
                checkBrackets();
                break;
            default:
                break;
        }
    }while(actionSelect != 0);
    


    return 0;
}