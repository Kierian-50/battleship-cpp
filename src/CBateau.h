#ifndef BATTLESHIP_CBATEAU_H
#define BATTLESHIP_CBATEAU_H

#include "BiblioStd.h"

class CBateau {

private:
    /**
     * Number of occupied spaces (horizontally) on the grid
     * Nombre de cases occupées (horizontalement) sur la grille
     */
    int m_taille;

    /**
     * The name of the boat
     * Nom du bateau
     */
     string m_nom;

     /**
      * Coordonnées (int ligneHoriz, int colonneVert) du point d'ancrage
      * m_position.first = le numéro de la ligne horizontale
      * m_position.second = le numéro de la colonne verticale
      */
      pair<int, int> m_position;

      /**
       * Array of size damage m_taille (bose at false if no damage)
       * Tableau des dégâts de taille m_taille (case à faux si pas de dégat)
       */
       bool* m_pDegats;

public:
    /**
     * Default Constructor : "néant", (0,0),0, NULL
     * Constructeur par défaut : "néant", (0,0),0, NULL
     */
    CBateau();

    /**
     * Constructor of the class ; the boat has not damage/touched boxes (m_pDegats false on each elements)
     * Constructeur de la classe; le bateau n'a pas encore de case touchée (m_pDegats à faux partout)
     * @param n The name of the boat / Le nom du bateau
     * @param p The position at the anchor point / La position du bateau au point d'ancrage
     * @param t The length of the boat / La taille du bateau.
     */
    CBateau(string n, pair<int, int> p, int t);

    /**
     * Renvoie vrai si la case numéro i du bateau est touchée (0<=i<m_taille)
     * Return true if the boxe number i of the boat is touched/damaged (0<=i<m_taille)
     * @param i The number of the boxe / Le numéro de la case
     * @return True : if the boat is touched at this point / False : if it's not the case
     *         Vrai : si le bateau est touché à cet endroit / Faux : Si ce n'est pas le cas
     */
    bool getDegats(int i);

    /**
     * Return the name of the boat
     * Retourne le nom du bateau
     * @return the name of the boat / Le nom du bateaeu
     */
    string getNom();

    /**
     * Return the length of the boat
     * Retourne la taille du bateau
     * @return the length of the boat / La taille du bateau
     */
    int getTaille();

    /**
     * Return the position of the anchor point
     * Retourne la position au point d'ancrage du bateau.
     * @return The position of the anchor point / La position au point d'ancrage du bateau.
     */
    pair<int, int> getPositions();

    /**
     * Change the position of the boat on the grid with the i line and the j column (new anchor point)
     * Modifier la position du bateau sur la grille en ième ligne, jème colonne (nouveau point d'ancrage)
     * @param i The new position on the line / La nouvelle position sur la ligne
     * @param j The new position on the column / La nouvelle position sur la colonne
     */
    void setPosition(int i, int j);

    /**
     * Return true if the boat is sunk.
     * Retourne vrai si le bateau est coulé
     * @return True if the boat is sunk / False : if it's not the case.
     *         Vrai si le bateau est coulé / Faux si ce n'est pas le cas
     */
    bool estCoule();

    /**
     * Return true if the position past in parameter is a victory shoot (a boxe is touched). If the shoot is victorious
     * it must mark it in the m_pDegats array.
     * But if the boxe is already shot, the method don't return true.
     * Retourne vrai si la position passée en parametre est un tir vitorieux (une case est touchée). Si le tir est
     * victorieux, il doit être marqué dans le tableay m_pDegats.
     * Mais si la case est deja touché, la méthode ne retourne pas vrai.
     * @param p The position of the adverse shot / La position du tir adverse.
     * @return True If the boat is touched and not already touched at this position / False : if it's not the case
     *         False Si le bateau est touché et pas déjà touché a cette position / Faux : Si ce n'est pas le cas
     */
    bool tirAdverse(pair<int, int> p);

    /**
     * Overload of the << operator to display the characteristics of the boat on the screen
     * Surcharge de l'opérateur << pour afficher à l'écran les caractéristiqes du bateau
     * @param os Ostream
     * @param theB The boat that we want to display the characteristics
     * @return Ostream
     */
    friend ostream& operator<< (ostream& os, CBateau& theB);

    /**
     * Copy constructor that allows to copy the content of a CBateau object in another object
     * Copie constructeur qui permet de copier le contenu d'un objet CBateau dans un autre
     * @param toCopy The CBateau object to copy | L'objet CBateau a copié
     */
    CBateau(const CBateau& toCopy);

    /**
     * Destructor | Destructeur
     */
    ~CBateau();
};


#endif //BATTLESHIP_CBATEAU_H
