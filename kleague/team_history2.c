#include "���.h"

int result(void) {
	//���ϴ� Ȱ�� ����
	int select = 0;

	system("cls");

	printf("\n\n");
	printf("**************************************************************************************************************\n");
	printf("*   \t\t\t\t\t���ϴ� �۾��� �������ּ���\t\t\t\t\t     *\n");
	printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t     *\n");
	printf("* 1. ��� ��� �Է�\t2. ��� ��� ����\t3. ��� ��� ��ȸ\t4. ��� ��� ����\t5. ��������  *\n");
	printf("**************************************************************************************************************\n\n");
	printf("���� �Է� : ");
	scanf("%d", &select);
	printf("\n");

	//��� ��� �Է�
	if (select == 1) {

		system("cls");

		printf("��� ����� �Է��մϴ�.\n\n");
		int match_year, match_month, match_date;
		printf("��Ⱑ �־��� ������ �Է����ּ��� : ");
		scanf("%d", &match_year);
		printf("\n");
		printf("��Ⱑ �־��� ���� �Է����ּ��� : ");
		scanf("%d", &match_month);
		printf("\n");
		printf("��Ⱑ �־��� ���� �Է����ּ��� : ");
		scanf("%d", &match_date);
		printf("\n");

		printf("��� ����� ���� �Է��� �����մϴ�.");
		printf("\n");
		char HOME_TEAM[10], AWAY_TEAM[10];
		printf("HOME ���� �̸��� �Է����ּ��� : ");
		scanf("%s", &HOME_TEAM);
		printf("\n");
		printf("AWAY ���� �̸��� �Է����ּ��� : ");
		scanf("%s", &AWAY_TEAM);
		printf("\n");

		int HOME_TEAM_GOALS = 0, AWAY_TEAM_GOALS = 0;
		printf("%s ���� ������ �Է����ּ��� : ", HOME_TEAM);
		scanf("%d", &HOME_TEAM_GOALS);
		printf("\n");
		printf("%s ���� ������ �Է����ּ��� : ", AWAY_TEAM);
		scanf("%d", &AWAY_TEAM_GOALS);
		printf("\n\n");

		printf("���� �Է� ������ Ȯ���մϴ�.\n\n");
		printf("��� ��¥ : %d�� %d�� %d��\n", match_year, match_month, match_date);
		printf("HOME TEAM : %s\t\t%d��\n", HOME_TEAM, HOME_TEAM_GOALS);
		printf("AWAY TEAM : %s\t\t%d��\n\n", AWAY_TEAM, AWAY_TEAM_GOALS);

		int number_select = 0;
		printf("������ ��ġ�ϸ� 1��, �������� ���ư����� �ٸ� ���ڸ� �Է����ּ���.\n");
		printf("���� �Է� : ");
		scanf("%d", &number_select);
		printf("\n");

		if (number_select == 1) {
			printf("���ο� ��⸦ �Է��մϴ�.");

			for (int empty_space = 0; empty_space < 100; empty_space++) {
				if (team_hist_list[empty_space].team_hist_month == 0) {

					team_hist_list[empty_space].team_hist_year = match_year;
					team_hist_list[empty_space].team_hist_month = match_month;
					team_hist_list[empty_space].team_hist_date = match_date;
					strcpy(team_hist_list[empty_space].team_hist_home, HOME_TEAM);
					strcpy(team_hist_list[empty_space].team_hist_away, AWAY_TEAM);
					team_hist_list[empty_space].team_hist_homegoal = HOME_TEAM_GOALS;
					team_hist_list[empty_space].team_hist_awaygoal = AWAY_TEAM_GOALS;
					team_hist_list[empty_space].team_hist_datadelete = 'y';
					break;
				}
				else {

				}
			}
			system("pause");
			result();
		}
		else {
			system("pause");
			result();

		}
	}

	//��� ��� ����
	else if (select == 2) {
		printf("������ ��� ����� �����մϴ�.\n\n");
		for (int print_score = 0; print_score < 100; print_score++) {
			if (team_hist_list[print_score].team_hist_date > 0) {
				printf("%d. %d�� %d�� %d��\n\t=> HOME TEAM : %s \t %d��  \t //\tAWAY TEAM : %s \t %d�� \n", print_score + 1, team_hist_list[print_score].team_hist_year, team_hist_list[print_score].team_hist_month, team_hist_list[print_score].team_hist_date, team_hist_list[print_score].team_hist_home, team_hist_list[print_score].team_hist_homegoal, team_hist_list[print_score].team_hist_away, team_hist_list[print_score].team_hist_awaygoal);
			}
			}
		printf("\n");
		int update_score;
		printf("������ ���ϴ� ��� ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &update_score);

		int update_year, update_month, update_date, update_homegoal, update_awaygoal;
		char update_home[10], update_away[10];

		printf("\n");
		printf("������ �ٽ� �Է��մϴ�.\n");
		printf("��Ⱑ �־��� ������ �Է����ּ��� : ");
		scanf("%d", &update_year);
		printf("\n");
		printf("��Ⱑ �־��� ���� �Է����ּ��� : ");
		scanf("%d", &update_month);
		printf("\n");
		printf("��Ⱑ �־��� ���� �Է����ּ��� : ");
		scanf("%d", &update_date);
		printf("\n\n");

		printf("��� ����� ���� �Է��� �����մϴ�.");
		printf("\n");
		printf("HOME ���� �̸��� �Է����ּ��� : ");
		scanf("%s", &update_home);
		printf("\n");
		printf("AWAY ���� �̸��� �Է����ּ��� : ");
		scanf("%s", &update_away);
		printf("\n");

		printf("%s ���� ������ �Է����ּ��� : ", update_home);
		scanf("%d", &update_homegoal);
		printf("\n");
		printf("%s ���� ������ �Է����ּ��� : ", update_away);
		scanf("%d", &update_awaygoal);
		printf("\n\n");

		team_hist_list[update_score -1].team_hist_year = update_year;
		team_hist_list[update_score -1].team_hist_month = update_month;
		team_hist_list[update_score -1].team_hist_date = update_date;

		strcpy(team_hist_list[update_score -1].team_hist_home, update_home);
		strcpy(team_hist_list[update_score -1].team_hist_away, update_away);

		team_hist_list[update_score -1].team_hist_homegoal = update_homegoal;
		team_hist_list[update_score -1].team_hist_awaygoal = update_awaygoal;

		printf("������ �Ϸ�Ǿ����ϴ�. \n");
		system("pause");
		result();
	}


	//��� ��� ��ȸ
	else if (select == 3) {
		for (int top_bobsult = 0; top_bobsult < 99; top_bobsult++) {
			for (int bobsult = 99; bobsult < (0 + top_bobsult) + 1; bobsult--) {
				int bobsult_year, bobsult_month, bobsult_date, bobsult_homegoals, bobsult_awaygoals;
				char bobsult_home[100], bobsult_away[100];
				if (team_hist_list[bobsult].team_hist_date > team_hist_list[bobsult - 1].team_hist_date) {
					bobsult_year = team_hist_list[bobsult].team_hist_year;
					team_hist_list[bobsult].team_hist_year = team_hist_list[bobsult - 1].team_hist_year;
					team_hist_list[bobsult - 1].team_hist_year = bobsult_year;

					bobsult_month = team_hist_list[bobsult].team_hist_month;
					team_hist_list[bobsult].team_hist_month = team_hist_list[bobsult - 1].team_hist_month;
					team_hist_list[bobsult - 1].team_hist_month = bobsult_month;

					bobsult_date = team_hist_list[bobsult].team_hist_date;
					team_hist_list[bobsult].team_hist_date = team_hist_list[bobsult - 1].team_hist_date;
					team_hist_list[bobsult - 1].team_hist_date = bobsult_date;

					strcpy(bobsult_home, team_hist_list[bobsult].team_hist_home);
					strcpy(team_hist_list[bobsult].team_hist_home, team_hist_list[bobsult - 1].team_hist_home);
					strcpy(team_hist_list[bobsult - 1].team_hist_home, bobsult_home);

					strcpy(bobsult_away, team_hist_list[bobsult].team_hist_away);
					strcpy(team_hist_list[bobsult].team_hist_away, team_hist_list[bobsult - 1].team_hist_away);
					strcpy(team_hist_list[bobsult - 1].team_hist_away, bobsult_away);

					bobsult_homegoals = team_hist_list[bobsult].team_hist_homegoal;
					team_hist_list[bobsult].team_hist_homegoal = team_hist_list[bobsult - 1].team_hist_homegoal;
					team_hist_list[bobsult - 1].team_hist_homegoal = bobsult_homegoals;

					bobsult_awaygoals = team_hist_list[bobsult].team_hist_awaygoal;
					team_hist_list[bobsult].team_hist_awaygoal = team_hist_list[bobsult - 1].team_hist_awaygoal;
					team_hist_list[bobsult - 1].team_hist_awaygoal = bobsult_awaygoals;
				}
				else {
				}

				
		}
		
	}
	int hist_year_select;
	printf("\n\n");
	printf("��ȸ�ϰ� ���� ������ �Է��ϼ��� : ");
	scanf("%d", &hist_year_select);

	int hist_month_select;
	printf("\n");
	printf("��ȸ�ϰ� ���� ���� �Է��ϼ��� : ");
	scanf("%d", &hist_month_select);
	printf("\n");

	int print_no = 0;

	for (int run = 0; run < 100; run++) {
		if (team_hist_list[run].team_hist_year == hist_year_select && team_hist_list[run].team_hist_month == hist_month_select) {
			print_no += 1;
		}
	}


	if (print_no > 0) {
		printf("%d �� %d ���� ��� ����� �˻��մϴ�.", hist_year_select, hist_month_select);
		for (int i = 0; i < 99; i++) {
			if (team_hist_list[i].team_hist_year == hist_year_select && team_hist_list[i].team_hist_month == hist_month_select && team_hist_list[i].team_hist_datadelete == 'y') {
				printf("\n");
				printf("====================================");
				printf("\n");
				printf("%d�� %d�� %d�� ���", team_hist_list[i].team_hist_year, team_hist_list[i].team_hist_month, team_hist_list[i].team_hist_date);
				printf("\n");

				printf("\tHOME\t<%s>\t%d\n\tAWAY\t<%s>\t%d", team_hist_list[i].team_hist_home, team_hist_list[i].team_hist_homegoal, team_hist_list[i].team_hist_away, team_hist_list[i].team_hist_awaygoal);
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
		printf("��Ⱑ ���� ���Դϴ�.");
		printf("\n");
	}
	system("pause");
	result();
}

	//��� ��� ����
	else if (select == 4) {
	printf("��� ����� �����մϴ�.\n");

		for (int print_del = 0; print_del < 100; print_del++) {
			if (team_hist_list[print_del].team_hist_date > 0 && team_hist_list[print_del].team_hist_datadelete == 'y') {
				printf("%d. %d�� %d�� %d��\n\t=> HOME TEAM : %s \t %d��  \t //\tAWAY TEAM : %s \t %d�� \n", print_del + 1, team_hist_list[print_del].team_hist_year, team_hist_list[print_del].team_hist_month, team_hist_list[print_del].team_hist_date, team_hist_list[print_del].team_hist_home, team_hist_list[print_del].team_hist_homegoal, team_hist_list[print_del].team_hist_away, team_hist_list[print_del].team_hist_awaygoal);
			}
		}
		printf("\n");
		int delete = 0;
		printf("������ ���ϴ� ��� ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &delete);

		team_hist_list[delete - 1].team_hist_datadelete = 'n';
	
		printf("\n");
		printf("������ �Ϸ��߽��ϴ�.");
		printf("\n\n");

		system("pause");
		result();

	}

	else if (select == 5) {
		printf("�������� ���ư��ϴ�.\n");
		main();
	}
	
	else 
	{
		printf("�Է¿����Դϴ�.\n");
		result();
	}

	//�̾��ϱ� ����
	/*printf("\n\n");
	printf("����Ͻðڽ��ϱ�?");
	printf("\n");


	printf("1. ����ϱ�\t2. ����\n\n");
	int gostop = 0;
	printf("���� �Է� : ");
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

