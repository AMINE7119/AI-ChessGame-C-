#include "plateau.h"
#include <iostream>
plateau::plateau()
{
	xm=0; ym=0; xma = 0; yma = 0;
	for(int i=2;i<=5;i++)
	{
		for(int j=0;j<=7;j++)
		{
			tj[i][j]=0;
		}	
	}
 
	for(int j=0;j<=7;j++)
	{
		tj[1][j]=1;
		tj[6][j]=-1;		
	}

	tj[0][0]=6;
	tj[0][1]=5;
	tj[0][2]=2;
	tj[0][3]=4;
	tj[0][4]=3;
	tj[0][5]=2;
	tj[0][6]=5;
	tj[0][7]=6;
	//Advancer
    tj[2][4]=7;
    //dragon
    tj[2][2]=8;


	tj[7][0]=-6;
	tj[7][1]=-5;
	tj[7][2]=-2;
	tj[7][3]=-4;
	tj[7][4]=-3;
	tj[7][5]=-2;
	tj[7][6]=-5;
	tj[7][7]=-6;

	
	mWeight[1].pieces[1] = -3;
	mWeight[2].pieces[1] = -2;
	mWeight[3].pieces[1] = -5;
	mWeight[4].pieces[1] = -6;
	mWeight[5].pieces[1] = -4;
	mWeight[6].pieces[1] = -1;
	
	aWeight[6].pieces[0] = 3;
	aWeight[5].pieces[0] = 4;
	aWeight[4].pieces[0] = 2;
	aWeight[3].pieces[0] = 6;
	aWeight[2].pieces[0] = 5;
	aWeight[1].pieces[0] = 1;	
}

void plateau::showBoard()
{
	system("cls");
	std::cout<<"  0   1   2   3   4   5   6   7 \n";
	for(int i=0;i<=7;i++)
	{ 
	  std::cout<<i<<"|";
	  
		for(int j=0;j<=7;j++)
		{
			
			switch(tj[i][j])
			{
				case -6: std::cout<<"TB |";
						break;
				case -5: std::cout<<"CB |";
						break;
				case -4: std::cout<<"QB |";
						break;
				case -3: std::cout<<"KB |";
						break;
				case -2: std::cout<<"FB |";
						break;
				case -1: std::cout<<"PB |";
						break;
				case 0: std::cout<<"   |";
						break;
				case 6: std::cout<<"TN |";
						break;
				case 5: std::cout<<"CN |";
						break;
				case 4: std::cout<<"QN |";
						break;
				case 3: std::cout<<"KN |";
						break;
				case 2: std::cout<<"FN |";
						break;
				case 1: std::cout<<"PN |";
						break;
				case 7: std::cout<<"AD |";
						break;
				case 8: std::cout<<"DR |";
						break;																																										
				default :break;
			}
		
		}		
		std::cout<<std::endl;	
		std::cout<<"----------------------------------"<<std::endl;
	}
}
plateau::~plateau()
{
	
}

bool plateau::endGame()
{
	
	if(Pat('N') || Pat('B')){
		cout << "STALEMATE!"; getch();
		return false;
	}else if(CheckMate('N')){
		cout << "CHECKMATE! blanc gagne!"; getch();
		return false;
	}else if(Ai==false && CheckMate('B')){
		cout << "CHECKMATE! noir gagne!"; getch();
		return false;
	}
	return true;
}

bool plateau::Pat(char joueur){
	int nbPieces=0;
	int nx,ny,cp=0;
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			if(joueur=='N'){
				if(tj[i][j]==3){
					nx=i;
					ny=j;
					i=8;
					j=8;
				}
			}else if(joueur=='B'){
				if(tj[i][j]==-3){
					nx=i;
					ny=j;
					j=8;
				}
			}
		}
	}
	
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			if(joueur=='N'){
				if(tj[i][j]>0 && tj[i][j]!=3){
					nbPieces++;
				}
			}else if(joueur=='B' && tj[i][j]!=-3){
				if(tj[i][j]<0){
					nbPieces++;
				}
			}
		}
	}
	if(nbPieces==0){
		return true;
	}
	
	if(!Check(joueur,nx,ny)){
		for(int i=0; i<=7; i++){
			for(int j=0; j<=7; j++){
				if(joueur=='N'){
					pMoves.clear();
					if(tj[i][j]>0){
						possibleMoves(i,j);
						if(pMoves.size()==0){
							cp++;	
						}
					}
				}else if(joueur=='B'){
					pMoves.clear();
					if(tj[i][j]<0){
						possibleMoves(i,j);
						if(pMoves.size()==0){
							cp++;	
						}
					}
				}
			}
		}
		if(nbPieces==cp){
			return true;
		}
	}
	return false;
}

void plateau::inputStart(int &x,int &y,char joueur)
{
	int a,b;
	bool ind;
	do{
	ind=true;
	std::cout<<"Veuillez saisir une LIGNE de depart: ";
	std::cin>>a;
	std::cout<<"Veuillez saisir une COLONNE de depart: ";
	std::cin>>b;
	if(a==-1 && b==-1){
		cout << "Player '" << joueur << "' has surrendered!"; getch();
		exit(1);
	}else{
		x=a; y=b;
	}
	if(joueur=='N')
	{
		if(tj[x][y]<0)
		{
			ind=true;
		}
		else
		{
			ind=false;
		}
	}
	else
	{
		if(tj[x][y]<0)
		{
			ind=false;
		}
		else
		{
			ind=true;
		}
	}
	}while(((x<0)||(x>7)) || ((y<0)||(y>7)) || (tj[x][y]==0) || (ind==true));
}

void plateau::inputArrival(int &x,int &y,char joueur)
{
	bool ind;
	do{
		ind=true;
		std::cout<<"Veuillez saisir une LIGNE d arrivee: ";
		std::cin>>x;
		std::cout<<"Veuillez saisir une COLONNE d arrivee: ";
		std::cin>>y;
		if(joueur=='N')
		{
			if(tj[x][y]<=0)
			{
				ind=false;
			}
		}
		else
		{
			if(tj[x][y]>=0)
			{
				ind=false;
			}		
		}
	}while(((x<0)||(x>7)) || ((y<0)||(y>7)) || (ind==true));
}

bool plateau::bPawn(int xa, int xd, int ya, int yd){
	if((xd == 1) && (yd == 0)||(xd == 1) && (yd == 1) || (xd == 1) && (yd == 2) || (xd == 1) && (yd == 3) || (xd == 1) && (yd == 4) || (xd == 1) && (yd == 5) || (xd == 1) && (yd == 6) || (xd == 1) && (yd == 7)){
		//DEPLACEMENT PAR 2 CASES EN AVANT AU DEBUT DU TOUR
		if((xa==xd+2) && (ya==yd)){
			if(tj[xd+2][yd]==0){
				return false;
			}
		}else if((xa==xd+1) && (ya==yd)){
			if(tj[xd+1][yd]==0){
				return false;
			}
		}else if((xa==xd+1) && (ya==yd+1)){
			if(tj[xd+1][yd+1]<0){
				return false;
			}
		}else if((xa==xd+1) && (ya==yd-1)){
			if(tj[xd+1][yd-1]<0){
				return false;
			}
		}
	}else if((xa==xd+1) && (ya==yd)){
		if(tj[xd+1][yd]==0){
			if(xa==7){
			}
		}
		return false;
	}else if((xa==xd+1) && (ya==yd+1)){
		if(tj[xd+1][yd+1]<0){
			return false;
		}
	}else if((xa==xd+1) && (ya==yd-1)){
		if(tj[xd+1][yd-1]<0){
			return false;
		}
	}
	return true;
}

bool plateau::wPawn(int xa, int xd, int ya, int yd){
	if((xd == 6) && (yd == 0)||(xd == 6) && (yd == 1) || (xd == 6) && (yd == 2) || (xd == 6) && (yd == 3) || (xd == 6) && (yd == 4) || (xd == 6) && (yd == 5) || (xd == 6) && (yd == 6) || (xd == 6) && (yd == 7)){
		//DEPLACEMENT PAR 2 CASES EN AVANT AU DEBUT DU TOUR
		if((xa==xd-2) && (ya==yd)){
			if(tj[xd-2][yd]==0){
				return false;
			}
		}else if((xa==xd-1) && (ya==yd)){
			if(tj[xd-1][yd]==0){
				return false;
			}
		}else if((xa==xd-1) && (ya==yd+1)){
			if(tj[xd-1][yd+1]>0){
				return false;
			}
		}else if((xa==xd-1) && (ya==yd-1)){
			if(tj[xd-1][yd-1]>0){
				return false;
			}
		}
	}else if((xa==xd-1) && (ya==yd)){
		if(tj[xd-1][yd]==0 ){
			if(xa==0){
				tj[xd][yd]=-2;
			}
			return false;
		}
	}else if((xa==xd-1) && (ya==yd+1)){
		if(tj[xd-1][yd+1]>0){
			return false;
		}
	}else if((xa==xd-1) && (ya==yd-1)){
		if(tj[xd-1][yd-1]>0){
			return false;
		}
	}
	return true;
}

bool plateau::bRook(int xa, int xd, int ya, int yd){
	for(int i=0; i<8; i++){
		if((xa==xd-i) && (ya==yd)){
			//DEPLACEMENT EN ARRIERE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd+i) && (ya==yd)){
			//DEPLACEMENT EN AVANT
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd) && (ya==yd-i)){
			//DEPLACEMENT A GAUCHE
			int j=yd-1;
			while(j > ya){
				if((tj[xd][j]!=0)){
					return true;
				}
				j--;
			}
//			passant = false;
			return false;
		}else if((xa==xd) && (ya==yd+i)){
			//DEPLACEMENT A DROITE
			int j=yd+1;
			while(j < ya){
				if((tj[xd][j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}
	}
	return true;
}

bool plateau::wRook(int xa, int xd, int ya, int yd){
	for(int i=0; i<8; i++){
		if((xa==xd-i) && (ya==yd)){
			//DEPLACEMENT EN AVANT
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd+i) && (ya==yd)){
			//DEPLACEMENT EN ARRIERE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd) && (ya==yd-i)){
			//DEPLACEMENT A GAUCHE
			int j=yd-1;
			while(j > ya){
				if((tj[xd][j]!=0)){
					return true;
				}
				j--;
			}
//			passant = false;
			return false;
		}else if((xa==xd) && (ya==yd+i)){
			//DEPLACEMENT A DROITE
			int j=yd+1;
			while(j < ya){
				if((tj[xd][j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}
	}
	return true;
}

bool plateau::bKnight(int xa, int xd, int ya, int yd){
	if((xa==xd-2)&&(ya==yd-1)||(xa==xd-1)&&(ya==yd-2)||(xa==xd+1)&&(ya==yd-2)||(xa==xd+2)&&(ya==yd-1)||(xa==xd-2)&&(ya==yd+1)||(xa==xd-1)&&(ya==yd+2)||(xa==xd+1)&&(ya==yd+2)||(xa==xd+2)&&(ya==yd+1))
	{
//		passant = false;
		return false;
	}
	return true;
}

bool plateau::wKnight(int xa, int xd, int ya, int yd){
	if((xa==xd-2)&&(ya==yd-1)||(xa==xd-1)&&(ya==yd-2)||(xa==xd+1)&&(ya==yd-2)||(xa==xd+2)&&(ya==yd-1)||(xa==xd-2)
	&&(ya==yd+1)||(xa==xd-1)&&(ya==yd+2)||(xa==xd+1)&&(ya==yd+2)||(xa==xd+2)&&(ya==yd+1))
	{
		return false;
	}
	return true;
}

bool plateau::bDRAGON(int xa, int xd, int ya, int yd) {
    for(int i=0; i<8; i++){
        if((xa==xd-i) && (ya==yd-i)) {
            // DIAGONALE EN ARRIERE A GAUCHE
            int j=1;
            while(j < xd-xa){
                if((tj[xd-j][yd-j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd-i) && (ya==yd+i)){
            // DIAGONALE EN ARRIERE A DROITE
            int j=1;
            while(j < xd-xa){
                if((tj[xd-j][yd+j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd+i) && (ya==yd+i)){
            // DIAGONALE EN AVANT A DROITE
            int j=1;
            while(j < xa-xd){
                if((tj[xd+j][yd+j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd+i) && (ya==yd-i)){
            // DIAGONALE EN AVANT A GAUCHE
            int j=1;
            while(j < xa-xd){
                if((tj[xd+j][yd-j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd-i) && (ya==yd)){
            // DEPLACEMENT DERRIERE
            int j=1;
            while(j < xd-xa){
                if((tj[xd-j][yd]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd+i) && (ya==yd)){
            // DEPLACEMENT EN AVANT
            int j=1;
            while(j < xa-xd){
                if((tj[xd+j][yd]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd) && (ya==yd-i)){
            // DEPLACEMENT A GAUCHE
            int j=yd-1;
            while(j > ya){
                if((tj[xd][j]!=0)){
                    return true;
                }
                j--;
            }
            return false;
        }
        else if((xa==xd) && (ya==yd+i)){
            // DEPLACEMENT A DROITE
            int j=yd+1;
            while(j < ya){
                if((tj[xd][j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
    }
    return true;
}

bool plateau::bBishop(int xa, int xd, int ya, int yd){
	for(int i=0; i<8; i++){
		if((xa==xd-i) && (ya==yd-i))
		{
			//DIAGONALE EN ARRIERE A GAUCHE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd-j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}else if((xa==xd-i) && (ya==yd+i)){
			//DIAGONALE EN ARRIERE A DROITE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd+j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}else if((xa==xd+i) && (ya==yd+i)){
			//DIAGONALE EN AVANT A DROITE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd+j]!=0)){ 
					return true;
				}
				j++;
			}
			return false;
		}else if((xa==xd+i) && (ya==yd-i)){
			//DIAGONALE EN AVANT A GAUCHE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd-j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}
	}
	return true;
}
bool plateau::wBishop(int xa, int xd, int ya, int yd){
	for(int i=0; i<8; i++){
		if((xa==xd-i) && (ya==yd-i))
		{
			//DIAGONALE EN AVANT A GAUCHE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd-j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}else if((xa==xd-i) && (ya==yd+i)){
			//DIAGONALE EN AVANT A DROITE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd+j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}else if((xa==xd+i) && (ya==yd+i)){
			//DIAGONALE EN ARRIERE A DROITE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd+j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}else if((xa==xd+i) && (ya==yd-i)){
			//DIAGONALE EN ARRIERE A GAUCHE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd-j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}
	}
	return true;
}
bool plateau::bADVANCER(int xa, int xd, int ya, int yd){
    for(int i=0; i<8; i++){
        if((xa==xd-i) && (ya==yd-i)) {
            // DIAGONALE EN ARRIERE A GAUCHE
            int j=1;
            while(j < xd-xa){
                if((tj[xd-j][yd-j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd-i) && (ya==yd+i)){
            // DIAGONALE EN ARRIERE A DROITE
            int j=1;
            while(j < xd-xa){
                if((tj[xd-j][yd+j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd+i) && (ya==yd+i)){
            // DIAGONALE EN AVANT A DROITE
            int j=1;
            while(j < xa-xd){
                if((tj[xd+j][yd+j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd+i) && (ya==yd-i)){
            // DIAGONALE EN AVANT A GAUCHE
            int j=1;
            while(j < xa-xd){
                if((tj[xd+j][yd-j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd-i) && (ya==yd)){
            // DEPLACEMENT DERRIERE
            int j=1;
            while(j < xd-xa){
                if((tj[xd-j][yd]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd+i) && (ya==yd)){
            // DEPLACEMENT EN AVANT
            int j=1;
            while(j < xa-xd){
                if((tj[xd+j][yd]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
        else if((xa==xd) && (ya==yd-i)){
            // DEPLACEMENT A GAUCHE
            int j=yd-1;
            while(j > ya){
                if((tj[xd][j]!=0)){
                    return true;
                }
                j--;
            }
            return false;
        }
        else if((xa==xd) && (ya==yd+i)){
            // DEPLACEMENT A DROITE
            int j=yd+1;
            while(j < ya){
                if((tj[xd][j]!=0)){
                    return true;
                }
                j++;
            }
            return false;
        }
    }
    return true;
}

bool plateau::bQueen(int xa, int xd, int ya, int yd){
	for(int i=0; i<8; i++){
		if((xa==xd-i) && (ya==yd-i))
		{
			//DIAGONALE EN ARRIERE A GAUCHE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd-j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd-i) && (ya==yd+i)){
			//DIAGONALE EN ARRIERE A DROITE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd+i]!=0)){
					return true;
				}
				j++;
			}
//			passant=false;
			return false;
		}else if((xa==xd+i) && (ya==yd+i)){
			//DIAGONALE EN AVANT A DROITE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd+j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd+i) && (ya==yd-i)){
			//DIAGONALE EN AVANT A GAUCHE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd-j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd-i) && (ya==yd)){
			//DEPLACEMENT DERRIERE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd+i) && (ya==yd)){
			//DEPLACEMENT EN AVANT
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd) && (ya==yd-i)){
			//DEPLACEMENT A GAUCHE
			int j=yd-1;
			while(j > ya){
				if((tj[xd][j]!=0)){
					return true;
				}
				j--;
			}
//			passant = false;
			return false;
		}else if((xa==xd) && (ya==yd+i)){
			//DEPLACEMENT A DROITE
			int j=yd+1;
			while(j < ya){
				if((tj[xd][j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}
	}
	return true;
}

bool plateau::wQueen(int xa, int xd, int ya, int yd){
	for(int i=0; i<8; i++){
		if((xa==xd-i) && (ya==yd-i))
		{
			//DIAGONALE EN AVANT A GAUCHE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd-j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}else if((xa==xd-i) && (ya==yd+i)){
			//DIAGONALE EN AVANT A DROITE
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd+j]!=0)){
					return true;
				}
				j++;
			}
			return false;
		}else if((xa==xd+i) && (ya==yd+i)){
			//DIAGONALE EN ARRIERE A DROITE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd+j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd+i) && (ya==yd-i)){
			//DIAGONALE EN ARRIERE A GAUCHE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd-j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd-i) && (ya==yd)){
			//DEPLACEMENT EN AVANT
			int j=1;
			while(j < xd-xa){
				if((tj[xd-j][yd]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd+i) && (ya==yd)){
			//DEPLACEMENT EN ARRIERE
			int j=1;
			while(j < xa-xd){
				if((tj[xd+j][yd]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}else if((xa==xd) && (ya==yd-i)){
			//DEPLACEMENT A GAUCHE
			int j=yd-1;
			while(j > ya){
				if((tj[xd][j]!=0)){
					return true;
				}
				j--;
			}
//			passant = false;
			return false;
		}else if((xa==xd) && (ya==yd+i)){
			//DEPLACEMENT A DROITE
			int j=yd+1;
			while(j < ya){
				if((tj[xd][j]!=0)){
					return true;
				}
				j++;
			}
//			passant = false;
			return false;
		}
	}
	return true;
}

bool plateau::bKing(int xa, int xd, int ya, int yd){
	if((xa==xd+1) && (ya==yd) || (xa==xd-1) && (ya==yd) || (xa==xd+1) && (ya==yd+1) || (xa==xd+1) && (ya==yd-1) || (xa==xd-1)&& (ya==yd-1) || (xa==xd-1)&&(ya==yd+1) || (xa==xd)&& (ya==yd+1) || (xa==xd)&& (ya==yd-1)){
		return false;
	}
	return true;
}

bool plateau::wKing(int xa, int xd, int ya, int yd){
	if((xa==xd+1) && (ya==yd) || (xa==xd-1) && (ya==yd) || (xa==xd+1) && (ya==yd+1) || (xa==xd+1) && (ya==yd-1) || (xa==xd-1)&& (ya==yd-1) || (xa==xd-1)&&(ya==yd+1) || (xa==xd)&& (ya==yd+1) || (xa==xd)&& (ya==yd-1)){
		return false;
	}
	return true;
}

void plateau::setAi(bool Ai){
	this->Ai=Ai;
}

int plateau::compareWeight(int a, int b, int c, int d){
	int fWeight=0,sWeight=0;
	for(int i=1; i<=6; i++){
		if(mWeight[i].pieces[1] == tj[a][b]){
			fWeight = i;
			i=7;
		}
	}
	for(int i=1; i<=6; i++){
		if(mWeight[i].pieces[1] == tj[c][d]){
			sWeight = i;
			i=7;
		}
	}
	if(fWeight > sWeight){
		return 1;
	}else if(fWeight < sWeight){
		return 2;
	}else if(fWeight == sWeight){
		return 3;
	}
}

int plateau::compareAWeight(int a, int b, int c, int d){
	int fWeight=0,sWeight=0;
	for(int i=1; i<=6; i++){
		if(aWeight[i].pieces[0] == tj[a][b]){
			fWeight = i;
			i=7;
		}
	}
	for(int i=1; i<=6; i++){
		if(aWeight[i].pieces[0] == tj[c][d]){
			sWeight = i;
			i=7;
		}
	}
	if(fWeight > sWeight){
		return 1;
	}else if(fWeight < sWeight){
		return 2;
	}else if(fWeight == sWeight){
		return 3;
	}
}

bool plateau::notEliminated(int a,int b){
	for(int i=0; i<ePieces.size(); i++){
		if(ePieces[i].x == a && ePieces[i].y == b){
			return false;
		}
	}
	return true;
}

bool plateau::hasMaxWeight(int a,int b){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(notEliminated(i,j)==true && (i!=a || j!=b) && tj[i][j] < 0){
				if(compareWeight(a,b,i,j) == 2){
					xm=i; ym=j;
					return false;
				}
			}
		}
	}
	return true;
}

bool plateau::hasMaxAWeight(int a,int b){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if((i!=a || j!=b) && tj[i][j] < 0){
				if(compareAWeight(a,b,i,j) == 2){
					xma = i; yma = j;
					return false;
				}
			}
		}
	}
	return true;
}

void plateau::AiPossibleMoves(){
	elPieces e;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(tj[i][j]<0){
				if(compareWeight(xm,ym,i,j) > 1){
					xm=i; ym=j;
					if(hasMaxWeight(i,j)){
						pMoves.clear();
						possibleMoves(i,j);
						if(pMoves.empty()){
							continue; 
						}else{
							xAi = i; yAi = j;
							i=9; j=9;
						}
					}
				}
			}
		}	
	}
}

void plateau::AiPossibleAttacks(){
	poAttacks a;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(tj[i][j]<0){
				pMoves.clear();
				possibleMoves(i,j);
				for(int k=0; k<pMoves.size(); k++){
					if(tj[pMoves[k].x][pMoves[k].y] > 0){
						a.xa = pMoves[k].x; a.ya= pMoves[k].y;
						a.xd = i; a.yd = j;
						pAttacks.push_back(a);
					}
				}
			}
		}	
	}
}

void plateau::possibleMoves(int xd,int yd){
	poMoves m; int i,j;
	if(tj[xd][yd]<0){
		switch(tj[xd][yd]){
			case -1 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!wPawn(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case -2 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!wBishop(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case -3 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!wKing(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case -4 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!wQueen(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case -5 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!wKnight(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case -6 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!wRook(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
		}
	}else if(tj[xd][yd]>0){
		switch(tj[xd][yd]){
			case 1 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(tj[k][l]<=0){	
							if(!bPawn(k,xd,l,yd)){
								m.x = k; m.y = l;
								pMoves.push_back(m);
							}
						}
					}
				}
				break;
			case 2 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!bBishop(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case 3 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!bKing(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case 4 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!bQueen(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case 5 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!bKnight(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case 6 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!bRook(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case 7 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!bQueen(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
			case 8 :
				for(int k=0; k<8; k++){
					for(int l=0; l<8; l++){
						if(!bBishop(k,xd,l,yd)){
							m.x = k; m.y = l;
							pMoves.push_back(m);
						}
					}
				}
				break;
		}
	}
}

bool plateau::Mov(int xa,int xd,int ya,int yd){
	switch(tj[xd][yd]){
		case 1 : return bPawn(xa,xd,ya,yd);break;
		case 2 : return bBishop(xa,xd,ya,yd);break;
		case 3 : return bKing(xa,xd,ya,yd);break;
		case 4 : return bQueen(xa,xd,ya,yd);break;
		case 5 : return bKnight(xa,xd,ya,yd);break;
		case 6 : return bRook(xa,xd,ya,yd);break;
		case -1 : return wPawn(xa,xd,ya,yd);break;
		case -2 : return wBishop(xa,xd,ya,yd);break;
		case -3 : return wKing(xa,xd,ya,yd);break;
		case -4 : return wQueen(xa,xd,ya,yd);break;
		case -5 : return wKnight(xa,xd,ya,yd);break;
		case -6 : return wRook(xa,xd,ya,yd);break;
		//advanver
		case 7 : return bADVANCER(xa,xd,ya,yd);break;
		//dragon
		case 8 : return bDRAGON(xa,xd,ya,yd);break;
	}
}

int plateau::Path(int kx, int ky, int a, int b){
	int cp=0;
	for(int i=kx; i<=7; i++){
		for(int j=ky; j<=7; j++){
			if(i==a && j==b){
				return cp;
			}
			cp++;
		}
	}
	return -1;
} 

void plateau::AiPlay(){
	int kx, ky; int tj2[8][8]; int p; int cp=0;
	bool M=true;
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			if(tj[i][j]==-3){
				kx=i; ky=j;
			}
		}
	}
	M=Check('B',kx,ky);
	if(M==true){
		for(int i=0; i<=7; i++){
			for(int j=0; j<=7; j++){
				if(tj[i][j]<0 && tj[i][j]!=-3){
					pMoves.clear();
					possibleMoves(i,j);
					for(int x=0; x<pMoves.size(); x++){
						for(int k=0; k<=7; k++){
							for(int l=0; l<=7; l++){
								tj2[k][l]=tj[k][l];
							}
						}
						if(!Mov(pMoves[x].x,i,pMoves[x].y,j)){
							sleep(1);
							tj[pMoves[x].x][pMoves[x].y]=tj[i][j];
							tj[i][j]=0;
						}
						bool m=Check('B',kx,ky);
						if(m==false){
							return;
						}else{
							for(int k=0; k<=7; k++){
								for(int l=0; l<=7; l++){
									tj[k][l]=tj2[k][l];
								}
							}
						}
					}
				}
			}
		}
	}else{
		pAttacks.clear();
		AiPossibleAttacks();
		if(!pAttacks.empty()){
			if(pAttacks.size()==1){
				sleep(1);
				tj[pAttacks[0].xa][pAttacks[0].ya]=tj[pAttacks[0].xd][pAttacks[0].yd];
				tj[pAttacks[0].xd][pAttacks[0].yd]=0;
				return;
			}
			for(int i=0; i<pAttacks.size(); i++){
				if(hasMaxAWeight(pAttacks[i].xa,pAttacks[i].ya) && hasMaxWeight(pAttacks[i].xd,pAttacks[i].yd)){
					sleep(1);
					tj[pAttacks[i].xa][pAttacks[i].ya]=tj[pAttacks[i].xd][pAttacks[i].yd];
					tj[pAttacks[i].xd][pAttacks[i].yd]=0;
					return; //care
				}
			}
		}else{
			pMoves.clear();
			AiPossibleMoves();
			for(int i=0; i<=7; i++){
				for(int j=0; j<=7; j++){
					if(tj[i][j]==3){
						kx=i; ky=j;
					}
				}
			}
			int min=Path(kx,ky,pMoves[0].x,pMoves[0].y);
			if(min==-1){
				sleep(1);			
				tj[pMoves[0].x][pMoves[0].y]=tj[xAi][yAi];
				tj[xAi][yAi]=0;
				return;
			}
			for(int p=1; p<pMoves.size(); p++){
				int x=Path(kx,ky,pMoves[p].x,pMoves[p].y);
				if(x<min){
					min=x;
				}
			}
			sleep(1);
			tj[pMoves[min].x][pMoves[min].y]=tj[xAi][yAi];
			tj[xAi][yAi]=0;
			pMoves.clear();
			xm=0; ym=0;
		}
	}
}

bool plateau::Check(char joueur,int xa,int ya){
	for (int i=0; i<=7; i++){
		for (int j=0; j<=7; j++){
			if(joueur=='N'){
				if(tj[i][j]==-1)
				{
					if(wPawn(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==-2){
					if(wBishop(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==-3){
					if(wKing(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==-4){
					if(wQueen(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==-5){
					if(wKnight(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==-6){
					if(wRook(xa,i,ya,j)==false)
					{
						return true;
					}
				}
			}else if(joueur=='B'){
				if(tj[i][j]==1)
				{
					if(bPawn(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==2){
					if(bBishop(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==3){
					if(bKing(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==4){
					if(bQueen(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==5){
					if(bKnight(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==6){
					if(bRook(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==7){
					if(bADVANCER(xa,i,ya,j)==false)
					{
						return true;
					}
				}else if(tj[i][j]==8){
					if(bDRAGON(xa,i,ya,j)==false)
					{
						return true;
					}
				}
			}
		}
	}		
	return false;
}

void plateau::CheckSetup(char joueur,int nx, int ny,int& cp){
	int tj2[8][8];
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			if(joueur=='N'){
				if(tj[i][j]>0 && tj[i][j]!=3){
					pMoves.clear();
					possibleMoves(i,j);
					for(int x=0; x<pMoves.size(); x++){
						for(int k=0; k<=7; k++){
							for(int l=0; l<=7; l++){
								tj2[k][l]=tj[k][l];
							}
						}
						if(!Mov(pMoves[x].x,i,pMoves[x].y,j)){
							tj[pMoves[x].x][pMoves[x].y]=tj[i][j];
							tj[i][j]=0;
						}
						bool m=Check('N',nx,ny);
						if(m==false){
							cp++;
						}
						for(int k=0; k<=7; k++){
							for(int l=0; l<=7; l++){
								tj[k][l]=tj2[k][l];
							}
						}
					}
				}
			}else if(joueur=='B'){
				if(tj[i][j]<0 && tj[i][j]!=-3){
					pMoves.clear();
					possibleMoves(i,j);
					for(int x=0; x<pMoves.size(); x++){
						for(int k=0; k<=7; k++){
							for(int l=0; l<=7; l++){
								tj2[k][l]=tj[k][l];
							}
						}
						if(!Mov(pMoves[x].x,i,pMoves[x].y,j)){
							tj[pMoves[x].x][pMoves[x].y]=tj[i][j];
							tj[i][j]=0;
						}
						bool m=Check('B',nx,ny);
						if(m==false){
							cp++;
						}
						for(int k=0; k<=7; k++){
							for(int l=0; l<=7; l++){
								tj[k][l]=tj2[k][l];
							}
						}
					}
				}
			}
		}
	}
}

bool plateau::CheckMate(char joueur){
	int nx,ny,cp=0;
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			if(joueur=='N'){
				if(tj[i][j]==3){
					nx=i;
					ny=j;
					i=8;
					j=8;
				}
			}else if(joueur=='B'){
				if(tj[i][j]==-3){
					nx=i;
					ny=j;
					j=8;
				}
			}
		}
	}
	int tj2[8][8];
	if(Check(joueur,nx,ny)){
		CheckSetup(joueur,nx,ny,cp);
		if(cp<2){
			return true;
		}
	}
	return false;
}

void plateau::mvPiece(char joueur)
{
	bool k=false;
	int xd,yd,ya,xa; bool M=true;
	int nx,ny; int tj2[8][8];
	do{
		inputStart(xd,yd,joueur);
		inputArrival(xa,ya,joueur);
		if(joueur =='N'){
			if(tj[xd][yd]==3){
				M=Check(joueur,xd,yd);
				nx = xd; ny = yd;
				k=true;
			}else{
				for(int i=0;i<=7;i++)
				{
					for(int j=0;j<=7;j++)
					{
						if(tj[i][j]==3){
							nx=i;
							ny=j;
							i=8;
							j=8;
						}
					}
				}
				M=Check(joueur, nx, ny);
			}
		}else if(joueur =='B'){
			if(tj[xd][yd]==-3){
				M=Check(joueur,xd,yd);
				nx=xd; ny=yd;
				k=true;
			}else{
				for(int i=0;i<=7;i++)
				{
					for(int j=0;j<=7;j++)
					{
						if(tj[i][j]==-3){
							nx=i;
							ny=j;
							i=8;
							j=8;
						}
					}
				}
				M=Check(joueur, nx, ny);
			}
		}
		if(M==true){
			
			for(int i=0; i<8; i++){
				for(int j=0; j<8; j++){
					tj2[i][j]=tj[i][j];
				}
			}
			if(!Mov(xa,xd,ya,yd)){
				tj[xa][ya]=tj[xd][yd];
				tj[xd][yd]=0;
			}
			if(k){
				nx=xa; ny=ya;
			}
			bool x=Check(joueur, nx, ny);
			if(x==false){
				M=x;
			}
			for(int i=0; i<8; i++){
				for(int j=0; j<8; j++){
					tj[i][j]=tj2[i][j];
				}
			}
		}
	}while(Mov(xa,xd,ya,yd)==true || M==true);
	tj[xa][ya]=tj[xd][yd];
	tj[xd][yd]=0;
}



