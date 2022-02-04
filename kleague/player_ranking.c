#include "���.h"

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
		//������ ��������
		strcpy(player_rank_list[i].player_name, player_list[i].player_name);

		//���� ��������
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

		//��뿩�� ��������
		player_rank_list[i].useYN = player_list[i].useYN;

		if (by == 1) {
			//������ ��������
			player_rank_list[i].value = player_history_list[i].score;
		}
		else if (by == 2) {
			//���� ��������
			player_rank_list[i].value = player_history_list[i].assistant;
		}
			
	}

	//���� Ȥ�� ���� ������ ����
	while (1) {
		int flag = 0;
		player_rank_info tmp[1];
			
		for (int i = 0; i < player_number - 1; i++) {
			if (player_rank_list[i].value < player_rank_list[i + 1].value) {
				//i��°�� i+1��°�� ��°�� ��ȯ�ϱ� ���� �ӽ÷� ���� ����
				strcpy(tmp[0].player_name, player_rank_list[i].player_name);
				strcpy(tmp[0].team_name, player_rank_list[i].team_name);
				tmp[0].value = player_rank_list[i].value;
				tmp[0].useYN = player_rank_list[i].useYN;

				//i��°�� i+1��° �� ����
				strcpy(player_rank_list[i].player_name, player_rank_list[i + 1].player_name);
				strcpy(player_rank_list[i].team_name, player_rank_list[i + 1].team_name);
				player_rank_list[i].value = player_rank_list[i+1].value;
				player_rank_list[i].useYN = player_rank_list[i + 1].useYN;

				//i+1��°�� �ӽ������� ��(���� i��° ��) ����
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

	printf("---------------------------------------------------------------\n���ϴ� �۾��� �����ϼ���\n");
	printf("1. ������ ��ŷ ����\n");
	printf("2. ����� ��ŷ ����\n");
	printf("3. ��������\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		sorting_player(1);
		strcpy(std, "����");
	}
	else if (cmd == 2) {
		sorting_player(2);
		strcpy(std, "����");
	}
	else {
		ranking();
	}
	system("cls");
	printf("---------------------------------------------------------------\n");
	printf("����\t����\t\t\t������\t%s��\n", std);
	printf("---------------------------------------------------------------\n");
	for (int i = 0; i < player_number; i++) {
		if (player_rank_list[i].useYN == 'Y') {
			printf("%d��\t%s\t%s\t%d\n\n", rank, player_rank_list[i].team_name, player_rank_list[i].player_name, player_rank_list[i].value);
			rank++;
			if (rank > 5) {
				break;
			}
		}
	}
	system("pause");
	player_ranking();
}

