#include <bits/stdc++.h>
#include <map>
void showMap(const std::map<std::string , std::string> &map){
    for(const auto& a : map ){
        std:: cout << "[" << a.first << "] = " << a.second << std::endl;
    }
}
int main(){
    std::map<std::string, std::string> myMap;
    int n;
    std::cout << "Enter number element Key: " << std::endl;
    std::cin >> n;
    for(int i = 0 ; i < n; i++){
        std::string valueMap, keyMap;
        std::cin.ignore();
        std::cout << "Enter Key element [" << i << "] : ";
        std::cin >> keyMap;
        std::cout << "Enter Value element [" << i << "] : ";
        std::cin >> valueMap;
        myMap[keyMap] = valueMap;
    }
    showMap(myMap);
    return 0;
}