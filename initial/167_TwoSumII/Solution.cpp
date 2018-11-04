#include "../IOLib.hpp"

using namespace std;

vector<int> twoSumII(vector<int>& numbers, int target){
    vector<int> result(2);
    int l = 0, r = numbers.size()-1;
    while(numbers[l] + numbers[r] != target){
        if(numbers[l] + numbers[r] < target) l++;
        else r--;
    }
    result[0] = l + 1;
    result[1] = r + 1;
    return result;
}

int main(void){
    vector<int> numbers;
    readVector(numbers);
    int target = readInt();
    vector<int> result = twoSumII(numbers, target);
    cout << "Result is ";
    printVector(result);
    return 0;
}
