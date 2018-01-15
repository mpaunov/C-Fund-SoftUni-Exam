#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


int main(){
    std::cin.sync_with_stdio(false);

    typedef std::vector<std::map<std::string, std::string> > vectorMaps;

    std::string indexator;
    getline(std::cin, indexator);

    std::string line;
    getline(std::cin, line);

    std::vector<vectorMaps> entities;

    while(line != "[queries]"){
        vectorMaps current;

        std::istringstream inputLine(line);
        std::string key, value;

        while(inputLine >> key && inputLine >> value){
            std::map<std::string, std::string> currMap;
            currMap[key] = value;
            current.push_back(currMap);
        }
        entities.push_back(current);

        getline(std::cin, line);
    }

    getline(std::cin, line);

    std::vector<std::vector<std::string> > result;

    while(line != "end"){
        std::istringstream inputLine(line);
        std::string value, key;

        inputLine >> value >> key;

        std::vector<std::string> currResult;

        for(int i = 0; i < entities.size(); i++){
            for(int k = 0; k < entities[i].size(); k++){
                if(value == entities[i][k][indexator]){
                    for(int m = 0; m < entities[i].size(); m++){
                        currResult.push_back(entities[i][m][key]);
                    }
                }
            }
        }
        if(currResult.empty()){
            currResult.push_back("[not found]");
        }
        result.push_back(currResult);

        getline(std::cin, line);
    }

    for(int i = 0; i < result.size(); i++){
        for(int k = 0; k < result[i].size(); k++){
            if(result[i][k] != ""){
                std::cout << result[i][k] << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
