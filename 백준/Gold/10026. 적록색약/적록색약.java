import java.util.Scanner;

public class Main {

  static final char RED = 'R', GREEN = 'G', BLUE = 'B', VISITED = 'V';
  static char[][] map1 = new char[101][101];
  static char[][] map2 = new char[101][101];
  static int N;
  static int[] dx = {1, -1, 0, 0};
  static int[] dy = {0, 0, 1, -1};

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();
    sc.nextLine();
    for (int y = 1; y <= N; y++) {
      String line = sc.nextLine();
      for (int x = 1; x <= N; x++) {
        map1[y][x] = line.charAt(x - 1);
        if (map1[y][x] != BLUE) {
          map2[x][y] = RED;
        } else {
          map2[x][y] = BLUE;
        }
      }
    }

    System.out.printf("%d %d", findArea(map1), findArea(map2));
  }

  public static int findArea(char[][] map) {
    int area = 0;

    for (int y = 1; y <= N; y++) {
      for (int x = 1; x <= N; x++) {
        if (map[y][x] != VISITED) {
          area++;
          visitAllReachableNode(map, x, y);
        }
      }
    }

    return area;
  }

  public static void visitAllReachableNode(char[][] map, int x, int y) {
    char color = map[y][x];
    map[y][x] = VISITED;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > N || ny < 1 || ny > N || map[ny][nx] != color) {
        continue;
      }
      visitAllReachableNode(map, nx, ny);
    }
  }
}
