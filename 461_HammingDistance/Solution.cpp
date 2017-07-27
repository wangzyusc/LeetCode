#include "../IOLib.hpp"

int hammingDistance(int x, int y){
    int n = x ^ y;
    int count = 0;
    while(n){
        n &= (n-1);
        count++;
    }
    return count;
}

int main(void){
    int x = readInt();
    int y = readInt();
    int result = hammingDistance(x, y);
    cout << "Hamming distance between " << x << 
    " and " << y << " is " << result << endl;
}
