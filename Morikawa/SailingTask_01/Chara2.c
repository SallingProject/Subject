#include <stdio.h>

struct status
{
	float life;    // HP
	float attack;  // ATK
	float defense; // DEF
};

void input(struct status *player);

void main()
{
	struct status player;

	input(&player);

	printf("HP :%f\n", player.life);
	printf("ATK:%f\n", player.attack);
	printf("DEF:%f\n", player.defense);
		
	return;
}

void input(struct status *player)
{
	player->life = 40;
	player->attack = 30;
	player->defense = 20;

	return;
	/* ポインタ理解用
	printf("HP :%f\n", player->life);
	printf("ATK:%f\n", player->attack);
	printf("DEF:%f\n", player->defense);
	*/
};