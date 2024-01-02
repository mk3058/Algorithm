#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODE 1000

int N, M, X;
int graph[MAX_NODE][MAX_NODE], graph_reverse[MAX_NODE][MAX_NODE];
int visit[MAX_NODE], cost[MAX_NODE], round_cost[MAX_NODE];

void create_edge(int start, int end, int cost) {

	graph[start][end] = cost;
	graph_reverse[end][start] = cost;
}

void init_graph(int size) {

	for(int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			graph[i][j] = INT_MAX;
			graph_reverse[i][j] = INT_MAX;
		}
	}
}

int find_next_node(int *cost) {

	int min = INT_MAX;
	int node = -1;

	for(int i = 0; i < N; i++) {
		if (!visit[i] && cost[i] < min) {
			min = cost[i];
			node = i;
		}
	}
	return (node);
}

void dijkstra(int start, int (*graph)[MAX_NODE], int *cost) {

	int current = start;

	for(int i = 0; i < N; i++) {
		cost[i] = graph[current][i];
		visit[i] = false;
	}
	visit[current] = true;

	for (int i = 0; i < N; i++) {
		current = find_next_node(cost);
		if (current == -1) break;
		visit[current] = true;
	
		for(int j = 0; j < N; j++) {
			if (!visit[j] && graph[current][j] != INT_MAX && cost[current] + graph[current][j] < cost[j]) {
				cost[j] = cost[current] + graph[current][j];
			}
		}
	}
}

int main() {

	int start, end, c;
	int max = INT_MIN;

	scanf("%d %d %d", &N, &M, &X);
	init_graph(N);
	X--;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &start, &end, &c);
		start--; end--;

		create_edge(start, end, c);
	}

	dijkstra(X, graph, cost);
	dijkstra(X, graph_reverse, round_cost);
	for(int i = 0; i < N; i++) {
		if (i == X) continue;
		round_cost[i] += cost[i];
		if (round_cost[i] > max) max = round_cost[i];
	}
	printf("%d", max);
}