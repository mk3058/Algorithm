import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int[] mem = new int[12];
    int T = scanner.nextInt();

    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 4;

    for (int i = 0; i < T; i++) {
      int num = scanner.nextInt();

      if (mem[num] != 0) {
        System.out.println(mem[num]);
        continue;
      }
      
      for (int j = 4; j <= num; j++) {
        if (mem[j] == 0) {
          mem[j] = mem[j - 1] + mem[j - 2] + mem[j - 3];
        }
      }

      System.out.println(mem[num]);
    }
  }
}
