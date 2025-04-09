import java.util.Scanner;

public class Main {

  static final int LAND = 1, VISITED = 2;
  static final int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
  static final int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
  static int[][] map = new int[51][51];
  static int w, h;
  static int count = 0;
  static Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {
    while (true) {
      if (init() == 1) {
        break;
      }
      countLands();
      System.out.println(count);
    }
  }

  public static int init() {
    count = 0;
    w = scanner.nextInt();
    h = scanner.nextInt();

    if (w == 0 && h == 0) {
      return 1;
    }

    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        map[i][j] = scanner.nextInt();
      }
    }
    return 0;
  }

  public static void countLands() {
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (map[i][j] == LAND) {
          count++;
          visitAllReachableLand(j, i);
        }
      }
    }
  }

  public static void printLands() {
    System.out.println();
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        System.out.printf("%d ", map[i][j]);
      }
      System.out.println();
    }
    System.out.println();
  }

  public static void visitAllReachableLand(int x, int y) {
    map[y][x] = VISITED;

    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > w || ny < 1 || ny > h || map[ny][nx] != LAND) {
        continue;
      }
      visitAllReachableLand(nx, ny);
    }
  }
}
