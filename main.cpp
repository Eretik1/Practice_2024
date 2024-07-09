#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


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

int main1()
{
    int r = writeToFile("ошибка", "error");
    std::cout << r << std::endl;
    r = writeToFile("книга", "book");
    std::cout << r << std::endl;
    r = edit("книга", "книга", "volume");
    std::cout << r << std::endl;
    return 0;
}

void mainMenu(){
    sf::RenderWindow window(sf::VideoMode(400, 600), "Сards", sf::Style::Default);
    
    sf::RectangleShape button1(sf::Vector2f(250, 50));
    button1.setPosition(75, 50);
    button1.setFillColor(sf::Color::Black);

    sf::RectangleShape button2(sf::Vector2f(250, 50));
    button2.setPosition(75, 150);
    button2.setFillColor(sf::Color::Black);

    sf::RectangleShape button3(sf::Vector2f(250, 50));
    button3.setPosition(75, 250);
    button3.setFillColor(sf::Color::Black);

    sf::RectangleShape exitButton(sf::Vector2f(100, 50));
    exitButton.setPosition(150, 500);
    exitButton.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (button1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // Button 1 pressed
                    // Add your code here
                } else if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // Button 2 pressed
                    // Add your code here
                } else if (button3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // Button 3 pressed
                    // Add your code here
                } else if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(exitButton);
        window.display();
    }
}

void mainMenu2(){
    sf::Font font;
    font.loadFromFile("D:\\projects\\practice2024\\arial.ttf");
    
    sf::RenderWindow window(sf::VideoMode(400, 600), "Сards", sf::Style::Default);
    
    sf::RectangleShape button1(sf::Vector2f(250, 50));
    button1.setPosition(75, 50);
    button1.setFillColor(sf::Color::Black);

    sf::Text text1;
    text1.setFont(font); // Установите шрифт для текста
    text1.setString("Button 1"); // Установите текст
    text1.setCharacterSize(20); // Установите размер текста
    text1.setFillColor(sf::Color::White); // Установите цвет текста
    text1.setPosition(95, 60); // Установите позицию текста

    sf::RectangleShape button2(sf::Vector2f(250, 50));
    button2.setPosition(75, 150);
    button2.setFillColor(sf::Color::Black);

    sf::Text text2;
    text2.setFont(font);
    text2.setString("Button 2");
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(95, 160);

    sf::RectangleShape button3(sf::Vector2f(250, 50));
    button3.setPosition(75, 250);
    button3.setFillColor(sf::Color::Black);

    sf::Text text3;
    text3.setFont(font);
    text3.setString("Button 3");
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(95, 260);

    sf::RectangleShape exitButton(sf::Vector2f(100, 50));
    exitButton.setPosition(150, 500);
    exitButton.setFillColor(sf::Color::Red);

    sf::Text exitText;
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(20);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(180, 510);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (button1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // Button 1 pressed
                    // Add your code here
                } else if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // Button 2 pressed
                    // Add your code here
                } else if (button3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // Button 3 pressed
                    // Add your code here
                } else if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(button1);
        window.draw(text1);
        window.draw(button2);
        window.draw(text2);
        window.draw(button3);
        window.draw(text3);
        window.draw(exitButton);
        window.draw(exitText);
        window.display();
    }
}

int main() {
    mainMenu2();

    return 0;
}
