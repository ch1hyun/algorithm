import java.util.*;
import java.util.stream.*;
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
    
        Set<String> parsing = new HashSet<>();
        Arrays.sort(phone_book, Collections.reverseOrder());
        
        for (int i = 0; i < phone_book.length; ++i) {
            if (parsing.contains(phone_book[i])) {
                return false;
            }
            
            for (int j = 1; j <= phone_book[i].length(); ++j) {
                parsing.add(phone_book[i].substring(0, j));
            }
        }
        
        return answer;
    }
}