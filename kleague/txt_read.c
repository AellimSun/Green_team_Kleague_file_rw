#include<stdio.h>
#include"structure.h"

team_hist team_hist_list[100];

int txt_read() {
	FILE* THT;
	int i = 0;

	/******************** team_history ���� ���� ********************/
	THT = fopen("team_history.txt", "r");

	if (THT == NULL) {
		printf("team_history ������ ������ �ʾҽ��ϴ�.\n");
	}

	for (i = 0; i < 100; i++)
	{
		fscanf(THT, "%d %d %d %s %s %d %d %c",
			&team_hist_list[i].team_hist_year, &team_hist_list[i].team_hist_month, &team_hist_list[i].team_hist_date, &team_hist_list[i].team_hist_home,
			&team_hist_list[i].team_hist_away, &team_hist_list[i].team_hist_homegoal, &team_hist_list[i].team_hist_awaygoal, &team_hist_list[i].team_hist_datadelete);
	}
	fclose(THT);

	/******************** player_prof ���� ���� ********************/
	THT = fopen("player_prof.txt", "r");

	if (THT == NULL) {
		printf("player_prof ������ ������ �ʾҽ��ϴ�.\n");
	}

	for (i = 0; i < 100; i++)
	{
		fscanf(THT, "%s %s %d %d %d %s %c\n",
			player_list[i].player_id, player_list[i].player_name, &player_list[i].player_height, &player_list[i].player_weight, &player_list[i].player_back_num, player_list[i].player_position, &player_list[i].useYN);
	}
	fclose(THT);
}