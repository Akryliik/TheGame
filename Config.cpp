#include "Config.h"

Config::Config(){
	nbr_monster = 1;					//Nombre de Monstres sur la Carte
	nbr_obstacle = 15;					//Nombre d'obstacle sur la Carte
	dim_map = 20;						//Dimension d'un cote de la carte
	nbr_pot_map = 3;					//Nombre de potion de vie sur la carte
	nbr_pot_perso = 2;					//Nombre de potion de vie dans l'inventaire du personnage
	nbr_mana_map = 3;					//Nombre de potion de mana sur la carte
	nbr_mana_perso = 2;					//Nombre de potion de mana dans l'inventaire du personnage
	pot_mana = 50;						//Points de mana d'une potion de vie
	pot_life = 50;						//Points de vie d'une potion de vie
	heros = new Character*[4];			//Tableau des Heros
	monsters = new Character*[3];		//Tableau des Monstres
	Ability *Abh = new Ability[2];
	Inventory inv(0, 0);

	Abh[0] = Ability(50, 0, "Coup d'épée");
	Abh[1] = Ability(400, 25, "Epee divine");
	heros[0] = new Character(800, 100, Abh, 2, "Guerrier", true, inv);

	Abh[0] = Ability(75, 0, "Tir charge");
	Abh[1] = Ability(400, 25, "Tir perforant");
	heros[1] = new Character(500, 100, Abh, 2, "Chasseur", true, inv);

	Abh[0] = Ability(150, 0, "Assassinat");
	Abh[1] = Ability(300, 15, "Coup Furtif");
	heros[2] = new Character(250, 100, Abh, 2, "Voleuse", true, inv);

	Abh[0] = Ability(120, 0, "Brasier");
	Abh[1] = Ability(300, 15, "Foudre");
	heros[3] = new Character(350, 100, Abh, 2, "Mage", true, inv);

	Ability *Abm = new Ability[1];
	Abm[0] = Ability(20, 2, "Morsure");
	monsters[0] = new Character(70, 100, Abm, 1, "Goule", false, inv);

	Abm[0] = Ability(40, 4, "Griffe de l'ombre");
	monsters[1] = new Character(200, 100, Abm, 1, "Demon", false, inv);

	Abm[0] = Ability(80, 8, "Souffle de Feu");
	monsters[2] = new Character(500, 100, Abm, 1, "Dragon", false, inv);
}

void Config::editConfig() {
	int choice;
	Character *Charac = NULL;
	cout << "Bienvenue dans TheGame." << endl;
	cout << "Quel Heros ou Monstres ou Carcteristique du jeu souhaitez-vous modifier ? " << endl;
	cout << "1." << heros[0]->name << " : combattant solide utilisant des attaques de corps a corps " << endl;
	cout << "2." << heros[1]->name << " : expert des arcs , il prefere attaque a distance " << endl;
	cout << "3." << heros[2]->name << " : experte dans l'art de la furtivite , elle prefere les dagues " << endl;
	cout << "4." << heros[3]->name << " : expert en magie , il utilise le feu et la foudre contre ses ennemies " << endl;
	cout << "5." << monsters[0]->name << " : une cr�ature monstrueuse " << endl;
	cout << "6." << monsters[1]->name << " : un etre surnaturel et doue de raison " << endl;
	cout << "7." << monsters[2]->name << " : une creature legendaire representee comme une sorte de gigantesque reptile " << endl;
	cin >> choice;
	system("CLS");
	switch (choice) {
	case 1:
		heros[0]->display();
		Charac = heros[0];
		break;
	case 2:
		heros[1]->display();
		Charac = heros[1];
		break;
	case 3:
		heros[2]->display();
		Charac = heros[2];
		break;
	case 4:
		heros[3]->display();
		Charac = heros[3];
		break;
	case 5:
		heros[0]->display();
		Charac = monsters[0];
		break;
	case 6:
		heros[1]->display();
		Charac = monsters[1];
		break;
	case 7:
		heros[2]->display();
		Charac = monsters[2];
		break;
	}
	cout << "Quel caracteristique souhaitez-vous ? " << endl;
	cout << "1. Les Points de Vie" << endl;
	cout << "2. Les Points de Mana" << endl;
	cout << "3. Une Comp�tence" << endl;
	cout << "4. Le Nom" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Nouvelle Valeur = " << endl;
		cin >> Charac->life;
		break;
	case 2:
		cout << "Nouvelle Valeur = " << endl;
		cin >> Charac->mana;
		break;
	case 3:
		system("CLS");
		Charac->comp[0].display();
		if(Charac->nbComp == 2) {
			Charac->comp[1].display();
			cout << "Quel caracteristique d'une comp�tence souhaitez-vous ? " << endl;
			cout << "1. Nom de la competence 1" << endl;
			cout << "2. Degat de la competence 1" << endl;
			cout << "3. Consomation de mana de la Comp�tence 1" << endl;
			cout << "4. Nom de la competence 2" << endl;
			cout << "5. Degat de la competence 2" << endl;
			cout << "6. Consomation de mana de la Comp�tence 2" << endl;
			cin >> choice;
			cout << "Nouvelle Valeur = " << endl;
			switch (choice) {
			case 1:
				cin >> Charac->comp[0].name;
				break;
			case 2:
				cin >> Charac->comp[0].dmg;
				break;
			case 3:
				cin >> Charac->comp[0].conso_Mana;
				break;
			case 4:
				cin >> Charac->comp[1].name;
				break;
			case 5:
				cin >> Charac->comp[1].dmg;
				break;
			case 6:
				cin >> Charac->comp[1].conso_Mana;
				break;
			}
		}
		else {
			cout << "Quel caracteristique de comp�tence souhaitez-vous ? " << endl;
			cout << "1. Nom de la competence" << endl;
			cout << "2. Degat de la competence" << endl;
			cout << "3. Consomation de mana de la Comp�tence" << endl;
			cin >> choice;
			cout << "Nouvelle Valeur = " << endl;
			switch (choice) {
			case 1:
				cin >> Charac->comp[0].name;
				break;
			case 2:
				cin >> Charac->comp[0].dmg;
				break;
			case 3:
				cin >> Charac->comp[0].conso_Mana;
				break;
			}
		}
		break;
	case 4:
		cout << "Nouvelle Valeur = " << endl;
		cin >> Charac->name;
		break;
	}

}
