#include <iostream>
#include <fstream>
#include <string>



void writeToFile(const std::string& content1, const std::string& content2) {
    std::ofstream file("example.txt", std::ios::app);
    file << content1 << "//" << content2 << std::endl;
    file.close();
}

std::string readFile() {
    std::ifstream file("example.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close(); 
    return line;
}

std::string find(const std::string& key){
    std::ifstream file("example.txt");
    std::string line, word;
    int res;
    while (std::getline(file, line)) {
        res = line.find(key);
        if(res != -1){
            res = line.find("//");
            word = line.substr(res + 2);
        }
    }
    file.close(); 
    return word;
}


int main()
{
    writeToFile("книга", "book");
    writeToFile("ключ", "key");
    std::string res = find("книга");
    std::cout << res;
    return 0;
}
