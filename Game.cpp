#include <iostream>
#include "Game.h"

Game::Game(Config &conf){

	int choice;		
		cout << "Bienvenue dans TheGame ."<< endl;
		cout << "quel heros voulez-vous jouer ? "<< endl;
		cout << "1.Guerrier : combattant solide utilisant des attaques dee corps a corps "<< endl;
		cout << "2.Chasseur : expert des arcs , il prefere attaqué a distance "<< endl;	
		cout << "3.voleuse : experte dans l'art de la furtivité , elle prefere les dagues "<< endl;	
		cout << "4.Mage : expert en magie , il utilise le feu et la foudre contre ses ennemies "<< endl;
		cin >> choice;				
		Character *c ;// définir le personnage	
			
		c->nbComp = 2;
		c->isHero = true;
		switch(choice){
			case 1:
				c->life = conf.heros[0] -> life;
				c->mana = conf.heros[0] -> mana;
				c->comp[0].name = conf.heros[0] -> comp[0].name;
				c->comp[0].damage = conf.heros[0] -> comp[0].damage;
				c->comp[0].conso_Mana = conf.heros[0] -> comp[0].conso_Mana;
				c->comp[1].name = conf.heros[0] -> comp[1].name;
				c->comp[1].damage = conf.heros[0] -> comp[1].damage;
				c->comp[1].conso_Mana = conf.heros[0] -> comp[1].conso_Mana;
				c->name = conf.heros[0] -> name;
				break;

			case 2:
				c->life = conf.heros[1] -> life;
				c->mana = conf.heros[1] -> mana;
				c->comp[0].name = conf.heros[1] -> comp[0].name;
				c->comp[0].damage = conf.heros[1] -> comp[0].damage;
				c->comp[0].conso_Mana = conf.heros[1] -> comp[0].conso_Mana;
				c->comp[1].name = conf.heros[1] -> comp[1].name;
				c->comp[1].damage = conf.heros[1] -> comp[1].damage;
				c->comp[1].conso_Mana = conf.heros[1] -> comp[1].conso_Mana;
				c->name = conf.heros[1] -> name;
				break;
			case 3:
				c->life = conf.heros[2] -> life;
				c->mana = conf.heros[2] -> mana;
				c->comp[0].name = conf.heros[2] -> comp[0].name;
				c->comp[0].damage = conf.heros[2] -> comp[0].damage;
				c->comp[0].conso_Mana = conf.heros[2] -> comp[0].conso_Mana;
				c->comp[1].name = conf.heros[2] -> comp[1].name;
				c->comp[1].damage = conf.heros[2] -> comp[1].damage;
				c->comp[1].conso_Mana = conf.heros[2] -> comp[1].conso_Mana;
				c->name = conf.heros[2] -> name;
				break;
			case 4:
				c->life = conf.heros[3] -> life;
				c->mana = conf.heros[3] -> mana;
				c->comp[0].name = conf.heros[3]  -> comp[0].name;
				c->comp[0].damage= conf.heros[3] -> comp[0].damage[3];
				c->comp[0].conso_Mana = conf.heros[3] -> comp[0].conso_Mana;
				c->comp[1].name = conf.heros[3] -> comp[1].name;
				c->comp[1].damage= conf.heros[3] -> comp[1].damage[3];
				c->comp[1].conso_Mana = conf.heros[3] -> comp[1].conso_Mana;
				c->name = conf.heros[3] -> name;
				break;		
		}		
	
		Map map = new Map( size , nbr_obstacle , nbr_monster); //création de la map
	
	while (nbr_monster > 0 || conf.life > 0){
		map.display(); //affichage map
		cout << "Où voulez vous allez ? " << endl;
		// display la map après un déplcement
		cin >> direction;		
		string t = m.move(direction);
			
		while (t == "R"){
			cout << "Où voulez vous allez ? " << endl;
			// display la map après un déplcement
			cin >> direction;		
			string t = m.move(direction);
		}			
		if (t == "0"){
			int r = rand() % 3//rand le montre  faire			
			Fight f = new Fight(&c , conf.monster[r] );			
			f.on();
			if (conf.life > 0){
				nbr_monster -=1 ;			
			}
		}
		if (t == "h" || t =="m"){
			conf.inv.AddObject(string pot);
		}

	}
}

