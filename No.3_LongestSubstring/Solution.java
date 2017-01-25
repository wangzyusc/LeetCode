import java.lang.Math;

public class Solution {
    public static int lengthOfLongestSubstring(String s) {
        int length = s.length();
        if(length < 2) return length;
        int[] hist = new int[256];
        int j = 0, maxlen = 1;
        for(int i = 0; i < length; i++){
            while(j < length && hist[s.charAt(j)] == 0){
                hist[s.charAt(j)] += 1;
                maxlen = Math.max(maxlen, j-i+1);
                j++;
            }
            hist[s.charAt(i)] -= 1;
        }
        return maxlen;
    }
}