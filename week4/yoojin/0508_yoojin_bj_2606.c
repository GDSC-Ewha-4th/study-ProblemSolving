#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ConnectedComp[100][100]; //����� ��ǻ�� 2���� �迭
int check[100]; //Ž�� �ߴ��� ���θ� ����

void check_connected_comp(int n, int k);
int virus = 0;

int main(void) {
	// 1. �Է� �ޱ�
	int n, connected_comps;
	int a, b;
	int k = 0;
	scanf("%d", &n);
	scanf("%d", &connected_comps);

	for (int i = 0; i < connected_comps; i++) {
		scanf("%d %d", &a, &b);
		ConnectedComp[a-1][b-1] = 1; //0���� �����ϴϱ� -1 ���־����.
		ConnectedComp[b - 1][a - 1] = 1; //��Ī
	}

	
	check_connected_comp(n, k); //k�� ��ǻ�Ϳ� ����� ��ǻ���� ���� ���
	
	// 5. ���
	printf("%d", virus);
	return 0;
}


void check_connected_comp(int n, int k) {
	check[0] = 1; //ù��° ��ǻ�ͺ��� üũ
	for (int i = 0; i < n; i++) { //��ǻ�� ��ȣ

		// 2. ��� ��� 
		// ���� �˻����� �ʾҰ� ����������� count
		if (check[i] == 0 && ConnectedComp[k][i] == 1) {
			check[i] = 1;
			// 3. i�� ��ǻ�Ϳ� ����� ���� Ž��
			check_connected_comp(n, i);
			// 4. ���̷��� ����
			virus++;
		}
	}
}
