#include<stdio.h>

typedef struct
{
	int team_hist_year;
	int team_hist_month;
	int team_hist_date;
	char team_hist_home[10];
	char team_hist_away[10];
	int team_hist_homegoal;
	int team_hist_awaygoal;
} team_hist;

int team_history_data(void) {
	team_hist team_hist_list[100] = {
		{2021, 2, 24, "부산", "울산", 3, 1},
		{2021, 5, 11, "부산", "제주", 4, 5},
		{2021, 5, 11, "울산", "제주", 2, 1}
	};
	
	int hist_year_select;
	printf("\n\n");
	printf("조회하고 싶은 연도를 입력하세요 : ");
	scanf("%d", &hist_year_select);

	int hist_month_select;
	printf("\n");
	printf("조회하고 싶은 달을 입력하세요 : ");
	scanf("%d", &hist_month_select);
	printf("\n");

	printf("%d 년 %d 월의 경기 결과를 검색합니다.", hist_year_select, hist_month_select);


	for (int i = 0; i < sizeof(team_hist_list); i++) {
		if (team_hist_list[i].team_hist_year = hist_year_select && team_hist_list[i].team_hist_month = hist_month_select) {
			printf("%d년 %d월 %d일", team_hist_list[i].team_hist_year, team_hist_list[i].team_hist_month, team_hist_list[i].team_hist_date);

		}
	}




	return 0;
}