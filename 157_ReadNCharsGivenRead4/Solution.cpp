#include "../IOLib.hpp"

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int idx = 0;
        while(idx < n){
            char* temp = new char[4];
            int res = read4(temp);
            for(int i = 0; i < res && idx < n; i++){
                buf[idx] = temp[i];
                idx++;
            }
            if(res < 4) break;
        }
        return idx;
    }
};

int main(void){
    return 0;
}
