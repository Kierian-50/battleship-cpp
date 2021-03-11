/*
 * 	Cette classe d�finit un ensemble de fonctionnalit�s que l'interface graphique (CGui) devra impl�menter.
 * 	Elle est ABSTRAITE et doit donc �tre h�rit�e.
 */

#ifndef BATTLESHIP_CBASEJEU_H
#define BATTLESHIP_CBASEJEU_H

#include "BiblioStd.h"

class CBaseJeu {

	public:
		virtual bool positionnerBateaux () = 0;								// m�thode abstraite voir classe CGui
		virtual pair<int,int> choisirAttaque () = 0;						// m�thode abstraite voir classe CGui
		virtual void afficheGagne() = 0;									// m�thode abstraite voir classe CGui
		virtual void affichePerdu() = 0;									// m�thode abstraite voir classe CGui

	private:
		virtual void remplirDeuxGrilles ( ostream& os ) = 0;				// m�thode abstraite voir classe CGui
		virtual void afficherLaGrille ( ostream& os, string jouOuAdv ) = 0;	// m�thode abstraite voir classe CGui
};

#endif // CBASEJEU_H
