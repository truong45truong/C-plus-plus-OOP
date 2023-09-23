#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int findElement(const std::vector<std::string> &vt , const std::string &str){
    auto it = std::find(vt.begin(),vt.end(),str);

    if(it != vt.end()){
        return std::distance(vt.begin(), it);
    } else {
        return -1;
    }
}

int main(){
    std::vector<std::string> vt = {"a","b","c","d"};
    std::cout << findElement(vt,"d") << vt[findElement(vt,"d")] << std::endl;
}

