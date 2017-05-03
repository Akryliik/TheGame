using namespace std;
#include "Map.h"
#include <random>
#include <stdlib.h>


Map::Map(int size , int nbr_obs, int nbr_mon){
	map_size = size;		// là vous avait compris vous êtes pas con on initialise les valeurs	
	nbr_obstacle = nbr_obs;
	nbr_monster = nbr_mon;
    map_case = new Case*[size];					// on crée le tableau
	for ( int i = 0 ; i < size ; i++){
		map_case[i] = new Case[size];
		for (int j =0 ; j < size ; j++){
			map_case[i][j].case_type = "";
			map_case[i][j].x = i+1;				
			map_case[i][j].y = j+1;
		}
	}
	player_pos = new int[2];		//position joueur x,y 
	player_pos[0] = size/2-1;			// on met le joueur au milieu si possible si case pair on le met à size/2
	player_pos[1] = size/2-1;
	map_case[size/2][size/2].case_type = "X"; // type de case player =pos du joueur
	
		
}

void Map::repartition (int nbr_pot_mana , int nbr_pot_heal , int nbr_obstacle,int nbr_monster){
	std::random_device rd;  
	std::default_random_engine gen(rd());
	//std::mt19937 gen(rd()); 
	std::uniform_int_distribution<int> dis(0, map_size-1);//(rand() %100+1)-(100 - (map_size-1)
	int coord_x = dis(gen);
	int coord_y = dis(gen);
	for (int i = 0 ; i <= nbr_pot_mana-1 ; i++){		// placement random des potion mana
		while (map_case[coord_x][coord_y].case_type != "" ){
			coord_x = dis(gen);
			coord_y = dis(gen);
		}
		map_case[coord_x][coord_y].case_type = "m" ;
	}

	for (int i = 0 ; i <= nbr_pot_heal-1 ; i++){		// placement random des potion de heal
		while (map_case[coord_x][coord_y].case_type != "" ){
			coord_x = dis(gen);
			coord_y = dis(gen);
		}
		map_case[coord_x][coord_y].case_type = "h" ;
	}

	string diff_obstacle = {'A' , 'R' };
	for (int k = 0 ; k <= nbr_obstacle-1 ; k++){			// placement random obstacle
		while (map_case[coord_x][coord_y].case_type != ""  ){
			coord_x = dis(gen);
			coord_y = dis(gen);
		}
		
		map_case[coord_x][coord_y].case_type = diff_obstacle[rand()%1+1] ;
	}

	for (int k = 0 ; k <= nbr_monster-1 ; k++){			// placement random monstre
		while (map_case[coord_x][coord_y].case_type != "" ){
			coord_x = dis(gen);
			coord_y = dis(gen);
		}
		
		map_case[coord_x][coord_y].case_type = "0";
	}

}

bool Map::move(string direction){		//déplacement vers le haut
	if( direction ==  "z" ){
		if(player_pos[0] > 0 || map_case[player_pos[0]][player_pos[1]].case_type != "Arbre" ||  map_case[player_pos[0]][player_pos[1]].case_type != "Rocher" ){	// si la case est dazns tableau et accessible 
			player_pos[0] += -1;  				// mise à jour pos du joueur
			return true;						// return true si on à réussi à bouger
		}
		else{
			cout << " Déplacement impossible"<< endl;
			return false;						// return false si on à pas reussi à bouger afin de ressayer
		}
	}
	if(direction == "s"){				//déplacement vers le bas 
		if(player_pos[0] < map_size-1 || map_case[player_pos[0]][player_pos[1]].case_type != "Arbre" ||  map_case[player_pos[0]][player_pos[1]].case_type != "Rocher" ){
			player_pos[0] += +1; 
			return true; 
		}
		else{
			cout << " Déplacement impossible"<< endl;
			return false;
		}
	}
	if(direction == "q"){			//déplacement vers le gauche
		if(player_pos[1] > 0 || map_case[player_pos[0]][player_pos[1]].case_type != "Arbre" ||  map_case[player_pos[0]][player_pos[1]].case_type != "Rocher" ){
			player_pos[1] += -1;  
			return true;
		}
		else{
			cout << " Déplacement impossible"<< endl;
			return false;
		}
	}
	if(direction == "d"){			//déplacement vers la droite 
		if(player_pos[1] < map_size-1 || map_case[player_pos[0]][player_pos[1]].case_type != "Arbre" ||  map_case[player_pos[0]][player_pos[1]].case_type != "Rocher" ){
			player_pos[1] += +1;  
			return true;
		}
		else{
			cout << " Déplacement impossible"<< endl;
			return false;
		}
	}
}

string Map::get_type(){					// renvoie le type de la case
	return map_case[player_pos[0]][player_pos[1]].case_type;
}


void Map::display(){				// fonction d'affichage de la map
	for (int i = 0 ; i < map_size ; i++){
		for (int j = 0 ; j < map_size ; j++){
				cout <<map_case[i][j].case_type<< " ";
		}
		cout<<endl;
	}
}

int main() {
	Map M(10,2,2);
	M.repartition (1,1, 2,4);						// mana , heal , obstacle , monstre
	M.display();
}
