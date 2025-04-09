import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

  static final int VISITED = 2, MUSHROOM = 0;
  static int[][] board = new int[101][101];
  static int N, M, K;
  static int[] dx = {-1, 0, 1, 0};
  static int[] dy = {0, -1, 0, 1};

  static Scanner sc = new Scanner(System.in);
  static List<Integer> list = new ArrayList<>();

  public static void main(String[] args) {
    N = sc.nextInt();
    M = sc.nextInt();
    K = sc.nextInt();

    for (int y = 1; y <= N; y++) {
      for (int x = 1; x <= N; x++) {
        board[y][x] = sc.nextInt();
      }
    }

    checkBoard();
    int remainingSpore = M - countRequiredSpore();

    if (remainingSpore < 0 || remainingSpore == M) {
      System.out.println("IMPOSSIBLE");
    } else {
      System.out.println("POSSIBLE\n" + remainingSpore);
    }
  }

  public static int countRequiredSpore() {
    int count = 0;

    for (int nodes : list) {
      count += nodes / K;

      if (nodes % K != 0) {
        count++;
      }
    }

    return count;
  }

  public static void checkBoard() {
    for (int y = 1; y <= N; y++) {
      for (int x = 1; x <= N; x++) {
        if (board[y][x] == MUSHROOM) {
          list.add(visitAndCountAllReachableNodes(x, y));
        }
      }
    }
  }

  public static int visitAndCountAllReachableNodes(int x, int y) {
    int count = 1;
    board[y][x] = VISITED;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > N || ny < 1 || ny > N || board[ny][nx] != MUSHROOM) {
        continue;
      }

      count += visitAndCountAllReachableNodes(nx, ny);
    }

    return count;
  }
}
