#include "CGui.h"
#include "CArmada.h"
#include "CCoups.h"

/**
 * Default constructor m_pArmada and m_pCoups to NULL
 * Constructeur par défaut : m_pArmada et m_pCoups
 */
CGui::CGui() {
    this->m_pArmada = NULL;
    this->m_pCoups = NULL;
}

/**
 * Constructor which receive a pointer on the armada and a pointer on the shooting recording structure
 * Constructeur qui reçoit un pointeur sur l'armada et un pointeur sur la structure d'enregistrement des tirs
 * @param pArmada Pointer on the armada / Pointeur sur l'armada
 * @param pCoups Pointer on the shooting recording structure / Pointeur sur la structure d'enregistrement des tirs
 */
CGui::CGui(CArmada *pArmada, CCoups *pCoups) {

    if(pArmada == NULL or pCoups == NULL){
        throw "pArmada and pCoups can't be NULL | pArmada and pCoups ne peut être NULL";
    }
    this->m_pCoups = pCoups;
    this->m_pArmada = pArmada;
}

/**
 * Destructor : Destruction of the pointing areas by m_pArmada and m_pCoups
 * Desctruteur : Destruction des zones pointées par m_pArmada et m_pCoups
 */
CGui::~CGui() {
    this->m_pArmada = NULL;
    delete m_pArmada;
    this->m_pCoups = NULL;
    delete m_pCoups;
}

/**
 * Modifier : Update the attributes
 * Modificateur : Mise à jour des attributs
 * @param pArmada Pointer on the armada / Pointeur sur l'armada
 * @param pCoups Pointer on the shooting recording structure / Pointeur sur la structure d'enregistrement des tirs
 */
void CGui::setArmadaCoups(CArmada *pArmada, CCoups *pCoups) {
    this->m_pCoups = pCoups;
    this->m_pArmada = pArmada;
}

/**
 * Method which is called at the beginning of the game to place every boats on the grid by performing
 * placerAleatoirement of CArmada. Return false if the positioning.
 * Méthode appélée au début du jeu pour positionner tous les bateaux sur la grille en exécutant placerAleatoirement
 * de CArmada. Renvoie faux si le positionnement a échoué.
 * @return False if the positioning failed / Faux si le positionnement a échoué.
 */
bool CGui::positionnerBateaux() {
    return m_pArmada->placerAleatoirement();
}

/**
 * Enter the coordinates (line, column) of the attack (check that the user enter the correct form for
 * the coordinates)
 * Saisie de la coordonnée (ligne, colonne) de l'attaque (vérification obligatoire bon/mauvais après saisie de la
 * coordonnée par l'utilisateur)
 * @return The coordinates entered by the user / Les coordonnées entrées par l'utilisateur
 */
pair<int, int> CGui::choisirAttaque() {
    // Variables
    int x;
    int y;

    cout << "Entrez la valeur en x : " << endl;

    // Error Checkin algorithm | Algo de vérfification du contenu entrée par l'utilisateur
    while (!(cin >> x) or (x < 0 or x > TAILLE_GRILLE-2))
    {
        // Explain error | Explique l'error
        cout << "ERREUR: Un nombre entre 0 et 9 doit être entré: ";
        // Clear input stream | Nettoie l'entrée
        cin.clear();
        // Discard previous input | Rejete l'entrée précedente
        cin.ignore(132, '\n');
    }

    cout << "Entrez la valeur en y : " << endl;

    // Error Checkin algorithm | Algo de vérfification du contenu entrée par l'utilisateur
    while (!(cin >> y) or (y < 0 or y > TAILLE_GRILLE-2))
    {
        // Explain error | Explique l'error
        cout << "ERREUR: Un nombre entre 0 et 9 doit être entré: ";
        // Clear input stream | Nettoie l'entrée
        cin.clear();
        // Discard previous input | Rejete l'entrée précedente
        cin.ignore(132, '\n');
    }

    return make_pair(x,y);
}

/**
 * Display "Game won" on the screen
 * Affiche "La partie est gagnée" à l'écran
 */
void CGui::afficheGagne() {
    cout << "La partie est gagnée !" << endl;
}

/**
 * Display "Lost Game" on the screen
 * Affiche "La partie est perdue à l'écran
 */
void CGui::affichePerdu() {
    cout << "La partie est perdue..." << endl;
}

/**
 * Overload of the << operator to display the grids. This function does a simple call to remplirDeuxGrilles of
 * the theG's object.
 * Surcharge de l'opérateur << pour l'affichage des grilles. Cette fonction fait un simple appel à
 * remplirDeuxGrilles(...) de l'objet theG
 * @param os Ostream
 * @param theG The CGui's object / L'objet CGui
 * @return The ostream pointer / Le pointer ostream
 */
ostream &operator<<(ostream &os, CGui &theG) {
    theG.remplirDeuxGrilles(os);
    return os;
}

/**
 * Fill the grid of the player m_grilleJou and the grid of the opponent m_grilleAdv
 * Remplir la grille du joueur m_grilleJou et la grille de l'adversaire m_grilleAdv
 * @param os Ostream
 */
void CGui::remplirDeuxGrilles(ostream &os) {
    // Init the grid
    for(int i = 0; i <= TAILLE_GRILLE-2; i++){
        for(int j = 0; j <= TAILLE_GRILLE-2; j++){
            this->m_grilleJou[i][j] = '-';
            this->m_grilleAdv[i][j] = '-';
        }
    }

    // Grid of the player | Grille du joueur
    for(int i = 0; i < m_pArmada->getEffectifTotal(); i++){
        CBateau* bateau = m_pArmada->getBateau(i);
        pair<int, int> position = bateau->getPositions();

        // For each emplacement of the boat | Pour chaque emplacement du bateau
        for(int ii = 0; ii < bateau->getTaille(); ii++){
            // Check that the boat is shoot | Vérifie que le bateau est touché
            if(bateau->getDegats(ii)){
                this->m_grilleJou[position.first+ii][position.second] = 'X';
            }else{
                this->m_grilleJou[position.first+ii][position.second] = 'B';
            }
        }
    }

    // Enemy shot on our grid | Tirs enemies sur notres grille
    for(int i = 0; i < m_pCoups->getTaille("ploufAdverse"); i++){
        pair<int,int> position;
        position = m_pCoups->getPair("ploufAdverse", i);
        this->m_grilleJou[position.first][position.second] = 'O';
    }

    // Grid of the opponent | La grille de l'adverse
    for(int i = 0; i < m_pCoups->getTaille("touche"); i++){
        pair<int, int> position;
        position = m_pCoups->getPair("touche", i);
        this->m_grilleAdv[position.first][position.second] = 'X';
    }

    for(int i = 0; i <m_pCoups->getTaille("dansLEau"); i++){
        pair<int,int> position;
        position = m_pCoups->getPair("dansLEau", i);
        this->m_grilleAdv[position.first][position.second] = 'O';
    }

    afficherLaGrille(os, "joueur");
    afficherLaGrille(os, "adversaire");
}

/**
 * Display the grid (player and opponent) on the screen, this is to say display the content of m_grilleJou ou
 * m_grilleAdv and legends (0 ... TAILLE_GRILLE-2)
 * Affichage d'une grille (joueur ou adversaire) à l'écran, c'est-à-dire affichage du contenu de m_grilleJou ou
 * m_grilleAdv + les légendes (0 ... TAILLE_GRILLE-2)
 * @param os Ostream
 * @param jouOuAdv The name of the player that we'll display / Le nom du joueur dont nous allons afficher la grille
 */
void CGui::afficherLaGrille(ostream &os, string jouOuAdv) {
    if(jouOuAdv == "joueur"){
        os << "Affichage de la grille du joueur :" << endl;

        // Display the top number | Affiche les nombres en haut
        os << " ";
        for(int j = 0; j < TAILLE_GRILLE-1; j++){
            os << " " << j;
        }
        os << endl;

        // Display the content | Affiche le contenu
        for (int x = 0 ; x < TAILLE_GRILLE-1 ; x++) {
            os << x;
            for (int y = 0 ; y < TAILLE_GRILLE-1 ; y++) {
                os << " " << this->m_grilleJou[y][x];
            }
            os << endl;
        }
        os << endl;

    }else if(jouOuAdv == "adversaire"){
        os << "Affichage de la grille de l'adversaire :" << endl;

        // Display the top number | Affiche les nombres en haut
        os << " ";
        for(int j = 0; j < TAILLE_GRILLE-1; j++){
            os << " " << j;
        }
        os << endl;

        // Display the content | Affiche le contenu
        for (int x = 0 ; x < TAILLE_GRILLE-1 ; x++) {
            os << x;
            for (int y = 0 ; y < TAILLE_GRILLE-1 ; y++) {
                os << " " << this->m_grilleAdv[y][x];
            }
            os << endl;
        }
        os << endl;
    }else{
        throw "Error with jouOuAdv | Erreur avec jouOuAdv";
    }
}
