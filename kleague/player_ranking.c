#include "헤더.h"

typedef struct
{
	char player_name[10];
	char team_name[50];
	int value;
	char useYN;
} player_rank_info;

player_rank_info player_rank_list[player_number];

void sorting_player(int by) {
	for (int i = 0; i < player_number; i++) {
		//선수명 가져오기
		strcpy(player_rank_list[i].player_name, player_list[i].player_name);

		//팀명 가져오기
		if (strlen(player_rank_list[i].player_name) != 0) {
			char* ptr = strtok(player_list[i].player_id, "-");
			int tmp_id = atoi(ptr);
		
			for (int j = 0; j < 10; j++) {
				int  team_id = team_list[j].team_id;
				if (team_id == tmp_id) {
					strcpy(player_rank_list[i].team_name, team_list[j].team_name);
					break;
				}
			}
		}

		//사용여부 가져오기
		player_rank_list[i].useYN = player_list[i].useYN;

		if (by == 1) {
			//득점값 가져오기
			player_rank_list[i].value = player_history_list[i].score;
		}
		else if (by == 2) {
			//도움값 가져오기
			player_rank_list[i].value = player_history_list[i].assistant;
		}
			
	}

	//득점 혹은 도움 순서로 정렬
	while (1) {
		int flag = 0;
		player_rank_info tmp[1];
			
		for (int i = 0; i < player_number - 1; i++) {
			if (player_rank_list[i].value < player_rank_list[i + 1].value) {
				//i번째와 i+1번째를 통째로 교환하기 위해 임시로 값을 저장
				strcpy(tmp[0].player_name, player_rank_list[i].player_name);
				strcpy(tmp[0].team_name, player_rank_list[i].team_name);
				tmp[0].value = player_rank_list[i].value;
				tmp[0].useYN = player_rank_list[i].useYN;

				//i번째에 i+1번째 값 저장
				strcpy(player_rank_list[i].player_name, player_rank_list[i + 1].player_name);
				strcpy(player_rank_list[i].team_name, player_rank_list[i + 1].team_name);
				player_rank_list[i].value = player_rank_list[i+1].value;
				player_rank_list[i].useYN = player_rank_list[i + 1].useYN;

				//i+1번째에 임시저장한 값(원래 i번째 값) 저장
				strcpy(player_rank_list[i + 1].player_name, tmp[0].player_name);
				strcpy(player_rank_list[i + 1].team_name, tmp[0].team_name);
				player_rank_list[i + 1].value = tmp[0].value;
				player_rank_list[i + 1].useYN = tmp[0].useYN;
			}
		}

		for (int i = 0; i < player_number; i++) {
			if (player_rank_list[i].value < player_rank_list[i + 1].value) {
				flag = 1;
			}
		}

		if (flag == 0) {
			break;
		}
	}
}

void player_ranking()
{
	system("cls");
	int cmd = 0;
	int rank = 1;
	char std[5];

	printf("---------------------------------------------------------------\n원하는 작업을 선택하세요\n");
	printf("1. 득점왕 랭킹 보기\n");
	printf("2. 도움왕 랭킹 보기\n");
	printf("3. 이전으로\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		sorting_player(1);
		strcpy(std, "득점");
	}
	else if (cmd == 2) {
		sorting_player(2);
		strcpy(std, "득점");
	}
	else {
		ranking();
	}
	system("cls");
	printf("---------------------------------------------------------------\n");
	printf("순위\t팀명\t\t\t선수명\t%s수\n", std);
	printf("---------------------------------------------------------------\n");
	for (int i = 0; i < player_number; i++) {
		if (player_rank_list[i].useYN == 'Y') {
			printf("%d위\t%s\t%s\t%d\n\n", rank, player_rank_list[i].team_name, player_rank_list[i].player_name, player_rank_list[i].value);
			rank++;
			if (rank > 5) {
				break;
			}
		}
	}
	system("pause");
	player_ranking();
}

