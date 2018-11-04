#include "../IOLib.hpp"

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        lib[count] = longUrl;
        return prefix + to_string(count++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int pos = stoi(shortUrl.substr((int)prefix.size()));     
        return lib[pos];
    }
    
private:
    int count = 0;
    unordered_map<int, string> lib;
    string prefix = "http://tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(void){
    Solution sol;
    string longlink = readString();
    cout << sol.encode(longlink) << endl;
    string shortlink = readString();
    cout << sol.decode(shortlink) << endl;
    return 0;
}
