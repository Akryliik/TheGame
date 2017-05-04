#include <iostream>
#include "Game.h"

Game::Game(inr dim_map , int nbr_obstacle, nbr_monster , character *heros ){
	
	int size = dim_map;
	int nbr_obstacle = nbr_obstacle;
	int nbr_monster = nbr_monster; //initialisation du nb de monstre //VALEUR A METTRE DANS CONGIF 
	int choice;		
		cout << "Bienvenue dans TheGame ."<< endl;
		cout << "quel heros voulez-vous jouer ? "<< endl;
		cout << "1.Guerrier : combattant solide utilisant des attaques dee corps a corps "<< endl;
		cout << "2.Chasseur : expert des arcs , il prefere attaqué a distance "<< endl;	
		cout << "3.voleuse : experte dans l'art de la furtivité , elle prefere les dagues "<< endl;	
		cout << "4.Mage : expert en magie , il utilise le feu et la foudre contre ses ennemies "<< endl;
		cin << choice;				
		Character c ;// définir le personnage		
		c->nbComp = 2;
		c->isHero = True;
		switch(choice){
			case 1:
				c->life = heros[0] -> life;
				c->mana = heros[0] -> mana;
				c->comp[0].name = heros[0] -> comp[0].name;
				c->comp[0].damage = heros[0] -> comp[0].damage;
				c->comp[0].conso_Mana = heros[0] -> comp[0].conso_Mana;
				c->comp[1].name = heros[0] -> comp[1].name;
				c->comp[1].damage = heros[0] -> comp[1].damage;
				c->comp[1].conso_Mana = heros[0] -> comp[1].conso_Mana;
				c->name = heros[0] -> name;
								

			case 2:
				c->life = heros[1] -> life;
				c->mana = heros[1] -> mana;
				c->comp[0].name = heros[1] -> comp[0].name;
				c->comp[0].damage = heros[1] -> comp[0].damage;
				c->comp[0].conso_Mana = heros[1] -> comp[0].conso_Mana;
				c->comp[1].name = heros[1] -> comp[1].name;
				c->comp[1].damage = heros[1] -> comp[1].damage;
				c->comp[1].conso_Mana = heros[1] -> comp[1].conso_Mana;
				c->name = heros[1] -> name;
			
			case 3:
				c->life = heros[2] -> life;
				c->mana = heros[2] -> mana;
				c->comp[0].name = heros[2] -> comp[0].name;
				c->comp[0].damage = heros[2] -> comp[0].damage;
				c->comp[0].conso_Mana = heros[2] -> comp[0].conso_Mana;
				c->comp[1].name = heros[2] -> comp[1].name;
				c->comp[1].damage = heros[2] -> comp[1].damage;
				c->comp[1].conso_Mana = heros[2] -> comp[1].conso_Mana;
				c->name = heros[2] -> name;

			case 4:
				c->life = heros[3] -> life;
				c->mana = heros[3] -> mana;
				c->comp[0].name = heros[3]  -> comp[0].name;
				c->comp[0].damage= heros[3] -> comp[0].daheros[3];
				c->comp[0].conso_Mana = heros[3] -> comp[0].conso_Mana;
				c->comp[1].name = heros[3] -> comp[1].name;
				c->comp[1].damage= heros[3] -> comp[1].daheros[3];
				c->comp[1].conso_Mana = heros[3] -> comp[1].conso_Mana;
				c->name = heros[3] -> name;
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
