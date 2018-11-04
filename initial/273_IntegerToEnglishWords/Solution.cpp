#include "../IOLib.hpp"

const string singles[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const string tens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string doubles[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const int billion = 1000000000;
const int million = 1000000;
const int thousand = 1000;
const int hundred = 100;

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string result;
        if(num / billion != 0){
            result = singles[num / billion] + " Billion";
            num %= billion;
        }
        if(num / million != 0){
            if(result.size() > 0) result += " ";
            result += hundreds(num / million) + " Million";
            num %= million;
        }
        if(num / thousand != 0){
            if(result.size() > 0) result += " ";
            result += hundreds(num / thousand) + " Thousand";
            num %= thousand;
        }
        if(num != 0){
            if(result.size() > 0) result += " ";
            result += hundreds(num);
        }
        return result;
    }
    string hundreds(int num){
        string result;
        if(num >= 100){
            result = singles[num / 100] + " Hundred";
        }
        num %= 100;
        if(num != 0){
            if(result.size() > 0) result += " ";
            result += twodigits(num);
        }
        return result;
    }
    string twodigits(int num){
        if(num < 10){
            return singles[num];
        }
        if(num / 10 == 1) return tens[num % 10];
        else{
            string result = doubles[num / 10];
            if(num % 10 > 0) result += " " + singles[num % 10];
            return result;
        }
    }  
};

int main(void){
    int num = readInt();
    Solution solution;
    string res = solution.numberToWords(num);
    cout << "\"" << res << "\"" << endl;
    return 0;
}
