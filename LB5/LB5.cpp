#include "Creature.h"
#include <chrono>
#include <thread>


void main()
{
	setlocale(LC_ALL, "RUS");

	vector<Animals*> a;
	int N, Width, Height, R, W, x, y, d, k;

	cout << "Введите размеры поля и количество ходов (Высота Ширина Ходы)"<<endl;
	while (!(cin >> Width >> Height>> N))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Неверные данные. Попробуйте еще раз\n";
		}
	cout << "Введите количество хищников и жертв (Жертвы Хищники)" << endl;
	while (!(cin >> R >> W))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Неверные данные. Попробуйте еще раз\n";
		}

	vector <vector<int>> Vec(Width, vector<int>(Height));

	Herbivore* v;
	Predator* p;

	for (int i = 0; i < Width; i++)
		for (int j = 0; j < Height; j++)
			Vec[k][j] = 0;

	for (int i = 0; i < R; i++)
	{
		cout << "Введите координаты, направление, ходы для смены направления (X Y Направление Ходы)" << endl;
			while (!(cin >> x >> y >> d >> k))
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Неверные данные. Попробуйте еще раз\n";
			}
		v = new Herbivore(x, y, d, k, false);
		a.push_back(v);
	}

	for (int i = 0; i < W; i++)
	{
		cout << "Введите координаты, направление, ходы для смены направления (X Y Направление Ходы)" << endl;
			while (!(cin >> x >> y >> d >> k))
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Неверные данные. Попробуйте еще раз\n";
			}
		p = new Predator(x, y, d, k, false);
		a.push_back(p);
	}

	for (int l = 0; l < a.size(); l++)
	{
		if (l < R)
		{
			Vec[a[l]->gety()][a[l]->getx()]++;
		}
		else
		{
			Vec[a[l]->gety()][a[l]->getx()]--;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (k = 0; k < Width; k++)
			for (int j = 0; j < Height; j++)
				Vec[k][j] = 0;
		for (int j = 0; j < a.size(); j++)
		{
			if ((a[j]->getdead()) || (a[j]->getbirth()))
				continue;
			a[j]->move(Width, Height, i);
			if (j >= R)
			{
				for (k = 0; k < R; k++)
				{
					if ((a[j]->getx() == a[k]->getx()) && (a[j]->gety() == a[k]->gety()))
					{
						a[j]->eat();
						a[k]->eat();
					}
				}
			}
			a[j]->addyear();
			
			if (a[j]->reproduction())
			{
				if (j < R)
				{
					vector<Animals*>::iterator it = a.begin();
					advance(it, R);
					a.insert(it, new Herbivore(a[j]->getx(), a[j]->gety(), a[j]->getd(), a[j]->getk(), true));
					R++;
				}
				else
				{
					a.insert(a.end(), new Predator(a[j]->getx(), a[j]->gety(), a[j]->getd(), a[j]->getk(), true));
					W++;
				}
			}
			a[j]->death();
		}

		for (int l = 0; l < a.size(); l++)
		{
			if (a[l]->getbirth())
				a[l]->setbirth(false);
			if ((l < R) && (a[l]->getdead() == false))
			{
				Vec[a[l]->gety()][a[l]->getx()]++;
			}
			else if (a[l]->getdead() == false)
			{
				Vec[a[l]->gety()][a[l]->getx()]--;
			}
		}

		system("cls");
		for (auto element : Vec)
		{
			for (auto item : element)
				if (item == 0)
					cout << '*' << ' ';
				else
					cout << item << ' ';
			cout << endl;
		}
		this_thread::sleep_for(2s);
		
	}
}