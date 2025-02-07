import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int numberOfLine = scanner.nextInt();
    scanner.nextLine();

    List<BigInteger> numbers = new ArrayList<>();

    for (int i = 0; i < numberOfLine; i++) {
      String line = scanner.nextLine();
      String[] numberStrings = line.split("[a-z]+");

      Arrays.stream(numberStrings)
          .filter(numberString -> {
            return !numberString.isBlank();
          })
          .forEach(numberString -> numbers.add(new BigInteger(numberString)));
    }

    numbers.sort(Comparator.naturalOrder());
    numbers.forEach(System.out::println);

  }
}
