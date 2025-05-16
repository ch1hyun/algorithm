import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        
        Map<String, Set<String>> box = new HashMap();
        
        for (int i = 0; i < clothes.length; ++i) {
            String cloth = clothes[i][0], category = clothes[i][1];
            
            if (!box.containsKey(category)) {
                box.put(category, new HashSet<>());
            }
            
            box.get(category).add(cloth);
        }
        
        answer = 1;
        for (String key : box.keySet()) {
            answer *= (box.get(key).size() + 1);
        }
        answer -= 1;
        
        return answer;
    }
}