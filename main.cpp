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

void mainMenu(){
    sf::Font font;
    font.loadFromFile("D:\\projects\\practice2024\\arial.ttf");
    
    sf::RenderWindow window(sf::VideoMode(400, 600), L"Сards", sf::Style::Default);
    
    sf::RectangleShape button1(sf::Vector2f(250, 50));
    button1.setPosition(75, 50);
    button1.setFillColor(sf::Color::Black);

    sf::Text text1;
    text1.setFont(font); // Установите шрифт для текста
    text1.setString(L"Добавить слово"); // Установите текст
    text1.setCharacterSize(20); // Установите размер текста
    text1.setFillColor(sf::Color::White); // Установите цвет текста
    text1.setPosition(95, 60); // Установите позицию текста

    sf::RectangleShape button2(sf::Vector2f(250, 50));
    button2.setPosition(75, 150);
    button2.setFillColor(sf::Color::Black);

    sf::Text text2;
    text2.setFont(font);
    text2.setString(L"Редактирование слов");
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(95, 160);

    sf::RectangleShape button3(sf::Vector2f(250, 50));
    button3.setPosition(75, 250);
    button3.setFillColor(sf::Color::Black);

    sf::Text text3;
    text3.setFont(font);
    text3.setString(L"Тренировка");
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(95, 260);

    sf::RectangleShape exitButton(sf::Vector2f(100, 50));
    exitButton.setPosition(150, 500);
    exitButton.setFillColor(sf::Color::Red);

    sf::Text exitText;
    exitText.setFont(font);
    exitText.setString(L"Выход ");
    exitText.setCharacterSize(20);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(170, 510);

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



void mainMenu2(){
    sf::Font font;
    font.loadFromFile("D:\\projects\\practice2024\\arial.ttf");
    
    sf::RenderWindow window(sf::VideoMode(400, 600), L"Сards", sf::Style::Default);
    
    sf::RectangleShape button1(sf::Vector2f(250, 50));
    button1.setPosition(75, 50);
    button1.setFillColor(sf::Color::Black);

    sf::Text text1;
    text1.setFont(font); // Установите шрифт для текста
    text1.setString(L"Добавить слово"); // Установите текст
    text1.setCharacterSize(20); // Установите размер текста
    text1.setFillColor(sf::Color::White); // Установите цвет текста
    text1.setPosition(95, 60); // Установите позицию текста

    sf::RectangleShape button2(sf::Vector2f(250, 50));
    button2.setPosition(75, 150);
    button2.setFillColor(sf::Color::Black);

    sf::Text text2;
    text2.setFont(font);
    text2.setString(L"Редактирование слов");
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(95, 160);

    sf::RectangleShape button3(sf::Vector2f(250, 50));
    button3.setPosition(75, 250);
    button3.setFillColor(sf::Color::Black);

    sf::Text text3;
    text3.setFont(font);
    text3.setString(L"Тренировка");
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(95, 260);

    sf::RectangleShape exitButton(sf::Vector2f(100, 50));
    exitButton.setPosition(150, 500);
    exitButton.setFillColor(sf::Color::Red);

    sf::Text exitText;
    exitText.setFont(font);
    exitText.setString(L"Выход ");
    exitText.setCharacterSize(20);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(170, 510);

    while (window.isOpen()) {
        sf::Event event;
        int t = 0;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (button1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    
                    int t1 = 0, t2 = 0;
                    std::wstring textInput1, textInput2;

                    sf::RectangleShape inputField1(sf::Vector2f(250, 50));
                    inputField1.setPosition(75, 50);
                    inputField1.setFillColor(sf::Color::Black);

                    sf::RectangleShape inputField1_1(sf::Vector2f(255, 55));
                    inputField1_1.setPosition(72.5, 47.5); 
                    inputField1_1.setFillColor(sf::Color::Black);

                    sf::Text inputText1;
                    inputText1.setFont(font); 
                    inputText1.setCharacterSize(20);
                    inputText1.setPosition(95, 60);
                    inputText1.setFillColor(sf::Color::White);

                    sf::RectangleShape inputField2(sf::Vector2f(250, 50));
                    inputField2.setPosition(75, 150);
                    inputField2.setFillColor(sf::Color::Black);

                    sf::RectangleShape inputField2_1(sf::Vector2f(255, 55));
                    inputField2_1.setPosition(72.5, 147.5);
                    inputField2_1.setFillColor(sf::Color::Black);

                    sf::Text inputText2;
                    inputText2.setFont(font); 
                    inputText2.setCharacterSize(20);
                    inputText2.setPosition(95, 160);
                    inputText2.setFillColor(sf::Color::White);

                    sf::RectangleShape saveButton(sf::Vector2f(250, 50));
                    saveButton.setPosition(75, 250);
                    saveButton.setFillColor(sf::Color::Green);

                    sf::Text saveText;
                    saveText.setFont(font);
                    saveText.setString(L"Сохранить");
                    saveText.setCharacterSize(20);
                    saveText.setFillColor(sf::Color::White);
                    saveText.setPosition(95, 260);

                    sf::RectangleShape backButton(sf::Vector2f(100, 50));
                    backButton.setPosition(150, 500);
                    backButton.setFillColor(sf::Color::Red);

                    sf::Text backText;
                    backText.setFont(font);
                    backText.setString(L"Назад");
                    backText.setCharacterSize(20);
                    backText.setFillColor(sf::Color::White);
                    backText.setPosition(170, 510);

                    while (window.isOpen() & t == 0){
                        sf::Event event2;
                        while (window.pollEvent(event2)){
                            if (event2.type == sf::Event::Closed){
                                window.close();
                            }
                            if (event2.type == sf::Event::MouseButtonPressed){
                                sf::Vector2i mousePos2 = sf::Mouse::getPosition(window);
                                if (inputField1.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){
                                    t1 ^= 1;
                                    t2 = 0;
                                }
                                else if (inputField2.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){
                                    t2 ^= 1;
                                    t1 = 0;
                                }
                                else if (saveButton.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){
                                    const std::string s1( textInput1.begin(), textInput1.end() );
                                    const std::string s2( textInput2.begin(), textInput2.end() );
                                    int res = writeToFile(s1, s2);
                                    std::cout << res;
                                    textInput1.clear();
                                    textInput2.clear();
                                    inputText1.setString(textInput1);
                                    inputText2.setString(textInput2);
                                } 
                                else if (backButton.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){
                                    t = 1;
                                }
                                else{
                                    t1 = 0;
                                    t2 = 0;
                                }
                            }
                            if (t1 == 1 & event2.type == sf::Event::TextEntered) {
                                if (event2.text.unicode == '\b' && textInput1.size() > 0) {
                                    textInput1.pop_back(); 
                                } else if (event2.text.unicode != '\b') {
                                    textInput1 += event2.text.unicode; 
                                }
                                inputText1.setString(textInput1); 
                            }            
                            if (t2 == 1 & event2.type == sf::Event::TextEntered) {
                                if (event2.text.unicode == '\b' && textInput2.size() > 0) {
                                    textInput2.pop_back(); 
                                } else if (event2.text.unicode != '\b') {
                                    textInput2 += event2.text.unicode; 
                                }
                                inputText2.setString(textInput2);                                
                            }
                        }

                        


                        window.clear(sf::Color::White);
                        if(t1 == 1){
                            window.draw(inputField1_1);
                        }
                        window.draw(inputField1);
                        window.draw(inputText1);
                        if(t2 == 1){
                            window.draw(inputField2_1);
                        }
                        window.draw(inputField2);
                        window.draw(inputText2);
                        window.draw(saveButton);
                        window.draw(saveText);
                        window.draw(backButton);
                        window.draw(backText);
                        window.display();
                    }
                }
                else if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
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
    setlocale(LC_ALL, "Russian");
    mainMenu2();

    return 0;
}

int main2()
{
    int r = writeToFile("кот", "cat");
    std::cout << r << std::endl;
    std::string res = find("кот");
    std::cout << r << std::endl;
    std::vector<std::string> res2 = readFile();
    for(int i = 0; i < res2.size(); i++){
        std::cout << res2[i] << std::endl;
    }
    return 0;
}


