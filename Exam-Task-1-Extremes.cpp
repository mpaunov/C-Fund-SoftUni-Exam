#include <iostream>
#include <vector>

int main(){
    std::cin.sync_with_stdio(false);

    double inputIncome;
    int numbersCount;

    std::cin >> inputIncome >> numbersCount;

    std::vector<int> numbers;

    for (int i = 0; i < numbersCount; i++){
        int currNum;
        std::cin >> currNum;
        numbers.push_back(currNum);
    }
    int minElement = INT_MAX;
    int maxElement = INT_MIN;

    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] < minElement){
            minElement = numbers[i];
        }else if(numbers[i] > maxElement){
            maxElement = numbers[i];
        }
    }
    std::vector<int> result;
    for(int i = 0; i < numbers.size(); i++){
        if((numbers[i] > minElement + inputIncome) && ((numbers[i] < maxElement - inputIncome)&& (numbers[i] < maxElement))){
            result.push_back(numbers[i]);
        }
    }

    double sum = 0;
    for(auto num : result){
        sum += num;
    }

    std::cout << sum / result.size() << std::endl;





    return 0;
}
