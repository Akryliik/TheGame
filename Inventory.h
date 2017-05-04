#include <iostream>
#include "Object.h"

using namespace std;

class Inventory{ 
	
	int nbPotL; //nb de potion de vie
	int nbPotM; //nb de potion de mana

	public :
		
		Inventory(config &conf);
		void UseObject(int lPotion , int mPotion, Character c);
		void AddObject();

};
