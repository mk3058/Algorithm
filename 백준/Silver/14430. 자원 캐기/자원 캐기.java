import java.util.Scanner;

public class Main {

  static final int RESOURCE = 1;
  static int[][] map = new int[301][301];
  static int[][] dp = new int[301][301];
  static int N, M;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();
    M = sc.nextInt();

    for (int y = 1; y <= N; y++) {
      for (int x = 1; x <= M; x++) {
        map[y][x] = sc.nextInt();
      }
    }

    for (int y = 1; y <= N; y++) {
      for (int x = 1; x <= M; x++) {
        dp[y][x] = findCurVal(x, y);
      }
    }
    System.out.println(dp[N][M]);
  }

  public static int findCurVal(int x, int y) {
    int prevX = x - 1, prevY = y - 1;
    int prevMax = 0;

    if (prevX >= 1 && prevY >= 1) {
      prevMax = Math.max(dp[y - 1][x], dp[y][x - 1]);
    } else if (prevX >= 1) {
      prevMax = dp[y][prevX];
    } else if (prevY >= 1) {
      prevMax = dp[prevY][x];
    }

    return prevMax + map[y][x];
  }
}