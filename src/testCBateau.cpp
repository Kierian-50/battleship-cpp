//
// Created by kierian on 10/02/2021.
//

#include "CBateau.h"

void testConstructeurVide();
void testConstructeurNormal();
void testConstructeurErreur();
void testTirAdverse();
void testEstCoule();

int main() {
    testConstructeurVide();
    testConstructeurNormal();
    testConstructeurErreur();
    testTirAdverse();
    testEstCoule();
    cout << "[I] Fin !" << endl;
    return 0;
}

/**
 * This method allows to testEstCoule the empty constructor.
 * Cette méthode permet de tester le constructeur vide.
 */
void testConstructeurVide(){
    CBateau bateau;
    if(bateau.getNom() == "néant" && bateau.getPositions().first == 0 && bateau.getPositions().second == 0 &&
            bateau.getTaille() == 0){
        cout << "[I] Constructeur vide : OK" << endl;
    }else{
        cout << "[*] ERREUR : constructeur vide " << endl;
        cout << bateau;
    }
}

/**
 * This method allows to testEstCoule the constructor in a normal case
 * Cette méthode permet de tester le constructeur dans un cas normal.
 */
void testConstructeurNormal(){
    pair<int, int> pos;
    pos.first = 5;
    pos.second = 5;
    CBateau bateau ("Le Redoutable", pos, 2);
    if(bateau.getNom() == "Le Redoutable" &&
        bateau.getPositions().first == 5 &&
        bateau.getPositions().second == 5 &&
        bateau.getTaille() == 2 && !
        bateau.getDegats(0) &&
        !bateau.getDegats(1)){
        cout << "[I] Constructeur erreur : OK" << endl;
    }else{
        cout << "[*] ERREUR constructeur normal : " << endl;
        cout << bateau;
    }
}

/**
 * This method allows to testEstCoule the constructor in an error case.
 * Cette méthode permet de tester le constructeur dans un cas d'erreur.
 */
void testConstructeurErreur(){
    pair<int, int> pos;
    pos.first = -5;
    pos.second = -5;
    CBateau bateau ("", pos, -1);
    if(bateau.getNom() == "néant" &&
       bateau.getPositions().first == 0 &&
       bateau.getPositions().second == 0 &&
       bateau.getTaille() == 0 && !
               bateau.getDegats(0)){
        cout << "[I] Constructeur normal : OK" << endl;
    }else{
        cout << "[*] ERREUR Constructeur erreur : " << endl;
        cout << bateau;
    }
}

/**
 * This method allows to test the estCoule' method.
 * Cette méthode permet de tester la méthode estCoule.
 */
void testTirAdverse() {
    // Create the CBateau object
    // The position of the boat ; it'll be on (5;5), (6;5), (7;5)
    // La position du bateau ; Il sera sur (5;5), (6;5), (7;5)
    pair<int, int> pos;
    pos.first = 5;
    pos.second = 5;
    CBateau bateau("Le Téméraire", pos, 3);
    // The position of the shot
    // La position du tir
    pair<int, int> touch;
    touch.first = 7;
    touch.second = 5;
    bateau.tirAdverse(touch);
    if(bateau.getDegats(2)){ // Two because we start at 0 / deux car on commence à 0
        cout << "[I] Tir sur (7;5) : OK" << endl;
    }else{
        cout << "[*] ERREUR tirAdverse : " << endl;
        cout << bateau;
    }

    // A shot which is not on the boat
    // Un tir qui n'est pas sur le bateau
    pair<int, int> touch_two;
    touch_two.first = 6;
    touch_two.second = 6;
    bateau.tirAdverse(touch_two);
    if(bateau.getDegats(2) && !bateau.getDegats(1) && !bateau.getDegats(0)){ // Two because we start at 0 / deux car on commence à 0
        cout << "[I] Tir sur (6;6) : OK" << endl;
    }else{
        cout << "[*] ERREUR tirAdverse: " << endl;
        cout << bateau;
    }
}

/**
 * This method allows to test if the boat is sunk with the method estCoule
 * Cette methode permet de tester la methode estCoule.
 */
void testEstCoule(){
    // Create the CBateau object
    // The position of the boat ; it'll be on (5;5), (6;5), (7;5)
    // La position du bateau ; Il sera sur (5;5), (6;5), (7;5)
    pair<int, int> pos;
    pos.first = 5;
    pos.second = 5;
    CBateau bateau("Le Téméraire", pos, 3);
    // The position of the shot
    // La position du tir
    pair<int, int> touch;
    touch.first = 7;
    touch.second = 5;
    bateau.tirAdverse(touch);

    if(!bateau.estCoule()){
        cout << "[I] Bateau non après coulé : OK" << endl;
    }else{
        cout << "[*] ERREUR estCoule : " << endl;
        cout << bateau;
    }

    touch.first = 6;
    bateau.tirAdverse(touch);
    touch.first = 5;
    bateau.tirAdverse(touch);

    if(bateau.estCoule()){
        cout << "[I] Bateau coulé : OK" << endl;
    }else{
        cout << "[*] ERREUR estCoule : " << endl;
        cout << bateau;
    }
}