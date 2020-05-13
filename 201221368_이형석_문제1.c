#include <stdio.h>

int main()
{
	char answer[11]; // 배열선언, 문자열로 입력받을 것이기에 11로 선언
	int score, sum;
	sum = 0;
	score = 1;

	scanf("%s", answer); // 문자열 입력
	for (int i = 0; i < 10; i++) {
		if (answer[i] == 'O')
		{
			sum += score; // O면 score를 sum에 더한다
			score++;
		}
		if (answer[i] == 'X')
			score = 1; // X면 score를 1로 초기화
	}
	printf("%d\n", sum);

}