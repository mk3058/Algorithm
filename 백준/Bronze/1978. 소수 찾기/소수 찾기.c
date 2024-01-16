#include <stdio.h>
#include <math.h>

int is_prime(int num) {

	if (num < 2)
		return (0);

	for(int i = 2; i <= (int)sqrt((double)num); i++) {
		if (num % i == 0) return (0);
	}
	return 1;
}

int main() {
	int N;
	int num;
	int cnt = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		cnt += is_prime(num);	
	}
	printf("%d", cnt);
}