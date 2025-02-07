import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    int bits = 33554432;
    int bytes = bits / 8;
    byte[] flag = new byte[bytes];

    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
      StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

      while (stringTokenizer.hasMoreElements()) {
        int input = Integer.parseInt(stringTokenizer.nextToken());
        int index = input / 8;
        int bit = input % 8;
        if ((flag[index] & (1 << bit)) != 0) {
          continue;
        }
        flag[index] |= (1 << bit);

        bw.write(input + " ");
      }
      bw.flush();
    }
  }
}
