#include<iostream>
using namespace std;

// ==============================================
// =            function definition             =
// ==============================================
int** init(int, int);
bool seek_dirty_area(int**, int, int, int);
int reverse_direction(int);\
void free(int***, int);
// ==============================================

// �������� ����� ���⿡ ���� �������Դϴ�.
// 0: ��, 1: ��, 2: ��, 3: ��
int loX[] = {-1, 0, 1, 0};
int loY[] = { 0, 1, 0, -1};

int main(void) {

	int rx, ry, d;
	int n, m;
	int clean = 0;
	// 4���� üũ ����(seek), �˻��� ����(check_d)
	int seek, check_d;

	cin >> n >> m;
	cin >> rx >> ry >> d;

	// �� ���� ������ �����ϴ� 2���� ������ �迭 ����
	int** room = init(n, m);

	while (true) {

		if (room[rx][ry] == 0) {
			room[rx][ry] = -1;
			clean += 1;
		}
		seek = 0;
		check_d = d;

		while(seek != 15) {
			check_d = (check_d == 0 ? 3 : check_d - 1);
			// û���� ������ �ִ��� Ȯ���մϴ�.
			if (seek_dirty_area(room, rx, ry, check_d)) {
				// �ִٸ� �κ��� ������ �����ϴ�. (d -> check_d)
				d = check_d;
				break;
			}
			d = check_d;
			// û���� ���� üũ
			seek |= (1 << check_d);
		}

		// seek ���� 15��°� 4���� ��� Ž���ߴٴ� ��
		if (seek == 15) {
			int reverse_d = reverse_direction(d);
			// �������� �� ���̶�� �� �̻� �� ���� �����Ƿ� ����
			if (room[rx + loX[reverse_d]][ry + loY[reverse_d]] == 1) {
				break;
			}
			// �������� �� ���� �ƴ϶� ����(û���ߵ� ���ߵ�)�̶�� �̵�
			rx += loX[reverse_d];
			ry += loY[reverse_d];
		}
		// seek ���� 15�� �ƴ϶�� ������
		// û���� ������ ��� �ϳ��� �ִٴ� ��
		else {
			rx += loX[d];
			ry += loY[d];
		}
	}
	// û���� ���� ���
	cout << clean << endl;
	// memory free
	free(&room, n);
	return 0;
}

// �ʱ�ȭ �Լ��Դϴ�.
// 
// �迭�� N * M ũ�⸸ŭ �����ϰ�,
// ���� �Է¹޾� �Ҵ��� 2���� �迭�� ��ȯ�մϴ�.
int** init(int n, int m) {

	int** matrix = nullptr;
	matrix = new int* [n];
	for (int i = 0; i < n; i += 1) {
		matrix[i] = new int[m];
	}

	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1)
			cin >> matrix[i][j];
	}
	return matrix;
}

// �ش� ������ û������ ���� �������� Ȯ���ϴ� �Լ��Դϴ�.
bool seek_dirty_area(int** room, int rx, int ry, int check_d) {
	int x = rx + loX[check_d];
	int y = ry + loY[check_d];
	return room[x][y] == 0;
}

// �ݴ������ ��ȯ�ϴ� �Լ��Դϴ�.
// ex: 0001 XOR 0010 = 0011
int reverse_direction(int current_d) {
	return current_d ^ (1 << 1);
}

// �Ҵ��� memory�� �ٽ� ��ȯ�ϴ� �Լ��Դϴ�.
void free(int*** matrix, int n) {

	for (int i = 0; i < n; i += 1)
		delete[] (*matrix)[i];
	delete *matrix;
}
