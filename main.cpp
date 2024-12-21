#include <iostream>
#include <conio.h> // for getch()
#include "partie.h"
#include <windows.h> // pour SetConsoleTextAttribute

using namespace std;

void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = (bgColor << 4) | textColor;
    SetConsoleTextAttribute(hConsole, color);
}
void printLogo() {
    setColor(1, 6);
    
    std::cout << "		#######  #####  ###  #####     #   " << std::endl;
    std::cout << "		#######  #####  ###  #####     #   " << std::endl;
    std::cout << "		#       #     #  #  #     #   # #  " << std::endl;
    std::cout << "		#       #     #  #  #     #   # #  " << std::endl;
    std::cout << "		#       #        #  #        #   # " << std::endl;
    std::cout << "		#       #        #  #        #   # " << std::endl;
    std::cout << "		#####    #####   #   #####  #     #" << std::endl;
    std::cout << "		#####    #####   #   #####  #     #" << std::endl;
    std::cout << "		#             #  #        # #######" << std::endl;
    std::cout << "		#             #  #        # #######" << std::endl;
    std::cout << "		#       #     #  #  #     # #     #" << std::endl;
    std::cout << "		#       #     #  #  #     # #     #" << std::endl;
    std::cout << "		#######  #####  ###  #####  #     #" << std::endl;
    std::cout << "		#######  #####  ###  #####  #     #" << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
}

void regle() {
    system("cls");
    cout << endl;
    std::cout << "1. Chaque joueur (Blancs et Noirs) commence avec 16 pi�ces de sa couleur," << std::endl;
	std::cout << "	� savoir un roi, une dame, deux tours, deux fous, deux cavaliers et huit pions." << std::endl;
    std::cout << "2. La pi�ce la plus importante est le roi, car le but du jeu est de mettre le roi adverse dans une" << std::endl;
	std::cout << "	position o� il ne peut �viter d'�tre captur�." << std::endl;
    std::cout << "3. Les mouvements des pi�ces sont r�gis par des r�gles sp�cifiques : les pions avancent d'une case vers" << std::endl;
	std::cout << "	l'avant mais capturent en diagonale, les cavaliers se d�placent en L, les tours se d�placent horizontalement ou verticalement," << std::endl;
	std::cout << "	les fous se d�placent en diagonale, la dame peut se d�placer dans toutes les directions et " << std::endl;
	std::cout << "	le roi peut se d�placer d'une case dans n'importe quelle direction." << std::endl;
    std::cout << "4. Le joueur doit prot�ger son propre roi tout en cherchant � capturer le roi adverse." << std::endl;
    std::cout << "5. Les �checs et les �checs et mat sont des conditions importantes du jeu. Un �chec se produit " << std::endl;
	std::cout << "	lorsque le roi est menac� par une pi�ce adverse et doit �tre prot�g�." << std::endl;
	std::cout << "	Un �chec et mat se produit lorsque le roi est menac� et ne peut �tre sauv� par aucun mouvement l�gal." << std::endl;
    std::cout << "6. Le roque est un mouvement sp�cial o� le roi et l'une des tours du joueur" << std::endl;
	std::cout << "	peuvent �tre d�plac�s simultan�ment sous certaines conditions." << std::endl;
    std::cout << "7. La promotion des pions se produit lorsque l'un des pions atteint la rang�e oppos�e du plateau de jeu," << std::endl;
	std::cout << "	o� il peut �tre promu en une pi�ce plus puissante (g�n�ralement une dame)." << std::endl;
    std::cout << "8. La r�gle de la r�p�tition stipule que si la m�me position appara�t trois fois dans une partie," << std::endl;
	std::cout << "	avec le m�me joueur au tour, le jeu peut �tre d�clar� nul." << std::endl;
    std::cout << "9. Le jeu peut �galement �tre d�clar� nul par la r�gle du pat," << std::endl;
	std::cout << "	o� un joueur n'a aucun mouvement l�gal mais son roi n'est pas en �chec." << std::endl;
}

void menuprc() {
    int ch;
    do {
    setColor(1,0); 	
    cout << "                         ```````````````````````````" << endl;
    setColor(1,0); 
    cout << "                             1-     START         " << endl;
    setColor(1,0);
    cout << "                             2- APPREND A JOUER     " << endl;
    setColor(1,0); // Couleur verte
    cout << "                             3-    QUITTER         " << endl;
    cout << "                         ```````````````````````````" << endl;
    setColor(1,0);
    cout << endl;
    cout << "                         ----------------------------" << endl;
    cout << "                                Votre choix : " << endl;
    cout << "                         ----------------------------" << endl;

        cin >> ch;
        switch(ch) {
            case 1: {
                system("cls");
                partie p;
                p.menu();
                getch();
                break;
            }
            case 2: {
                system("cls");
                regle();
                getch();
                break;
            }
            case 3:
                break;
            default:
                break;
        }
    } while(ch != 3);
}

int main() {
    printLogo();
    menuprc();
    return 0;
}

