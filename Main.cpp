#include "Character.h"

#pragma region variables
int nbr_monster = 9;						//Nombre de Monstres sur la Carte
int nbr_obstacle = 15;						//Nombre d'obstacle sur la Carte
int dim_map = 20;							//Dimension d'un cote de la carte
int nbr_pot_map = 3;						//Nombre de potion de vie sur la carte
int nbr_pot_perso = 2;						//Nombre de potion de vie dans l'inventaire du personnage
int nbr_mana_map = 3;						//Nombre de potion de mana sur la carte
int nbr_mana_perso = 2;						//Nombre de potion de mana dans l'inventaire du personnage
int pot_mana = 50;							//Points de mana d'une potion de vie
int pot_life = 50;							//Points de vie d'une potion de vie
Character *heros = new Character[4];		//Tableau des Heros
Character *monsters = new Character[3];		//Tableau des Monstres
//Object* Object = NULL;
#pragma endregion variables

int main(){
	Ability *Abh = new Ability[2];
	Abh[0] = Ability(50, 6, "Coup d epee");
	Abh[1] = Ability(400, 25, "Epee divine");
	heros[0] = Character(800, 100, Abh, 2, "Guerrier", true);

	Abh[0] = Ability(75, 9, "Tir charge");
	Abh[1] = Ability(400, 25, "Tir perforant");
	heros[1] = Character(500, 100, Abh, 2, "Chasseur", true);

	Abh[0] = Ability(150, 15, "Assassinat");
	Abh[1] = Ability(300, 15, "Coup Furtif");
	heros[2] = Character(250, 100, Abh, 2, "Voleuse", true);

	Abh[0] = Ability(120, 12, "Brasier");
	Abh[1] = Ability(300, 15, "Foudre");
	heros[3] = Character(350, 100, Abh, 2, "Mage", true);

	Ability *Abm = new Ability[1];
	Abm[0] = Ability(20, 2, "Morsure");
	monsters[0] = Character(70, 100, Abm, 1, "Goule", false);

	Abm[0] = Ability(40, 4, "Griffe de l'ombre");
	monsters[1] = Character(200, 100, Abm, 1, "Demon", false);

	Abm[0] = Ability(80, 8, "Souffle de Feu");
	monsters[2] = Character(500, 100, Abm, 1, "Dragon", false);

	cout << nbr_monster << endl;
	//monsters[2].display();
	//cout << monsters[1].display() << endl;
	Character M = heros[0];
	M.display();

	cin.ignore(100);
	return 0;
}