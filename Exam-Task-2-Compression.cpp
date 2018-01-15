#include <iostream>
#include <string>
#include <sstream>

int main() {

    std::string text;

    getline(std::cin, text);

    std::string result;

    while(!text.empty()){
        int i = 0;
        char currChar;
        while(text[i] == text[i + 1] && i + 1 < text.size()){
                i++;
                currChar = text[i];
        }
        i++;
        if(i >= 3){
            std::ostringstream str;
            str << i;
            std::string occurances = str.str();
            result += occurances + currChar;
            text.erase(text.begin(), text.begin() + (i));
        }else{
            result += text.substr(0, i);
            text.erase(text.begin(), text.begin() + (i));

        }
    }

     std::cout << result << std::endl;

    return 0;
}
