#include<stdio.h>

int main(void) {
	int cnt;
	int bucket[100];
	int prime_number_cnt = 0;
	int i = 0;
	
	scanf("%d", &cnt);

	//�迭�� �Է� �޾Ƽ� ������ ���´�.
	for (i = 0; i < cnt; i++) {
		scanf("%d", &bucket[i]);
	}

	//printf("cnt = %d\n", cnt);

	for (i = 0; i < cnt; i++) {
		for (int j = 2; j <= bucket[i]; j++) {
			// 1�� �Ҽ��� �ƴϹǷ� ����, 1 ���ϵ� ����.
			if (bucket[i] <= 1) {
				break;
			}
			
			// 2�� �Ҽ� �̹Ƿ� prime_number_cnt ����.
			if (bucket[i] == 2) {
				prime_number_cnt++;
				break;
			}
			// ������ üũ.
			if (bucket[i] % j == 0) {
				break;
			}

			// �ڱ� �ڽ� -1 ���� ������� ������ prime_number_cnt ����.
			if (j == bucket[i] - 1) {
				printf("add Prime_Number_Cnt bucket = %d, i = %d, j = %d \n", bucket[i], i, j);
				prime_number_cnt++;
			}
		}
	}

	//���������� ���.
	printf("%d", prime_number_cnt);
	
	return 0;
}