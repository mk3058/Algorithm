import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<Integer, String> numMap = new HashMap();
        Map<String, Integer> nameMap = new HashMap();
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        for (int i = 1; i <= N; i++) {
            String name = scanner.next();
            numMap.put(i, name);
            nameMap.put(name, i);
        }
        
        for (int i = 0; i < M; i++) {
            String input = scanner.next();

            if (Character.isDigit(input.charAt(0))) {
                System.out.println(numMap.get(Integer.parseInt(input)));
            } else {
                System.out.println(nameMap.get(input));
            }
        }
        
        scanner.close();
    }
}