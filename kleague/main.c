#include "���.h"

void ranking() {
	int cmd = 0;
	
	system("cls");




	printf("---------------------------------------------------------------\n���ϴ� �۾��� �����ϼ���\n");
	printf("1. ���� ��ŷ ����\n");
	printf("2. �� ��ŷ ����\n");
	printf("3. ��������\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		player_ranking();
	}
	else if (cmd == 2) {
		team_ranking();
	}
	else if (cmd == 3){
		main();
	}
	else {
		printf("�Է¿����Դϴ�.");
		ranking();
	}
}

void player_mng() {
	int cmd = 0;

	system("cls");

	printf("---------------------------------------------------------------\n���ϴ� �۾��� �����ϼ���\n");
	printf("1. ���� ������\n");
	printf("2. ���� ��� ����\n");
	printf("3. ��������\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		player_prof();
	}
	else if (cmd == 2) {
		player_history();
	}
	else if (cmd == 3) {
		main();
	}
	else {
		printf("�Է¿����Դϴ�.");
		ranking();
	}
}

int main(void) {
	int cmd = 0;

	system("cls");
	txt_read();

	printf("---------------------------------------------------------------\n���ϴ� �۾��� �����ϼ���\n");
	printf("1. ���� ����\n");
	printf("2. �� ����\n");
	printf("3. ��� ���\n");
	printf("4. ��ŷ\n\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		player_mng();
	}
	else if (cmd == 2) {
		team();
	}
	else if (cmd == 3) {
		result();
	}
	else if (cmd == 4) {
		ranking();
	}

	return 0;
}