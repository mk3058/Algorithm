import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  /**
   * 지나간적 없는 알파벳이 있는 칸만 갈 수 있음. -> 그냥 N^2 탐색?
   */
  static int row, col;
  static char[][] map;
  static boolean[] alpha;
  static int[] dx = {1, -1, 0, 0};
  static int[] dy = {0, 0, 1, -1};
  static int max = Integer.MIN_VALUE;

  public static void main(String[] args) throws IOException {

    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
      String[] split = br.readLine().split(" ");
      row = Integer.parseInt(split[0]);
      col = Integer.parseInt(split[1]);

      alpha = new boolean[26];
      map = new char[row][col];

      for (int i = 0; i < row; i++) {
        map[i] = br.readLine().toCharArray();
      }
      find(0, 0, 1);
      System.out.println(max);
    }
  }

  public static void find(int x, int y, int count) {
    if (x < 0 || y < 0 || x > row - 1 || y > col - 1) {
      return;
    }
    if (alpha[map[x][y] - 'A']) {
      return;
    }

    alpha[map[x][y] - 'A'] = true;
    max = Math.max(max, count);

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      find(nx, ny, count + 1);
    }

    alpha[map[x][y] - 'A'] = false;
  }
}
