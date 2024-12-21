#ifndef PLATEAU_H
#define PLATEAU_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <conio.h>
using namespace std;

struct moveDepth{
	int pieces[8];
};

struct attackDepth{
	int pieces[8];
};

struct poMoves{
	int x;
	int y;
};

struct poAttacks{
	int xd;
	int yd;
	int xa; 
	int ya;
};

struct elPieces{
	int x;
	int y;
};

class plateau
{
	public:
		plateau();
		void showBoard();
		~plateau();
		bool endGame();
		void mvPiece(char);
		bool Pat(char);
		bool Check(char,int,int);
		void CheckSetup(char,int,int,int&);
		int Path(int,int,int,int);
		bool CheckMate(char);
		void setAi(bool);
		void inputStart(int&,int&,char);
		void inputArrival(int&,int&,char);
		bool Mov(int,int,int,int);
		bool bBishop(int,int,int,int);
		bool wBishop(int,int,int,int);
		bool wKing(int,int,int,int);
		bool bKing(int,int,int,int);
		bool bKnight(int,int,int,int);
		bool wKnight(int,int,int,int);
		bool bPawn(int,int,int,int);
		bool wPawn(int,int,int,int);
		bool bRook(int,int,int,int);
		bool wRook(int,int,int,int);
		bool bADVANCER(int,int,int,int);
		bool bDRAGON(int,int,int,int);
		bool bQueen(int,int,int,int);
		bool wQueen(int,int,int,int);
		bool canDefend(char,int,int);
		bool possibleMoves(char,int,int);
		void moveAI(int,int,int,int);
		bool notEliminated(int,int);
		void AiPossibleMoves();
		void AiPossibleAttacks();
		void possibleMoves(int,int);
		int compareWeight(int,int,int,int);
		int compareAWeight(int,int,int,int);
		bool hasMaxWeight(int,int);
		bool hasMaxAWeight(int,int);
		void CopyBoard(int,int);
		void AiPlay();
	private:
		int tj[8][8];
		moveDepth mWeight[8]; attackDepth aWeight[8]; vector<poMoves> pMoves; vector<elPieces> ePieces; vector<poAttacks> pAttacks;
		int xAi, yAi;
		bool Ai;
		int xm,ym,xma,yma;
};

#endif



