//
// Created by kierian on 10/03/2021.
//

#ifndef BATTLESHIP_CGUI_H
#define BATTLESHIP_CGUI_H

#include "BiblioStd.h"
#include "CArmada.h"
#include "CCoups.h"
#include "CBaseJeu.h"

class CGui : public CBaseJeu{
private:
    /**
     * Grid of the player
     * Grille du joueur
     */
    char m_grilleJou[TAILLE_GRILLE-1][TAILLE_GRILLE-1]{};

    /**
     * Grid of the opponent
     * Grille de l'adversaire
     */
    char m_grilleAdv[TAILLE_GRILLE-1][TAILLE_GRILLE-1]{};

    /**
     * Pointer on the only armada of the player
     * Pointeur sur l'unique armada du joueur
     */
    CArmada* m_pArmada;

    /**
     * Pointer on the only shooting recording structure
     * Pointeur sur l'unique structure d'enregistrement des tirs
     */
    CCoups* m_pCoups;

public:
    /**
     * Default constructor m_pArmada and m_pCoups to NULL
     * Constructeur par défaut : m_pArmada et m_pCoups
     */
    CGui();

    /**
     * Constructor which receive a pointer on the armada and a pointer on the shooting recording structure
     * Constructeur qui reçoit un pointeur sur l'armada et un pointeur sur la structure d'enregistrement des tirs
     * @param pArmada Pointer on the armada / Pointeur sur l'armada
     * @param pCoups Pointer on the shooting recording structure / Pointeur sur la structure d'enregistrement des tirs
     */
    CGui(CArmada* pArmada, CCoups* pCoups);

    /**
     * Destructor : Destruction of the pointing areas by m_pArmada and m_pCoups
     * Desctruteur : Destruction des zones pointées par m_pArmada et m_pCoups
     */
    virtual ~CGui();

    /**
     * Modifier : Update the attributes
     * Modificateur : Mise à jour des attributs
     * @param pArmada Pointer on the armada / Pointeur sur l'armada
     * @param pCoups Pointer on the shooting recording structure / Pointeur sur la structure d'enregistrement des tirs
     */
    void setArmadaCoups(CArmada* pArmada, CCoups* pCoups);

    /**
     * Method which is called at the beginning of the game to place every boats on the grid by performing
     * placerAleatoirement of CArmada. Return false if the positioning.
     * Méthode appélée au début du jeu pour positionner tous les bateaux sur la grille en exécutant placerAleatoirement
     * de CArmada. Renvoie faux si le positionnement a échoué.
     * @return False if the positioning failed / Faux si le positionnement a échoué.
     */
    bool positionnerBateaux();

    /**
     * Enter the coordinates (line, column) of the attack (check that the user enter the correct form for
     * the coordinates)
     * Saisie de la coordonnée (ligne, colonne) de l'attaque (vérification obligatoire bon/mauvais après saisie de la
     * coordonnée par l'utilisateur)
     * @return The coordinates entered by the user / Les coordonnées entrées par l'utilisateur
     */
    pair<int, int> choisirAttaque();

    /**
     * Display "Game won" on the screen
     * Affiche "La partie est gagnée" à l'écran
     */
    void afficheGagne();

    /**
     * Display "Lost Game" on the screen
     * Affiche "La partie est perdue à l'écran
     */
    void affichePerdu();

    /**
     * Overload of the << operator to display the grids. This function does a simple call to remplirDeuxGrilles of
     * the theG's object.
     * Surcharge de l'opérateur << pour l'affichage des grilles. Cette fonction fait un simple appel à
     * remplirDeuxGrilles(...) de l'objet theG
     * @param os Ostream
     * @param theG The CGui's object / L'objet CGui
     * @return The ostream pointer / Le pointer ostream
     */
    friend ostream& operator<< (ostream& os, CGui& theG);

    /**
     * Fill the grid of the player m_grilleJou and the grid of the opponent m_grilleAdv
     * Remplir la grille du joueur m_grilleJou et la grille de l'adversaire m_grilleAdv
     * @param os Ostream
     */
    void remplirDeuxGrilles(ostream& os);

    /**
     * Display the grid (player and opponent) on the screen, this is to say display the content of m_grilleJou ou
     * m_grilleAdv and legends (0 ... TAILLE_GRILLE-2)
     * Affichage d'une grille (joueur ou adversaire) à l'écran, c'est-à-dire affichage du contenu de m_grilleJou ou
     * m_grilleAdv + les légendes (0 ... TAILLE_GRILLE-2)
     * @param os Ostream
     * @param jouOuAdv The name of the player that we'll display / Le nom du joueur dont nous allons afficher la grille
     */
    void afficherLaGrille(ostream& os, string jouOuAdv);
};

#endif //BATTLESHIP_CGUI_H
