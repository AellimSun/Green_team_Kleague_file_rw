#include "헤더.h"

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
	txt_read();

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