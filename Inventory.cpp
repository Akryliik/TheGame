#include <iostream>
#include "Inventory.h"
using namespace std;

Inventory::Inventory(){

	nbPotL = nbr_pot_perso; //nb de potion de vie dans l'inventaire / VALEUR A METTRE DANS CONFIG
	nbPotM = nbr_mana_perso; //nb de potion de mana dans l'inventaire / VALEUR A METTRE DANS CONFIG
}


void Inventory::UseObject(int lPotion , int mPotion, Character c){
		
	int choice;
	cout << "Veuillez choisir un objet à utiliser (1 : vie ; 2 : mana ; 3 : exit) : " << endl ;
	cin >> choice;
	
	if (choice == 1){
		if(nbPotL > 0){	//si il reste des potions
			c.life += lPotion; //vie rendu
			cout << "point de vie : " << heroe.life << endl; //point de vie restant
			cout << "point de mana : " << heroe.mana << endl; //point de mana restant
			nbPotL -= 1; //retrait de une potion
			cout << "potion de vie restantes : " << nbPotL << endl; //nb de potion qu'il reste 
		}
		
		else{	
			cout << "Vous n'avez plus de potion de vie." << endl ;
		}			
	}

	if (choice == 2){
		if(nbPotM > 0){	//si il reste des potions	
			c.mana += mPotion; //mana rendu
			cout << "point de vie : " << heroe.life << endl; //point de vie restant		
			cout << "point de mana : " << heroe.mana << endl; //point de mana restant
			nbPotM -= 1; //retrait de une potion 
			cout << "potion de mana restantes : " << nbPotM << endl; // nb de potion qui reste 
		}
		
		else{
			cout << "Vous n'avez plus de potion de mana." << endl ;
		}	
	}

	if (choice == 3){
		return; //on sort de l'Inventaire
	}
}

void Inventory::AddObject(){
	string pot; //nom de l'objet trouver (à changer)
	
	if (pot == "heal"){ //si objet "name" est une potion de vie 
		nbPotL +=1 ; //ajout de 1 potion dans l'inventaire
	}

	if (pot == "mana"){ //si objet "name" est une potion de mana
		nbPotM +=1; //ajout de 1 potion dans l'inventaire
	}
}

