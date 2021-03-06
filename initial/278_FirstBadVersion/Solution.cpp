bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1, r = n;
        while(l < r){
            int mid = (l + r) / 2;
            if(isBadVersion(mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return (int)l;
    }
};
