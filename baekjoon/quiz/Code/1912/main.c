#include<stdio.h>

#define MAX_INPUT 100000
#define MAX(x,y) ((x > y) ? x:y)

void main() {
	int _input_cnt;
	int _number_bucket[MAX_INPUT];
	int i, _ret = -9999;

	scanf("%d", &_input_cnt);

	for (i = 0; i < _input_cnt; i++) {
		scanf("%d", &_number_bucket[i]);
	}

	// �迭�� �� ������ Ȯ�ο� ���.
	/*for (i = 0; i < _input_cnt; i++) {
		printf("[ %d ]", _number_bucket[i]);
	}*/

	/*printf("\n");*/

	// ������ ���� Ǯ�� ���� Ǯ����.
	// ���ӵ� ���ڸ� ���� �ϹǷ�. �� �������� �ڱ� �ڽŸ� ������ �� �ִ�.
	// �ڿ��� �ι�° ���ڴ� �ڱ� �ڽŰ� ������ ���ڸ� ���� �� �� �ִµ�
	// ���⼭ �ڱ� �ڽ� + ������, �ڱ� �ڽ��� ���ؼ� �� ū���� �����ϸ�
	// �� ���� �������� �����Ҷ� ���� ū ���� �����ϰ� �Ǵ� ���̴�.
	for (i = _input_cnt - 2; i >= 0; i--) {
		_number_bucket[i] = MAX(_number_bucket[i], _number_bucket[i] + _number_bucket[i + 1]);
	}

	// ����� �� ����� Ȯ�ο� ���.
	/*for (i = 0; i < _input_cnt; i++) {
		printf("[ %d ]", _number_bucket[i]);
	}*/

	for (i = 0; i < _input_cnt; i++) {
		_ret = MAX(_ret, _number_bucket[i]);
	}

	printf("%d", _ret);
	
}