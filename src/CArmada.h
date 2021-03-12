#ifndef BATTLESHIP_CARMADA_H
#define BATTLESHIP_CARMADA_H

#include "BiblioStd.h"
#include "CBateau.h"

class CArmada {

private:
    /**
     * The collection of boats which is empty at the beginning.
     * La collection de bateaux qui est vide au départ.
     */
    vector<CBateau> m_listeBateaux;

public:
    /**
     * Add a boat in the structure of m_listeBateaux (to the continuation with the method push_back of the vector'
     * class)
     * Ajoute un bateau dans la structure m_listeBateaux (à la suite avec la méthode  push_back de la classe vector)
     * @param unBat The boat to add / Le bateau à ajouter.
     */
    void ajouterBateau(CBateau& unBat);

    /**
     * Getter: return (by pointer) the boat who is at the index i in the array (0 <= i < taille)
     * Accesseur: renvoie (par pointeur) le bateau qui se trouve à l'index i dans le tableau (0 <= i < taille)
     * @param i The index which we want to have the boat / L'index qui correspond au bateau que l'on veut.
     * @return The pointer of the boat / Le pointeur du bateau.
     */
    CBateau* getBateau(int i);

    /**
     * Return the total number of boats of the armada
     * Retourne le nombre total de bateaux de l'armada
     * @return The total number of boats of the armada / Le nombre total de bateaux de l'armada
     */
    int getEffectifTotal();

    /**
     * Getter : Return the total number of occupied boxes by the armada.
     * Accesseur : Retourne le nombre total de cases occupées par l'Armada.
     * @return the total number of occupied boxes by the armada / Le nombre total de cases occupées par l'Armada
     */
    int getNbreTotCases();

    /**
     * Return the number of boats which are not sunk yet (so boats which are still alive)
     * Retourne le nombre de bateaux qui ne sont pas encore coulés (flottille encore en vie sur l'eau).
     * @return The number of boats which are still alive / Le nombre de bateau qui sont encore en vie sur l'eau.
     */
    int getEffectif();

    /**
     * Read the file flotille.txt which contains the complete list of every boats.
     * Lecture du fichier flotille.txt qui contient la liste complete de tous les bateaux.
     */
    void getArmadaFromFile();

    /**
     * Placing randomly and automatically horizontally of each boats on the grid. Return false if the automatically
     * positioning failed.
     * Placement aléatoire et automatique horizontalement de tous les bateaux sur la grille. Renvoie faux si le
     * positionnement automatique a échoué.
     * @return False if the automatically positioning failed / Faux si le positionnement automatique a échoué.
     */
    bool placerAleatoirement();
};


#endif //BATTLESHIP_CARMADA_H
