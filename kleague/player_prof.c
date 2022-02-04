#include "���.h"

#define player_number 20


void player_prof();
void player_prof_C();
void player_prof_R();
void player_prof_U();

/********** ��� ���� �Լ� **********/
void player_prof_C() {
	int hasRoom = 0;
	int seq = 99;
	char team_name[10];
	int tmp_id;
	char tmp_id_c[5];
	int valid = 0;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n���� ����� �����ϼ̽��ϴ�.\n");
	for (int i = 0; i < player_number; i++) {
		if (strlen(player_list[i].player_name) == 0) {
			seq = i;
			hasRoom = 1;
			break;
		}
	}

	if (hasRoom != 1) {
		printf("��� ������ ���� ���� �Ѿ���ϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		player_prof();
	}

	printf("���� �̸� �Է� : ");
	gets(player_list[seq].player_name);
	printf("�Է��Ͻ� �̸��� %s�Դϴ�.\n\n", player_list[seq].player_name);

	printf("�Ҽ� �� �Է� : ");
	gets(team_name);
	printf("�Է��Ͻ� ������ %s�Դϴ�.\n\n", team_name);

	//�����ϴ� �������� ����
	for (int i = 0; i < 10; i++) {
		if (strcmp(team_name, team_list[i].team_name) == 0) {
			tmp_id = team_list[i].team_id;
			valid = 1;
		}
	}

	if (valid == 0) {
		printf("�Է��Ͻ� ���� �������� �ʴ� ���Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		strcpy(player_list[seq].player_name, "\0");
		player_prof();
	}

	printf("���� Ű �Է� : ");
	scanf("%d", &player_list[seq].player_height);
	printf("�Է��Ͻ� Ű�� %d�Դϴ�.\n\n", player_list[seq].player_height);

	printf("���� ������ �Է� : ");
	scanf("%d", &player_list[seq].player_weight);
	printf("�Է��Ͻ� �����Դ� %d�Դϴ�.\n\n", player_list[seq].player_weight);

	printf("���� ���ȣ �Է� : ");
	scanf("%d", &player_list[seq].player_back_num);
	printf("�Է��Ͻ� ���ȣ�� %d�Դϴ�.\n\n", player_list[seq].player_back_num);
	getchar();

	printf("���� ������ �Է� ( GK / DF / MF / FW �� �Ѱ����� �Է� ) : ");
	gets(player_list[seq].player_position);
	printf("�Է��Ͻ� �������� %s�Դϴ�.\n\n", player_list[seq].player_position);

	//���� ���̵� ����
	sprintf(tmp_id_c, "%d", tmp_id);
	strcpy(player_list[seq].player_id, tmp_id_c);
	strcat(player_list[seq].player_id, "-");
	sprintf(tmp_id_c, "%d", player_list[seq].player_back_num);
	strcat(player_list[seq].player_id, tmp_id_c);

	//��뿩��(���� ���� ó�� ����) �⺻�� Y ����
	player_list[seq].useYN = 'Y';

	//���� ��Ͽ��� �Էµ� ���� ���� �߰�
	strcpy(player_history_list[seq].id, player_list[seq].player_id);
	player_history_list[seq].score = 0;
	player_history_list[seq].assistant = 0;
	player_history_list[seq].yellow_card = 0;
	player_history_list[seq].off_the_field = 0;
	player_history_list[seq].view_YN = 'Y';

	printf("%s", player_list[12].player_name);
	printf("������ ��ϵǾ����ϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
	player_prof();
}

/********** ���� ���� �Լ� **********/
void proc_update(int seq) {
	int cmd = 0;
	char tmp_id_c[5];

	system("cls");

	printf("---------------------------------------------------------------\n���ϴ� �۾��� �����ϼ���\n");
	printf("1. ���� �̸� ����\n");
	printf("2. �Ҽ� �� ����\n");
	printf("3. ���� Ű ����\n");
	printf("4. ���� ������ ����\n");
	printf("5. ���� ���ȣ ����\n");
	printf("6. ���� ������ ����\n");
	printf("7. ���� �������� ���ư���\n");
	printf("8. ���� ������ ������ ���ư���\n");
	printf("9. �������� ���ư���\n\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		printf("���� �̸� �Է� : ");
		gets(player_list[seq].player_name);
		printf("������ �̸��� %s�Դϴ�.\n\n", player_list[seq].player_name);

		proc_update(seq);
	}
	else if (cmd == 2) {
		char team_name[10];
		int tmp_id;
		int valid = 0;

		printf("�Ҽ� �� �Է� : ");
		gets(team_name);

		//�����ϴ� �������� ����
		for (int i = 0; i < 10; i++) {
			if (strcmp(team_name, team_list[i].team_name) == 0) {
				tmp_id = team_list[i].team_id;
				valid = 1;
			}
		}

		if (valid == 0) {
			printf("�Է��Ͻ� ���� �������� �ʴ� ���Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
			strcpy(player_list[seq].player_name, "\0");
			player_prof();
		}

		//���� ���̵� ����
		sprintf(tmp_id_c, "%d", tmp_id);
		strcpy(player_list[seq].player_id, tmp_id_c);
		strcat(player_list[seq].player_id, "-");
		sprintf(tmp_id_c, "%d", player_list[seq].player_back_num);
		strcat(player_list[seq].player_id, tmp_id_c);

		printf("������ �Ҽ� ���� %s�Դϴ�.\n\n", team_name);

		proc_update(seq);
	}
	else if (cmd == 3) {
		printf("���� Ű �Է� : ");
		scanf("%d", &player_list[seq].player_height);
		getchar();
		printf("������ Ű�� %d�Դϴ�.\n\n", player_list[seq].player_height);

		proc_update(seq);
	}
	else if (cmd == 4) {
		printf("���� ������ �Է� : ");
		scanf("%d", &player_list[seq].player_weight);
		getchar();
		printf("������ �����Դ� %d�Դϴ�.\n\n", player_list[seq].player_weight);

		proc_update(seq);
	}
	else if (cmd == 5) {
		char tmp_id[5];

		printf("���� ���ȣ �Է� : ");
		scanf("%d", &player_list[seq].player_back_num);
		getchar();

		//���� ���̵� ����
		char* ptr = strtok(player_list[seq].player_id, "-");
		strcpy(player_list[seq].player_id, ptr);
		strcat(player_list[seq].player_id, "-");
		sprintf(tmp_id, "%d", player_list[seq].player_back_num);
		strcat(player_list[seq].player_id, tmp_id);

		printf("������ ���ȣ�� %d�Դϴ�.\n\n", player_list[seq].player_back_num);

		proc_update(seq);
	}
	else if (cmd == 6) {
		printf("���� ������ �Է� ( GK / DF / MF / FW �� �Ѱ����� �Է� ) : ");
		gets(player_list[seq].player_position);
		printf("������ �������� %s�Դϴ�.\n\n", player_list[seq].player_position);

		proc_update(seq);
	}
	else if (cmd == 7) {
		player_prof_U();
	}
	else if (cmd == 8) {
		player_prof();
	}
	else if (cmd == 9) {
		main();
	}
	else {
		printf("�߸��� �Է��Դϴ�. ���� ���� �޴��� ���ư��ϴ�.\n\n");
		proc_update(seq);
	}
}

void player_prof_U() {
	char input[10];
	int seq = 99;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n���� ��ȸ�� �����ϼ̽��ϴ�.\n");
	printf("������ ���ϴ� ������ �̸� : \n");
	gets(input);

	for (int i = 0; i < player_number; i++) {
		if (strcmp(input, player_list[i].player_name) == 0) {
			seq = i;
			break;
		}
	}
	
	if (strlen(player_list[seq].player_name) != 0 && player_list[seq].useYN == 'Y') {
		proc_update(seq);
	}
	else {
		printf("������� ���� ���� �̸��Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		player_prof();
	}
}

/********** ��ȸ ���� �Լ� **********/
void player_prof_R() {
	char input[10];
	int seq = 99;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n���� ��ȸ�� �����ϼ̽��ϴ�.\n");
	printf("��ȸ�� ���ϴ� ������ �̸� : \n");
	gets(input);

	for (int i = 0; i < player_number; i++) {
		if (strcmp(input, player_list[i].player_name) == 0) {
			seq = i;
			break;
		}
	}

	if (strlen(player_list[seq].player_name) != 0 && player_list[seq].useYN == 'Y') {
		char team_name[50];
		int team_id = player_list[seq].player_id[0] - '0';
		printf("%d", team_id);

		//�� ID�� ���� �޾ƿ��� 
		for (int i = 0; i < 10; i++) {
			if (team_id == team_list[i].team_id) {
				strcpy(team_name, team_list[i].team_name);
				break;
			}
		}

		printf("---------------------------------------------------------------\n");
		printf("����ID\t������\tŰ\t������\t���ȣ\t������\t�Ҽ���\n");
		printf("---------------------------------------------------------------\n");
		printf("%s\t%s\t%dcm\t%dkg\t%d\t%s\t%s\n\n", player_list[seq].player_id, player_list[seq].player_name, player_list[seq].player_height, player_list[seq].player_weight,
			player_list[seq].player_back_num, player_list[seq].player_position, team_name);

		system("pause");
		player_prof();

	}
	else {
		printf("������� ���� ���� �̸��Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		player_prof();
	}
}

/********** ���� ���� �Լ� **********/
void player_prof_D() {
	char input[10];
	int seq = 99;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n���� ������ �����ϼ̽��ϴ�.\n");
	printf("������ ���ϴ� ������ �̸� : \n");
	gets(input);

	for (int i = 0; i < player_number; i++) {
		if (strcmp(input, player_list[i].player_name) == 0) {
			seq = i;
			break;
		}
	}

	if (strlen(player_list[seq].player_name) != 0 && player_list[seq].useYN == 'Y') {
		char cfm = NULL;

		printf("\n\n%s ������ ���� �����Ͻðڽ��ϱ�?( Y / N ) : ", input);
		scanf("%c", &cfm);

		if (cfm == 'Y') {
			player_list[seq].useYN = 'N';

			printf("���� ó���Ǿ����ϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
			player_prof();
		}
		else {
			printf("��Ҹ� �����ϼ̽��ϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
			player_prof();
		}
	}
	else {
		printf("������� ���� ���� �̸��Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		player_prof();
	}
}

void player_prof() {
	int cmd = 0;

	system("cls");

	printf("---------------------------------------------------------------\n���ϴ� �۾��� �����ϼ���\n");
	printf("1. ���� ���\n");
	printf("2. ���� ����\n");
	printf("3. ���� ��ȸ\n");
	printf("4. ���� ����\n");
	printf("5. �������� ���ư���\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		player_prof_C();
	}
	else if (cmd == 2) {
		player_prof_U();
	}
	else if (cmd == 3) {
		player_prof_R();
	}
	else if (cmd == 4) {
		player_prof_D();
	}
	else if (cmd == 5) {
		main();
	}
	else {
		printf("�߸��� �Է��Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		player_prof();
	}
}