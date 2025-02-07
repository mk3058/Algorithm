import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

  public static void main(String[] args) throws IOException {
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

      int n = Integer.parseInt(br.readLine());

      Map<String, Integer> count = new HashMap<>();
      List<Pair> stateInfo = new ArrayList<>();
      int ans = 0;

      for (int i = 0; i < n; i++) {
        String[] input = br.readLine().split(" ");
        String state = input[0];
        String code = input[1];
        String x = state.substring(0, 2) + code;

        count.put(x, count.getOrDefault(x, 0) + 1);
        stateInfo.add(new Pair(state.substring(0, 2), code));
      }

      for (Pair p : stateInfo) {
        if (!p.first.equals(p.second)) {
          String key = p.second + p.first;
          if (count.containsKey(key)) {
            ans += count.get(key);
          }
        }
      }

      bw.write((ans / 2) + "\n");
      bw.flush();
    }
  }

  static class Pair {

    String first, second;

    Pair(String first, String second) {
      this.first = first;
      this.second = second;
    }
  }
}