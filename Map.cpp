using namespace std;
#include "Map.h"
#include <random>
#include <stdlib.h>


Map::Map(int size, int nbr_obs, int nbr_mon) {
	map_size = size;		// là vous avait compris vous êtes pas con on initialise les valeurs	
	nbr_obstacle = nbr_obs;
	nbr_monster = nbr_mon;
	map_case = new Case*[size];					// on crée le tableau
	for (int i = 0; i < size; i++) {
		map_case[i] = new Case[size];
		for (int j = 0; j < size; j++) {
			map_case[i][j].case_type = ".";
			map_case[i][j].x = i + 1;
			map_case[i][j].y = j + 1;
		}
	}
	player_pos = new int[2];		//position joueur x,y 
	player_pos[0] = size / 2 - 1;			// on met le joueur au milieu si possible si case pair on le met à size/2
	player_pos[1] = size / 2 - 1;
	map_case[size / 2-1][size / 2-1].case_type = "X"; // type de case player =pos du joueur


}

void Map::repartition(int nbr_pot_mana, int nbr_pot_heal, int nbr_obstacle, int nbr_monster) {
	std::random_device rd;
	std::default_random_engine gen(rd());
	//std::mt19937 gen(rd()); 
	std::uniform_int_distribution<int> dis(0, map_size - 1);//(rand() %100+1)-(100 - (map_size-1)
	int coord_x = dis(gen);
	int coord_y = dis(gen);
	for (int i = 0; i <= nbr_pot_mana - 1; i++) {		// placement random des potion mana
		while (map_case[coord_x][coord_y].case_type != ".") {
			coord_x = dis(gen);
			coord_y = dis(gen);
		}
		map_case[coord_x][coord_y].case_type = "m";
	}

	for (int i = 0; i <= nbr_pot_heal - 1; i++) {		// placement random des potion de heal
		while (map_case[coord_x][coord_y].case_type != ".") {
			coord_x = dis(gen);
			coord_y = dis(gen);
		}
		map_case[coord_x][coord_y].case_type = "h";
	}

	//string diff_obstacle = { "salut" , "salut" };
	for (int k = 0; k <= nbr_obstacle - 1; k++) {			// placement random obstacle
		while (map_case[coord_x][coord_y].case_type != ".") {
			coord_x = dis(gen);
			coord_y = dis(gen);
		}

		map_case[coord_x][coord_y].case_type = "R";//diff_obstacle[rand() % 1 + 1];
	}

	for (int k = 0; k <= nbr_monster - 1; k++) {			// placement random monstre
		while (map_case[coord_x][coord_y].case_type != ".") {
			coord_x = dis(gen);
			coord_y = dis(gen);
		}

		map_case[coord_x][coord_y].case_type = "0";
	}

}

string Map::move(string direction) {		//déplacement vers le haut
	string ret = "";		// le string à return 
	if (direction == "z") {
		if (player_pos[0] > 0 && map_case[player_pos[0]-1][player_pos[1]].case_type != "A" && map_case[player_pos[0]-1][player_pos[1]].case_type != "R") {	// si la case est dazns tableau et accessible 
			ret = map_case[player_pos[0]-1][player_pos[1]].case_type;				// on prend la valeur de ce qu'il y à dans ka case avant l'arrivé
			map_case[player_pos[0]][player_pos[1]].case_type = "." ;				// Met à jour l'ancienne cazse à vide
			player_pos[0] += -1;  				// mise à jour pos du joueur
			map_case[player_pos[0]][player_pos[1]].case_type = "X";				// met le joueur à la bone pos
									
		}
		else {
			cout << " Déplacement impossible" << endl;
			ret = "impossible";
								// return false si on à pas reussi à bouger afin de ressayer
		}
	}
	if (direction == "s") {				//déplacement vers le bas 
		if (player_pos[0] < map_size - 1 && map_case[player_pos[0]+1][player_pos[1]].case_type != "A" && map_case[player_pos[0]+1][player_pos[1]].case_type != "R") {
			ret = map_case[player_pos[0]+1][player_pos[1]].case_type;				// on prend la valeur de ce qu'il y à dans ka case avant l'arrivé
			map_case[player_pos[0]][player_pos[1]].case_type = ".";				// Met à jour l'ancienne cazse à vide
			player_pos[0] += +1;
			map_case[player_pos[0]][player_pos[1]].case_type = "X";				// met le joueur à la bone pos
		}
		else {
			cout << " Déplacement impossible" << endl;
			ret = "impossible";
		}
	}
	if (direction == "q") {			//déplacement vers le gauche
		if (player_pos[1] > 0 && map_case[player_pos[0]][player_pos[1]-1].case_type != "A" && map_case[player_pos[0]][player_pos[1]-1].case_type != "R") {
			ret = map_case[player_pos[0]][player_pos[1]-1].case_type;				// on prend la valeur de ce qu'il y à dans ka case avant l'arrivé
			map_case[player_pos[0]][player_pos[1]].case_type = ".";				// Met à jour l'ancienne cazse à vide
			player_pos[1] += -1;
			map_case[player_pos[0]][player_pos[1]].case_type = "X";				// met le joueur à la bone pos
		}
		else {
			cout << " Déplacement impossible" << endl;
			ret = "impossible";
		}
	}
	if (direction == "d") {			//déplacement vers la droite 
		if (player_pos[1] < map_size-1 && map_case[player_pos[0]][player_pos[1]+1].case_type != "A" && map_case[player_pos[0]][player_pos[1]+1].case_type != "R") {
			ret = map_case[player_pos[0]][player_pos[1]+1].case_type;				// on prend la valeur de ce qu'il y à dans ka case avant l'arrivé
			map_case[player_pos[0]][player_pos[1]].case_type = ".";				// Met à jour l'ancienne cazse à vide
			player_pos[1] += +1;
			map_case[player_pos[0]][player_pos[1]].case_type = "X";				// met le joueur à la bone pos
		}
		else {
			cout << " Déplacement impossible" << endl;
			ret = "impossible";
		}
	}
	return ret;
}

string Map::get_type() {					// renvoie le type de la case
	return map_case[player_pos[0]][player_pos[1]].case_type;
}


void Map::display() {				// fonction d'affichage de la map
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			cout << map_case[i][j].case_type << " ";
		}
		cout << endl;
	}
}

int main() {
	Map M(10, 2, 2);
	M.repartition(1, 1, 2, 4);						// mana , heal , obstacle , monstre
	M.display();
	string dir;
	while (dir != "fin") {
		cout << "bouger " << endl;
		cin >> dir;
		
		cout << M.move(dir) << endl;
		M.display();
	}
	cin.ignore(100);
	return 0;
}