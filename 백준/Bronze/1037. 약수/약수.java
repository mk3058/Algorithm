import java.io.IOException;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws IOException {
    try (Scanner scanner = new Scanner(System.in)) {

      int numberOfDivisor = scanner.nextInt();
      int minDivisor = Integer.MAX_VALUE, maxDivisor = Integer.MIN_VALUE;

      for (int i = 0; i < numberOfDivisor; i++) {
        int input = scanner.nextInt();

        if (input < minDivisor) {
          minDivisor = input;
        }
        if (input > maxDivisor) {
          maxDivisor = input;
        }
      }

      System.out.println(minDivisor * maxDivisor);
    }
  }
}
