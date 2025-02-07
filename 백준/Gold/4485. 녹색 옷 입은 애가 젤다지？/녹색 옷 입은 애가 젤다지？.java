import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class Main {

  static int N;
  static int[] dx = {1, -1, 0, 0};
  static int[] dy = {0, 0, 1, -1};

  public static void main(String[] args) throws IOException {
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      for (int roop = 1; true; roop++) {
        N = Integer.parseInt(br.readLine());
        if (N == 0) {
          return;
        }

        int[][] cost = new int[N][N];

        for (int i = 0; i < N; i++) {
          List<Integer> input = Arrays.stream(br.readLine().split(" "))
              .map(Integer::parseInt)
              .collect(Collectors.toList());
          for (int j = 0; j < N; j++) {
            cost[i][j] = input.get(j);
          }
        }

        System.out.printf("Problem %d: %d\n", roop, dijkstra(cost));
      }
    }
  }

  public static int dijkstra(int[][] cost) {
    int[][] dist = new int[N][N];
    for (int[] row : dist) {
      Arrays.fill(row, Integer.MAX_VALUE);
    }

    PriorityQueue<Node> pq = new PriorityQueue<>();
    pq.add(new Node(0, 0, cost[0][0]));
    dist[0][0] = cost[0][0];

    while (!pq.isEmpty()) {
      Node node = pq.poll();
      int x = node.x;
      int y = node.y;
      int currentCost = node.cost;

      if (x == N - 1 && y == N - 1) {
        return currentCost;
      }

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
          int newCost = currentCost + cost[nx][ny];

          if (newCost < dist[nx][ny]) {
            dist[nx][ny] = newCost;
            pq.add(new Node(nx, ny, newCost));
          }
        }
      }
    }

    return -1;
  }

  static class Node implements Comparable<Node> {

    int x, y, cost;

    Node(int x, int y, int cost) {
      this.x = x;
      this.y = y;
      this.cost = cost;
    }

    @Override
    public int compareTo(Node other) {
      return Integer.compare(this.cost, other.cost);
    }
  }
}