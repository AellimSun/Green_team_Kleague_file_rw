#include "«Ï¥ı.h"

void team_ranking()
{
	system("cls");

	printf("\n∆¿ ∑©≈∑¿ª »Æ¿Œ«’¥œ¥Ÿ.\n\n");
	match_team_sort();
	match_team_points();

	int winpoints = 0, drawpoints = 0;
	int addpoints[10];

	for (int i = 0; i < 10; i++) {
		winpoints = team_match_list[i].team_win;
		drawpoints = team_match_list[i].team_draw;
		addpoints[i] = (winpoints * 3) + drawpoints;
		team_match_list[i].total_points = addpoints[i];
	}

	//πˆ∫Ì¡§∑ƒ
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			int temp1, temp2, temp3;
			char temp4[50];
			if (team_match_list[j].total_points < team_match_list[j+1].total_points) {
				temp1 = team_match_list[j].team_win;
				team_match_list[j].team_win = team_match_list[j + 1].team_win;
				team_match_list[j + 1].team_win = temp1;

				temp2 = team_match_list[j].team_draw;
				team_match_list[j].team_draw = team_match_list[j + 1].team_draw;
				team_match_list[j + 1].team_draw = temp2;

				temp3 = team_match_list[j].total_points;
				team_match_list[j].total_points = team_match_list[j + 1].total_points;
				team_match_list[j + 1].total_points = temp3;

				strcpy(temp4, team_match_list[j].team_name_match);
				strcpy(team_match_list[j].team_name_match, team_match_list[j + 1].team_name_match);
				strcpy(team_match_list[j + 1].team_name_match, temp4);
			}

		}
	}
	printf("=============================================================\n");
	printf("    ∑©≈∑\t\t∆¿ ¿Ã∏ß\t\t\tΩ¬¡°\n");
	for (int i = 0; i < 10; i++) {
		if (team_match_list[i].total_points != 0) {
			printf("    %d\t\t%s\t\t%d\n", i + 1, team_match_list[i].team_name_match, team_match_list[i].total_points);
		}
	}
	printf("=============================================================\n");

	for (int i = 0; i < 10; i++) {
		team_match_list[i].total_points = 0;
		team_match_list[i].team_win = 0;
		team_match_list[i].team_draw = 0;
	}

	system("pause");
	ranking();
}


int match_team_sort(void) {
	for (int i = 0; i < 10; i++) {
		strcpy(team_match_list[i].team_name_match, team_list[i].team_name);
	}
}

int match_team_points(void) {
	for (int i = 0; i < 100; i++) {
		if (team_hist_list[i].team_hist_datadelete == 'y') {
			if (team_hist_list[i].team_hist_homegoal > team_hist_list[i].team_hist_awaygoal) {
				for (int j = 0; j < 10; j++) {
					if (strcmp(team_hist_list[i].team_hist_home, team_match_list[j].team_name_match) == 0) {
						team_match_list[j].team_win += 1;
					}
				}
			}
			else if (team_hist_list[i].team_hist_homegoal < team_hist_list[i].team_hist_awaygoal) {
				for (int j = 0; j < 10; j++) {
					if (strcmp(team_hist_list[i].team_hist_away, team_match_list[j].team_name_match) == 0) {
						team_match_list[j].team_win += 1;
					}
				}
			}

			else if (team_hist_list[i].team_hist_homegoal = team_hist_list[i].team_hist_awaygoal) {
				for (int j = 0; j < 10; j++) {
					if (strcmp(team_hist_list[i].team_hist_home, team_match_list[j].team_name_match) == 0) {
						team_match_list[j].team_draw += 1;
					}
					if (strcmp(team_hist_list[i].team_hist_away, team_match_list[j].team_name_match) == 0) {
						team_match_list[j].team_draw += 1;
					}
				}
			}
		}
	}
}
