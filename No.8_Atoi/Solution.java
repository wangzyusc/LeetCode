public class Solution {
    public static int myAtoi(String str) {
        int length = str.length(), i = 0;
        while(i < length && str.charAt(i) == ' '){
            i++;
        }
        if(i == length) return 0;
        str = str.substring(i);
        boolean minus = false;
        if(str.charAt(0) == '-'){
            minus = true;
            str = str.substring(1);
        }
        else if(str.charAt(0) == '+'){
            str = str.substring(1);
        }
        i = 0;
        length = str.length();
        if(length == 0) return 0;
        while(i < length && isNum(str.charAt(i))) i++;
        str = str.substring(0, i);//str is a sequence of numerical characters
        length = str.length();
        if(length > 10) return minus ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        int result = 0;
        for(i = 0; i < length; i++){
            result = result * 10 + (str.charAt(i)-'0');
        }
        if(result < 0) return minus ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        return minus ? (-1 * result) : result;
    }
    public static boolean isNum(char c){
        return ((c - '0') >= 0) && ((c - '0') <= 9);
    }
}