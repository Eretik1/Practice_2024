#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>


std::vector<std::string> readFile() {
    std::ifstream file("example.txt");
    std::string line;
    std::vector<std::string> words;
    while (std::getline(file, line)) {
        words.push_back(line);
    }
    file.close(); 
    return words;
}

std::string find(const std::string& key){
    std::vector<std::string> words = readFile();
    std::string word;
    int res;
    for(int i = 0; i < words.size(); i++){
        res = words[i].find("//");
        word = words[i].substr(0, res);
        if(word == key){
            word = words[i].substr(res + 2);
            return word;
        }
    }
    return "Такого слова нет";
}

bool writeToFile(const std::string& content1, const std::string& content2) {
    std::string res = find(content1);
    if(res == "Такого слова нет"){
        std::ofstream file("example.txt", std::ios::app);
        file << content1 << "//" << content2 << std::endl;
        file.close();
        return 0;
    }
    return 1;
}

void deleteWord(const std::string& key) {
    std::string line, word, fileName = "example.txt";
    std::ifstream inputFile(fileName);
    std::ofstream tempFile("temp.txt");
    int res;
    while (getline(inputFile, line)) {
        res = line.find("//");
        word = line.substr(0, res);
        if (word == key) {
            continue;
        }
        tempFile << line << std::endl;
    }
    inputFile.close();
    tempFile.close();
    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());
}

bool edit(const std::string& key, const std::string& content1, const std::string& content2) {
    std::string line, word, fileName = "example.txt";
    std::ifstream inputFile(fileName);
    std::ofstream tempFile("temp.txt");
    int res, output = 1;
    while (getline(inputFile, line)) {
        res = line.find("//");
        word = line.substr(0, res);
        if (word == key) {
            output = 0;
            tempFile << content1 << "//" << content2 << std::endl;
        }
        else{
            tempFile << line << std::endl;
        }
    }
    inputFile.close();
    tempFile.close();
    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());
    return output;
}

int main()
{
    int r = writeToFile("ошибка", "error");
    std::cout << r << std::endl;
    r = writeToFile("книга", "book");
    std::cout << r << std::endl;
    r = edit("книга", "книга", "volume");
    std::cout << r << std::endl;
    return 0;
}

int main1()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
