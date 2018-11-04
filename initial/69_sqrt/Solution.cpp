#include "../IOLib.hpp"

using namespace std;

bool debug = false;

class Solution {
public:
  int mySqrt(int x) {
    if(x < 0) return 0;
    if(x < 2) return x;
    int start = 1, end = x-1;
    if(debug) cout << debug << endl << "start = " << start << " end = " << end << endl;
    int count = 0;
    while(start < end){
      long long mid = (start + end) / 2;
      long long mid2 = mid * mid, midplus2 = (mid+1)*(mid+1);
      if(debug){
	  cout << "start = " << start << " end = " << end << " mid = " << mid << " mid2 = " << mid2 << " midplus2 = " << midplus2 << endl;
      }
      if(mid2 <= x && midplus2 > x) return mid;
      if(mid2 > x) end = mid - 1;
      if(midplus2 <= x) start = mid+1;
      if((++count) > 100) break;
    }
    if(start * start <= x && (start+1) * (start+1) > x) return start;
    if(end * end <= x && (end+1) * (end+1) > x) return end;
  }
};

int main(int argc, char* argv[]){
    if(argc == 2 && string(argv[1]) == "debug"){
        debug = true;
    }
    int x = readInt();
    Solution solution;
    int res = solution.mySqrt(x);
    cout << "Result is " << res << endl;
    return 0;
}
