#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include <random>
#include <numeric>
#include "functions.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class training{
    public:
    
    std::vector<std::string> words;
    int length, index;
    std::vector<int> answers, trueAnswers, falseAnswers;
    
    
    training(){
        words = readFile();
        length = words.size();
        std::vector<int> answers1(length, 0);
        answers = answers1;
        trueAnswers = answers1;
        falseAnswers = answers1;
    }
    std::string start(){
        index = getRandomIndex(answers);
        return words[index];
    }
    void trueAnswer(){
        answers[index] += 1;
        trueAnswers[index] += 1;
    }
    void falseAnswer(){
        if(answers[index] > 0){
            answers[index] -= 1;
        }
        falseAnswers[index] += 1;
    }
};

void mainMenu(){
    sf::Font font;
    font.loadFromFile("..//..//arial.ttf");
    
    sf::RenderWindow window(sf::VideoMode(400, 600), L"Сards", sf::Style::Default);
    
    sf::RectangleShape button1(sf::Vector2f(250, 50));
    button1.setPosition(75, 50);
    button1.setFillColor(sf::Color::Black);

    sf::Text text1;
    text1.setFont(font); 
    text1.setString(L"Добавить слово"); 
    text1.setCharacterSize(20); 
    text1.setFillColor(sf::Color::White); 
    text1.setPosition(95, 60); 

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
                                else if (saveButton.getGlobalBounds().contains(mousePos2.x, mousePos2.y) & (textInput1.empty() == 0) & (textInput2.empty() == 0)){
                                    std::wstring wstr1 = textInput1;
                                    std::wstring wstr2 = textInput2;
                                    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
                                    std::string str1 = converter.to_bytes(wstr1);
                                    std::string str2 = converter.to_bytes(wstr2);
                                    int res = writeToFile(str1, str2);
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
                else if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                    std::vector<std::string> words = readFile();

                    sf::Text text1;
                    text1.setFont(font);
                    text1.setCharacterSize(24);
                    text1.setFillColor(sf::Color::White);

                    sf::Text text2;
                    text2.setFont(font);
                    text2.setCharacterSize(24);
                    text2.setFillColor(sf::Color::White);

                    sf::RectangleShape textContainer(sf::Vector2f(340, 48));
                    textContainer.setFillColor(sf::Color::Black);

                    sf::RectangleShape container(sf::Vector2f(350, 310));
                    container.setPosition(25, 25);
                    container.setFillColor(sf::Color::White);
                    container.setOutlineThickness(2);
                    container.setOutlineColor(sf::Color::Black);

                    float textHeight = 50;
                    unsigned int maxVisibleWords = container.getSize().y / textHeight;
                    unsigned int startIndex = 0;

                    int t1 = 0, t2 = 0, t3 = 0;
                    std::wstring textInput1, textInput2;

                    sf::RectangleShape inputField1(sf::Vector2f(250, 50));
                    inputField1.setPosition(75, 345);
                    inputField1.setFillColor(sf::Color::Black);

                    sf::RectangleShape inputField1_1(sf::Vector2f(255, 55));
                    inputField1_1.setPosition(72.5, 342.5); 
                    inputField1_1.setFillColor(sf::Color::Black);

                    sf::Text inputText1;
                    inputText1.setFont(font); 
                    inputText1.setCharacterSize(20);
                    inputText1.setPosition(95, 355);
                    inputText1.setFillColor(sf::Color::White);

                    sf::RectangleShape inputField2(sf::Vector2f(250, 50));
                    inputField2.setPosition(75, 410);
                    inputField2.setFillColor(sf::Color::Black);

                    sf::RectangleShape inputField2_2(sf::Vector2f(255, 55));
                    inputField2_2.setPosition(72.5, 407.5); 
                    inputField2_2.setFillColor(sf::Color::Black);

                    sf::Text inputText2;
                    inputText2.setFont(font); 
                    inputText2.setCharacterSize(20);
                    inputText2.setPosition(95, 420);
                    inputText2.setFillColor(sf::Color::White);

                    sf::RectangleShape saveButton(sf::Vector2f(140, 50));
                    saveButton.setPosition(40, 480);
                    saveButton.setFillColor(sf::Color::Green);

                    sf::Text saveText;
                    saveText.setFont(font);
                    saveText.setString(L"Сохранить");
                    saveText.setCharacterSize(20);
                    saveText.setFillColor(sf::Color::White);
                    saveText.setPosition(60, 490);

                    sf::RectangleShape delButton(sf::Vector2f(140, 50));
                    delButton.setPosition(210, 480);
                    delButton.setFillColor(sf::Color::Red);

                    sf::Text delText;
                    delText.setFont(font);
                    delText.setString(L"Удалить");
                    delText.setCharacterSize(20);
                    delText.setFillColor(sf::Color::White);
                    delText.setPosition(230, 490);

                    sf::RectangleShape backButton(sf::Vector2f(100, 50));
                    backButton.setPosition(150, 550);
                    backButton.setFillColor(sf::Color::Red);

                    sf::Text backText;
                    backText.setFont(font);
                    backText.setString(L"Назад");
                    backText.setCharacterSize(20);
                    backText.setFillColor(sf::Color::White);
                    backText.setPosition(170, 560);

                    while (window.isOpen() & t == 0) {
                    sf::Event event;
                    while (window.pollEvent(event)) {
                        int i;
                        if (event.type == sf::Event::Closed) {
                            window.close();
                        }
                        if (event.type == sf::Event::MouseButtonPressed){
                            sf::Vector2i mousePos2 = sf::Mouse::getPosition(window);
                            if (backButton.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){
                                t = 1;
                            }
                            else if (container.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){
                                i = (mousePos2.y - 25) / 50 + startIndex;
                                if(i < words.size() & i >= 0){
                                    t3 = 1;
                                    int res = words[i].find("//");
                                    std::string word1 = words[i].substr(0, res);
                                    std::string word2 = words[i].substr(res + 2);
                                    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
                                    
                                    textInput1 = converter.from_bytes(word1);
                                    textInput2 = converter.from_bytes(word2);
                                    inputText1.setString(textInput1);
                                    inputText2.setString(textInput2);
                                }
                            }
                            else if (inputField1.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){
                                t1 ^= 1;
                                t2 = 0;
                                }
                            else if (inputField2.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){
                                t2 ^= 1;
                                t1 = 0;
                            }
                            else if (saveButton.getGlobalBounds().contains(mousePos2.x, mousePos2.y) & (textInput1.empty() == 0) & (textInput2.empty() == 0) & (t3 == 1)){
                                std::wstring wstr1 = textInput1;
                                std::wstring wstr2 = textInput2;
                                std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
                                std::string str1 = converter.to_bytes(wstr1);
                                std::string str2 = converter.to_bytes(wstr2);
                                edit(words[i].substr(0, words[i].find("//")), str1, str2);
                                textInput1.clear();
                                textInput2.clear();
                                inputText1.setString(textInput1);
                                inputText2.setString(textInput2);
                                words = readFile();
                            }
                            else if (delButton.getGlobalBounds().contains(mousePos2.x, mousePos2.y) & (textInput1.empty() == 0) & (textInput2.empty() == 0) & (t3 == 1)){
                                std::wstring wstr1 = textInput1;
                                std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
                                std::string str1 = converter.to_bytes(wstr1);
                                deleteWord(str1);
                                textInput1.clear();
                                textInput2.clear();
                                inputText1.setString(textInput1);
                                inputText2.setString(textInput2);
                                words = readFile();
                            }
                            else{
                                t1 = 0;
                                t2 = 0;
                            } 
                        }
                         
                        else if (event.type == sf::Event::MouseWheelScrolled) {
                            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                                if (event.mouseWheelScroll.delta > 0 && startIndex > 0) {
                                    startIndex--;
                                } else if (event.mouseWheelScroll.delta < 0 && startIndex < words.size() - maxVisibleWords) {
                                    startIndex++;
                                }
                            }   
                        }
                        if (t1 == 1 & event.type == sf::Event::TextEntered) {
                                if (event.text.unicode == '\b' && textInput1.size() > 0) {
                                    textInput1.pop_back(); 
                                } else if (event.text.unicode != '\b') {
                                    textInput1 += event.text.unicode; 
                                }
                                inputText1.setString(textInput1); 
                        }            
                        if (t2 == 1 & event.type == sf::Event::TextEntered) {
                            if (event.text.unicode == '\b' && textInput2.size() > 0) {
                                textInput2.pop_back(); 
                            } else if (event.text.unicode != '\b') {
                                textInput2 += event.text.unicode; 
                            }
                            inputText2.setString(textInput2);                                
                        }
                        if (event.type == sf::Event::KeyPressed) {
                            if (event.key.code == sf::Keyboard::Enter){
                                std::wstring wstr1 = textInput1;
                                std::wstring wstr2 = textInput2;
                                std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
                                std::string str1 = converter.to_bytes(wstr1);
                                std::string str2 = converter.to_bytes(wstr2);
                                edit(words[i].substr(0, words[i].find("//")), str1, str2);
                                textInput1.clear();
                                textInput2.clear();
                                inputText1.setString(textInput1);
                                inputText2.setString(textInput2);
                                words = readFile();
                            }
                        }
                    }
                    window.clear(sf::Color::White);
                    window.draw(container);
                    std::string word1, word2;
                    int res;
                    for (unsigned int i = startIndex; i < std::min(startIndex + maxVisibleWords, static_cast<unsigned int>(words.size())); i++) {
                        res = words[i].find("//");
                        word1 = words[i].substr(0, res);
                        word2 = words[i].substr(res + 2);
                        textContainer.setPosition(30, 30 + (i - startIndex) * 50);
                        window.draw(textContainer);
                        text1.setString(sf::String::fromUtf8(word1.begin(), word1.end()));
                        text1.setPosition(30, 30 + (i - startIndex) * 50 - 5);
                        window.draw(text1);
                        text2.setString(sf::String::fromUtf8(word2.begin(), word2.end()));
                        text2.setPosition(30, 30 + (i - startIndex) * 50 + 20);
                        window.draw(text2);
                    }
                    if(t1 == 1){
                        window.draw(inputField1_1);
                    }
                    window.draw(inputField1);
                    window.draw(inputText1);
                    if(t2 == 1){
                        window.draw(inputField2_2);
                    }
                    window.draw(inputField2);
                    window.draw(inputText2);
                    window.draw(saveButton);
                    window.draw(saveText);
                    window.draw(delButton);
                    window.draw(delText);
                    window.draw(backButton);
                    window.draw(backText);
                    window.display();
                    }
                }
                else if (button3.getGlobalBounds().contains(mousePos.x, mousePos.y)){
                    training tr;
                    std::string wd = tr.start();
                    int res = wd.find("//");
                    std::string word1 = wd.substr(0, res);
                    std::string word2 = wd.substr(res + 2);
                    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;        
                    std::wstring wd1 = converter.from_bytes(word1);
                    std::wstring wd2 = converter.from_bytes(word2);
                    int t = 0, t1 = 0; 

                    sf::RectangleShape word(sf::Vector2f(250, 50));
                    word.setPosition(75, 50);
                    word.setFillColor(sf::Color::Black);

                    sf::Text textWord;
                    textWord.setFont(font); 
                    textWord.setString(wd1); 
                    textWord.setCharacterSize(20); 
                    textWord.setFillColor(sf::Color::White); 
                    textWord.setPosition(95, 60); 

                    sf::RectangleShape test(sf::Vector2f(250, 50));
                    test.setPosition(75, 150);
                    test.setFillColor(sf::Color::Black);

                    sf::Text textTest;
                    textTest.setFont(font); 
                    textTest.setString(L"Проверить"); 
                    textTest.setCharacterSize(20); 
                    textTest.setFillColor(sf::Color::White); 
                    textTest.setPosition(95, 160); 

                    sf::RectangleShape trueTest(sf::Vector2f(250, 50));
                    trueTest.setPosition(75, 150);
                    trueTest.setFillColor(sf::Color::Green);

                    sf::Text textTrueTest;
                    textTrueTest.setFont(font); 
                    textTrueTest.setString(L"Верно"); 
                    textTrueTest.setCharacterSize(20); 
                    textTrueTest.setFillColor(sf::Color::White); 
                    textTrueTest.setPosition(95, 160);

                    sf::RectangleShape falseTest(sf::Vector2f(250, 50));
                    falseTest.setPosition(75, 250);
                    falseTest.setFillColor(sf::Color::Red);

                    sf::Text textFalseTest;
                    textFalseTest.setFont(font); 
                    textFalseTest.setString(L"Неверно"); 
                    textFalseTest.setCharacterSize(20); 
                    textFalseTest.setFillColor(sf::Color::White); 
                    textFalseTest.setPosition(95, 260);

                    sf::RectangleShape backButton(sf::Vector2f(250, 50));
                    backButton.setPosition(75, 500);
                    backButton.setFillColor(sf::Color::Red);

                    sf::Text backText;
                    backText.setFont(font); 
                    backText.setString(L"Завершить"); 
                    backText.setCharacterSize(20); 
                    backText.setFillColor(sf::Color::White); 
                    backText.setPosition(95, 510); 

                    while (window.isOpen() & t == 0){
                        sf::Event event2;
                        while (window.pollEvent(event2)){
                            if (event2.type == sf::Event::Closed){
                                window.close();
                            }
                            if (event2.type == sf::Event::MouseButtonPressed){
                                sf::Vector2i mousePos2 = sf::Mouse::getPosition(window);
                                if (test.getGlobalBounds().contains(mousePos2.x, mousePos2.y) & (t1 == 0)){
                                    t1 = 1;
                                    textWord.setString(wd2); 
                                    
                                }
                                else if (trueTest.getGlobalBounds().contains(mousePos2.x, mousePos2.y) & (t1 == 1)){
                                    tr.trueAnswer();
                                    t1 = 0;
                                    wd = tr.start();
                                    res = wd.find("//");
                                    word1 = wd.substr(0, res);
                                    word2 = wd.substr(res + 2);       
                                    wd1 = converter.from_bytes(word1);
                                    wd2 = converter.from_bytes(word2);
                                    textWord.setString(wd1);
                                }
                                else if (falseTest.getGlobalBounds().contains(mousePos2.x, mousePos2.y) & (t1 == 1)){
                                    tr.falseAnswer();
                                    t1 = 0;
                                    wd = tr.start();
                                    res = wd.find("//");
                                    word1 = wd.substr(0, res);
                                    word2 = wd.substr(res + 2);       
                                    wd1 = converter.from_bytes(word1);
                                    wd2 = converter.from_bytes(word2);
                                    textWord.setString(wd1);
                                }
                                else if (backButton.getGlobalBounds().contains(mousePos2.x, mousePos2.y)){

                                    sf::Text inf1;
                                    inf1.setFont(font); 
                                    inf1.setString(L"Слова"); 
                                    inf1.setCharacterSize(20); 
                                    inf1.setFillColor(sf::Color::Black); 
                                    inf1.setPosition(30, 25); 

                                    sf::Text inf2;
                                    inf2.setFont(font); 
                                    inf2.setString(L"Верно"); 
                                    inf2.setCharacterSize(20); 
                                    inf2.setFillColor(sf::Color::Black); 
                                    inf2.setPosition(220, 25); 

                                    sf::Text inf3;
                                    inf3.setFont(font); 
                                    inf3.setString(L"Неверно"); 
                                    inf3.setCharacterSize(20); 
                                    inf3.setFillColor(sf::Color::Black); 
                                    inf3.setPosition(290, 25); 

                                    std::vector<std::string> words = readFile();

                                    sf::Text text1;
                                    text1.setFont(font);
                                    text1.setCharacterSize(24);
                                    text1.setFillColor(sf::Color::White);

                                    sf::Text text2;
                                    text2.setFont(font);
                                    text2.setCharacterSize(24);
                                    text2.setFillColor(sf::Color::White);

                                    sf::Text text3;
                                    text3.setFont(font);
                                    text3.setCharacterSize(24);
                                    text3.setFillColor(sf::Color::White);

                                    sf::Text text4;
                                    text4.setFont(font);
                                    text4.setCharacterSize(24);
                                    text4.setFillColor(sf::Color::White);

                                    sf::RectangleShape textContainer(sf::Vector2f(340, 48));
                                    textContainer.setFillColor(sf::Color::Black);

                                    sf::RectangleShape container(sf::Vector2f(350, 310));
                                    container.setPosition(25, 50);
                                    container.setFillColor(sf::Color::White);
                                    container.setOutlineThickness(2);
                                    container.setOutlineColor(sf::Color::Black);

                                    float textHeight = 50;
                                    unsigned int maxVisibleWords = container.getSize().y / textHeight;
                                    unsigned int startIndex = 0;

                                    int sumt = 0;
                                    for(int i = 0; i < tr.trueAnswers.size(); i++){
                                        sumt += tr.trueAnswers[i];
                                    }
                                    std::string sinf4 = "Количество верных ответов: ";
                                    sinf4.append(std::to_string(sumt));
            
                                    sf::Text inf4;
                                    inf4.setFont(font); 
                                    inf4.setString(sf::String::fromUtf8(sinf4.begin(), sinf4.end())); 
                                    inf4.setCharacterSize(20); 
                                    inf4.setFillColor(sf::Color::Black); 
                                    inf4.setPosition(25, 380);

                                    int sumf = 0;
                                    for(int i = 0; i < tr.falseAnswers.size(); i++){
                                        sumf += tr.falseAnswers[i];
                                    }
                                    std::string sinf5 = "Количество неверных ответов: ";
                                    sinf5.append(std::to_string(sumf));

                                    sf::Text inf5;
                                    inf5.setFont(font); 
                                    inf5.setString(sf::String::fromUtf8(sinf5.begin(), sinf5.end())); 
                                    inf5.setCharacterSize(20); 
                                    inf5.setFillColor(sf::Color::Black); 
                                    inf5.setPosition(25, 410);

                                    sf::RectangleShape backButton(sf::Vector2f(100, 50));
                                    backButton.setPosition(150, 500);
                                    backButton.setFillColor(sf::Color::Red);

                                    sf::Text backText;
                                    backText.setFont(font);
                                    backText.setString(L"Назад");
                                    backText.setCharacterSize(20);
                                    backText.setFillColor(sf::Color::White);
                                    backText.setPosition(170, 510);

                                    while (window.isOpen() & t == 0) {
                                        sf::Event event3;
                                        while (window.pollEvent(event3)) {
                                            if (event3.type == sf::Event::Closed){
                                                window.close();
                                            }
                                            if (event3.type == sf::Event::MouseButtonPressed){
                                                sf::Vector2i mousePos3 = sf::Mouse::getPosition(window);
                                                if (backButton.getGlobalBounds().contains(mousePos3.x, mousePos3.y)){
                                                    t = 1;
                                                }
                                            }
                                            else if (event3.type == sf::Event::MouseWheelScrolled) {
                                                if (event3.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                                                    if (event3.mouseWheelScroll.delta > 0 && startIndex > 0) {
                                                        startIndex--;
                                                    } else if (event3.mouseWheelScroll.delta < 0 && startIndex < words.size() - maxVisibleWords) {
                                                        startIndex++;
                                                    }
                                                }   
                                            }
                                        }
                                        window.clear(sf::Color::White);
                                        window.draw(inf1);
                                        window.draw(inf2);
                                        window.draw(inf3);
                                        window.draw(container);
                                        std::string word1, word2;
                                        int res;
                                        for (unsigned int i = startIndex; i < std::min(startIndex + maxVisibleWords, static_cast<unsigned int>(words.size())); i++) {
                                            res = words[i].find("//");
                                            word1 = words[i].substr(0, res);
                                            word2 = words[i].substr(res + 2);
                                            textContainer.setPosition(30, 55 + (i - startIndex) * 50);
                                            window.draw(textContainer);
                                            text1.setString(sf::String::fromUtf8(word1.begin(), word1.end()));
                                            text1.setPosition(30, 55 + (i - startIndex) * 50 - 5);
                                            window.draw(text1);
                                            text2.setString(sf::String::fromUtf8(word2.begin(), word2.end()));
                                            text2.setPosition(30, 55 + (i - startIndex) * 50 + 20);
                                            window.draw(text2);
                                           
                                            text3.setString(std::to_wstring(tr.trueAnswers[i]));
                                            text3.setPosition(220, 55 + (i - startIndex) * 50);
                                            window.draw(text3);
                                            
                                            text4.setString(std::to_wstring(tr.falseAnswers[i]));
                                            text4.setPosition(290, 55 + (i - startIndex) * 50);
                                            window.draw(text4);
                                            
                                        }
                                        window.draw(inf4);
                                        window.draw(inf5);
                                        window.draw(backButton);
                                        window.draw(backText);
                                        window.display();
                                    }
                                }
                            }
                        }
                    
                        window.clear(sf::Color::White);
                        window.draw(word);
                        window.draw(textWord);
                        if(t1 == 0){
                            window.draw(test);
                            window.draw(textTest);
                        }
                        else{
                            window.draw(trueTest);
                            window.draw(textTrueTest);
                            window.draw(falseTest);
                            window.draw(textFalseTest);
                        }
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
    
    mainMenu();

    return 0;
}




