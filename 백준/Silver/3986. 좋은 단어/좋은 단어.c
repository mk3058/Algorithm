#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char ch;
	struct node *next;
} s_node;

s_node *push(s_node *head, char content)
{
	s_node *new = malloc(sizeof(s_node));

	new->ch = content;
	if(head)
		new->next = head;
	else
		new->next = NULL;
	return (new);
}

s_node *pop(s_node *head)
{
	s_node *tmp = head->next;

	free(head);
	return (tmp);
}

void destroy_list(s_node *head)
{
	s_node *tmp;

	while (head){
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

int is_good(char *str){

	int len = strlen(str);
	s_node *head = NULL;

	if (len % 2 != 0) return 0;

	for(int i = 0; str[i]; i++) {
		if (!head || head->ch != str[i])
			head = push(head, str[i]);
		else
			head = pop(head);
	}
	destroy_list(head);
	return (head == NULL ? 1 : 0);
}

int main() {
	int goot_word = 0;
	char *str = malloc(100001);
	int N;

	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", str);
		goot_word += is_good(str);
	}
	printf("%d", goot_word);
	free(str);
	return (0);
}
