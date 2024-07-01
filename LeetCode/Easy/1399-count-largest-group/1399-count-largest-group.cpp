class Solution {
public:
    /**
        그룹 : [1, n]의 수 중 수의 각 자리수를 더해서 특정 수가 되는 수의 집합
        원소 개수가 가장 많은 그룹의 개수 찾기
        
        입력 제한이 [1, 10000] 이므로 각 자리수의 합은 36을 넘지 않음(9999 일때)
        각 자리수의 합을 인덱스로 하는 정수 배열을 만들고, 그룹 내 원소의 수를 기록
        배열을 순회하면서, 최대 개수인 경우를 세서 반환
    */
    
    int countLargestGroup(int n) {
        int arr[37] = {}; // 원소의 개수를 카운트 할 배열
        int max = INT_MIN; // 최대 원소 개수
        int res = 0;

        for(int i = 1; i <= n; i++) {
            string num = to_string(i);
            int digitSum = 0;

            for(int j = 0; j < num.size(); j++) {
                char digit = num.at(j);
                digitSum += (digit - '0');
                    // 아스키 코드 상 (수의 문자형) - '0' = (해당 숫자)
            }  
            arr[digitSum]++;
            if (arr[digitSum] > max) {
                max = arr[digitSum];
            }
        }

        for(int i = 1; i < 37; i++) {
            if (arr[i] == max) {
                res++;
            }
        }

        return res;
    }
};