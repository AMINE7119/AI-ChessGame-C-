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
    std::cout << "1. Chaque joueur (Blancs et Noirs) commence avec 16 pièces de sa couleur," << std::endl;
	std::cout << "	à savoir un roi, une dame, deux tours, deux fous, deux cavaliers et huit pions." << std::endl;
    std::cout << "2. La pièce la plus importante est le roi, car le but du jeu est de mettre le roi adverse dans une" << std::endl;
	std::cout << "	position où il ne peut éviter d'être capturé." << std::endl;
    std::cout << "3. Les mouvements des pièces sont régis par des règles spécifiques : les pions avancent d'une case vers" << std::endl;
	std::cout << "	l'avant mais capturent en diagonale, les cavaliers se déplacent en L, les tours se déplacent horizontalement ou verticalement," << std::endl;
	std::cout << "	les fous se déplacent en diagonale, la dame peut se déplacer dans toutes les directions et " << std::endl;
	std::cout << "	le roi peut se déplacer d'une case dans n'importe quelle direction." << std::endl;
    std::cout << "4. Le joueur doit protéger son propre roi tout en cherchant à capturer le roi adverse." << std::endl;
    std::cout << "5. Les échecs et les échecs et mat sont des conditions importantes du jeu. Un échec se produit " << std::endl;
	std::cout << "	lorsque le roi est menacé par une pièce adverse et doit être protégé." << std::endl;
	std::cout << "	Un échec et mat se produit lorsque le roi est menacé et ne peut être sauvé par aucun mouvement légal." << std::endl;
    std::cout << "6. Le roque est un mouvement spécial où le roi et l'une des tours du joueur" << std::endl;
	std::cout << "	peuvent être déplacés simultanément sous certaines conditions." << std::endl;
    std::cout << "7. La promotion des pions se produit lorsque l'un des pions atteint la rangée opposée du plateau de jeu," << std::endl;
	std::cout << "	où il peut être promu en une pièce plus puissante (généralement une dame)." << std::endl;
    std::cout << "8. La règle de la répétition stipule que si la même position apparaît trois fois dans une partie," << std::endl;
	std::cout << "	avec le même joueur au tour, le jeu peut être déclaré nul." << std::endl;
    std::cout << "9. Le jeu peut également être déclaré nul par la règle du pat," << std::endl;
	std::cout << "	où un joueur n'a aucun mouvement légal mais son roi n'est pas en échec." << std::endl;
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

