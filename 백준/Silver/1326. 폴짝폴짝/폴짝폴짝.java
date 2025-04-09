import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

  public static void findMinimumJumps(int n, int start, int target, int[] jumps, int[] steps,
      boolean[] visited) {
    Queue<Integer> queue = new LinkedList<>();
    queue.offer(start);
    visited[start] = true;

    while (!queue.isEmpty()) {
      int current = queue.poll();

      if (current == target) {
        return;
      }

      for (int next = current + jumps[current]; next <= n; next += jumps[current]) {
        if (!visited[next]) {
          steps[next] = steps[current] + 1;
          visited[next] = true;
          queue.offer(next);
        }
      }

      for (int next = current - jumps[current]; next >= 1; next -= jumps[current]) {
        if (!visited[next]) {
          steps[next] = steps[current] + 1;
          visited[next] = true;
          queue.offer(next);
        }
      }
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();

    int[] jumps = new int[n + 1];
    int[] steps = new int[n + 1];
    boolean[] visited = new boolean[n + 1];

    for (int i = 1; i <= n; i++) {
      jumps[i] = scanner.nextInt();
    }

    int start = scanner.nextInt();
    int target = scanner.nextInt();

    if (start == target) {
      System.out.println(0);
      return;
    }

    findMinimumJumps(n, start, target, jumps, steps, visited);

    System.out.println(steps[target] == 0 ? -1 : steps[target]);
  }
}
