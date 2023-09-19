#include <bits/stdc++.h>
#include <vector>

void showVector(const std::vector<int> &vt){
    for(int i = 0 ; i < vt.size(); i++){
        std::cout << "Value[" << i <<"]: " << vt[i] << std::endl;
    }
    return;
}

int main(){
    std::vector<int> myVertor;
    int n;
    std::cout << "Enter number element vector: " << std::endl;
    std::cin >> n;
    for(int i = 0 ; i < n; i++){
        int valueVt;
        std::cout << "Enter Value element [" << i << "] : ";
        std::cin >> valueVt;
        myVertor.push_back(valueVt);
    }
    showVector(myVertor);


}