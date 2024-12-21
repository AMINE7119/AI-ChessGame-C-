#include "partie.h"

partie::partie()
{
	tour=1;
}
partie::~partie()
{
	
}
partie::menu(){
	int choix;
	do{
    cout << "                         ---------------------------" << endl;
    cout << "                             1- MACHINE VS JOUEUR           " << endl;
    cout << "                             2- PARTIE MULTIJOUEUR             " << endl;
    cout << "                             3- QUITTER                       " << endl;
    cout << "                         ---------------------------" << endl;
    cout << endl;
    cout << "                         ----------------------------" << endl;
    cout << "                                Votre choix : ";
        cin >> choix;
		switch(choix){
			case 1:
				system("cls"); jouer(1); break;
			case 2:
				system("cls"); jouer(2); break;
		}
	}while(choix!=3);
}
partie::jouer(int choix)
{
	do{
		p.showBoard();
		if(tour%2==0){
			p.mvPiece('N');
		}else{
			if(choix==1){
				p.setAi(true);
				p.AiPlay();
			}else if(choix==2){
				p.mvPiece('B');			
			}
		}
		tour++;
	}while(p.endGame());
}



