import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static void main(String[] args) throws IOException {
    try (BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

      MiniSet miniSet = new MiniSet();
      int numberOfOperations = Integer.parseInt(bf.readLine());
      for (int i = 0; i < numberOfOperations; i++) {
        String[] op = bf.readLine().split(" ");

        switch (op[0]) {
          case "add":
            miniSet.add(Integer.parseInt(op[1]));
            break;
          case "remove":
            miniSet.remove(Integer.parseInt(op[1]));
            break;
          case "check":
            bw.append(miniSet.check(Integer.parseInt(op[1])) + "\n");
            break;
          case "toggle":
            miniSet.toggle(Integer.parseInt(op[1]));
            break;
          case "all":
            miniSet.all();
            break;
          case "empty":
            miniSet.empty();
            break;
        }
      }
      bw.flush();
    }
  }

  public static class MiniSet {

    static int set;

    public void add(int number) {
      set |= (1 << number);
    }

    public void remove(int number) {
      set &= ~(1 << number);
    }

    public int check(int number) {
      return (set & (1 << number)) == 0 ? 0 : 1;
    }

    public void toggle(int number) {
      set ^= (1 << number);
    }

    public void all() {
      set = Integer.MAX_VALUE;
    }

    public void empty() {
      set = 0;
    }
  }

}
