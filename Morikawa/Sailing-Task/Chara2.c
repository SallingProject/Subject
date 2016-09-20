#include <stdio.h>

struct status
{
	float life;    // HP
	float attack;  // Attack
	float defense; // Defence
};

struct status players();

void main()
{
	struct status player;

	player = players();

	printf("HP :%f\n", player.life);
	printf("ATK:%f\n", player.attack);
	printf("DEF:%f\n", player.defense);

	return;
}

struct status players()
{
	struct status player = { 40, 30, 30 };

	return player;
};