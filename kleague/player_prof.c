#include "헤더.h"

#define player_number 20


void player_prof();
void player_prof_C();
void player_prof_R();
void player_prof_U();

/********** 등록 관련 함수 **********/
void player_prof_C() {
	int hasRoom = 0;
	int seq = 99;
	char team_name[10];
	int tmp_id;
	char tmp_id_c[5];
	int valid = 0;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n선수 등록을 선택하셨습니다.\n");
	for (int i = 0; i < player_number; i++) {
		if (strlen(player_list[i].player_name) == 0) {
			seq = i;
			hasRoom = 1;
			break;
		}
	}

	if (hasRoom != 1) {
		printf("등록 가능한 선수 수를 넘어섰습니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
		player_prof();
	}

	printf("선수 이름 입력 : ");
	gets(player_list[seq].player_name);
	printf("입력하신 이름은 %s입니다.\n\n", player_list[seq].player_name);

	printf("소속 팀 입력 : ");
	gets(team_name);
	printf("입력하신 팀명은 %s입니다.\n\n", team_name);

	//존재하는 팀명인지 검증
	for (int i = 0; i < 10; i++) {
		if (strcmp(team_name, team_list[i].team_name) == 0) {
			tmp_id = team_list[i].team_id;
			valid = 1;
		}
	}

	if (valid == 0) {
		printf("입력하신 팀은 존재하지 않는 팀입니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
		strcpy(player_list[seq].player_name, "\0");
		player_prof();
	}

	printf("선수 키 입력 : ");
	scanf("%d", &player_list[seq].player_height);
	printf("입력하신 키는 %d입니다.\n\n", player_list[seq].player_height);

	printf("선수 몸무게 입력 : ");
	scanf("%d", &player_list[seq].player_weight);
	printf("입력하신 몸무게는 %d입니다.\n\n", player_list[seq].player_weight);

	printf("선수 등번호 입력 : ");
	scanf("%d", &player_list[seq].player_back_num);
	printf("입력하신 등번호는 %d입니다.\n\n", player_list[seq].player_back_num);
	getchar();

	printf("선수 포지션 입력 ( GK / DF / MF / FW 중 한가지로 입력 ) : ");
	gets(player_list[seq].player_position);
	printf("입력하신 포지션은 %s입니다.\n\n", player_list[seq].player_position);

	//선수 아이디 생성
	sprintf(tmp_id_c, "%d", tmp_id);
	strcpy(player_list[seq].player_id, tmp_id_c);
	strcat(player_list[seq].player_id, "-");
	sprintf(tmp_id_c, "%d", player_list[seq].player_back_num);
	strcat(player_list[seq].player_id, tmp_id_c);

	//사용여부(논리적 삭제 처리 위해) 기본값 Y 삽입
	player_list[seq].useYN = 'Y';

	//선수 기록에도 입력된 선수 정보 추가
	strcpy(player_history_list[seq].id, player_list[seq].player_id);
	player_history_list[seq].score = 0;
	player_history_list[seq].assistant = 0;
	player_history_list[seq].yellow_card = 0;
	player_history_list[seq].off_the_field = 0;
	player_history_list[seq].view_YN = 'Y';

	printf("%s", player_list[12].player_name);
	printf("선수가 등록되었습니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
	player_prof();
}

/********** 수정 관련 함수 **********/
void proc_update(int seq) {
	int cmd = 0;
	char tmp_id_c[5];

	system("cls");

	printf("---------------------------------------------------------------\n원하는 작업을 선택하세요\n");
	printf("1. 선수 이름 수정\n");
	printf("2. 소속 팀 수정\n");
	printf("3. 선수 키 수정\n");
	printf("4. 선수 몸무게 수정\n");
	printf("5. 선수 등번호 수정\n");
	printf("6. 선수 포지션 수정\n");
	printf("7. 선수 선택으로 돌아가기\n");
	printf("8. 선수 프로필 관리로 돌아가기\n");
	printf("9. 메인으로 돌아가기\n\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		printf("선수 이름 입력 : ");
		gets(player_list[seq].player_name);
		printf("수정된 이름은 %s입니다.\n\n", player_list[seq].player_name);

		proc_update(seq);
	}
	else if (cmd == 2) {
		char team_name[10];
		int tmp_id;
		int valid = 0;

		printf("소속 팀 입력 : ");
		gets(team_name);

		//존재하는 팀명인지 검증
		for (int i = 0; i < 10; i++) {
			if (strcmp(team_name, team_list[i].team_name) == 0) {
				tmp_id = team_list[i].team_id;
				valid = 1;
			}
		}

		if (valid == 0) {
			printf("입력하신 팀은 존재하지 않는 팀입니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
			strcpy(player_list[seq].player_name, "\0");
			player_prof();
		}

		//선수 아이디 생성
		sprintf(tmp_id_c, "%d", tmp_id);
		strcpy(player_list[seq].player_id, tmp_id_c);
		strcat(player_list[seq].player_id, "-");
		sprintf(tmp_id_c, "%d", player_list[seq].player_back_num);
		strcat(player_list[seq].player_id, tmp_id_c);

		printf("수정된 소속 팀은 %s입니다.\n\n", team_name);

		proc_update(seq);
	}
	else if (cmd == 3) {
		printf("선수 키 입력 : ");
		scanf("%d", &player_list[seq].player_height);
		getchar();
		printf("수정된 키는 %d입니다.\n\n", player_list[seq].player_height);

		proc_update(seq);
	}
	else if (cmd == 4) {
		printf("선수 몸무게 입력 : ");
		scanf("%d", &player_list[seq].player_weight);
		getchar();
		printf("수정된 몸무게는 %d입니다.\n\n", player_list[seq].player_weight);

		proc_update(seq);
	}
	else if (cmd == 5) {
		char tmp_id[5];

		printf("선수 등번호 입력 : ");
		scanf("%d", &player_list[seq].player_back_num);
		getchar();

		//선수 아이디 수정
		char* ptr = strtok(player_list[seq].player_id, "-");
		strcpy(player_list[seq].player_id, ptr);
		strcat(player_list[seq].player_id, "-");
		sprintf(tmp_id, "%d", player_list[seq].player_back_num);
		strcat(player_list[seq].player_id, tmp_id);

		printf("수정된 등번호는 %d입니다.\n\n", player_list[seq].player_back_num);

		proc_update(seq);
	}
	else if (cmd == 6) {
		printf("선수 포지션 입력 ( GK / DF / MF / FW 중 한가지로 입력 ) : ");
		gets(player_list[seq].player_position);
		printf("수정된 포지션은 %s입니다.\n\n", player_list[seq].player_position);

		proc_update(seq);
	}
	else if (cmd == 7) {
		player_prof_U();
	}
	else if (cmd == 8) {
		player_prof();
	}
	else if (cmd == 9) {
		main();
	}
	else {
		printf("잘못된 입력입니다. 선수 수정 메뉴로 돌아갑니다.\n\n");
		proc_update(seq);
	}
}

void player_prof_U() {
	char input[10];
	int seq = 99;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n선수 조회를 선택하셨습니다.\n");
	printf("수정을 원하는 선수의 이름 : \n");
	gets(input);

	for (int i = 0; i < player_number; i++) {
		if (strcmp(input, player_list[i].player_name) == 0) {
			seq = i;
			break;
		}
	}
	
	if (strlen(player_list[seq].player_name) != 0 && player_list[seq].useYN == 'Y') {
		proc_update(seq);
	}
	else {
		printf("저장되지 않은 선수 이름입니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
		player_prof();
	}
}

/********** 조회 관련 함수 **********/
void player_prof_R() {
	char input[10];
	int seq = 99;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n선수 조회를 선택하셨습니다.\n");
	printf("조회를 원하는 선수의 이름 : \n");
	gets(input);

	for (int i = 0; i < player_number; i++) {
		if (strcmp(input, player_list[i].player_name) == 0) {
			seq = i;
			break;
		}
	}

	if (strlen(player_list[seq].player_name) != 0 && player_list[seq].useYN == 'Y') {
		char team_name[50];
		int team_id = player_list[seq].player_id[0] - '0';
		printf("%d", team_id);

		//팀 ID로 팀명 받아오기 
		for (int i = 0; i < 10; i++) {
			if (team_id == team_list[i].team_id) {
				strcpy(team_name, team_list[i].team_name);
				break;
			}
		}

		printf("---------------------------------------------------------------\n");
		printf("선수ID\t선수명\t키\t몸무게\t등번호\t포지션\t소속팀\n");
		printf("---------------------------------------------------------------\n");
		printf("%s\t%s\t%dcm\t%dkg\t%d\t%s\t%s\n\n", player_list[seq].player_id, player_list[seq].player_name, player_list[seq].player_height, player_list[seq].player_weight,
			player_list[seq].player_back_num, player_list[seq].player_position, team_name);

		system("pause");
		player_prof();

	}
	else {
		printf("저장되지 않은 선수 이름입니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
		player_prof();
	}
}

/********** 삭제 관련 함수 **********/
void player_prof_D() {
	char input[10];
	int seq = 99;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n선수 삭제를 선택하셨습니다.\n");
	printf("삭제를 원하는 선수의 이름 : \n");
	gets(input);

	for (int i = 0; i < player_number; i++) {
		if (strcmp(input, player_list[i].player_name) == 0) {
			seq = i;
			break;
		}
	}

	if (strlen(player_list[seq].player_name) != 0 && player_list[seq].useYN == 'Y') {
		char cfm = NULL;

		printf("\n\n%s 선수를 정말 삭제하시겠습니까?( Y / N ) : ", input);
		scanf("%c", &cfm);

		if (cfm == 'Y') {
			player_list[seq].useYN = 'N';

			printf("삭제 처리되었습니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
			player_prof();
		}
		else {
			printf("취소를 선택하셨습니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
			player_prof();
		}
	}
	else {
		printf("저장되지 않은 선수 이름입니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
		player_prof();
	}
}

void player_prof() {
	int cmd = 0;

	system("cls");

	printf("---------------------------------------------------------------\n원하는 작업을 선택하세요\n");
	printf("1. 선수 등록\n");
	printf("2. 선수 수정\n");
	printf("3. 선수 조회\n");
	printf("4. 선수 삭제\n");
	printf("5. 메인으로 돌아가기\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		player_prof_C();
	}
	else if (cmd == 2) {
		player_prof_U();
	}
	else if (cmd == 3) {
		player_prof_R();
	}
	else if (cmd == 4) {
		player_prof_D();
	}
	else if (cmd == 5) {
		main();
	}
	else {
		printf("잘못된 입력입니다. 선수 프로필 메뉴로 돌아갑니다.\n\n");
		player_prof();
	}
}