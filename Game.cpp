#include <iostream>
#include "Game.h"

Game::Game(Config c){
	
	int size = c->dim_map;
	int nbr_obstacle = c->nbr_obstacle;
	int nbr_monster = c->nbr_monster; //initialisation du nb de monstre //VALEUR A METTRE DANS CONGIF 
	int choice;		
		cout << "Bienvenue dans TheGame ."<< endl;
		cout << "quel heros voulez-vous jouer ? "<< endl;
		cout << "1.guerrier : combattant solide utilisant des attaques dee corps a corps "<< endl;
		cout << "2.archer : expert des arcs , il prefere attaqué a distance "<< endl;	
		cout << "3.voleuse : experte dans l'art de la furtivité , elle prefere les dagues "<< endl;	
		cout << "4.Mage : expert en magie , il utilise le feu et la foudre contre ses ennemies "<< endl;
		cin << choice;				
		Character c ;// définir le personnage		
		c-> nbComp = 2;
		c->isHero = True;
		switch(choice){
			case 1:
				c->life = Guerrier -> life;
				c->mana = Guerrier -> mana;
				c->comp[0].name = Guerrier -> comp[0].name;
				c->comp[0].damage = Guerrier -> comp[0].damage;
				c->comp[0].conso_Mana = Guerrier -> comp[0].conso_Mana;
				c->comp[1].name = Guerrier -> comp[1].name;
				c->comp[1].damage = Guerrier -> comp[1].damage;
				c->comp[1].conso_Mana = Guerrier -> comp[1].conso_Mana;
				c->name = Guerrier -> name;
								

			case 2:
				c->life = Chasseur -> life;
				c->mana = Chasseur -> mana;
				c->comp[0].name = Chasseur -> comp[0].name;
				c->comp[0].damage = Chasseur -> comp[0].damage;
				c->comp[0].conso_Mana = Chasseur -> comp[0].conso_Mana;
				c->comp[1].name = Chasseur -> comp[1].name;
				c->comp[1].damage = Chasseur -> comp[1].damage;
				c->comp[1].conso_Mana = Chasseur -> comp[1].conso_Mana;
				c->name = Chasseur -> name;
			
			case 3:
				c->life = Voleuse -> life;
				c->mana = Voleuse -> mana;
				c->comp[0].name = Voleuse -> comp[0].name;
				c->comp[0].damage = Voleuse -> comp[0].damage;
				c->comp[0].conso_Mana = Voleuse -> comp[0].conso_Mana;
				c->comp[1].name = Voleuse -> comp[1].name;
				c->comp[1].damage = Voleuse -> comp[1].damage;
				c->comp[1].conso_Mana = Voleuse -> comp[1].conso_Mana;
				c->name = Voleuse -> name;

			case 4:
				c->life = Mage -> life;
				c->mana = Mage -> mana;
				c->comp[0].name = Mage  -> comp[0].name;
				c->comp[0].damage = Mage -> comp[0].damage;
				c->comp[0].conso_Mana = Mage -> comp[0].conso_Mana;
				c->comp[1].name = Mage -> comp[1].name;
				c->comp[1].damage = Mage -> comp[1].damage;
				c->comp[1].conso_Mana = Mage -> comp[1].conso_Mana;
				c->name = Mage -> name;
		}		
	
		Map map = new Map( size , nbr_obstacle , nbr_monster); //création de la map
	
	while (nb_monster > 0 || c.life > 0){
		map.display(); //affichage map
		cout << "Où voulez vous allez ? " << endl;
		// display la map après un déplcement
		cin >> direction;		
		map.move(direction);
		string t = m.get_type();
			
		/*
		if (t == "monster"){
			Fight(; //A finir
			f.on();	
		}
		if (t == "heal" || t =="mana"){
			//A finir 
		}
		*/	

	}
}
