//
// Created by kierian on 10/02/2021.
//

#include "CBateau.h"

/**
 * Default Constructor : "néant", (0,0),0, NULL
 * Constructeur par défaut : "néant", (0,0),0, NULL
 */
CBateau::CBateau() {
    this->m_nom = "néant";
    this->m_taille = 0;
    this->m_position.first = 0;
    this->m_position.second = 0;
    this->m_pDegats = NULL;
}

/**
 * Constructor of the class ; the boat has not damage/touched boxes (m_pDegats false on each elements)
 * Constructeur de la classe; le bateau n'a pas encore de case touchée (m_pDegats à faux partout)
 * @param n The name of the boat / Le nom du bateau
 * @param p The position at the anchor point / La position du bateau au point d'ancrage
 * @param t The length of the boat / La taille du bateau.
 */
CBateau::CBateau(string n, pair<int, int> p, int t) {
    this->m_nom = n;
    this->m_taille = t;
    this->m_position = p;
    if(n.empty()){
        this->m_nom="néant";
        cout << "[*] Le nom ne peut etre vide"<< endl;
        cout << "[*] The name can't be empty"<< endl;
    }
    if(t < 0){
        this->m_taille = 0;
        cout << "[*] La taille ne peut être négative" << endl;
        cout << "[*] The length can't be negative" << endl;
    }
    if(p.first < 0){
        this->m_position.first = 0;
        cout << "[*] La position ne peut être négative" << endl;
        cout << "[*] The position can't be negative" << endl;
    }
    if(p.second < 0){
        this->m_position.second= 0;
        cout << "[*] La position ne peut être négative" << endl;
        cout << "[*] The position can't be negative" << endl;
    }
    this->m_pDegats = new bool[this->m_taille];
    for (int i = this->m_taille - 1; i >= 0; i--)
        this->m_pDegats[i] = false;
}

/**
 * Renvoie vrai si la case numéro i du bateau est touchée (0<=i<m_taille)
 * Return true if the boxe number i of the boat is touched/damaged (0<=i<m_taille)
 * @param i The number of the boxe / Le numéro de la case
 * @return True : if the boat is touched at this point / False : if it's not the case
 *         Vrai : si le bateau est touché à cet endroit / Faux : Si ce n'est pas le cas
 */
bool CBateau::getDegats(int i) {
    return this->m_pDegats[i];
}

/**
 * Return the name of the boat
 * Retourne le nom du bateau
 * @return the name of the boat / Le nom du bateaeu
 */
string CBateau::getNom() {
    return this->m_nom;
}

/**
 * Return the length of the boat
 * Retourne la taille du bateau
 * @return the length of the boat / La taille du bateau
 */
int CBateau::getTaille() {
    return this->m_taille;
}

/**
 * Return the position of the anchor point
 * Retourne la position au point d'ancrage du bateau.
 * @return The position of the anchor point / La position au point d'ancrage du bateau.
 */
pair<int, int> CBateau::getPositions() {
    return this->m_position;
}

/**
 * Change the position of the boat on the grid with the i line and the j column (new anchor point)
 * Modifier la position du bateau sur la grille en ième ligne, jème colonne (nouveau point d'ancrage)
 * @param i The new position on the line / La nouvelle position sur la ligne
 * @param j The new position on the column / La nouvelle position sur la colonne
 */
void CBateau::setPosition(int i, int j) {
    this->m_position.first = i;
    this->m_position.second = j;
}

/**
 * Return true if the boat is sunk.
 * Retourne vrai si le bateau est coulé
 * @return True if the boat is sunk / False : if it's not the case.
 *         Vrai si le bateau est coulé / Faux si ce n'est pas le cas
 */
bool CBateau::estCoule() {
    for (int i = this->m_taille - 1; i >= 0; i--){
        if(!this->m_pDegats[i]){
            return false;
        }
    }
    return true;
}

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
bool CBateau::tirAdverse(pair<int, int> p) {
    if(this->m_position.second == p.second &&
        this->m_position.first<=p.first &&
        this->m_position.first+this->getTaille()>=p.first &&
        !this->getDegats(p.first-this->getPositions().first)){
        this->m_pDegats[p.first-this->getPositions().first] = true;
        return true;
    }
    return false;
}

/**
 * Operator overload << to display the boat's characteristics on the screen.
 * Surcharge de l'opérateur << pour afficher à l'écran les caractéristiqes du bateau.
 * @param os The ostream object / L'objet ostream
 * @param theB The CBateau' object / L'objet Cbateau
 * @return The ostream object that return the current value of the attributes.
 *         L'objet ostream qui retourne la valeur courante de l'attribut.
 */
ostream &operator<<(ostream &os, CBateau &theB) {
    os << "[I] Caractéristique du bateau / Boat characteristics : " << endl;
    os << "[I] Nom / Name : " << theB.getNom() << endl;
    os << "[I] Taille / Size : " << theB.getTaille() << endl;
    os << "[I] Position : ( " << theB.getPositions().first << " ; " << theB.getPositions().second << " ) "<< endl;
    os << "[I] Coulé / isSunk : " ;
    if(theB.estCoule()){
        os << "True" << endl;

    }else{
        os << "False" << endl;
    }
    os << "[I] Dégats / Damages : [";
    for (int i = theB.m_taille - 1; i >= 0; i--){
        if(theB.getDegats(i)){
            os << i << " : " << "True" << ", ";

        }else{
            os << i << " : " << "False" << ", ";
        }
    }
    os << "]" << endl;
    return os;
}

/**
 * Copy constructor
 * @param toCopy The object to copy
 */
CBateau::CBateau(const CBateau &toCopy) {
    this->m_taille = toCopy.m_taille;
    this->m_nom = toCopy.m_nom;
    this->m_position.first = toCopy.m_position.first;
    this->m_position.second = toCopy.m_position.second;
    this->m_pDegats = new bool[toCopy.m_taille];
    if(toCopy.m_pDegats != NULL){
        for (int i = toCopy.m_taille - 1; i >= 0; i--)
            this->m_pDegats[i] = toCopy.m_pDegats[i];
    }else this->m_pDegats = NULL;
}

/**
 * Destructor / Destructeur
 */
CBateau::~CBateau() {
    if ( this->m_pDegats != NULL ) {
        //cout << "[I] Destruction de CBateau" << endl;
        delete[] this->m_pDegats;
    }
}


