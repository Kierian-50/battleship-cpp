#include "BiblioStd.h"
#include "CGui.h"
#include "CBateau.h"
#include "CArmada.h"
#include "CCoups.h"

void testDefaultConstructor();
void testConstructorParamNormal();
void testConstructorParamError();
void testPositionnerBateau();
void testChoisirAttaque();
void testAffichage();

int main() {
    testDefaultConstructor();
    testConstructorParamNormal();
    testConstructorParamError();
    testPositionnerBateau();
    testChoisirAttaque();
    testAffichage();
    cout << "[I] Fin test CGui !" << endl;
    return 0;
}

/**
 * This method allows to test the default constructor of CGui
 * Cette méthode permet de tester le constructeur par defaut de CGui
 */
void testDefaultConstructor(){
    CGui cGui;
    cout << "[I] Constructeur par défaut : OK" << endl;
}

/**
 * This method allows to test the constructor which receives parameters CArmada and CCoups in a normal case
 * Cette méthode permet de tester le constructeur qui reçoit des paramètres CArmada et CCoups dans un cas noraml
 */
void testConstructorParamNormal(){
    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    CCoups cCoups;
    try {
        CGui cGui(&armada, &cCoups);
        cout << "[I] Constructeur avec paramètre : OK" << endl;
    } catch (const char* msg) {
        cout << "[I] Constructeur avec paramètre : ERREUR" << endl;
        cerr << msg << endl;
    }
}

/**
 * This method allows to test the constructor which receives parameters CArmada and CCoups in an error case
 * Cette méthode permet de tester le constructeur qui reçoit des paramètres CArmada et CCoups dans un cas d'erreur
 */
void testConstructorParamError(){
    try {
        CGui cGui(NULL, NULL);
        cout << "[I] Constructeur avec paramètre erreur : ERREUR" << endl;
    } catch (const char* msg) {
        cout << "[I] Constructeur avec paramètre erreur : OK" << endl;
        cerr << msg << endl;
    }
}

/**
 * This method allows to test the method positionnerBateau by trying to use the method we'll display it later
 * Cette méthode permet de tester la méthode positionnerBateau en essayant d'utiliser la méthode, on l'affiche après
 */
void testPositionnerBateau(){
    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    CCoups cCoups;
    try {
        CGui cGui(&armada, &cCoups);
        cGui.positionnerBateaux();
        cout << "[I] bositionnerBateau : OK" << endl;
    } catch (const char* msg) {
        cout << "[I] bositionnerBateau : ERREUR" << endl;
        cerr << msg << endl;
    }
}

/**
 * This method allows to test the method choisirAttaque
 * Cette méthode permet de tester la methode choisirAttaque
 */
void testChoisirAttaque(){
    CGui cGui;
    pair<int,int> pos = cGui.choisirAttaque();
    cout << "[I] Entered value : (" << pos.first << ";" << pos.second << ")" << endl;
    cout << "[I] Fin du test de choisirAttaque : OK" << endl;
}

/**
 * This method allows to test the display of the grid
 * Cette method permet de tester l'affichage de la grille
 */
void testAffichage(){
    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    pair <int, int> posBat1 = armada.getBateau(0)->getPositions();
    armada.getBateau(0)->tirAdverse(posBat1);
    posBat1.first += armada.getBateau(0)->getTaille()-1;
    armada.getBateau(0)->tirAdverse(posBat1);

    pair <int, int> posBat2 = armada.getBateau(1)->getPositions();
    posBat2.first += armada.getBateau(1)->getTaille()-1;
    armada.getBateau(1)->tirAdverse(posBat2);

    CCoups cCoups;
    pair<int, int> pos1 = make_pair(0,0);
    pair<int, int> pos2 = make_pair(1,1);
    cCoups.ajouterTirMap("touche", pos1);
    cCoups.ajouterTirMap("dansLEau", pos2);
    cCoups.ajouterTirMap("ploufAdverse", pos1);
    try {
        CGui cGui(&armada, &cCoups);
        cGui.positionnerBateaux();
        cout << cGui;
        cout << "[I] Test de l'affichage : OK" << endl;
    } catch (const char* msg) {
        cout << "[I] Test de l'affichage : ERREUR" << endl;
        cerr << msg << endl;
    }
}