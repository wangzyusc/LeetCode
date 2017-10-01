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
        int len = 0;
        while(len < n && !legacy.empty()){
            buf[len++] = legacy.front();
            legacy.pop();
        }
        while(len < n){
            int count = read4(buf+len);
            len += count;
            if(count < 4) break;
        }
        for(int i = n; i < len; i++){
            legacy.push(buf[i]);
        }
        int res = min(len, n);
        buf[res] = '\0';
        return res;
    }
private:
    queue<char> legacy;
};

int main(void){
    return 0;
}
