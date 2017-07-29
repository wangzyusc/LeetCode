#include "../IOLib.hpp"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--; n--;
        while((m >= 0) && (n >= 0)){
            if(nums1[m] > nums2[n]){
                nums1[m+n+1] = nums1[m];
                m--;
            }
            else{
                nums1[m+n+1] = nums2[n];
                n--;
            }
        }
        while(n >= 0){
            nums1[n] = nums2[n];
            n--;
        }
    }
};

int main(void){
    vector<int> nums1, nums2;
    readVector(nums1);
    readVector(nums2);
    int m = nums1.size(), n = nums2.size();
    for(int i = 0; i < nums2.size(); i++){
        nums1.push_back(0);
    }
    cout << "nums1: ";
    printVector(nums1);
    cout << "nums2: ";
    printVector(nums2);
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    cout << "result: ";
    printVector(nums1);
    return 0;
}
