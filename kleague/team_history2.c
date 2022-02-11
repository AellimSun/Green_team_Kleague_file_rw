#include "헤더.h"

int result(team_hist *TH_p) {
	
	//원하는 활동 선택


	int select = 0;

	system("cls");

	printf("\n\n");
	printf("**************************************************************************************************************\n");
	printf("*   \t\t\t\t\t원하는 작업을 선택해주세요\t\t\t\t\t     *\n");
	printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t     *\n");
	printf("* 1. 경기 결과 입력\t2. 경기 결과 수정\t3. 경기 결과 조회\t4. 경기 결과 삭제\t5. 이전으로  *\n");
	printf("**************************************************************************************************************\n\n");
	printf("숫자 입력 : ");
	scanf("%d", &select);
	printf("\n");

	//경기 결과 입력
	if (select == 1) {

		system("cls");

		printf("경기 결과를 입력합니다.\n\n");
		int match_year, match_month, match_date;
		printf("경기가 있었던 연도를 입력해주세요 : ");
		scanf("%d", &match_year);
		printf("\n");
		printf("경기가 있었던 달을 입력해주세요 : ");
		scanf("%d", &match_month);
		printf("\n");
		printf("경기가 있었던 일을 입력해주세요 : ");
		scanf("%d", &match_date);
		printf("\n");

		printf("경기 결과에 대한 입력을 시작합니다.");
		printf("\n");
		char HOME_TEAM[10], AWAY_TEAM[10];
		printf("HOME 팀의 이름을 입력해주세요 : ");
		scanf("%s", &HOME_TEAM);
		printf("\n");
		printf("AWAY 팀의 이름을 입력해주세요 : ");
		scanf("%s", &AWAY_TEAM);
		printf("\n");

		int HOME_TEAM_GOALS = 0, AWAY_TEAM_GOALS = 0;
		printf("%s 팀의 점수를 입력해주세요 : ", HOME_TEAM);
		scanf("%d", &HOME_TEAM_GOALS);
		printf("\n");
		printf("%s 팀의 점수를 입력해주세요 : ", AWAY_TEAM);
		scanf("%d", &AWAY_TEAM_GOALS);
		printf("\n\n");

		printf("최종 입력 정보를 확인합니다.\n\n");
		printf("경기 날짜 : %d년 %d월 %d일\n", match_year, match_month, match_date);
		printf("HOME TEAM : %s\t\t%d점\n", HOME_TEAM, HOME_TEAM_GOALS);
		printf("AWAY TEAM : %s\t\t%d점\n\n", AWAY_TEAM, AWAY_TEAM_GOALS);

		int number_select = 0;
		printf("정보가 일치하면 1번, 이전으로 돌아가려면 다른 숫자를 입력해주세요.\n");
		printf("숫자 입력 : ");
		scanf("%d", &number_select);
		printf("\n");

		if (number_select == 1) {
			printf("새로운 경기를 입력합니다.");

			for (int empty_space = 0; empty_space < 100; empty_space++) {
				if ((TH_p + empty_space)->team_hist_month == 0) {

					(TH_p + empty_space) ->team_hist_year = match_year;
					(TH_p + empty_space) ->team_hist_month = match_month;
					(TH_p + empty_space) ->team_hist_date = match_date;
					strcpy((TH_p + empty_space) ->team_hist_home, HOME_TEAM);
					strcpy((TH_p + empty_space) ->team_hist_away, AWAY_TEAM);
					(TH_p + empty_space) ->team_hist_homegoal = HOME_TEAM_GOALS;
					(TH_p + empty_space) ->team_hist_awaygoal = AWAY_TEAM_GOALS;
					(TH_p + empty_space) ->team_hist_datadelete = 'y';
					break;
				}
				else {

				}
			}
			system("pause");
			result(team_hist_list);
		}
		else {
			system("pause");
			result(team_hist_list);

		}
	}

	//경기 결과 수정
	else if (select == 2) {
		printf("기존의 경기 결과를 수정합니다.\n\n");
		for (int print_score = 0; print_score < 100; print_score++) {
			if ((TH_p+print_score)->team_hist_date > 0) {
				printf("%d. %d년 %d월 %d일\n\t=> HOME TEAM : %s \t %d점  \t //\tAWAY TEAM : %s \t %d점 \n", print_score + 1, team_hist_list[print_score].team_hist_year, team_hist_list[print_score].team_hist_month, team_hist_list[print_score].team_hist_date, team_hist_list[print_score].team_hist_home, team_hist_list[print_score].team_hist_homegoal, team_hist_list[print_score].team_hist_away, team_hist_list[print_score].team_hist_awaygoal);
			}
			}
		printf("\n");
		int update_score;
		printf("수정을 원하는 경기 번호를 입력하세요 : ");
		scanf("%d", &update_score);

		int update_year, update_month, update_date, update_homegoal, update_awaygoal;
		char update_home[10], update_away[10];

		printf("\n");
		printf("정보를 다시 입력합니다.\n");
		printf("경기가 있었던 연도를 입력해주세요 : ");
		scanf("%d", &update_year);
		printf("\n");
		printf("경기가 있었던 달을 입력해주세요 : ");
		scanf("%d", &update_month);
		printf("\n");
		printf("경기가 있었던 일을 입력해주세요 : ");
		scanf("%d", &update_date);
		printf("\n\n");

		printf("경기 결과에 대한 입력을 시작합니다.");
		printf("\n");
		printf("HOME 팀의 이름을 입력해주세요 : ");
		scanf("%s", &update_home);
		printf("\n");
		printf("AWAY 팀의 이름을 입력해주세요 : ");
		scanf("%s", &update_away);
		printf("\n");

		printf("%s 팀의 점수를 입력해주세요 : ", update_home);
		scanf("%d", &update_homegoal);
		printf("\n");
		printf("%s 팀의 점수를 입력해주세요 : ", update_away);
		scanf("%d", &update_awaygoal);
		printf("\n\n");

		(TH_p + update_score -1)->team_hist_year = update_year;
		(TH_p + update_score - 1)->team_hist_month = update_month;
		(TH_p + update_score - 1)->team_hist_date = update_date;

		strcpy((TH_p + update_score - 1)->team_hist_home, update_home);
		strcpy((TH_p + update_score - 1)->team_hist_away, update_away);

		(TH_p + update_score - 1)->team_hist_homegoal = update_homegoal;
		(TH_p + update_score -1)->team_hist_awaygoal = update_awaygoal;

		printf("수정이 완료되었습니다. \n");
		system("pause");
		result(team_hist_list);
	}


	//경기 결과 조회
	else if (select == 3) {
	team_hist temp;
		for (int top_bobsult = 0; top_bobsult < 99; top_bobsult++) {
			for (int bobsult = 0; bobsult < 99 - top_bobsult; bobsult++) {

				//int bobsult_year, bobsult_month, bobsult_date, bobsult_homegoals, bobsult_awaygoals;
				//char bobsult_home[100], bobsult_away[100]
				if ((TH_p+bobsult)->team_hist_date > (TH_p+bobsult+1)->team_hist_date) {
					temp = TH_p[bobsult];
					TH_p[bobsult] = TH_p[bobsult + 1];
					TH_p[bobsult + 1] = temp;

				//if (team_hist_list[bobsult].team_hist_date > team_hist_list[bobsult - 1].team_hist_date) {
				//	bobsult_year = team_hist_list[bobsult].team_hist_year;
				//	team_hist_list[bobsult].team_hist_year = team_hist_list[bobsult - 1].team_hist_year;
				//	team_hist_list[bobsult - 1].team_hist_year = bobsult_year;
				//	bobsult_month = team_hist_list[bobsult].team_hist_month;
				//	team_hist_list[bobsult].team_hist_month = team_hist_list[bobsult - 1].team_hist_month;
				//	team_hist_list[bobsult - 1].team_hist_month = bobsult_month;
				//	bobsult_date = team_hist_list[bobsult].team_hist_date;
				//	team_hist_list[bobsult].team_hist_date = team_hist_list[bobsult - 1].team_hist_date;
				//	team_hist_list[bobsult - 1].team_hist_date = bobsult_date;
				//	strcpy(bobsult_home, team_hist_list[bobsult].team_hist_home);
				//	strcpy(team_hist_list[bobsult].team_hist_home, team_hist_list[bobsult - 1].team_hist_home);
				//	strcpy(team_hist_list[bobsult - 1].team_hist_home, bobsult_home);
				//	strcpy(bobsult_away, team_hist_list[bobsult].team_hist_away);
				//	strcpy(team_hist_list[bobsult].team_hist_away, team_hist_list[bobsult - 1].team_hist_away);
				//	strcpy(team_hist_list[bobsult - 1].team_hist_away, bobsult_away);
				//	bobsult_homegoals = team_hist_list[bobsult].team_hist_homegoal;
				//	team_hist_list[bobsult].team_hist_homegoal = team_hist_list[bobsult - 1].team_hist_homegoal;
				//	team_hist_list[bobsult - 1].team_hist_homegoal = bobsult_homegoals;
				//	bobsult_awaygoals = team_hist_list[bobsult].team_hist_awaygoal;
				//	team_hist_list[bobsult].team_hist_awaygoal = team_hist_list[bobsult - 1].team_hist_awaygoal;
				//	team_hist_list[bobsult - 1].team_hist_awaygoal = bobsult_awaygoals;
				}
				else {
				}
			
				
		}
		
	}
	int hist_year_select;
	printf("\n\n");
	printf("조회하고 싶은 연도를 입력하세요 : ");
	scanf("%d", &hist_year_select);
	int hist_month_select;
	printf("\n");
	printf("조회하고 싶은 달을 입력하세요 : ");
	scanf("%d", &hist_month_select);
	printf("\n");
	int print_no = 0;
	for (int run = 0; run < 100; run++) {
		if ((TH_p+run)->team_hist_year == hist_year_select && (TH_p + run)->team_hist_month == hist_month_select) {
			print_no += 1;
		}
	}
	if (print_no > 0) {
		printf("%d 년 %d 월의 경기 결과를 검색합니다.", hist_year_select, hist_month_select);
		for (int i = 0; i < 99; i++) {
			if ((TH_p + i)->team_hist_year == hist_year_select && (TH_p + i)->team_hist_month == hist_month_select && (TH_p + i)->team_hist_datadelete == 'y') {
				printf("\n");
				printf("====================================");
				printf("\n");
				printf("%d년 %d월 %d일 경기", (TH_p + i)->team_hist_year, (TH_p + i)->team_hist_month, (TH_p + i)->team_hist_date);
				printf("\n");
				printf("\tHOME\t<%s>\t%d\n\tAWAY\t<%s>\t%d", (TH_p + i)->team_hist_home, (TH_p + i)->team_hist_homegoal, (TH_p + i)->team_hist_away, (TH_p + i)->team_hist_awaygoal);
				printf("\n");
				printf("====================================");
				printf("\n");
			}
			else {
				printf("");
			}
		}
	}
	else {
		printf("\n");
		printf("경기가 없는 날입니다.");
		printf("\n");
	}
	//	for (int i = 0; i < 100; i++){
	//		if ((TH_p + i + 1)->team_hist_year != NULL) {
	//			(TH_p + i)->next = (TH_p + i + 1)->next;
	//			
	//		}
	//}

	system("pause");
	result(team_hist_list);
}

	//경기 결과 삭제
	else if (select == 4) {
	printf("경기 결과를 삭제합니다.\n");

		for (int print_del = 0; print_del < 100; print_del++) {
			if ((TH_p + print_del)->team_hist_date > 0 && (TH_p + print_del)->team_hist_datadelete == 'y') {
				printf("%d. %d년 %d월 %d일\n\t=> HOME TEAM : %s \t %d점  \t //\tAWAY TEAM : %s \t %d점 \n", print_del + 1, (TH_p + print_del)->team_hist_year, (TH_p + print_del)->team_hist_month, (TH_p + print_del)->team_hist_date, (TH_p + print_del)->team_hist_home, (TH_p + print_del)->team_hist_homegoal, (TH_p + print_del)->team_hist_away, (TH_p + print_del)->team_hist_awaygoal);
			}
		}
		printf("\n");
		int delete = 0;
		printf("삭제를 원하는 경기 번호를 입력하세요 : ");
		scanf("%d", &delete);

		(TH_p + delete)->team_hist_datadelete = 'n';
	
		printf("\n");
		printf("삭제를 완료했습니다.");
		printf("\n\n");

		system("pause");
		result(team_hist_list);

	}

	else if (select == 5) {
		printf("이전으로 돌아갑니다.\n");
		main();
	}
	
	else 
	{
		printf("입력오류입니다.\n");
		result(team_hist_list);
	}

	//이어하기 질문
	/*printf("\n\n");
	printf("계속하시겠습니까?");
	printf("\n");


	printf("1. 계속하기\t2. 종료\n\n");
	int gostop = 0;
	printf("숫자 입력 : ");
	scanf("%d", &gostop);
	printf("\n\n\n");


	if (gostop == 1) {
		main();
	}
	else if (gostop == 2) {
		exit();
	}*/

	return;
}

