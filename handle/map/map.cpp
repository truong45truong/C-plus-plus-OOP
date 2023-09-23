#include <iostream>
#include <string>
#include <map>

bool findKey(const std::map<std::string,std::string> &mp, const std::string key){
    auto it = mp.find(key);
    if(it != mp.end()){
        return true;
    }
    return false;
}

int main(){
    std::map<std::string,std::string> operations;
    operations["W"] = "write";
    operations["R"] = "read";
    operations["X"] = "execute";

    // case 1:
    std::cout << findKey(operations,"W") << std::endl;
    // case 2:
    std::cout << findKey(operations,"K") << std::endl;
}