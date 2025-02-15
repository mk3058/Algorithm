import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static void main(String[] args) throws IOException {
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

      int N = Integer.parseInt(br.readLine());
      int num;
      int count = 0;

      for (int i = 0; i < N; i++) {
        num = Integer.parseInt(br.readLine());
        count = 0;

        int quotient = num / 3;
        for (int j = 0; j <= quotient; j++) {
          int remainder = num - (3 * j);
          count += remainder / 2 + 1;
        }
        System.out.println(count);
      }


    }
  }
}
