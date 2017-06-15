import java.util.List;
import java.util.ArrayList;

public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        for(int i = 0; i < numRows; i++) generateHelper(result, i);
        return result;
    }
    public void generateHelper(List<List<Integer> > triangle, int rowNum){
        List<Integer> row = new ArrayList<Integer>();
        row.add(1);
        if(rowNum > 0){
            List<Integer> lastrow = triangle.get(triangle.size()-1);
            for(int i = 0; i < lastrow.size()-1; i++){
                row.add(lastrow.get(i) + lastrow.get(i+1));
            }
            row.add(1);
        } 
        triangle.add(row);
    }
}