#include "../IOLib.hpp"

/* Count the smaller number of total count of
 * factor 2 and factor 5.
 * Time: O(log(n)), Space: O(1).
 */
class Solution {
public:
    int trailingZeroes(int n) {
        long long n2 = 2, n5 = 5;
        long long sum2 = 0, sum5 = 0;
        while(n2 <= n){
            sum2 += n / n2;
            n2 *= 2;
        }
        while(n5 <= n){
            sum5 += n / n5;
            n5 *= 5;
        }
        return min(sum2, sum5);
    }
};

/* Smarter: # of factor 5 is definitely less than
 * that of factor 2.
 * So only need to calculate # of factor 5.
 * Time: O(log(n)), Space: O(1)
 */
class Solution {
public:
    int trailingZeroes(int n) {
        long long n5 = 5, sum5 = 0;
        while(n5 <= n){
            sum5 += n / n5;
            n5 *= 5;
        }
        return sum5;
    }
};
