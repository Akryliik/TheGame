#include<iostream>
#include<cstring>
#include "Case.h"


class Map {
	int * player_pos; 			// position du joueur [x,y]
	int map_size;				// taille map
	int nbr_obstacle;			// nbr obstacle
	int nbr_monster;			// nbr monstre
	Case ** map_case;			// le tableau de case

friend class Case;
public:
	Map(int size , int nbr_obs, int nbr_mon);
	void display();
	void repartition (int nbr_pot_mana , int nbr_pot_heal ,int nbr_obstacle, int nbr_monstre);
	bool move(string direction);
	string get_type();
};
