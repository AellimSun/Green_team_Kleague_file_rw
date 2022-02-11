#pragma once
#define player_number 20

typedef struct
{
	char player_id[10];
	char player_name[10];
	int player_height;
	int player_weight;
	int player_back_num;
	char player_position[3];
	char useYN;
} player;

typedef struct
{
	char id[10];
	int score;
	int assistant;
	int yellow_card;
	int off_the_field;
	char view_YN;

	struct player_his *next;

}player_his;

typedef struct 
{
	int team_id;	//id
	char area[20];		//연고지
	char stadium[50];	//홈구장
	int since;		//창단연도
	char coach[20];		//감독이름
	int v;			//우승횟수
	char team_name[50];	//팀명
	char use_YN;
	struct teamProfile *next;
}teamProfile;

typedef struct
{
	int team_hist_year;
	int team_hist_month;
	int team_hist_date;
	char team_hist_home[50];
	char team_hist_away[50];
	int team_hist_homegoal;
	int team_hist_awaygoal;
	char team_hist_datadelete;

	struct team_hist* next;
} team_hist;

typedef struct
{
	char team_name_match[50];
	int team_win;
	int team_draw;
	int total_points;

} team_match;


extern player player_list[player_number];
extern player_his player_history_list[player_number];
extern teamProfile team_list[10];
extern team_hist team_hist_list[100];
extern team_match team_match_list[10];
 