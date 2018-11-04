#include "../IOLib.hpp"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() >= 2)
            mergeSort(nums, 0, nums.size()-1);
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if(left == right) return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid+1, right);
    }
    void merge(vector<int>& nums, int left, int right, int right_end){
        vector<int> temp;
        int left_end = right - 1;
        int i = left, j = right;
        while(i <= left_end && j <= right_end){
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i <= left_end)
            temp.push_back(nums[i++]);
        while(j <= right_end)
            temp.push_back(nums[j++]);
        for(i = 0; i < temp.size(); i++){
            nums[left + i] = temp[i];
        }
    }
};

int main(void){
    vector<int> input;
    readVector(input);
    for(auto item: input){
        if(item > 2 || item < 0){
            cout << "Each number in input has to be among 0, 1, 2." << endl;
            return 1;
        }
    }
    Solution solution;
    solution.sortColors(input);
    printVector(input);
    return 0;
}
