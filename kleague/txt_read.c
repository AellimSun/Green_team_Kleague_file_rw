#include<stdio.h>
#include"structure.h"

team_hist team_hist_list[100];

int txt_read() {
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
}