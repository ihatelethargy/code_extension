#include <stdio.h>

int main()
{
	char answer[11]; // �迭����, ���ڿ��� �Է¹��� ���̱⿡ 11�� ����
	int score, sum;
	sum = 0;
	score = 1;

	scanf("%s", answer); // ���ڿ� �Է�
	for (int i = 0; i < 10; i++) {
		if (answer[i] == 'O')
		{
			sum += score; // O�� score�� sum�� ���Ѵ�
			score++;
		}
		if (answer[i] == 'X')
			score = 1; // X�� score�� 1�� �ʱ�ȭ
	}
	printf("%d\n", sum);

}