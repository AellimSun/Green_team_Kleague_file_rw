#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include "structure.h"

int new=3;


void team();

void team_prof_C(teamProfile* p_team)
{
	system("cls");

	if (new >= 10) {
		printf("10팀만 등록가능. 메인으로\n\n");
		main();
	}
	printf("팀을 등록합니다. \n\n");
	printf("=========================\n\n");
	int new_team_id;
	printf("팀 id를 입력하세요 : ");
	scanf("%d", &new_team_id);
	char new_area[20];
	printf("연고지를 입력하세요 : ");
	scanf("%s", &new_area);
	char new_stadium[50];
	printf("홈구장을 입력하세요 : ");
	scanf("%s", &new_stadium);
	printf("창단연도를 입력하세요 : ");
	int new_since;
	scanf("%d", &new_since);
	printf("감독이름을 입력하세요 : ");
	char new_coach[20];
	scanf("%s", &new_coach);
	printf("우승횟수를 입력하세요 : ");
	int new_v;
	scanf("%d", &new_v);
	printf("팀명을 입력하세요 : ");
	char new_team_name[50];
	scanf("%s", &new_team_name);

	printf("\n\n\n====================\n\n");
	printf("등록된 팀 정보 확인\n");
	printf("====================\n\n");
	printf("팀id : %d번  연고지 : %s   홈구장 : %s  창단연도 : %d년\n"
		"감독 : %s    K리그 우승 : %d번	구단명 : %s\n\n",
		new_team_id, new_area, new_stadium, new_since, new_coach, new_v, new_team_name);

	printf("입력한 정보가 정확하면 1, 부정확하면 2를 누르세요."
		"1을 누르면 메인화면, 2를 누르면 다시 등록화면으로 이동합니다.\n");
	int corr = 0;
	printf("1 or 2 입력 :  ");
	scanf("%d", &corr);

	if (corr == 1)
	{
		
		
			if ((p_team + new)->since == NULL)
			{

				(p_team + new)->team_id = new_team_id;
				strcpy((p_team + new)->area, new_area);
				strcpy((p_team + new)->stadium, new_stadium);
				(p_team + new)->since= new_since;
				strcpy((p_team + new)->coach, new_coach);
				(p_team + new)->v = new_v;
				strcpy((p_team + new)->team_name, new_team_name);
				(p_team + new)->use_YN = 'Y';
				
				new++;
			}
		
	main();
	}
	else
	{
		team_prof_C(team_list);
	}

}

void team_prof_update(teamProfile* p_team)
{
	int i;
	
	system("cls");

	for (i = 0; i < new; i++)
	{
		if ((p_team + i)->use_YN == 'Y')
		{
			printf("팀id : %d번 구단명 : %s\n\n", (p_team + i)->team_id, (p_team + i)->team_name);
		}
	}
	int update_id;
	printf("수정할 팀의 id를 입력하세요.");
	scanf("%d", &update_id);

	printf("팀을 수정합니다. \n\n");
	printf("=========================\n\n");
	
	char update_area[20];
	printf("연고지를 입력하세요 : ");
	scanf("%s", &update_area);
	char update_stadium[50];
	printf("홈구장을 입력하세요 : ");
	scanf("%s", &update_stadium);
	printf("창단연도를 입력하세요 : ");
	int update_since;
	scanf("%d", &update_since);
	printf("감독이름을 입력하세요 : ");
	char update_coach[20];
	scanf("%s", &update_coach);
	printf("우승횟수를 입력하세요 : ");
	int update_v;
	scanf("%d", &update_v);
	printf("팀명을 입력하세요 : ");
	char update_team_name[50];
	scanf("%s", &update_team_name);

	printf("\n\n\n====================\n\n");
	printf("수정된 팀 정보 확인\n");
	printf("====================\n\n");
	printf("팀id : %d번  연고지 : %s   홈구장 : %s  창단연도 : %d년\n"
		"감독 : %s    K리그 우승 : %d번	구단명 : %s\n\n",
		update_id, update_area, update_stadium, update_since, update_coach, update_v, update_team_name);

	printf("입력한 정보가 정확하면 1, 부정확하면 2를 누르세요."
		"1을 누르면 메인화면, 2를 누르면 다시 수정화면으로 이동합니다.\n");
	int corr = 0;
	printf("1 or 2 입력 :  ");
	scanf("%d", &corr);

	if (corr == 1)
	{
		int update = update_id;

		if ((p_team + update)->team_id == update_id)
		{

			(p_team + update)->team_id = update_id;
			strcpy((p_team + update)->area, update_area);
			strcpy((p_team + update)->stadium, update_stadium);
			(p_team + update)->since = update_since;
			strcpy((p_team + update)->coach, update_coach);
			(p_team + update)->v = update_v;
			strcpy((p_team + update)->team_name, update_team_name);

		}


		main();
	}
	else
	{
		team_prof_update(team_list);
	}
}

void team_show(teamProfile* p_team)
{
	system("cls");
	int i;
	


	for (i = 0; i < 10; i++)
	{
		if ((p_team + i)->use_YN == 'Y')
		{
			printf("팀id : %d번  연고지 : %s   홈구장 : %s  창단연도 : %d년\n"
				"감독 : %s    K리그 우승 : %d번	구단명 : %s\n\n",
				(p_team + i)->team_id, (p_team + i)->area, (p_team + i)->stadium, (p_team + i)->since, (p_team + i)->coach, (p_team + i)->v, (p_team + i)->team_name);
		}
	}
	
	printf("팀정보 조회완료.\n\n\n\n");
	system("pause");
	team();

}

void team_delete(teamProfile* p_team)
{
	int c;
	int flag = 0;

	system("cls");

	printf("1.삭제\n");
	printf("2.복구\n");
	printf("3.이전으로\n");

	scanf("%d", &c);

	if (c == 1)
	{
		int i;
		for (i = 0; i < new; i++)
		{
			if ((p_team + i)->use_YN == 'Y')
			{
				printf("팀id : %d번 구단명 : %s\n\n", (p_team + i)->team_id, (p_team + i)->team_name);

			}
		}
		int delete_id;

		printf("삭제할 팀의 id를 입력하세요.");
		scanf("%d", &delete_id);
		printf("\n\n");

		for (int j = 0; j < 20; j++)			//수정해야됨********************
		{
			if (strlen(player_list[j].player_id) == 0) {
				break;
			}
			char* ptr = strtok(player_list[j].player_id, "-");
			int tmp_id = atoi(ptr);
			if (delete_id == tmp_id && player_list[j].useYN == 'Y')
			{
				flag = 1;
				break;
			}						//여기까지 수정해야됨***************************

		}
		if (flag == 0)
		{
			int delete = delete_id;
			char YorN;
			printf("%s팀을 삭제하시겠습니까?	(Y/N)", (p_team + delete)->team_name);
			scanf("%s", &YorN);
			printf("\n\n");

			if (YorN == 'Y')
			{
				(p_team + delete)->use_YN = 'N';
				printf("%s팀이 삭제되었습니다.\n\n", (p_team + delete)->team_name);
			}
			system("pause");
			team();
		}
		else
		{
			printf("선수가 남아있어 팀을 삭제할 수 없습니다.\n\n");
			system("pause");
			team();
		}


	}
	else if (c == 2)
	{
		printf("삭제된 팀 조회\n\n");
		int i;
		int recovery_id;
		for (i = 0; i < new; i++)
		{
			if ((p_team + i)->use_YN == 'N')
			{
				printf("팀id : %d번  연고지 : %s   홈구장 : %s  창단연도 : %d년\n"
					"감독 : %s    K리그 우승 : %d번	구단명 : %s\n\n",
					(p_team + i)->team_id, (p_team + i)->area, (p_team + i)->stadium, (p_team + i)->since, (p_team + i)->coach, (p_team + i)->v, (p_team + i)->team_name);
			}
		}
		printf("복구할 팀의 id를 입력하세요.");
		scanf("%d", &recovery_id);

		int recovery = recovery_id;
		char NorY;
		printf("%s팀을 복구하겠습니까?	(Y/N)", (p_team + recovery)->team_name);
		scanf("%s", &NorY);
		printf("\n\n");

		if (NorY == 'Y')
		{
			(p_team + recovery)->use_YN = 'Y';
			printf("%s팀이 복구되었습니다.\n\n", (p_team + recovery)->team_name);
		}
		system("pause");
		team();
	}
	else if (c == 3)
	{
		team();
	}
}


void team()
{
	system("cls");

	int menu;
	printf("1.새로운 팀 등록\n");
	printf("2.팀 정보 수정\n");
	printf("3.팀 정보 조회\n");
	printf("4.팀 정보 삭제\n");
	printf("5.이전으로..\n");
	printf("6.링크로 팀 조회 \n");
	scanf("%d", &menu);
	printf("\n\n\n");

	switch (menu)
	{

	case 1:		//팀 등록
		team_prof_C(team_list);
		break;
	case 2:
		team_prof_update(team_list);
		break;
	case 3:
		team_show(team_list);
		break;
	case 4:
		team_delete(team_list);
		break;

	case 5:
		main();
		break;
	case 6:
		team_link();
		break;
	}
}


//int team_txt(void)
//{
//	//int n;
//
//	FILE* fp;
//	fp = fopen("team_prof.txt", "r");
//	//fscanf(fp, "%d", &n);
//
//	//teamProfile* team_list = (teamProfile*)malloc(sizeof(teamProfile) * n);
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d	%s	%s\n	%d	%s	%d	%s %c\n", team_list[i].team_id, team_list[i].area, team_list[i].stadium, team_list[i].since, team_list[i].coach, team_list[i].v, team_list[i].team_name, team_list[i].use_YN);
//	}
//	for (int j = 3; j < 10; j++)
//	{
//		fscanf(fp, "%d	%s	%s	%d	%s	%d	%s %c", &team_list[j].team_id, &team_list[j].area, &team_list[j].stadium, &team_list[j].since, &team_list[j].coach, &team_list[j].v, &team_list[j].team_name, &team_list[j].use_YN);
//		printf("%d	%s	%s\n	%d	%s	%d	%s %c\n", team_list[j].team_id, team_list[j].area, team_list[j].stadium, team_list[j].since, team_list[j].coach, team_list[j].v, team_list[j].team_name, team_list[j].use_YN);
//	}
//	fclose(fp);
//	
//	system("pause");
//	team();
//}

int team_link(void)
{
	teamProfile* head = &team_list[0], * current;
	for (int i = 0; i < new-1; i++)
	{
		team_list[i].next = &team_list[i + 1];
	}
	//team_list[0].next = &team_list[1];
	//team_list[1].next = &team_list[2];

	/*printf("head->team_id : %d,   head->area : %s\n", head->team_id,head->area);
	printf("head->next->team_id : %d,    head->next->coach : %s\n", head->next->team_id,head->next->coach);*/

	printf("list all\n\n\n");
	current = head;
	while (current != NULL)
	{
		printf("팀id : %d	연고지 : %s	홈구장 : %s\n"
			"창단연도 : %d	감독이름 : %s	우승횟수 : %d	팀명 : %s\n"
			"=========================================================\n\n", current->team_id, current->area, current->stadium, current->since, current->coach, current->v, current->team_name);
		current = current->next;
	}
	printf("\n");

	system("pause");
	team();

	return 0;
}