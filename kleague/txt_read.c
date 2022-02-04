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

	while (!feof(THT)) 
	{
		fscanf(THT, "%d %d %d %s %s %d %d %c",
			&team_hist_list[i].team_hist_year, &team_hist_list[i].team_hist_month, &team_hist_list[i].team_hist_date, &team_hist_list[i].team_hist_home,
			&team_hist_list[i].team_hist_away, &team_hist_list[i].team_hist_homegoal, &team_hist_list[i].team_hist_awaygoal, &team_hist_list[i].team_hist_datadelete);
		i++;
	}
	fclose(THT);
	i = 0;

	/******************** player_prof ���� ���� ********************/
	THT = fopen("player_prof.txt", "r");

	if (THT == NULL) {
		printf("player_prof ������ ������ �ʾҽ��ϴ�.\n");
	}

	while (!feof(THT)) 
	{
		fscanf(THT, "%s %s %d %d %d %s %c\n",
			player_list[i].player_id, player_list[i].player_name, &player_list[i].player_height, &player_list[i].player_weight, &player_list[i].player_back_num, player_list[i].player_position, &player_list[i].useYN);
		i++;
	}
	fclose(THT);
	i = 0;

	/******************** player_history ���� ���� ********************/
	THT = fopen("player_history.txt", "r");

	if (THT == NULL) {
		printf("player_history ������ ������ �ʾҽ��ϴ�.\n");
	}

	while (!feof(THT)) 
	{
		fscanf(THT, "%s %d %d %d %d %c", &player_history_list[i].id, &player_history_list[i].score,
			&player_history_list[i].assistant, &player_history_list[i].yellow_card, &player_history_list[i].off_the_field,
			&player_history_list[i].view_YN);
		i++;
	}
	fclose(THT);
	i = 0;
}