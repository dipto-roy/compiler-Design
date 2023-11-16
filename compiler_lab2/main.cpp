#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

bool isKeyword(const std::string& word) {

    std::set<std::string> keywords = {"int", "float", "if", "else", "while", "return"};
    return keywords.count(word) > 0;
}


bool isIdentifier(const std::string& word) {

    return isalpha(word[0]) != 0;
}

bool isNumber(const std::string& word) {

    std::istringstream iss(word);
    float f;
    iss >> std::noskipws >> f;


    return iss.eof() && !iss.fail();
}

int main() {

    std::ofstream outFile("output.txt");


    outFile << "int main() {\n";
    outFile << "    int x = 5;\n";
    outFile << "    float y = 3.14;\n";
    outFile << "    if (x > 0) {\n";
    outFile << "        y = y * x;\n";
    outFile << "    } else {\n";
    outFile << "        y = y / x;\n";
    outFile << "    }\n";
    outFile << "    return 0;\n";
    outFile << "}\n";


    outFile.close();


    std::ifstream inFile("output.txt");


    std::string word;
    while (inFile >> word) {
        if (isKeyword(word)) {
            std::cout << "Keyword: " << word << std::endl;
        } else if (isIdentifier(word)) {
            std::cout << "Identifier: " << word << std::endl;
        } else if (isNumber(word)) {
            std::cout << "Number: " << word << std::endl;
        } else {
            std::cout << "Other: " << word << std::endl;
        }
    }


    inFile.close();

    return 0;
}
