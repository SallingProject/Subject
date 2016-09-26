#include <stdio.h>

struct status
{
	float life;    // HP
	float attack;  // Attack
	float defense; // Dedence
};

struct status input();

void main()
{
	struct status player;

	player = input();
	
	printf("HP :%f\n", player.life);
	printf("ATK:%f\n", player.attack);
	printf("DEF:%f\n", player.defense);
	
	return;
}

struct status input()
{
	struct status player;

	player.life = 40;
	player.attack = 30;
	player.defense = 20;

	return player;
}