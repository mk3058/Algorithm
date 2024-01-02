import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public String[] solution(String[] record) {
        ArrayList<String> line = new ArrayList<>();
        Map<String, String> nickName = new HashMap();
        
        for(String s:record){ //최종 닉네임 상태 저장
            Scanner scanner = new Scanner(s);
            
            if(scanner.next().equals("Leave")) continue;
            else{
                nickName.put(scanner.next(), scanner.next());
            }
        }
        
        for(String s:record){ //출력
            Scanner scanner = new Scanner(s);
            String behavior = scanner.next();
            String userId = scanner.next();
            
            switch(behavior){
                case "Enter":
                    line.add(nickName.get(userId)+"님이 들어왔습니다.");
                    break;
                case "Leave":
                    line.add(nickName.get(userId)+"님이 나갔습니다.");
                    break;
            }
        }
        
        String[] answer = line.toArray(new String[line.size()]);
        return answer;
    }
}