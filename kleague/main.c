#include "���.h"

team_hist team_hist_list[100];

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

	FILE* THT;

	THT = fopen("team_history.txt", "r");

	if (THT == NULL) {
		printf("������ ������ �ʾҽ��ϴ�.\n");
	}
	int i = 0;

	for (i = 0; i < 12; i++)
	{
		fscanf(THT, "%d %d %d %s %s %d %d %c", 
			&team_hist_list[i].team_hist_year, &team_hist_list[i].team_hist_month, &team_hist_list[i].team_hist_date, &team_hist_list[i].team_hist_home, 
			&team_hist_list[i].team_hist_away, &team_hist_list[i].team_hist_homegoal, &team_hist_list[i].team_hist_awaygoal, &team_hist_list[i].team_hist_datadelete);
	}
	fclose(THT);

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