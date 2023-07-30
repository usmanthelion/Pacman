#include "mygraphics.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <time.h>
using namespace std;

char mapArr[22][56] = {         {"#######################################################"},
								{"#************************** #     ****************    #"},
								{"#************************** #                         #"},
								{"#*** ##################**** #    ##################   #"},
								{"#    ##################*****#****##################   #"},
								{"#                           # ****                    #"},
								{"#                           #                         #"},
								{"#                           #                         #"},
								{"################                       ################"},
								{"o              **************************             o"},
								{"################                       ################"},
								{"#                                                     #"},
								{"#***************************                          #"},
								{"#**************************                           #"},
								{"#                           #                         #"},
								{"#                           #*************************#"},
								{"#                           #*************************#"},
								{"#                           #*************************#"},
								{"#***************************#                         #"},
								{"#                           #                         #"},
								{"#                           #                         #"},
								{"#######################################################"} };


class map
{
private:
	//boundary coordinates

	int top1x, top1y;
	int top2x, top2y;
	int bot1x, bot1y; // rix, riy, lix, liy;
	int bot2x, bot2y;
	//stats
	int score;
	int lives;
	int mx, my;

public:


	map()
	{
		top1x = 0;
		top1y = 0;
		top2x = 0; top2y = 0;
		bot1x = 0; bot1y = 0; // rix, riy, lix, liy;
		bot2x = 0; bot2y = 0;
		score = 0;
		lives = 3;
		mx = 0;
		my = 0;
	}


	map(int t1x, int t1y, int t2x, int t2y, int b1x, int b1y, int b2x, int b2y, int l, int s)
	{
		// top points 
		top1x = t1x;
		top1y = t1y;
		top2x = t2x;
		top2y = t2y;
		// bottom points

		bot1x = b1x;
		bot1y = b1y;
		bot2x = b2x;
		bot2y = b2y;
		//score and lives of the player
		score = s;
		lives = l;
	}

	void setMap(int t1x, int t1y, int t2x, int t2y, int b1x, int b1y, int b2x, int b2y, int l, int s)
	{
		top1x = t1x;
		top1y = t1y;
		top2x = t2x;
		top2y = t2y;
		// bottom points

		bot1x = b1x;
		bot1y = b1y;
		bot2x = b2x;
		bot2y = b2y;
		//score and lives of the player
		score = s;
		lives = l;
	}
	void displayBoundary()
	{
		//boundaries
		drawLine(top1x, top1y, top2x, top2y, 0, 0, 255); //top
		drawLine(bot1x, bot1y, bot2x, bot2y, 0, 0, 255); //bottom
		drawLine(top1x, top1y, bot1x, bot1y, 0, 0, 255); //left
		drawLine(top2x, top2y, bot2x, bot2y, 0, 0, 255); //right


	}
	void displayObs()               //obstacles
	{
		int ob1x = (((top2x - top1x) / 2) / 2) + top1x;
		//y1 // (top)
		int y = top1y + 120;

		int ob2x = (((top2x - top1x) / 2) / 2) + top1x;
		int ob1y = top1y;
		//mid obs
		drawLine(((top2x - top1x) / 2) + top1x + 5, top1y, ((top2x - top1x) / 2) + top1x + 5, top1y + 150, 0, 0, 255);
		drawLine(((bot2x - bot1x) / 2) + bot1x + 5, bot1y, ((bot2x - bot1x) / 2) + bot1x + 5, bot1y - 150, 0, 0, 255);
		//other
		int ob3y = 329;

		drawLine(top1x, 288, top1x + 150, 288, 0, 0, 255);
		drawLine(top1x, ob3y, top1x + 150, ob3y, 0, 0, 255);
		drawLine(top1x, 288, top1x, ob3y, 0, 0, 0);

		drawLine(top2x, 288, top2x - 150, 288, 0, 0, 255);
		drawLine(top2x, ob3y, top2x - 150, ob3y, 0, 0, 255);
		drawLine(top2x, 288, top2x, ob3y, 0, 0, 0);
		int rx1 = 575, rx2 = 735, ry1 = 185, ry2 = 214;

		drawRectangle(rx1, ry1, rx2, ry2, 0, 0, 255);

		drawRectangle(rx1 + 255, ry1, rx2 + 255, ry2, 0, 0, 255);


	}

	void drawEner()
	{
		drawEllipse(1010 + 0, 300 + 0, 1010 + 15, 300 + 15, 0, 255, 0, 0, 255, 0);
		drawEllipse(540 + 0, 300 + 0, 540 + 15, 300 + 15, 0, 255, 0, 0, 255, 0);
	}
	void displayMapArr(int MX, int MY)
	{
		mx = MX;
		my = MY;
		gotoxy(mx, my);


		gotoxy(mx, my);
		int k = 6;
		for (int i = 0; i < 22; i++)
		{
			gotoxy(59, k);
			for (int j = 0; j < 56; j++)
			{

				cout << mapArr[i][j];
			}
			k++;
			cout << endl;
		}

	}
	void setScore(int n)
	{
		score = n;
	}
	int getmx()
	{
		return mx;
	}

	int getmy()
	{
		return my;
	}
	int getScore()
	{
		return score;
	}

	void displayFood()
	{
		int ix = 1, iy = 1;


		//graphic food
		int addx = 5, addy = 16;

		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 53; j++)
			{

				if (mapArr[i + 1][j + 1] == '*')
				{
					drawEllipse(top1x + addx, top1y + addy, top1x + 9 + addx, top1y + 9 + addy, 0, 0, 0, 255, 182, 193);
				}


				addx += 9;

			}
			addx = 5;
			addy += 20;
		}


	}

	int getLives()
	{
		return lives;
	}

	void setLives(int x)
	{
		lives = x;
	}

	/*void operator+(int n)
	{
		this->score = this->score + n;
	}

	void operator--()
	{
		this->score = this->score - 5;
	}*/

	void displayStats()
	{
		gotoxy(59, 0);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(h, 9);

		cout << "SCORE : ";
		cout << score << endl;

		//score
		gotoxy(59, 1);
		cout << "LIVES : ";
		cout << lives << endl;;

		SetConsoleTextAttribute(h, 14);
		gotoxy(80, 3);
		cout << "STATUS : ";
		if (score == 269)
		{
			cout << "You Won" << endl;
			exit(0);
		}
		else
		{
			cout << "IN-GAME " << endl;
		}
		//number of lives left
	}

	void displayeStats()
	{
		gotoxy(59, 0);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(h, 9);

		cout << "SCORE : ";
		cout << score << endl;

		//score
		gotoxy(59, 1);
		cout << "LIVES : ";
		cout << lives << endl;

		SetConsoleTextAttribute(h, 14);
		gotoxy(80, 3);
		cout << "STATUS : ";
		cout << "You Lost" << endl;
		//number of lives left
	}

	~map()
	{

	}
};



class PacMan : public map
{
private:

	int pmx, pmy;
	int s;
	int px;
	int py;

public:


	PacMan()
	{
		px = 0;
		py = 0;
		pmx = 1;
		pmy = 1;
		s = 0;

	}
	void setpx(int px) {

		this->px = px;
	}

	void setpy(int py) {

		this->py = py;
	}

	PacMan(int x, int y)
	{
		s = 0;
		px = x;
		py = y;
		pmx = 1;
		pmy = 1;
	}
	void setpacman(int x, int y)
	{
		s = 0;
		px = x;
		py = y;
		pmx = 1;
		pmy = 1;
	}


	void DrawPacMan()
	{

		int w = 0;
		drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 255, 255, 0);
		delay(10);
		drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 0, 0, 0);



	}


	void MovePacman(char c)
	{

		if (c == 'q')
		{
			px = 0;
		}

		if (c == 'a' && mapArr[pmx][pmy - 1] != '#')
		{
			drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 0, 0, 0);
			px -= 9;
			pmy--;
			if (mapArr[pmx][pmy] == '*')
			{
				// '*' represents food 
				// score calculatiion
				s++;
				setScore(s);
				mapArr[pmx][pmy] = ' ';//eaten food removed
			}
			drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 255, 255, 0);

		}

		if (c == 'd' && mapArr[pmx][pmy + 1] != '#')
		{
			drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 0, 0, 0);
			px += 9;
			pmy++;
			if (mapArr[pmx][pmy] == '*')
			{
				//score 
				s++;
				setScore(s);
				mapArr[pmx][pmy] = ' ';//eaten food removed
			}
			//DrawPacMan();
			drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 255, 255, 0);
		}

		if (c == 's' && mapArr[pmx + 1][pmy] != '#')
		{
			drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 0, 0, 0);
			py += 20;
			pmx++;
			if (mapArr[pmx][pmy] == '*')
			{
				s++;
				setScore(s);
				mapArr[pmx][pmy] = ' ';
			}
			//DrawPacMan();
			drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 255, 255, 0);
		}

		if (c == 'w' && mapArr[pmx - 1][pmy] != '#')
		{
			drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 0, 0, 0);
			py -= 20;
			pmx--;
			if (mapArr[pmx][pmy] == '*')
			{
				s++;
				setScore(s);
				mapArr[pmx][pmy] = ' ';
			}
			drawEllipse(px + 0, py + 0, px + 20, py + 20, 0, 0, 0, 255, 255, 0);
			//	DrawPacMan();
		}


	}

	void operator+(int n)
	{
		setScore(getScore() + n);
	}

	void operator-(int n)
	{
		setScore(getScore() - n);
	}
	int getpmx()
	{
		return pmx;
	}
	int getpmy()
	{
		return pmy;
	}

	int getpx()
	{
		return px;
	}
	int getpy()
	{
		return py;
	}


	~PacMan()
	{

	}

};

class randomGhost : public map
{
private:
	int rpx;
	int rpy;
	int pmx;
	int pmy;

public:
	randomGhost()
	{

		rpx = 550;
		rpy = 200;
		pmx = 1;
		pmy = 1;
	}


	void setGhost(int x, int y)
	{
		rpx = x;
		rpy = y;
	}

	void drawG()
	{

		drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 237, 28, 36);
		delay(10);
		drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 0, 0, 0);
	}

	void drawGhost()
	{

		srand(time(0));
		int rndm = (rand() % 4) + 1;


		//char rndm = getKey(); 
		if (rndm == 1 && mapArr[pmx][pmy - 1] != '#')
		{
			drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 0, 0, 0);

			rpx -= 9; //left
			pmy--;

			drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 237, 28, 36);
		}

		if (rndm == 2 && mapArr[pmx][pmy + 1] != '#')
		{
			drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 0, 0, 0);

			rpx += 9; //right
			pmy++;
			drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 237, 28, 36);
		}

		if (rndm == 3 && mapArr[pmx + 1][pmy] != '#')
		{
			drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 0, 0, 0);

			rpy += 20;//bottom
			pmx++;
			drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 237, 28, 36);
		}

		if (rndm == 4 && mapArr[pmx - 1][pmy] != '#')
		{
			drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 0, 0, 0);

			rpy -= 20; //top
			pmx--;
			drawRectangle(rpx + 0, rpy + 0, rpx + 20, rpy + 20, 0, 0, 0, 237, 28, 36);
		}
	}

	int getrpx()
	{
		return rpx;
	}
	int getrpy()
	{
		return rpy;
	}

};

class chaseGhost : public PacMan
{
private:
	//Chase Coordinates
	int gpx;
	int gpy;
	// Pacman Coordinates
	int pacx;
	int pacy;
	int pmmx;
	int pmmy;

public:
	chaseGhost()
	{

		gpx = 546;
		gpy = 521;
		pacx = 0;
		pacy = 0;
		pmmx = 0;
		pmmy = 0;
	}

	void drawGhost(int x, int y, int ppx, int ppy)
	{

		pacx = x;
		pacy = y;
		pmmx = ppx;
		pmmy = ppy;
	}

	void setGhost(int x, int y)
	{
		gpx = x;
		gpy = y;
	}

	void drawGhost()
	{

		int xi = gpx;
		int yi = gpy;




		if (gpx < pacx)
		{
			for (int i = 0; i <= 8; i++)
			{ //move right
				drawRectangle(gpx, gpy, gpx + 20, gpy + 20, 0, 0, 0, 0, 255, 255);
				delay(1);

				gpx++;
			}
		}

		if (gpx > pacx)
		{
			if (gpx <= 0)
			{
				//move left
				for (int i = 8; i >= 0; i--)
				{
					drawRectangle(gpx, gpy, gpx + 20, gpy + 20, 0, 0, 0, 0, 255, 255);
					delay(1);

					gpx--;
				}
			}
			else
			{

				for (int i = 8; i >= 0; i--)
				{
					drawRectangle(gpx, gpy, gpx + 20, gpy + 20, 0, 0, 0, 0, 255, 255);
					delay(1);

					gpx--;
				}
			}
		}

		if (gpy < pacy)
		{
			for (int i = 0; i <= 8; i++)
			{
				drawRectangle(gpx, gpy, gpx + 20, gpy + 20, 0, 0, 0, 0, 255, 255); //move bottom
				delay(1);

				gpy++;
			}
		}

		if (gpy > pacy)
		{
			if (gpy <= 0)
			{
				int c = gpy;
				for (int i = 8; i >= 0; i--)
				{
					drawRectangle(gpx, gpy, gpx + 20, gpy + 20, 0, 0, 0, 0, 255, 255); //move top
					delay(1);

					gpy--;
				}
			}
			else
			{
				int c = gpy;
				for (int i = 8; i >= 0; i--)
				{
					drawRectangle(gpx, gpy, gpx + 20, gpy + 20, 0, 0, 0, 0, 255, 255);
					delay(1);

					gpy--;
				}
			}
		}

		/*if (pmmx == 9 && pmmy == 53) {

			cout << "yes" << endl;

			int c = gpx;
			for (int i = c; i > 537; i--) {

				drawRectangle(gpx, gpy, gpx + 20, gpy + 20, 0, 0, 0, 0, 255, 255);
				gpx--;
			}
			int p = gpy;
			for (int i = p; i > 141;i--) {

				drawRectangle(gpx, gpy, gpx + 20, gpy + 20, 0, 0, 0, 0, 255, 255);
				gpy--;
			}
		}*/


	}

	int getgpx()
	{
		return gpx;
	}

	int getgpy()
	{
		return gpy;
	}

	~chaseGhost()
	{

	}
};


bool checkEnergizer(int a, int b)
{
	if (a == 9 && b == 53 || a == 9 && b == 2)
	{
		if (mapArr[a][b] == 'o')
		{
			mapArr[a][b] == ' ';
			return true;
		}
		else
			return false;
	}
	else
	{
		return false;
	}
}

int main() {

	//// Initialising
	int w = 0, h = 0;
	getWindowDimensions(w, h);

	cls();
	showConsoleCursor(false);


	map M(535, 125, 1030, 125, 535, 555, 1030, 555, 3, 0);
	PacMan P(537, 141);
	P.setMap(535, 125, 1030, 125, 535, 555, 1030, 555, 3, 0);
	randomGhost G1;
	chaseGhost G2;

	int i = 0, j = 0;

	M.drawEner();
	while (true)
	{
		//Map
		M.displayBoundary();
		M.displayObs();
		M.displayFood();
		P.displayStats();
		//Spirits
		P.MovePacman(getKey());
		G1.drawGhost();
		G2.drawGhost(P.getpx(), P.getpy(), P.getpmx(), P.getpmy());
		G2.drawGhost();

		//check for chase Ghost
		if (((P.getpx() == G2.getgpx()) && (P.getpy() - 5 <= G2.getgpy() && G2.getgpy() <= P.getpy())))
		{
			drawEllipse(P.getpx(), P.getpy(), P.getpx() + 20, P.getpy() + 20, 0, 0, 0, 0, 0, 0);//printing blank
			P.setLives(P.getLives() - 1);
			//setting  pacman at start
			P.setpacman(537, 141);
			//setting the ghost to prev position
			drawRectangle(G2.getgpx(), G2.getgpy(), G2.getgpx() + 20, G2.getgpy() + 20, 0, 0, 0, 0, 0, 0);
			G2.setGhost(546, 521);
			
			if (P.getLives() == 0)
			{
				cls();
				P.displayeStats();
				cout << "GAME ENDED!" << endl;
				delay(1000);
				exit(0);
			}
			M.drawEner();
			mapArr[9][53] = 'o';
			mapArr[9][2] = 'o';
			P - 5;

		}

		if (((P.getpx() - 5 == G1.getrpx()) && (P.getpy() - 5 <= G1.getrpy() && G1.getrpy() <= P.getpy())))
		{

			drawEllipse(P.getpx(), P.getpy(), P.getpx() + 20, P.getpy() + 20, 0, 0, 0, 0, 0, 0); //printing blank
			P.setLives(P.getLives() - 1);
			//setting  pacman at start
			P.setpacman(537, 141);
			//setting the ghost to prev position
			drawRectangle(G1.getrpx(), G1.getrpy(), G1.getrpx() + 20, G1.getrpy() + 20, 0, 0, 0, 0, 0, 0);
			G1.setGhost(546, 521);
			

			if (P.getLives() == 0)
			{
				cls();
				P.displayeStats();
				cout << "Game Ended!" << endl;
				delay(1000);
				exit(0);
			}
			M.drawEner();
			mapArr[9][53] = 'o';
			mapArr[9][2] = 'o';
			P - 5;

		}


		if (checkEnergizer(P.getpmx(), P.getpmy()))
		{

			P + 5;
			drawRectangle(G2.getgpx(), G2.getgpy(), G2.getgpx() + 20, G2.getgpy() + 20, 0, 0, 0, 0, 0, 0);
			G2.setGhost(0, 0);
			drawRectangle(G1.getrpx(), G1.getrpy(), G1.getrpx() + 20, G1.getrpy() + 20, 0, 0, 0, 0, 0, 0);
			G1.setGhost(537, 141);
		}





		gotoxy(0, 4);
		cout << P.getpx() << " " << P.getpy() << " " << G2.getgpx() << " " << G2.getgpy();
		gotoxy(0, 5);
		cout << P.getpx() << " " << P.getpy() << " " << G1.getrpx() << " " << G1.getrpy();


	}

	system("mode 650");
	system("pause");
	return 0;
}
