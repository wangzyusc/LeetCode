public class Solution {
    public static int numTrees(int n) {
        if(n <= 2) return n;
        int[][] rootNum = new int[n+1][n+1];//rootNum[i][n]: i-root, n-totalNum
        int[] totalNum = new int[n + 1];
        totalNum[0] = 1;
        totalNum[1] = 1;
        rootNum[1][1] = 1;
        for(int i = 2; i <= n; i++){//totalNum
            int sum = 0;
            for(int j = 1; j <= i; j++){//j-th as root
                sum += (rootNum[j][i] = totalNum[j-1] * totalNum[i-j]);
            }
            totalNum[i] = sum;
        }
        return totalNum[n];
    }
}