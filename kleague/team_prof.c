#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include "structure.h"

int new=3;

void team();

void team_prof_C()
{
	system("cls");

	if (new >= 10) {
		printf("10���� ��ϰ���. ��������\n\n");
		main();
	}
	printf("���� ����մϴ�. \n\n");
	printf("=========================\n\n");
	int new_team_id;
	printf("�� id�� �Է��ϼ��� : ");
	scanf("%d", &new_team_id);
	char new_area[20];
	printf("�������� �Է��ϼ��� : ");
	scanf("%s", &new_area);
	char new_stadium[50];
	printf("Ȩ������ �Է��ϼ��� : ");
	scanf("%s", &new_stadium);
	printf("â�ܿ����� �Է��ϼ��� : ");
	int new_since;
	scanf("%d", &new_since);
	printf("�����̸��� �Է��ϼ��� : ");
	char new_coach[20];
	scanf("%s", &new_coach);
	printf("���Ƚ���� �Է��ϼ��� : ");
	int new_v;
	scanf("%d", &new_v);
	printf("������ �Է��ϼ��� : ");
	char new_team_name[50];
	scanf("%s", &new_team_name);

	printf("\n\n\n====================\n\n");
	printf("��ϵ� �� ���� Ȯ��\n");
	printf("====================\n\n");
	printf("��id : %d��  ������ : %s   Ȩ���� : %s  â�ܿ��� : %d��\n"
		"���� : %s    K���� ��� : %d��	���ܸ� : %s\n\n",
		new_team_id, new_area, new_stadium, new_since, new_coach, new_v, new_team_name);

	printf("�Է��� ������ ��Ȯ�ϸ� 1, ����Ȯ�ϸ� 2�� ��������."
		"1�� ������ ����ȭ��, 2�� ������ �ٽ� ���ȭ������ �̵��մϴ�.\n");
	int corr = 0;
	printf("1 or 2 �Է� :  ");
	scanf("%d", &corr);

	if (corr == 1)
	{
		
		
			if (team_list[new].since == 0)
			{

				team_list[new].team_id = new_team_id;
				strcpy(team_list[new].area, new_area);
				strcpy(team_list[new].stadium, new_stadium);
				team_list[new].since= new_since;
				strcpy(team_list[new].coach, new_coach);
				team_list[new].v = new_v;
				strcpy(team_list[new].team_name, new_team_name);
				team_list[new].use_YN = 'Y';
				
				new++;
			}
		
	main();
	}
	else
	{
		team_prof_C();
	}

}

void team_prof_update()
{
	int i;
	
	system("cls");

	for (i = 0; i < new; i++)
	{
		if (team_list[i].use_YN == 'Y')
		{
			printf("��id : %d�� ���ܸ� : %s\n\n", team_list[i].team_id, team_list[i].team_name);
		}
	}
	int update_id;
	printf("������ ���� id�� �Է��ϼ���.");
	scanf("%d", &update_id);

	printf("���� �����մϴ�. \n\n");
	printf("=========================\n\n");
	
	char update_area[20];
	printf("�������� �Է��ϼ��� : ");
	scanf("%s", &update_area);
	char update_stadium[50];
	printf("Ȩ������ �Է��ϼ��� : ");
	scanf("%s", &update_stadium);
	printf("â�ܿ����� �Է��ϼ��� : ");
	int update_since;
	scanf("%d", &update_since);
	printf("�����̸��� �Է��ϼ��� : ");
	char update_coach[20];
	scanf("%s", &update_coach);
	printf("���Ƚ���� �Է��ϼ��� : ");
	int update_v;
	scanf("%d", &update_v);
	printf("������ �Է��ϼ��� : ");
	char update_team_name[50];
	scanf("%s", &update_team_name);

	printf("\n\n\n====================\n\n");
	printf("������ �� ���� Ȯ��\n");
	printf("====================\n\n");
	printf("��id : %d��  ������ : %s   Ȩ���� : %s  â�ܿ��� : %d��\n"
		"���� : %s    K���� ��� : %d��	���ܸ� : %s\n\n",
		update_id, update_area, update_stadium, update_since, update_coach, update_v, update_team_name);

	printf("�Է��� ������ ��Ȯ�ϸ� 1, ����Ȯ�ϸ� 2�� ��������."
		"1�� ������ ����ȭ��, 2�� ������ �ٽ� ����ȭ������ �̵��մϴ�.\n");
	int corr = 0;
	printf("1 or 2 �Է� :  ");
	scanf("%d", &corr);

	if (corr == 1)
	{
		int update = update_id;

		if (team_list[update].team_id == update_id)
		{

			team_list[update].team_id = update_id;
			strcpy(team_list[update].area, update_area);
			strcpy(team_list[update].stadium, update_stadium);
			team_list[update].since = update_since;
			strcpy(team_list[update].coach, update_coach);
			team_list[update].v = update_v;
			strcpy(team_list[update].team_name, update_team_name);

		}


		main();
	}
	else
	{
		team_prof_update();
	}
}

void team_show()
{
	system("cls");
	int i;
	


	for (i = 0; i < 10; i++)
	{
		if (team_list[i].use_YN == 'Y')
		{
			printf("��id : %d��  ������ : %s   Ȩ���� : %s  â�ܿ��� : %d��\n"
				"���� : %s    K���� ��� : %d��	���ܸ� : %s\n\n",
				team_list[i].team_id, team_list[i].area, team_list[i].stadium, team_list[i].since, team_list[i].coach, team_list[i].v, team_list[i].team_name);
		}
	}
	
	printf("������ ��ȸ�Ϸ�.\n\n\n\n");
	system("pause");
	team();

}

void team_delete()
{
	int c;
	int flag = 0;

	system("cls");

	printf("1.����\n");
	printf("2.����\n");
	printf("3.��������\n");

	scanf("%d", &c);

	if (c == 1)
	{
		int i;
		for (i = 0; i < new; i++)
		{
			if (team_list[i].use_YN == 'Y')
			{
				printf("��id : %d�� ���ܸ� : %s\n\n", team_list[i].team_id, team_list[i].team_name);

			}
		}
		int delete_id;

		printf("������ ���� id�� �Է��ϼ���.");
		scanf("%d", &delete_id);
		printf("\n\n");

		for (int j = 0; j < 20; j++)
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
			}

		}
		if (flag == 0)
		{
			int delete = delete_id;
			char YorN;
			printf("%s���� �����Ͻðڽ��ϱ�?	(Y/N)", team_list[delete].team_name);
			scanf("%s", &YorN);
			printf("\n\n");

			if (YorN == 'Y')
			{
				team_list[delete].use_YN = 'N';
				printf("%s���� �����Ǿ����ϴ�.\n\n", team_list[delete].team_name);
			}
			system("pause");
			team();
		}
		else
		{
			printf("������ �����־� ���� ������ �� �����ϴ�.\n\n");
			system("pause");
			team();
		}


	}
	else if (c == 2)
	{
		printf("������ �� ��ȸ\n\n");
		int i;
		int recovery_id;
		for (i = 0; i < new; i++)
		{
			if (team_list[i].use_YN == 'N')
			{
				printf("��id : %d��  ������ : %s   Ȩ���� : %s  â�ܿ��� : %d��\n"
					"���� : %s    K���� ��� : %d��	���ܸ� : %s\n\n",
					team_list[i].team_id, team_list[i].area, team_list[i].stadium, team_list[i].since, team_list[i].coach, team_list[i].v, team_list[i].team_name);
			}
		}
		printf("������ ���� id�� �Է��ϼ���.");
		scanf("%d", &recovery_id);

		int recovery = recovery_id;
		char NorY;
		printf("%s���� �����ϰڽ��ϱ�?	(Y/N)", team_list[recovery].team_name);
		scanf("%s", &NorY);
		printf("\n\n");

		if (NorY == 'Y')
		{
			team_list[recovery].use_YN = 'Y';
			printf("%s���� �����Ǿ����ϴ�.\n\n", team_list[recovery].team_name);
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
	printf("1.���ο� �� ���\n");
	printf("2.�� ���� ����\n");
	printf("3.�� ���� ��ȸ\n");
	printf("4.�� ���� ����\n");
	printf("5.��������..\n");
	/*printf("6.�ؽ�Ʈ �ҷ����� \n");*/
	scanf("%d", &menu);
	printf("\n\n\n");

	switch (menu)
	{

	case 1:		//�� ���
		team_prof_C();
		break;
	case 2:
		team_prof_update();
		break;
	case 3:
		team_show();
		break;
	case 4:
		team_delete();
		break;

	case 5:
		main();
		break;
	/*case 6:
		team_txt();
		break;*/
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