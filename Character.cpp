#include "Character.h"

Character::Character() { // Constructeur de la classe "Character" par défaut.
    life = 0;
    mana = 0;
    nbComp = 0;
    comp = new Ability[nbComp]; // Allocation d'un tableau à une dimension.
    name = "";
    isHero = true;
}

Character::Character(int llife, int mmana, Ability *ccomp, int nnbComp, string nname, bool iisHero) { // Constructeur de la classe "Character".
    life = llife; // Initialise les PV avec la valeur fournie en argument.
    mana = mmana; // Initialise les PM avec la valeur fournie en argument.
    nbComp = nnbComp; // Initialise le nombre de compétences avec la valeur fournie en argument.
    comp = new Ability[nbComp]; // Allocation d'un tableau à une dimension.
    for(int i = 0; i < nbComp; i++) {
        comp[i] = ccomp[i]; // Rempli le tableau de compétence.
    }
    name = nname; // Initialise le nom du personnage avec la chaîne fournie en argument.
    isHero = iisHero;
}

Character::~Character() { // Destructeur de la classe "Character".
    delete []comp;
}

void Character::display() {
    cout << "- Nom : " << name << endl;
    cout << "- PV : " << life << endl;
    cout << "- PM : " << mana << endl;
    cout << "- Nombre compétences : " << nbComp << endl;
    cout << "- Compétences : " << endl;
    for(int i = 0; i < nbComp; i++) {
        cout << i+1 << ") ";
        comp[i].display();
    }
    if(isHero) {
        cout << name << " est un héros." << endl;
    }
    else if(!isHero) {
        cout << name << " est un monstre." << endl;
    }
}
