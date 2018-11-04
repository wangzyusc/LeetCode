#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int>& B = (nums1.size() <= nums2.size()) ? nums2 : nums1;
        //size1 <= size2
        int size1 = A.size(), size2 = B.size();
        int halfsize = (size1 + size2 + 1) / 2;
        int odd = (size1 + size2) % 2;
        //make sure that a.size() >= b.size()
        int left = 0, right = size1;
        while(left <= right){
            int i = (left + right) / 2, j = halfsize - i;
            if(i > 0 && A[i - 1] > B[j]) right = i - 1;
            else if(i < size1 && B[j - 1] > A[i]) left = i + 1;
            else{
                int leftmax = 0;
                if(i == 0) leftmax = B[j - 1];
                else if(j == 0) leftmax = A[i - 1];
                else leftmax = max(A[i-1], B[j-1]);
                if(odd) return leftmax;
                //not odd, is even
                int rightmin = 0;
                if(j == size2) rightmin = A[i];
                else if(i == size1) rightmin = B[j];
                else rightmin = min(A[i], B[j]);
                return (leftmax + rightmin) / 2.0;
            }
        }
        return 0;
    }
};

int main(void){
  vector<int> nums1, nums2;
  readVector(nums1);
  readVector(nums2);
  Solution solution;
  cout << "The median is " << solution.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
