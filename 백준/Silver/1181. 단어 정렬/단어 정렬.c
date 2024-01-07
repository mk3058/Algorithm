#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *word1, const void *word2) {
	if (strlen(word1) > strlen(word2)) return (1);
	else if (strlen(word1) < strlen(word2)) return (-1);
	else return (strcmp(word1, word2));
}

int main() {
	int n;
	char words[20000][51] = {};

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", words[i]);
		for (int j = 0; j < i; j++) {
			if (strcmp(words[j], words[i]) == 0) {
				i--;
				n--;
				break;
			}
		}
	}
	qsort(words[0], n, sizeof(*words), compare);
	for(int i = 0; i < n; i++)
		printf("%s\n", words[i]);
}