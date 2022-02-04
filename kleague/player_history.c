#include "���.h"

#define menu_player_history_create 1
#define menu_player_history_update 2
#define menu_player_history_read 3
#define menu_player_history_del 4
#define menu_player_history_goto_main 0
#define loop_start 1
#define loop_end 0

#define ��� 0
#define �λ� 1
#define ���� 2
#define CNT_PLYAER 20
#define ID_LENGTH 5
#define NAME_LENGTH 10

void player_history(void);
void player_history_C(int repeat, char name_in[],int player_num);
void player_history_R(char name_in[], int player_num);
void player_history_U(char name_in[], int player_num);
void player_history_D(char name_in[], int player_num);

int search_by_name(char arr[]);
void initialize(int in_a, int player_num, char name_in[]);


void player_history(void)
{
    int in_a = 10;
    int repeat = 12;
    int player_num = CNT_PLYAER + 1;
    char name_in[NAME_LENGTH];

    while (in_a != menu_player_history_goto_main)
    {
        system("cls");

        printf("---------------------------------------------------------------\n���ϴ� �۾��� �����ϼ���\n");
        printf("1. ���� ��� ��� ���\n2.���� ��� ����\n3.���� ��� ��ȸ\n4.���� ��� ��ȸ ����\n0.��������\n");
        scanf("%d", &in_a);
        getchar();
        
        if ((0 <= in_a && in_a <= 4 )==1)
        {
            switch (in_a)
            {
            case menu_player_history_create:
                player_history_C(repeat, name_in, player_num);
                initialize(in_a, player_num, name_in);
                break;

            case menu_player_history_update:
                player_history_U(name_in, player_num);
                initialize(in_a, player_num, name_in);
                break;

            case menu_player_history_read:
                player_history_R(name_in, player_num);
                initialize(in_a, player_num, name_in);
                in_a = 0;
                break;

            case menu_player_history_del:
                player_history_D(name_in, player_num);
                initialize(in_a, player_num, name_in);
                in_a = 0;
                break;

            case menu_player_history_goto_main:
                printf("����ȭ������ ���ư��ϴ�.");

                break;
            }
        }
        else
        {
            printf("�Է¿����Դϴ�.\n");
        }
    }
    player_mng();
}

void player_history_C(int repeat, char name_in[], int player_num)
{
    int score = 0;
    int assitant = 0;
    int yellow_card = 0;
    int off_the_feild = 0;

    char player_id[ID_LENGTH];

    int go = loop_start;

    while (go == loop_start)
    {
        system("cls");
        printf("---------------------------------------------------------------\n");
        printf("���� �̸��� �Է��ϼ���.");
        scanf("%s", name_in);
    
        player_num = search_by_name(name_in);

        if (0 <= player_num && player_num < CNT_PLYAER)
        {
            printf("������ �Է��ϼ���.");
            scanf("%d", &score);

            player_history_list[player_num].score += score;

            printf("������ �Է��ϼ���.");
            scanf("%d", &assitant);
            player_history_list[player_num].assitant += assitant;

            printf("���� ��� Ƚ���� �Է��ϼ���.");
            scanf("%d", &yellow_card);
            player_history_list[player_num].yellow_card += yellow_card;

            printf("������ �Է��ϼ���.");
            scanf("%d", &off_the_feild);
            player_history_list[player_num].off_the_feild += off_the_feild;
            go = loop_end;
            system("pause");
        }
        else if (player_num == CNT_PLYAER + 1)
        {
            printf("���� �̸��� �߸��Ǿ����ϴ�. �̸��� �ٽ� �Է��ϼ���.\n");
            system("pause");
        }
        else if (player_num == CNT_PLYAER + 2)
        {
            printf("��ȸ�� ������ �����Դϴ�.\n");
            system("pause");
        }
        repeat++;
    }

}

void player_history_R(char name_in[], int player_num)
{
    int go = loop_start;

    while (go == loop_start)
    {
        system("cls");
        printf("---------------------------------------------------------------\n");
        printf("��ȸ�� ���� �̸��� �Է��ϼ���.");
        scanf("%s", name_in);

        player_num = search_by_name(name_in);

        if (0 <= player_num && player_num < CNT_PLYAER)
        {
            printf("���� : %d\n", player_history_list[player_num].score);
            printf("���� : %d\n", player_history_list[player_num].assitant);
            printf("��� : %d\n", player_history_list[player_num].yellow_card);
            printf("���� : %d\n", player_history_list[player_num].off_the_feild);
            go = loop_end;
        }
        else if (player_num == CNT_PLYAER + 1)
        {
            printf("�����Դϴ�. �����̸��� �ٽ� �Է��ϼ���.\n");
        }
        else if (player_num == CNT_PLYAER + 2)
        {
            printf("��ȸ�� ������ �����Դϴ�.\n");
        }
        system("pause");
    }
}

void player_history_U(char name_in[], int player_num)
{
    int go = loop_start;

    while (go == loop_start)
    {
        system("cls");
        printf("---------------------------------------------------------------\n");
        printf("������ ���� �̸��� �Է��ϼ���.");
        scanf("%s", name_in);

        player_num = search_by_name(name_in);

        if (0 <= player_num && player_num < CNT_PLYAER)
        {
            int in_b= 0;
            int i;
            int in_num = 0;

            while(in_b != 5)
            {
                printf("������ �׸��� �����ϼ���.\n");
                printf("1. ���� : %d\n", player_history_list[player_num].score);
                printf("2. ���� : %d\n", player_history_list[player_num].assitant);
                printf("3. ��� : %d\n", player_history_list[player_num].yellow_card);
                printf("4. ���� : %d\n", player_history_list[player_num].off_the_feild);
                printf("5. ��������\n");
                scanf("%d", &in_b);

                switch (in_b)
                {
                case 1:
                    printf("������ �߰� ���� ������, ������ ��Ҵ� ���� ������ �Է��Ͻÿ�.");
                    scanf("%d", &in_num);
                    player_history_list[player_num].score += in_num;
                    break;
                case 2:
                    printf("�������� �߰��� ���� ������, �������� ��Ҵ� ���� ������ �Է��Ͻÿ�.");
                    scanf("%d", &in_num);
                    player_history_list[player_num].assitant += in_num;
                    break;
                case 3:
                    printf("����� �߰��� ���� ������, ����� ��Ҵ� ���� ������ �Է��Ͻÿ�.");
                    scanf("%d", &in_num);
                    player_history_list[player_num].yellow_card += in_num;
                    break;
                case 4:
                    printf("�������� �߰��� ���� ������, �������� ��Ҵ� ���� ������ �Է��Ͻÿ�.");
                    scanf("%d", &in_num);
                    player_history_list[player_num].off_the_feild += in_num;
                    break;
                case 5:
                    printf("������ �����մϴ�.\n");
                    break;
                }
            }
            go = loop_end;
        }
        else if (player_num == CNT_PLYAER + 1)
        {
            printf("�����Դϴ�. �����̸��� �ٽ� �Է��ϼ���.\n");
        }
        else if (player_num == CNT_PLYAER + 2)
        {
            printf("��ȸ�� ������ �����Դϴ�.\n");
        }
        system("pause");
    }
}

void player_history_D(char name_in[], int player_num)
{
    int go = loop_start;

    while (go == loop_start)
    {
        system("cls");
        printf("---------------------------------------------------------------\n");
        printf("��� ��ȸ�� ������ ���� �̸��� �Է��ϼ���.");
        scanf("%s", name_in);

        player_num = search_by_name(name_in);

        if (0 <= player_num && player_num < CNT_PLYAER)
        {
            printf("%s�� ��� ��ȸ�� �����մϴ�.",name_in);
            player_history_list[player_num].view_YN = 'N';

            go = loop_end;
        }
        else if (player_num == CNT_PLYAER + 1)
        {
            printf("�����Դϴ�. �����̸��� �ٽ� �Է��ϼ���.\n");
            break;
        }
        else if (player_num == CNT_PLYAER + 2)
        {
            printf("��ȸ�� ������ �����Դϴ�.\n");
            break;
        }
        system("pause");
    }
}


int search_by_name(char name_in[])
{
    int i;
    int check = 1;
    int ply_num = CNT_PLYAER + 1;
    char cmp_id[ID_LENGTH];

    for (i = 0; i < CNT_PLYAER; i++)
    {
        check = strcmp(name_in,player_list[i].player_name);
        if (check == 0 && player_list[i].useYN == 'Y')
        {
            strcpy(cmp_id, player_list[i].player_id);
            break;
        }
        else
        {
            ply_num = CNT_PLYAER + 1;
        }
    }

    for (i = 0; i < CNT_PLYAER; i++)
    {
        check = strcmp(cmp_id, player_history_list[i].id);
        if (check == 0)
        {
            if (player_history_list[i].view_YN == 'Y')
            {
                ply_num = i;
            }
            else if (player_history_list[i].view_YN == 'N')
            {
                ply_num = CNT_PLYAER + 2;
            }
            break;
        }
        else
        {
            ply_num = CNT_PLYAER + 1;
        }
    }

    return  ply_num;
}

void initialize(int in_a, int player_num, char name_in[])
{
    in_a = 0;
    player_num = 0;
    name_in = 0;
}