#include<iostream>
#include<string>
#include <conio.h>
#include <ctime>
using namespace std;

class Event
{
protected:
	int step;
public:
	virtual int Move() = 0;
};


class Event_plus_7 : public Event
{
public:
	Event_plus_7()
	{
		step = 7;
	}

	int Move()
	{
		return step;
	}
};


class Event_plus_4 : public Event
{
public:
	Event_plus_4()
	{
		step = 4;
	}

	int Move()
	{
		return step;
	}
};

class Event_plus_2 : public Event
{
public:
	Event_plus_2()
	{
		step = 2;
	}

	int Move()
	{
		return step;
	}
};



class Event_minus_1 : public Event
{
public:
	Event_minus_1()
	{
		step = -1;
	}

	int Move()
	{
		return step;
	}
};

class Event_minus_3 : public Event
{
public:
	Event_minus_3()
	{
		step = -3;
	}

	int Move()
	{
		return step;
	}
};

class Event_minus_6 : public Event
{
public:
	Event_minus_6()
	{
		step = -6;
	}

	int Move()
	{
		return step;
	}
};



class Game
{
private:
	Event* event;
	int size_map;
	char** map;
	int x = 0;
	int y = 1;
	bool exit = false;
public:

	Game()
	{
		event = new Event_plus_2;

		size_map = 19;

		map = new char*[size_map];
		for (int i = 0; i < size_map; i++)
		{
			map[i] = new char[size_map];
		}

	}

	void Creating_map()
	{
		int rnd;

		for (int i = 0; i < size_map; i++)
		{
			rnd = rand() % (size_map - 3) + 1;
			for (int j = 0; j < size_map; j++)
			{
				if (i % 5 == 0 && i != 0)
				{
					if (j != rnd && j != rnd + 1)
					{
						map[i][j] = '#';
					}
					else
					{
						map[i][j] = '.';
					}
				}
				else
				{
					map[i][j] = '.';
				}
				if (j == 0 || j == size_map - 1)
				{
					map[i][j] = '#';
				}

			}
		}
	}

	void Move_player()
	{
		y += event->Move();
	}

	void Defeat_check()
	{
		if (map[x][y] == '#' || y<0 || y > size_map - 1)
		{
			system("cls");
			cout << "you lost" << endl;
			exit = true;
			system("pause");
		}
		else if (x == size_map - 1)
		{
			system("cls");
			cout << "you won" << endl;
			exit = true;
			system("pause");
		}
	}

	void Show_maps()
	{
		Defeat_check();

		if (exit == true)return;

		for (int i = 0; i < size_map; i++)
		{
			for (int j = 0; j < size_map; j++)
			{
				if (x == i && y == j)
				{
					map[x][y] = '+';
				}
				cout << map[i][j];
			}
			cout << endl;
		}
	}

	void Play_Game()
	{
		Creating_map();

		while (exit != true)
		{
			int choice = 0;
			system("cls");
			Show_maps();
			if (exit == true)return;

			cout << "\n 1-make a move" << endl;
			cout << " 2- event +7 steps" << endl;
			cout << " 3- event +4 steps" << endl;
			cout << " 4- event +2 steps" << endl;
			cout << " 5- event -1 steps" << endl;
			cout << " 6- event -3 steps" << endl;
			cout << " 7- event -6 steps" << endl;
			cout << " 8- exit" << endl;
			cout << "->";
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				map[x][y] = '/';
				Move_player();
				x++;

			}
			break;

			case 2:
			{
				delete event;
				event = new Event_plus_7;

			}
			break;
			case 3:
			{
				delete event;
				event = new Event_plus_4;
			}
			break;
			case 4:
			{
				delete event;
				event = new Event_plus_2;
			}
			break;
			case 5:
			{
				delete event;
				event = new Event_minus_1;

			}
			break;
			case 6:
			{
				delete event;
				event = new Event_minus_3;
			}
			break;
			case 7:
			{
				delete event;
				event = new Event_minus_6;
			}
			break;
			case 8:
			{
				exit = true;
				system("cls");
			}
			break;
			}
		}
	}

	~Game()
	{
		delete event;

		for (int i = 0; i < size_map; i++)
		{
			delete[]  map[i];
		}
		delete[]  map;

	}
};


int main()
{
	srand(time(NULL));
	Game gg;
	gg.Play_Game();
	return 0;
}