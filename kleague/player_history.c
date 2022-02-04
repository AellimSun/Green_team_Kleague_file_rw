#include "헤더.h"
#include <stdio.h>
#include <stdlib.h>

#define menu_player_history_create 1
#define menu_player_history_update 2
#define menu_player_history_read 3
#define menu_player_history_del 4
#define menu_player_history_goto_main 0
#define loop_start 1
#define loop_end 0

#define 울산 0
#define 부산 1
#define 제주 2
#define CNT_PLYAER 20
#define ID_LENGTH 5
#define NAME_LENGTH 10

#define FILE_NAME "player_history"

player_his player_history_list[player_number];

void player_history(void);
void player_history_C(int repeat, char name_in[],int player_num);
void player_history_R(char name_in[], int player_num);
void player_history_U(char name_in[], int player_num);
void player_history_D(char name_in[], int player_num);

int search_by_name(char arr[]);
void initialize(int in_a, int player_num, char name_in[]);

void player_history_data_read_txt(void);
void player_history_data_write_txt(void);
void player_history_data_read_json(void);

void player_history(void)
{
    int in_a = 10;
    int repeat = 12;
    int player_num = CNT_PLYAER + 1;
    char name_in[NAME_LENGTH];

    while (in_a != menu_player_history_goto_main)
    {
        system("cls");
        
        printf("---------------------------------------------------------------\n원하는 작업을 선택하세요\n");
        printf("1. 선수 경기 기록 등록\n2.선수 기록 수정\n3.선수 기록 조회\n4.선수 기록 조회 금지\n0.이전으로\n");
        scanf("%d", &in_a);
        getchar();
        
        if ((0 <= in_a && in_a <= 4 )==1)
        {
            switch (in_a)
            {
            case menu_player_history_create:
                player_history_data_read_txt();
                player_history_C(repeat, name_in, player_num);
                player_history_data_write_txt();
                initialize(in_a, player_num, name_in);
                break;

            case menu_player_history_update:
                player_history_data_read_txt();
                player_history_U(name_in, player_num);
                player_history_data_write_txt();
                initialize(in_a, player_num, name_in);
                break;

            case menu_player_history_read:
                player_history_data_read_txt();
                player_history_R(name_in, player_num);
                initialize(in_a, player_num, name_in);
                in_a = 0;
                break;

            case menu_player_history_del:
                player_history_data_read_txt();
                player_history_D(name_in, player_num);
                player_history_data_write_txt();
                initialize(in_a, player_num, name_in);
                in_a = 0;
                break;

            case menu_player_history_goto_main:
                printf("이전화면으로 돌아갑니다.");

                break;
            }
        }
        else
        {
            printf("입력오류입니다.\n");
        }
    }
    player_mng();
}

void player_history_C(int repeat, char name_in[], int player_num)
{
    int score = 0;
    int assistant = 0;
    int yellow_card = 0;
    int off_the_field = 0;

    char player_id[ID_LENGTH];

    int go = loop_start;

    while (go == loop_start)
    {
        system("cls");
        printf("---------------------------------------------------------------\n");
        printf("선수 이름을 입력하세요.");
        scanf("%s", name_in);
    
        player_num = search_by_name(name_in);

        if (0 <= player_num && player_num < CNT_PLYAER)
        {
            printf("득점을 입력하세요.");
            scanf("%d", &score);

            player_history_list[player_num].score += score;

            printf("도움을 입력하세요.");
            scanf("%d", &assistant);
            player_history_list[player_num].assistant += assistant;

            printf("받은 경고 횟수를 입력하세요.");
            scanf("%d", &yellow_card);
            player_history_list[player_num].yellow_card += yellow_card;

            printf("퇴장을 입력하세요.");
            scanf("%d", &off_the_field);
            player_history_list[player_num].off_the_field += off_the_field;

            player_history_data_write_txt();

            go = loop_end;
            system("pause");
        }
        else if (player_num == CNT_PLYAER + 1)
        {
            printf("선수 이름이 잘못되었습니다. 이름을 다시 입력하세요.\n");
            system("pause");
        }
        else if (player_num == CNT_PLYAER + 2)
        {
            printf("조회가 금지된 선수입니다.\n");
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
        printf("조회할 선수 이름을 입력하세요.");
        scanf("%s", name_in);

        player_history_data_read_txt();

        player_num = search_by_name(name_in);

        if (0 <= player_num && player_num < CNT_PLYAER)
        {
            printf("득점 : %d\n", player_history_list[player_num].score);
            printf("도움 : %d\n", player_history_list[player_num].assistant);
            printf("경고 : %d\n", player_history_list[player_num].yellow_card);
            printf("퇴장 : %d\n", player_history_list[player_num].off_the_field);
            go = loop_end;
        }
        else if (player_num == CNT_PLYAER + 1)
        {
            printf("오류입니다. 선수이름을 다시 입력하세요.\n");
        }
        else if (player_num == CNT_PLYAER + 2)
        {
            printf("조회가 금지된 선수입니다.\n");
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
        printf("수정할 선수 이름을 입력하세요.");
        scanf("%s", name_in);

        player_num = search_by_name(name_in);

        if (0 <= player_num && player_num < CNT_PLYAER)
        {
            int in_b= 0;
            int i;
            int in_num = 0;

            while(in_b != 5)
            {
                printf("수정할 항목을 선택하세요.\n");
                printf("1. 득점 : %d\n", player_history_list[player_num].score);
                printf("2. 도움 : %d\n", player_history_list[player_num].assistant);
                printf("3. 경고 : %d\n", player_history_list[player_num].yellow_card);
                printf("4. 퇴장 : %d\n", player_history_list[player_num].off_the_field);
                printf("5. 수정종료\n");
                scanf("%d", &in_b);

                switch (in_b)
                {
                case 1:
                    printf("누적골 추가 양의 정수로, 누적골 취소는 음의 정수로 입력하시오.");
                    scanf("%d", &in_num);
                    player_history_list[player_num].score += in_num;
                    break;
                case 2:
                    printf("누적도움 추가는 양의 정수로, 누적도움 취소는 음의 정수로 입력하시오.");
                    scanf("%d", &in_num);
                    player_history_list[player_num].assistant += in_num;
                    break;
                case 3:
                    printf("경고누적 추가는 양의 정수로, 경고누적 취소는 음의 정수로 입력하시오.");
                    scanf("%d", &in_num);
                    player_history_list[player_num].yellow_card += in_num;
                    break;
                case 4:
                    printf("누적퇴장 추가는 양의 정수로, 누적퇴장 취소는 음의 정수로 입력하시오.");
                    scanf("%d", &in_num);
                    player_history_list[player_num].off_the_field += in_num;
                    break;
                case 5:
                    printf("수정을 종료합니다.\n");
                    break;
                }
            }
            go = loop_end;
        }
        else if (player_num == CNT_PLYAER + 1)
        {
            printf("오류입니다. 선수이름을 다시 입력하세요.\n");
        }
        else if (player_num == CNT_PLYAER + 2)
        {
            printf("조회가 금지된 선수입니다.\n");
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
        printf("기록 조회를 금지할 선수 이름을 입력하세요.");
        scanf("%s", name_in);

        player_num = search_by_name(name_in);

        if (0 <= player_num && player_num < CNT_PLYAER)
        {
            printf("%s의 기록 조회를 금지합니다.",name_in);
            player_history_list[player_num].view_YN = 'N';

            go = loop_end;
        }
        else if (player_num == CNT_PLYAER + 1)
        {
            printf("오류입니다. 선수이름을 다시 입력하세요.\n");
            break;
        }
        else if (player_num == CNT_PLYAER + 2)
        {
            printf("조회가 금지된 선수입니다.\n");
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

void player_history_data_read_txt(void)
{
    int a;

    FILE* fp;

    fp = fopen(FILE_NAME".txt","r");

    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        main();
    }
    /*printf("파일이 열렸스\n");*/
    int i = 0;
    
    for (i = 0; i < 12; i++)
    {
        fscanf(fp, "%s %d %d %d %d %c", &player_history_list[i].id, &player_history_list[i].score,
            &player_history_list[i].assistant, &player_history_list[i].yellow_card, &player_history_list[i].off_the_field,
            &player_history_list[i].view_YN);

  /*      printf("%s %d %d %d %d %c \n", player_history_list[i].id, player_history_list[i].score,
            player_history_list[i].assistant, player_history_list[i].yellow_card, player_history_list[i].off_the_field,
            player_history_list[i].view_YN);*/
    }
    fclose(fp);
}

void player_history_data_write_txt(void)
{
    int a;

    FILE* fp;

    fp = fopen(FILE_NAME".txt", "w");


    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        main();
    }
    /*printf("파일이 열렸스\n");*/
    int i = 0;

    for (i = 0; i < CNT_PLYAER; i++)
    {
        fprintf(fp, "%s %d %d %d %d %c", player_history_list[i].id, player_history_list[i].score,
            player_history_list[i].assistant, player_history_list[i].yellow_card, player_history_list[i].off_the_field,
            player_history_list[i].view_YN);
        fprintf(fp, "\n");
        /*      printf("%s %d %d %d %d %c \n", player_history_list[i].id, player_history_list[i].score,
                  player_history_list[i].assistant, player_history_list[i].yellow_card, player_history_list[i].off_the_field,
                  player_history_list[i].view_YN);*/
    }
    fclose(fp);
}

void player_history_data_read_json(void)
{

}