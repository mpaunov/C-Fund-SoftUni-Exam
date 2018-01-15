#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <set>

class Message{
private:
    std::string message;
    int priority;
public:
    Message(const std::string& message, int priority):
        message(message),
        priority(priority){
        }
    bool operator<(const Message& other)const{
        return this->priority < other.priority;
    }
    std::string getMessage(const Message&){
        return this->message;
    }

};

int getPriorityFromString(std::string& text){
    int priority = 0;
    std::string str;

    for(int i = 0; i < text.size(); i++){
        if(isdigit(text[i])){
            str += text[i];
        }
    }

    std::istringstream inputNumber(str);

    inputNumber >> priority;

    return priority;
}

std::string removeDigitsFromString(const std::string& text){
    std::string result;

    for(int i = 0; i < text.size(); i++){
        if(!isdigit(text[i])){
            result += text[i];
        }
    }

    return result;
}

std::string examineElements(const std::string& text, const std::string& other){
    std::string result;

    for(int i = 0; i < text.size(); i++){
        if(text[i] == '?' && other[i] != '?'){
            result += other[i];
        }else{
            result += text[i];
        }
    }

    return result;
}

int main(){

    std::string line;

    getline(std::cin, line);

    std::map<double, std::string> messageByFrequency;

    std::priority_queue<Message, std::vector<Message>, std::less<Message> > resulContainer;

    std::vector<std::string> result;
    std::vector<double> addedItems;

    while(line != "end"){
        if(line != "report"){
            std::istringstream inputLine(line);
            std::string message;
            double frequency;
            inputLine >> frequency;
            inputLine >> message;

            if(messageByFrequency[frequency] == ""){
                messageByFrequency[frequency] = message;

                for(int i = 0; i < messageByFrequency[frequency].size(); i++){
                    if(messageByFrequency[frequency][i] == '?'){
                        break;
                    }
                    else if(i == messageByFrequency[frequency].size() - 1){
                        int items = 0;
                        for(int i = 0; i < addedItems.size(); i++){
                            if(addedItems[i] == frequency){
                                items++;
                            }
                        }
                        if(items == 0){
                        int priority = getPriorityFromString(messageByFrequency[frequency]);
                        std::string str = removeDigitsFromString(messageByFrequency[frequency]);

                        Message currObj(str, priority);

                        resulContainer.push(currObj);
                        addedItems.push_back(frequency);

                        }
                    }
                }
            }else{
                std::string currentMessage = examineElements(messageByFrequency[frequency], message);
                messageByFrequency[frequency] = currentMessage;

                for(int i = 0; i < messageByFrequency[frequency].size(); i++){
                    if(messageByFrequency[frequency][i] == '?'){
                        break;
                    }
                    else if(i == messageByFrequency[frequency].size() - 1){
                        int items = 0;
                        for(int i = 0; i < addedItems.size(); i++){
                            if(addedItems[i] == frequency){
                                items++;
                            }
                        }
                        if(items == 0){
                        int priority = getPriorityFromString(messageByFrequency[frequency]);
                        std::string str = removeDigitsFromString(messageByFrequency[frequency]);

                        Message currObj(str, priority);

                        resulContainer.push(currObj);
                        addedItems.push_back(frequency);

                        }
                }
            }
            }


        }else if(line == "report"){
            if(resulContainer.empty()){
                result.push_back("[no new messages]");
            }else{
                    Message currObj = resulContainer.top();
                    result.push_back(currObj.getMessage(currObj));
                    resulContainer.pop();

            }
        }

        getline(std::cin, line);
    }

    for(int i = 0; i < result.size(); i++){
        std::cout << result[i] << std::endl;
    }




    return 0;
}
