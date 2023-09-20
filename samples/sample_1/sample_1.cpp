#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

std::vector<std::string> splitString(const std::string &input, const std::string &delimiter ){
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = input.find(delimiter);
    
    while (end != std::string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
        end = input.find(delimiter, start);
    }

    tokens.push_back(input.substr(start));

    return tokens;
}


class File {
private:
    std::string name;
    std::vector<std::string> operations;
public:
    File(const std::string &file_name, const std::vector<std::string> &operation);
    void operation(const std::string &operation);   
};

File::File(const std::string &file_name,const std::vector<std::string> &operations){
    this->name = file_name;
    this->operations = operations;
};
void File::operation(const std::string &operation){
    return;
}

int main(){
    std::map<std::string,std::string> operations;
    operations["W"] = "write";
    operations["R"] = "read";
    operations["X"] = "execute";
    int n;
    std::cin >> n;
    for(int i = 0 ; i < n ; i++){
        std::string inputFile;

        std::cin.ignore();
        std::getline(std::cin ,inputFile);
        std::vector<std::string> inputFileSplit = splitString(inputFile, " ");
        for(const auto& a : inputFileSplit){
            std::cout << a << std::endl;
        }
    }
    File myFile("example.txt", {"read", "write", "execute"});
}
            