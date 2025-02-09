import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      String input = scanner.nextLine();
      String bomb = scanner.nextLine();

      StringBuilder stack = new StringBuilder();
      int bombLength = bomb.length();
      char lastBombChar = bomb.charAt(bombLength - 1);

      for (char c : input.toCharArray()) {
        stack.append(c);
        if (c == lastBombChar && stack.length() >= bombLength && stack.substring(
                stack.length() - bombLength)
            .equals(bomb)) {
          stack.delete(stack.length() - bombLength, stack.length());
        }
      }

      System.out.println(stack.length() == 0 ? "FRULA" : stack.toString());
    }
  }
}
