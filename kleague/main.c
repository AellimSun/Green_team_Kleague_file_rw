#include "헤더.h"

team_hist team_hist_list[100];

void ranking() {
	int cmd = 0;
	
	system("cls");




	printf("---------------------------------------------------------------\n원하는 작업을 선택하세요\n");
	printf("1. 선수 랭킹 보기\n");
	printf("2. 팀 랭킹 보기\n");
	printf("3. 이전으로\n");

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
		printf("입력오류입니다.");
		ranking();
	}
}

void player_mng() {
	int cmd = 0;

	system("cls");

	printf("---------------------------------------------------------------\n원하는 작업을 선택하세요\n");
	printf("1. 선수 프로필\n");
	printf("2. 선수 기록 관리\n");
	printf("3. 이전으로\n");

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
		printf("입력오류입니다.");
		ranking();
	}
}

int main(void) {
	int cmd = 0;

	system("cls");

	FILE* THT;

	THT = fopen("team_history.txt", "r");

	if (THT == NULL) {
		printf("파일이 열리지 않았습니다.\n");
	}
	int i = 0;

	for (i = 0; i < 12; i++)
	{
		fscanf(THT, "%d %d %d %s %s %d %d %c", 
			&team_hist_list[i].team_hist_year, &team_hist_list[i].team_hist_month, &team_hist_list[i].team_hist_date, &team_hist_list[i].team_hist_home, 
			&team_hist_list[i].team_hist_away, &team_hist_list[i].team_hist_homegoal, &team_hist_list[i].team_hist_awaygoal, &team_hist_list[i].team_hist_datadelete);
	}
	fclose(THT);

	printf("---------------------------------------------------------------\n원하는 작업을 선택하세요\n");
	printf("1. 선수 관리\n");
	printf("2. 팀 관리\n");
	printf("3. 경기 결과\n");
	printf("4. 랭킹\n\n");

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