import java.math.BigInteger;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String[] input = scanner.nextLine().split(" ");

    BigInteger bigInteger1 = new BigInteger(input[0]);
    BigInteger bigInteger2 = new BigInteger(input[1]);

    System.out.println(bigInteger1.add(bigInteger2));
  }

}
