//
// Created by kierian on 17/02/2021.
//

#include "CArmada.h"
#include "CBateau.h"

void testAjouterBateau();
void testGetEffectifTotal();
void testGetNbreTotCases();
void testGetEffectif();
void testGetArmadaFromFile();
void testPlacerAleatoirement();

int main() {
    testAjouterBateau();
    testGetEffectifTotal();
    testGetNbreTotCases();
    testGetEffectif();
    testGetArmadaFromFile();
    testPlacerAleatoirement();
    cout << "[I] Fin !" << endl;
    return 0;
}

/**
 * This method allows to test the method ajouterBateau of CArmada
 * Cette méthode permet de tester la méthode ajouterBateau de CArmada
 */
void testAjouterBateau(){
    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    if(armada.getBateau(0)->getNom() == bateau1.getNom() and
            armada.getBateau(1)->getNom() == bateau2.getNom() and
            armada.getBateau(2)->getNom() == bateau3.getNom() and
            armada.getBateau(3)->getNom() == bateau4.getNom()) {
        cout << "[I] Test de ajouterBateau : OK" << endl;
    }else{
        cout << "[*] Test de ajouterBateau : ERREUR" << endl;
    }
}

/**
 * This method allows to test the method getEffectif of CArmada.
 * Cette méthode permet de tester la méthode getEffectif de CArmada.
 */
void testGetEffectifTotal(){
    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    if(armada.getEffectifTotal() == 4) {
        cout << "[I] Test de ajouterBateau : OK" << endl;
    }else{
        cout << "[*] Test de ajouterBateau : ERREUR ; Nombre de bateau : " << armada.getEffectifTotal() << ", Attendu : 4"
        << endl;
    }
}

/**
 * This method allows to test the method GetNbreTotCases of CArmada
 * Cette méthode permet de tester la methode GetNbreTotCases de CArmada
 */
void testGetNbreTotCases(){
    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    if(armada.getNbreTotCases() == 3*4){
        cout << "[I] Test de getNbreTotCases : OK" << endl;
    }else{
        cout << "[*] Test de getNbreTotCases : ERREUR ; Nombre de cases : " << armada.getNbreTotCases() <<
        ", Attendu : 12" << endl;
    }
}

/**
 * This method allows to test the method getEffectif of CArmada
 * Cette méthode permet de tester la méthode de getEffectif of CArmada
 */
void testGetEffectif(){
    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    if(armada.getEffectif() == 4){
        cout << "[I] Test de getEffectif : OK" << endl;
    }else{
        cout << "[*] Test de getEffectif : ERREUR ; Nombre de bateau : " << armada.getEffectif() << ", Attendu : 4"
        << endl;
    }

    // Sunk a boat
    // Coule un bateau
    armada.getBateau(0)->tirAdverse(make_pair(1,1));
    armada.getBateau(0)->tirAdverse(make_pair(2,1));
    armada.getBateau(0)->tirAdverse(make_pair(3,1));

    if(armada.getEffectif() == 3){
        cout << "[I] Test de getEffectif : OK" << endl;
    }else{
        cout << "[*] Test de getEffectif : ERREUR ; Nombre de bateau : " << armada.getEffectif() << ", Attendu : 3"
             << endl;
    }
}

/**
 * This method allows to test the method getArmadaFromFile from CArmada in a normal case.
 * Cette méthode permet de tester les méthode de getArmadaFile de CArmada dans un cas normal.
 */
void testGetArmadaFromFile(){
    // Write in the file
    // Ecrit dans le fichier
    ofstream flotille;
    flotille.open ("/home/kierian/CLionProjects/battleship/flotille.txt");
    flotille << "# Ceci est un commentaire\n";
    flotille << "# This is a comment\n";
    flotille << "sous-marin 2 5\n";
    flotille << "FREMM 1 2\n";
    flotille << "FLF -1 2\n";
    flotille << "FAA 1 -2";
    flotille.close();

    CArmada armada;
    armada.getArmadaFromFile();
    if(armada.getBateau(0)->getNom() == "sous-marin"
        and armada.getBateau(1)->getNom() == "sous-marin"
        and armada.getBateau(2)->getNom() == "FREMM"
        and armada.getBateau(3)->getNom() == "FAA" ){
        cout << "[I] Test de getArmadaFromFile : OK" << endl;
    }else{
        cout << "[*] Test de getArmadaFromFile : ERREUR ; Nombre de bateau : " << armada.getEffectifTotal() << ", Attendu : 4"
             << endl;
    }
}

/**
 * This method allows to test the method placeAleatoirement from CArmada in a normal case.
 * Cette méthode permet de tester placeAleatoirement de CArmada dans un cas normal.
 */
void testPlacerAleatoirement(){
    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    armada.placerAleatoirement();
}