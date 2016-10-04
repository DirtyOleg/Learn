#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Plane
{
protected:
	char map[9];  //include the sign that each point in this 3x3 table. if no one have chosen the point, it will output the order number, or conputer(X), Player(@)
	int mapvalue[9];// store two value. 1 means have not been chosen; 0 means already been chosen
	int mapleft;//how many point not be chosen

public:

	Plane() {
		
	for (int i = 0; i < 9; i++)
		{
			map[i] = (char)(i + 49);
		}

		for (int j = 0; j < 9; j++)
		{
			mapvalue[j] = 1;
		}
		mapleft = 9;
		}

	virtual void drawmap() {}	//draw map

	void move(int who)
	{
		switch (who)
		{
		case 0:  //computer 
		{

			int *whichcomputerchose = new int[mapleft];
			int index = 0;

			for (int i = 0; i < 9; i++) //get a arrey of points, which not be chosen
			{
				if (this->mapvalue[i] == 1)
				{
					whichcomputerchose[index] = i;
					index++;
				}
			}

			srand(time(NULL));
			int choose = (rand() % (this->mapleft));


			this->map[whichcomputerchose[choose]] = (char)88;
			this->mapvalue[whichcomputerchose[choose]] = 0;

			delete[] whichcomputerchose;

			break;
		}


		case 1:  //player

			int input;
			cout << "input your choice" << endl;
			cin >> input;

			bool b = true;

			while (b)
			{
				while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6 && input != 7 && input != 8 && input != 9)
				{
					cout << "wrong input, please try again" << endl;
					cin >> input;
				}

				if (this->mapvalue[input - 1] == 1)
				{
					this->map[input - 1] = (char)64;
					this->mapvalue[input - 1] = 0;
					b = false;
				}
				else
				{
					cout << "the point already been choosen, please try again" << endl;
					cin >> input;
				}

			}

			break;
		}
	}
	void MapLeftRudece()
	{
		this->mapleft -= 1;
	}
	int MapLeftGet()
	{
		return this->mapleft;
	}
	char MapGet(int i)
	{
		return (char)this->map[i];
	}

};

class FirstPlane :public Plane
{

public:

	FirstPlane()
	{
	}

	void drawmap() override
	{
		cout << '\t' << map[0] << "  (1)\t" << "|" << '\t' << map[1] << "  (2)\t" << "|" << '\t' << map[2] << "  (3)\t" << "|" << endl;
		cout << "1st\t" << map[3] << "  (4)\t" << "|" << '\t' << map[4] << "  (5)\t" << "|" << '\t' << map[5] << "  (6)\t" << "|" << endl;
		cout << '\t' << map[6] << "  (7)\t" << "|" << '\t' << map[7] << "  (8)\t" << "|" << '\t' << map[8] << "  (9)\t" << "|" << endl << endl;
	}

};

class SecondPlane :public Plane
{
public:

	SecondPlane()
	{
		
	}

	void drawmap() override
	{
		cout << '\t' << map[0] << "  (1)\t" << "|" << '\t' << map[1] << "  (2)\t" << "|" << '\t' << map[2] << "  (3)\t" << "|" << endl;
		cout << "2nd\t" << map[3] << "  (4)\t" << "|" << '\t' << map[4] << "  (5)\t" << "|" << '\t' << map[5] << "  (6)\t" << "|" << endl;
		cout << '\t' << map[6] << "  (7)\t" << "|" << '\t' << map[7] << "  (8)\t" << "|" << '\t' << map[8] << "  (9)\t" << "|" << endl << endl;
	}

};

class ThirdPlane :public Plane
{
public:

	ThirdPlane()
	{
	}

	void drawmap() override
	{
		cout << '\t' << map[0] << "  (1)\t" << "|" << '\t' << map[1] << "  (2)\t" << "|" << '\t' << map[2] << "  (3)\t" << "|" << endl;
		cout << "3th\t" << map[3] << "  (4)\t" << "|" << '\t' << map[4] << "  (5)\t" << "|" << '\t' << map[5] << "  (6)\t" << "|" << endl;
		cout << '\t' << map[6] << "  (7)\t" << "|" << '\t' << map[7] << "  (8)\t" << "|" << '\t' << map[8] << "  (9)\t" << "|" << endl << endl;
	}
};

int win(int, FirstPlane, SecondPlane, ThirdPlane);
void move(int, FirstPlane*, SecondPlane*, ThirdPlane*);
void printresult(int, FirstPlane, SecondPlane, ThirdPlane); // print who win

int main()
{
	srand(time(NULL));
	int first = (rand() % 2); //random number to choose who go first, 0 is computer, 1 is player

	if (first == 0)
	{
		cout << "Computer go first" << endl << endl;
		system("pause");
	}
	else
	{
		cout << "Player go first" << endl << endl;
		system("pause");
	}

	FirstPlane *fp = new FirstPlane();
	SecondPlane *sp = new SecondPlane();
	ThirdPlane *tp = new ThirdPlane();

	while (1)
	{
		move(first, fp, sp, tp);
		if (fp->MapLeftGet() > 0 || sp->MapLeftGet() > 0 || tp->MapLeftGet() > 0)
		{
			move(1 - first, fp, sp, tp);
		}
		else
		{
			break;
		}

	}

	printresult(first, *fp, *sp, *tp);
	system("pause");
}

int win(int who, FirstPlane fp, SecondPlane sp, ThirdPlane tp) // check many score have alreafy got
{

	char checksign;
	if (who == 1)
	{
		checksign = (char)64;
	}
	else
	{
		checksign = (char)88;
	}

	int score = 0;


	if (fp.MapGet(0) == checksign && fp.MapGet(1) == checksign && fp.MapGet(2) == checksign)
	{
		score += 1;
		cout << "first plane NO.1, first plane NO.2, first plane NO.3" << endl;

	}

	if (fp.MapGet(3) == checksign && fp.MapGet(4) == checksign && fp.MapGet(5) == checksign)
	{
		score += 1;

		cout << "first plane NO.4, first plane NO.5, first plane NO.6" << endl;
	}
	if (fp.MapGet(6) == checksign && fp.MapGet(7) == checksign && fp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "first plane NO.7, first plane NO.8, first plane NO.9" << endl;
	}
	if (fp.MapGet(0) == checksign && fp.MapGet(3) == checksign && fp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "first plane NO.1, first plane NO.4, first plane NO.7" << endl;
	}
	if (fp.MapGet(1) == checksign && fp.MapGet(4) == checksign && fp.MapGet(7) == checksign)
	{
		score += 1;

		cout << "first plane NO.2, first plane NO.5, first plane NO.8" << endl;

	}
	if (fp.MapGet(2) == checksign && fp.MapGet(5) == checksign && fp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "first plane NO.3, first plane NO.6, first plane NO.9" << endl;
	}
	if (fp.MapGet(0) == checksign && fp.MapGet(4) == checksign && fp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "first plane NO.1, first plane NO.5, first plane NO.9" << endl;

	}
	if (fp.MapGet(2) == checksign && fp.MapGet(4) == checksign && fp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "first plane NO.3, first plane NO.5, first plane NO.7" << endl;
	}
	if (sp.MapGet(0) == checksign && sp.MapGet(1) == checksign && sp.MapGet(2) == checksign)
	{
		score += 1;

		cout << "second plane NO.1, second plane NO.2, second plane NO.3" << endl;
	}
	if (sp.MapGet(3) == checksign && sp.MapGet(4) == checksign && sp.MapGet(5) == checksign)
	{
		score += 1;

		cout << "second plane NO.4, second plane NO.5, second plane NO.6" << endl;
	}
	if (sp.MapGet(6) == checksign && sp.MapGet(7) == checksign && sp.MapGet(8) == checksign)
	{
		score += 1;
		cout << "second plane NO.7, second plane NO.8, second plane NO.9" << endl;
	}

	if (sp.MapGet(0) == checksign && sp.MapGet(3) == checksign && sp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "second plane NO.1, second plane NO.4, second plane NO.7" << endl;
	}
	if (sp.MapGet(1) == checksign && sp.MapGet(4) == checksign && sp.MapGet(7) == checksign)
	{
		score += 1;

		cout << "second plane NO.2, second plane NO.5, second plane NO.8" << endl;
	}
	if (sp.MapGet(2) == checksign && sp.MapGet(5) == checksign && sp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "second plane NO.3, second plane NO.6, second plane NO.9" << endl;
	}
	if (sp.MapGet(0) == checksign && sp.MapGet(4) == checksign && sp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "second plane NO.1, second plane NO.5, second plane NO.8" << endl;

	}
	if (sp.MapGet(2) == checksign && sp.MapGet(4) == checksign && sp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "second plane NO.3, second plane NO.5, second plane NO.7" << endl;
	}
	if (tp.MapGet(0) == checksign && tp.MapGet(1) == checksign && tp.MapGet(2) == checksign)
	{
		score += 1;

		cout << "third plane NO.1, third plane NO.2, third plane NO.3" << endl;
	}
	if (tp.MapGet(3) == checksign && tp.MapGet(4) == checksign && tp.MapGet(5) == checksign)
	{
		score += 1;

		cout << "third plane NO.4, third plane NO.5, third plane NO.6" << endl;

	}
	if (tp.MapGet(6) == checksign && tp.MapGet(7) == checksign && tp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "third plane NO.7, third plane NO.8, third plane NO.9" << endl;

	}
	if (tp.MapGet(0) == checksign && tp.MapGet(3) == checksign && tp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "third plane NO.1, third plane NO.4, third plane NO.7" << endl;

	}
	if (tp.MapGet(1) == checksign && tp.MapGet(4) == checksign && tp.MapGet(7) == checksign)
	{
		score += 1;

		cout << "third plane NO.2, third plane NO.5, third plane NO.8" << endl;
	}
	if (tp.MapGet(2) == checksign && tp.MapGet(5) == checksign && tp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "third plane NO.3, third plane NO.6, third plane NO.9" << endl;
	}
	if (tp.MapGet(0) == checksign && tp.MapGet(4) == checksign && tp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "third plane NO.1, third plane NO.5, third plane NO.9" << endl;

	}
	if (tp.MapGet(2) == checksign && tp.MapGet(4) == checksign && tp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "third plane NO.3, third plane NO.5, third plane NO.7" << endl;

	}
	//```` above 24
	if (fp.MapGet(0) == checksign && sp.MapGet(0) == checksign && tp.MapGet(0) == checksign)
	{

		cout << "first plane NO.1, second plane NO.1, third plane NO.1" << endl;
		score += 1;
	}
	if (fp.MapGet(3) == checksign && sp.MapGet(3) == checksign && tp.MapGet(3) == checksign)
	{
		score += 1;

		cout << "first plane NO.4, second plane NO.4, third plane NO.4" << endl;
	}
	if (fp.MapGet(6) == checksign && sp.MapGet(6) == checksign && tp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "first plane NO.7, second plane NO.7, third plane NO.7" << endl;
	}
	if (fp.MapGet(0) == checksign && sp.MapGet(3) == checksign && tp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "first plane NO.1, second plane NO.4, third plane NO.7" << endl;

	}
	if (fp.MapGet(6) == checksign && sp.MapGet(3) == checksign && tp.MapGet(0) == checksign)
	{
		score += 1;

		cout << "first plane NO.7, second plane NO.4, third plane NO.1" << endl;
	}
	if (fp.MapGet(1) == checksign && sp.MapGet(1) == checksign && tp.MapGet(1) == checksign)
	{
		score += 1;

		cout << "first plane NO.2, second plane NO.2, third plane NO.2" << endl;
	}
	if (fp.MapGet(4) == checksign && sp.MapGet(4) == checksign && tp.MapGet(4) == checksign)
	{
		score += 1;

		cout << "first plane NO.5, second plane NO.5, third plane NO.5" << endl;
	}
	if (fp.MapGet(7) == checksign && sp.MapGet(7) == checksign && tp.MapGet(7) == checksign)
	{
		score += 1;

		cout << "first plane NO.8, second plane NO.8, third plane NO.8" << endl;

	}
	if (fp.MapGet(1) == checksign && sp.MapGet(4) == checksign && tp.MapGet(7) == checksign)
	{
		score += 1;

		cout << "first plane NO.2, second plane NO.5, third plane NO.8" << endl;

	}
	if (fp.MapGet(7) == checksign && sp.MapGet(4) == checksign && tp.MapGet(1) == checksign)
	{
		score += 1;

		cout << "first plane NO.8, second plane NO.5, third plane NO.2" << endl;

	}
	if (fp.MapGet(2) == checksign && sp.MapGet(2) == checksign && tp.MapGet(2) == checksign)
	{
		score += 1;

		cout << "first plane NO.3, second plane NO.3, third plane NO.3" << endl;
	}
	if (fp.MapGet(5) == checksign && sp.MapGet(5) == checksign && tp.MapGet(5) == checksign)
	{
		score += 1;

		cout << "first plane NO.6, second plane NO.6, third plane NO.6" << endl;
	}
	if (fp.MapGet(8) == checksign && sp.MapGet(8) == checksign && tp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "first plane NO.9, second plane NO.9, third plane NO.9" << endl;
	}
	if (fp.MapGet(2) == checksign && sp.MapGet(5) == checksign && tp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "first plane NO.3, second plane NO.6, third plane NO.9" << endl;

	}
	if (fp.MapGet(8) == checksign && sp.MapGet(5) == checksign && tp.MapGet(2) == checksign)
	{
		score += 1;

		cout << "first plane NO.9, second plane NO.6, third plane NO.3" << endl;
	}
	//````` above 15
	if (fp.MapGet(0) == checksign && sp.MapGet(1) == checksign && tp.MapGet(2) == checksign)
	{
		score += 1;

		cout << "first plane NO.1, second plane NO.2, third plane NO.3" << endl;
	}
	if (fp.MapGet(3) == checksign && sp.MapGet(4) == checksign && tp.MapGet(5) == checksign)
	{
		score += 1;

		cout << "first plane NO.4, second plane NO.5, third plane NO.6" << endl;
	}
	if (fp.MapGet(6) == checksign && sp.MapGet(7) == checksign && tp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "first plane NO.7, second plane NO.8, third plane NO.9" << endl;

	}
	if (fp.MapGet(2) == checksign && sp.MapGet(1) == checksign && tp.MapGet(0) == checksign)
	{
		score += 1;

		cout << "first plane NO.3, second plane NO.2, third plane NO.1" << endl;
	}
	if (fp.MapGet(5) == checksign && sp.MapGet(4) == checksign && tp.MapGet(3) == checksign)
	{
		score += 1;

		cout << "first plane NO.6, second plane NO.5, third plane NO.4" << endl;
	}
	if (fp.MapGet(8) == checksign && sp.MapGet(7) == checksign && tp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "first plane NO.9, second plane NO.8, third plane NO.7" << endl;
	}
	//``` above 6
	if (fp.MapGet(0) == checksign && sp.MapGet(4) == checksign && tp.MapGet(8) == checksign)
	{
		score += 1;

		cout << "first plane NO.1, second plane NO.5, third plane NO.9" << endl;
	}
	if (fp.MapGet(2) == checksign && sp.MapGet(4) == checksign && tp.MapGet(6) == checksign)
	{
		score += 1;

		cout << "first plane NO.3, second plane NO.5, third plane NO.7" << endl;
	}
	if (fp.MapGet(6) == checksign && sp.MapGet(4) == checksign && tp.MapGet(2) == checksign)
	{
		score += 1;

		cout << "first plane NO.7, second plane NO.5, third plane NO.3" << endl;
	}
	if (fp.MapGet(8) == checksign && sp.MapGet(4) == checksign && tp.MapGet(0) == checksign)
	{
		score += 1;

		cout << "first plane NO.9, second plane NO.5, third plane NO.1" << endl;

	}

	return score;
}

void printresult(int who, FirstPlane fp, SecondPlane sp, ThirdPlane tp)
{
	fp.drawmap();
	sp.drawmap();
	tp.drawmap();



	cout << "Computer scores: \n" << endl;
	int computer = win(0, fp, sp, tp);
	cout << endl;
	cout << "Player score: \n" << endl;
	int player = win(1, fp, sp, tp);
	cout << endl;

	if (computer > player)
	{
		cout << "Computer win" << endl;
	}
	else if (computer < player)
	{
		cout << "Player win" << endl;
	}
	else
	{
		cout << "Draw" << endl;
	}
}

void move(int who, FirstPlane *fp, SecondPlane *sp, ThirdPlane *tp)
{
	system("cls");
	cout << "Computer is X, Player is @" << endl;

	fp->drawmap();
	sp->drawmap();
	tp->drawmap();

	switch (who)
	{

	case 1:
	{
		
		int input;
		cout << "enter which plane you want to choose" << endl;
		cin >> input;

		bool b = true;

		while (b)
		{
			while (1)
			{
				if (input == 1 || input == 2 || input == 3)
				{
					break;
				}
				else
				{
					cout << "wrong input, please enter your choose again" << endl;
					cin >> input;
				}
			}

			switch (input)
			{
			case 1:
				if (fp->MapLeftGet() > 0)
				{
					fp->move(1);
					fp->MapLeftRudece();
					system("cls");
					b = false;
				}
				else
				{
					cout << "this plane left no point to choose" << endl;
					cout << "enter another plane" << endl;
					cin >> input;
				}
				break;

			case 2:
				if (sp->MapLeftGet() > 0)
				{
					sp->move(1);
					sp->MapLeftRudece();
					system("cls");
					b = false;
				}
				else
				{
					cout << "this plane left no point to choose" << endl;
					cout << "enter another plane" << endl;
					cin >> input;
				}
				break;
			case 3:
				if (tp->MapLeftGet() > 0)
				{
					tp->move(1);
					tp->MapLeftRudece();
					system("cls");
					b = false;
				}
				else
				{
					cout << "this plane left no point to choose" << endl;
					cout << "enter another plane" << endl;
					cin >> input;
				}
				break;
			}

		}

		return;
	}


	case 0:

		int i = 0;
		if (fp->MapLeftGet() > 0)
		{
			i++;
		}
		if (sp->MapLeftGet() > 0)
		{
			i++;
		}
		if (tp->MapLeftGet() > 0)
		{
			i++;
		}

		int *choose = new int[i];

		int j = 0;
		if (fp->MapLeftGet() > 0)
		{
			choose[j] = 1;
			j++;
		}
		if (sp->MapLeftGet() > 0)
		{
			choose[j] = 2;
			j++;
		}
		if (tp->MapLeftGet() > 0)
		{
			choose[j] = 3;
			j++;
		}

		srand(time(NULL));

		switch (choose[(rand() % i)])
		{
		case 1:

			fp->move(0);
			fp->MapLeftRudece();
			system("cls");
			return;

		case 2:

			sp->move(0);
			sp->MapLeftRudece();
			system("cls");
			return;

		case 3:

			tp->move(0);
			tp->MapLeftRudece();
			system("cls");
			return;
		}

		break;
	}
}
