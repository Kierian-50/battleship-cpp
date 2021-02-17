//
// Created by kierian on 17/02/2021.
//

#include <iterator>
#include "CArmada.h"

/**
 * Add a boat in the structure of m_listeBateaux (to the continuation with the method push_back of the vector'
 * class)
 * Ajoute un bateau dans la structure m_listeBateaux (à la suite avec la méthode  push_back de la classe vector)
 * @param unBat The boat to add / Le bateau à ajouter.
 */
void CArmada::ajouterBateau(CBateau &unBat) {
    this->m_listeBateaux.push_back(unBat);
}

/**
 * Getter: return (by pointer) the boat who is at the index i in the array (0 <= i < taille)
 * Accesseur: renvoie (par pointeur) le bateau qui se trouve à l'index i dans le tableau (0 <= i < taille)
 * @param i The index which we want to have the boat / L'index qui correspond au bateau que l'on veut.
 * @return The pointer of the boat / Le pointeur du bateau.
 */
CBateau *CArmada::getBateau(int i) {
    return &this->m_listeBateaux[i];
}

/**
 * Return the total number of boats of the armada
 * Retourne le nombre total de bateaux de l'armada
 * @return The total number of boats of the armada / Le nombre total de bateaux de l'armada
 */
int CArmada::getEffectifTotal() {
    return (int)this->m_listeBateaux.size();
}

/**
 * Getter : Return the total number of occupied boxes by the armada.
 * Accesseur : Retourne le nombre total de cases occupées par l'Armada.
 * @return the total number of occupied boxes by the armada / Le nombre total de cases occupées par l'Armada
 */
int CArmada::getNbreTotCases() {
    int res = 0;
    for(int i = 0; i <= (int)this->m_listeBateaux.size(); i++){
        res += this->getBateau(i)->getTaille();
    }
    return res;
}

/**
 * Return the number of boats which are not sunk yet (so boats which are still alive)
 * Retourne le nombre de bateaux qui ne sont pas encore coulés (flottille encore en vie sur l'eau).
 * @return The number of boats which are still alive / Le nombre de bateau qui sont encore en vie sur l'eau.
 */
int CArmada::getEffectif() {
    int res = 0;
    for(int i = 0; i <= (int)this->m_listeBateaux.size(); i++){
        if(!this->getBateau(i)->estCoule()){
            res++;
        }
    }
    return res;
}

/**
 * Read the file flotille.txt which contains the complete list of every boats.
 * Lecture du fichier flotille.txt qui contient la liste complete de tous les bateaux.
 * Nom / Position en y / Taille
 */
void CArmada::getArmadaFromFile() {
    // TODO flexible path
    string filename = "/home/kierian/CLionProjects/battleship/flotille.txt";

    string maCh;
    ifstream input;
    input.open ( filename.c_str(), ios::in );

    while ( !input.eof() ) {
        getline ( input, maCh, '\n' );
        cout << "[I] " << maCh << endl;
        if(maCh.at(0) != '#'){
            // Split function
            istringstream buf(maCh);
            istream_iterator<std::string> beg(buf), end;
            std::vector<std::string> tokens(beg, end);

            string nom = tokens[0];
            string nbBateau = tokens[1];
            string taille = tokens[2];

            int nbBateauInt = stoi(nbBateau);
            int tailleInt = stoi(taille);

            if(nbBateauInt >= 1){
                for(int i = 0; i<= nbBateauInt-1; i++){
                    pair<int, int> pos;
                    pos.first = 0;
                    pos.second = 0;
                    CBateau bateau(nom, pos, tailleInt);
                    this->ajouterBateau(bateau);
                }
            }
        }
    }
    input.close();
}

/**
 * Placing randomly and automatically horizontally of each boats on the grid. Return false if the automatically
 * positioning failed.
 * Placement aléatoire et automatique horizontalement de tous les bateaux sur la grille. Renvoie faux si le
 * positionnement automatique a échoué.
 * @return False if the automatically positioning failed / Faux si le positionnement automatique a échoué.
 */
bool CArmada::placerAleatoirement() {
    int borneSup = 10;

    // If the number of boxes are inferior of the required number for every boats.
    // Si le nombre de cases est inférieur au nombre requis pour tous les bateaux.
    if(this->getNbreTotCases() > borneSup*borneSup){
        return false;
    }

    for(int i = 0; i <= (int) this->m_listeBateaux.size(); i++){
        int k = rand()%(borneSup + 1);
        cout << "k = " << k;
    }

    return false;
}

