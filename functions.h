#include <vector>
#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int getRandomIndex(const std::vector<int>& vec);

std::vector<std::string> readFile();

std::string find(const std::string& key);

bool writeToFile(const std::string& content1, const std::string& content2);

void deleteWord(const std::string& key);

bool edit(const std::string& key, const std::string& content1, const std::string& content2);

#endif