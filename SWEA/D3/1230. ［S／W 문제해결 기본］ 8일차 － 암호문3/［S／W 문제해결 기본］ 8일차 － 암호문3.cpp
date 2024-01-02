#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
	vector<int> code;
	vector<int>::iterator iter;
 	int T = 10, original_code_length, number_of_cmd;
	int x, y, s;
	char cmd;

	//freopen("input.txt", "r", stdin);

	for(int test_case = 1; test_case <= T; test_case++) {
		cin >> original_code_length;
		code.clear();

		for(int i = 0; i < original_code_length; i++) {
			cin >> s;
			code.push_back(s);
		}
		
		cin >> number_of_cmd;
		for(int i = 0; i < number_of_cmd; i++) {
			cin >> cmd;
			iter = code.begin();
			switch (cmd)
			{
			case 'I':
				cin >> x >> y;
				for(int j = 0; j < y; j++) {
					cin >> s;
					code.insert(iter + x + j, s);
				}
				break;
			
			case 'D':
				cin >> x >> y;
				code.erase(iter + x, iter + x + y);
				break;

			case 'A':
				cin >> y;
				for (int j = 0; j < y; j++) {
					cin >> s;
					code.push_back(s);
				}
				break;
			}
		}
		printf("#%d", test_case);
		for(int i = 0; i < 10; i++) {
			printf(" %d", code.at(i));
		}
		printf("\n");
	}
	return (0);
}