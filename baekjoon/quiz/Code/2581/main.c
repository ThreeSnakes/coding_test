#include<stdio.h>

int main(void) {
	int min, max, sum = 0, min_primary_number = 0, i;
	
	scanf("%d", &min);
	scanf("%d", &max);

	for (min; min <= max; min++) {
		for (i = 2; i <= min; i++) {		
			if (min == 2) {
				min_primary_number = 2;
				sum = sum + 2;
				break;
			}

			if (min%i == 0) {
				break;
			}

			//������ ������ ����ѰŸ� �װ��� �Ҽ�.
			if (i == min - 1) {
				// min �� ���. for������ ���� ������ ó�� ���� �ԷµǸ�
				// �� ���ķδ� �� �Է� X.
				if (min_primary_number == 0) {
					min_primary_number = min;
				}

				//printf("prime_number = %d\n", min);
				sum = sum + min;

				// �ѹ� �� ���ʿ� ����. break������ Ż��.
				break;
			}
		}
	}

	if (sum != 0) {
		printf("%d\n", sum);
		printf("%d\n", min_primary_number);
	}
	else {
		printf("-1");
	}

	return 0;
}