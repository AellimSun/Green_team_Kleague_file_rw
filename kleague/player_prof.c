#include "���.h"
#include "parson.h"

#define player_number 20

player* plp = &player_list;

void player_prof();
void player_prof_C();
void player_prof_R();
void player_prof_U();

/********** ���� �Է� �Լ� **********/
void write_file() {
	FILE* f = fopen("player_prof.txt", "w");
	for (int i = 0; i < player_number; i++) {
		if (player_list[i].player_id == 0) {
			break;
		}
		fprintf(f, "%s %s %d %d %d %s %c\n",
			(plp + i)->player_id, (plp + i)->player_name, (plp + i)->player_height, (plp + i)->player_weight, (plp + i)->player_back_num, (plp + i)->player_position, (plp + i)->useYN);
	}
	fclose(f);
}

/********** ���� ��� �Լ� **********/
void read_file() {
	FILE* f;
	f = fopen("player_prof.txt", "r");

	int i = 0;
	while (!feof(f)) {
		fscanf(f, "%s %s %d %d %d %s %c\n",
			(plp+i)->player_id, (plp + i)->player_name, &(plp + i)->player_height, &(plp + i)->player_weight, &(plp + i)->player_back_num, (plp + i)->player_position, &(plp + i)->useYN);
		i++;
	}
	fclose(f);
}

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
		//������ �ý��ۻ󿡼� ���� ����Ǹ� ���� ���� �ε�����ȣ ���� ������ 0���� �̷���� ��¥ ������ �����ǹǷ� üũ
		if (strcmp(player_list[i].player_name, "0") == 0) {
			seq = i;
			hasRoom = 1;
			break;
		}
		else if (strlen(player_list[i].player_name) == 0) {
			seq = i;
			hasRoom = 1;
			break;
		}
	}

	if (hasRoom != 1) {
		printf("��� ������ ���� ���� �Ѿ���ϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");

		system("pause");

		player_prof();
	}

	printf("���� �̸� �Է� : ");
	gets(plp[seq].player_name);
	printf("�Է��Ͻ� �̸��� %s�Դϴ�.\n\n", (*(plp+seq)).player_name);

	printf("�Ҽ� �� �Է� : ");
	gets(team_name);
	printf("�Է��Ͻ� ������ %s�Դϴ�.\n\n", team_name);

	//�����ϴ� �������� ����
	for (int i = 0; i < 10; i++) {
		if (strcmp(team_name, team_list[i].team_name) == 0) {
			tmp_id = team_list[i].team_id;
			valid = 1;
			break;
		}
	}

	if (valid == 0) {
		printf("�Է��Ͻ� ���� �������� �ʴ� ���Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		strcpy((*(plp + seq)).player_name, "\0");
		system("pause");
		player_prof();
	}

	printf("���� Ű �Է� : ");
	scanf("%d", &(*(plp + seq)).player_height);
	printf("�Է��Ͻ� Ű�� %d�Դϴ�.\n\n", (*(plp + seq)).player_height);

	printf("���� ������ �Է� : ");
	scanf("%d", &(*(plp + seq)).player_weight);
	printf("�Է��Ͻ� �����Դ� %d�Դϴ�.\n\n", (*(plp + seq)).player_weight);

	printf("���� ���ȣ �Է� : ");
	scanf("%d", &(*(plp + seq)).player_back_num);
	printf("�Է��Ͻ� ���ȣ�� %d�Դϴ�.\n\n", (*(plp + seq)).player_back_num);
	getchar();

	printf("���� ������ �Է� ( GK / DF / MF / FW �� �Ѱ����� �Է� ) : ");
	gets((*(plp + seq)).player_position);
	printf("�Է��Ͻ� �������� %s�Դϴ�.\n\n", (*(plp + seq)).player_position);

	//���� ���̵� ����
	sprintf(tmp_id_c, "%d", tmp_id);
	strcpy((*(plp + seq)).player_id, tmp_id_c);
	strcat((*(plp + seq)).player_id, "-");
	sprintf(tmp_id_c, "%d", (*(plp + seq)).player_back_num);
	strcat((*(plp + seq)).player_id, tmp_id_c);

	//��뿩��(���� ���� ó�� ����) �⺻�� Y ����
	(*(plp + seq)).useYN = 'Y';

	//���� ��Ͽ��� �Էµ� ���� ���� �߰�
	strcpy(player_history_list[seq].id, (*(plp + seq)).player_id);
	player_history_list[seq].score = 0;
	player_history_list[seq].assistant = 0;
	player_history_list[seq].yellow_card = 0;
	player_history_list[seq].off_the_field = 0;
	player_history_list[seq].view_YN = 'Y';

	//���Ͽ� ������� ����
	write_file();
	system("pause");
	printf("������ ��ϵǾ����ϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
	player_prof();
}

/********** ���� ���� �Լ� **********/
void proc_update(int seq) {
	int cmd = 0;
	char tmp_id_c[5];

	//���� ��� �Լ�
	write_file();

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
		gets(plp[seq].player_name);
		printf("������ �̸��� %s�Դϴ�.\n\n", plp[seq].player_name);

		system("pause");
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
			strcpy(plp[seq].player_name, "\0");
			player_prof();
		}

		//���� ���̵� ����
		sprintf(tmp_id_c, "%d", tmp_id);
		strcpy(plp[seq].player_id, tmp_id_c);
		strcat(plp[seq].player_id, "-");
		sprintf(tmp_id_c, "%d", plp[seq].player_back_num);
		strcat(plp[seq].player_id, tmp_id_c);

		printf("������ �Ҽ� ���� %s�Դϴ�.\n\n", team_name);

		system("pause");
		proc_update(seq);
	}
	else if (cmd == 3) {
		printf("���� Ű �Է� : ");
		scanf("%d", &plp[seq].player_height);
		getchar();
		printf("������ Ű�� %d�Դϴ�.\n\n", plp[seq].player_height);

		system("pause");
		proc_update(seq);
	}
	else if (cmd == 4) {
		printf("���� ������ �Է� : ");
		scanf("%d", &plp[seq].player_weight);
		getchar();
		printf("������ �����Դ� %d�Դϴ�.\n\n", player_list[seq].player_weight);

		system("pause");
		proc_update(seq);
	}
	else if (cmd == 5) {
		char tmp_id[5];

		printf("���� ���ȣ �Է� : ");
		scanf("%d", &plp[seq].player_back_num);
		getchar();

		//���� ���̵� ����
		char* ptr = strtok(plp[seq].player_id, "-");
		strcpy(plp[seq].player_id, ptr);
		strcat(plp[seq].player_id, "-");
		sprintf(tmp_id, "%d", plp[seq].player_back_num);
		strcat(plp[seq].player_id, tmp_id);

		printf("������ ���ȣ�� %d�Դϴ�.\n\n", plp[seq].player_back_num);

		system("pause");
		proc_update(seq);
	}
	else if (cmd == 6) {
		printf("���� ������ �Է� ( GK / DF / MF / FW �� �Ѱ����� �Է� ) : ");
		gets(plp[seq].player_position);
		printf("������ �������� %s�Դϴ�.\n\n", plp[seq].player_position);

		system("pause");
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
		system("pause");
		proc_update(seq);
	}
}

void player_prof_U() {
	char input[10];
	int seq = 99;

	system("cls");

	printf("\n\n---------------------------------------------------------------\n���� ��ȸ�� �����ϼ̽��ϴ�.\n");
	printf("������ ���ϴ� ������ �̸� : ");
	gets(input);

	for (int i = 0; i < player_number; i++) {
		if (strcmp(input, plp[i].player_name) == 0) {
			seq = i;
			break;
		}
	}

	if (strlen(plp[seq].player_name) != 0 && plp[seq].useYN == 'Y') {
		//���� ��� �Լ�
		read_file();
		proc_update(seq);
	}
	else {
		printf("������� ���� ���� �̸��Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		system("pause");
		player_prof();
	}
}

/********** ��ȸ ���� �Լ� **********/
void player_prof_R() {
	int cmd;

	system("cls");
	
	//JSON���� �о��
	////�ʱ�ȭ
	//JSON_Value* jval = json_parse_file("player_list.json");
	//JSON_Object* jobj = json_value_get_object(jval);
	////JSON_Array* jarr = json_object_get_array(jobj, "player");
	////JSON_Array* jarr = json_value_get_array(jval);

	//JSON_Array* jarr = json_object_get_array(jobj, "player");

	////���
	//for (int i = 0; i < json_array_get_count(jarr); i++) {
	//	printf("i : %d\n", i);
	//	JSON_Object* in = json_array_get_object(jarr, i);
	//	strcpy(player_list[i].player_id, json_object_get_string(in, "id"));
	//	printf("%s\n", json_object_get_string(in, "name"));
	//	strcpy(player_list[i].player_name, json_object_get_string(in, "name"));
	//	player_list[i].player_height = (int)json_object_get_number(in, "height");
	//	player_list[i].player_weight= (int)json_object_get_number(in, "weight");
	//	player_list[i].player_back_num = (int)json_object_get_number(in, "back");
	//	strcpy(player_list[i].player_position, json_object_get_string(in, "position"));
	//	player_list[i].useYN = json_object_get_string(in, "useYN")[0];
	//}

	//for (int i = 0; i < player_number; i++) {
	//	printf("%s\t%s\t%dcm\t%dkg\t%d\t%s\t%c\n\n", player_list[i].player_id, player_list[i].player_name, player_list[i].player_height, player_list[i].player_weight,
	//		player_list[i].player_back_num, player_list[i].player_position, player_list[i].useYN);
	//}
	//json_value_free(jval);

	printf("\n\n---------------------------------------------------------------\n���� ��ȸ�� �����ϼ̽��ϴ�.\n");

	printf("���ϴ� �۾��� �����ϼ���\n");
	printf("1. ��� ���� ��ȸ\n");
	printf("2. ���� �̸����� ��ȸ\n");
	printf("3. ���� ������ ������ ���ư���\n");
	printf("4. �������� ���ư���\n\n");

	scanf("%d", &cmd);
	getchar();

	if (cmd == 1) {
		char team_name[50]; 
		int team_id;

		for (int i = 0; i < player_number - 1; i++) {
			if (plp[i + 1].player_back_num == 0) break;
			plp[i + 1].next = plp + i + 1;
		}

		printf("---------------------------------------------------------------\n");
		printf("����ID\t������\tŰ\t������\t���ȣ\t������\t�Ҽ���\n");
		printf("---------------------------------------------------------------\n");

		for (int i = 0; i < player_number; i++) {
			if (plp[i + 1].player_back_num == 0) break;
			team_id = player_list[i].player_id[0] - '0';

			//�� ID�� ���� �޾ƿ��� 
			for (int i = 0; i < 10; i++) {
				if (team_id == team_list[i].team_id) {
					strcpy(team_name, team_list[i].team_name);
					break;
				}
			}

			printf("%s\t%s\t%dcm\t%dkg\t%d\t%s\t%s\n\n", plp[i].player_id, plp[i].player_name, plp[i].player_height, plp[i].player_weight,
				plp[i].player_back_num, plp[i].player_position, team_name);
		}

		system("pause");
		player_prof_R();
	}
	else if (cmd == 2) {
		char input[10];
		int seq = 99;

		printf("��ȸ�� ���ϴ� ������ �̸� : \n");
		gets(input);

		for (int i = 0; i < player_number; i++) {
			if (strcmp(input, plp[i].player_name) == 0) {
				seq = i;
				break;
			}
		}

		if (strlen(plp[seq].player_name) != 0 && plp[seq].useYN == 'Y') {
			char team_name[50];
			int team_id = player_list[seq].player_id[0] - '0';

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
			printf("%s\t%s\t%dcm\t%dkg\t%d\t%s\t%s\n\n", plp[seq].player_id, plp[seq].player_name, plp[seq].player_height, plp[seq].player_weight,
				plp[seq].player_back_num, plp[seq].player_position, team_name);

			system("pause");
			player_prof();

		}
		else {
			printf("������� ���� ���� �̸��Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
			system("pause");
			player_prof();
		}
	}
	else {
		printf("�߸��� �Է��Դϴ�.\n\n");
		system("pause");
		player_prof_R();
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
		if (strcmp(input, plp[i].player_name) == 0) {
			seq = i;
			break;
		}
	}

	if (strlen(plp[seq].player_name) != 0 && plp[seq].useYN == 'Y') {
		char cfm = NULL;

		printf("\n\n%s ������ ���� �����Ͻðڽ��ϱ�?( Y / N ) : ", input);
		scanf("%c", &cfm);

		if (cfm == 'Y') {
			plp[seq].useYN = 'N';

			printf("���� ó���Ǿ����ϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
			//���� ��� �Լ�
			write_file();

			system("pause");
			player_prof();
		}
		else {
			printf("��Ҹ� �����ϼ̽��ϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
			system("pause");
			player_prof();
		}
	}
	else {
		printf("������� ���� ���� �̸��Դϴ�. ���� ������ �޴��� ���ư��ϴ�.\n\n");
		system("pause");
		player_prof();
	}
}

void player_prof() {
	int cmd = 0;

	system("cls");

	//���� �б� �Լ�
	read_file();

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