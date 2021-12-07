#include "Creatures.h"
#include "Creature.h"
#include <iostream>
#include <thread>


using namespace std;

int main()
{
	int fieldH=0, fieldW=0, steps=0, herb,pred;
	int x=0,y=0,d=0,k=0;
    setlocale(LC_ALL,"Russian");
    cout << "Введите размеры поля и количество ходов (Высота Ширина Ходы)" << endl;
		while (!(cin >> fieldH >> fieldW >> steps))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Неверные данные. Попробуйте еще раз\n";
		}
	Creatures::Instance().set_field_h(fieldH);
	Creatures::Instance().set_field_w(fieldW);
	cout << "Введите количество хищников и жертв (Жертвы Хищники)" << endl;
		while (!(cin >> herb >> pred))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Неверные данные. Попробуйте еще раз\n";
		}
		for (int i=0;i<pred;i++){
			cout << "Введите координаты, направление, ходы для смены направления (X Y Направление Ходы)" << endl;
			while (!(cin >> x >> y >> d >> k))
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Неверные данные. Попробуйте еще раз\n";
			}
			Creatures::Instance().addp(*new Predator(x,y,d,k,i));

		}
	for (int i=0;i<herb;i++){
			cout << "Введите координаты, направление, ходы для смены направления (X Y Направление Ходы)" << endl;
			while (!(cin >> x >> y >> d >> k))
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Неверные данные. Попробуйте еще раз\n";
			}
		Creatures::Instance().addh(*new Herbivore(x,y,d,k,i));
		}
	int counter=0;
	for (int m=0;m<steps;m++)
	{
		
		for (Predator element : Creatures::Instance().predators_vector())
		{
			element.doStep();
		}
		for (Herbivore element : Creatures::Instance().herbivores_vector())
		{
			element.doStep();
		}
	}
	for (int i=0;i<fieldH;i++)
			{
				for (int j=0;j<fieldW;j++)
				{
					for (Herbivore element : Creatures::Instance().herbivores_vector())
					{
						if ((element.get_x()==j && element.get_y()==i) && !element.get_dead())
							{
								counter++;
							}
					}
					for (Predator element : Creatures::Instance().predators_vector())
					{
						if ((element.get_x()==j && element.get_y()==i) && !element.get_dead())
							{
								counter--;
							}
					}
					cout << counter;
					counter=0;
				}
				cout << endl;
			}
	
    //system("cls");
}


/*
 *
3 3 3
2 1
1 2 1 1
1 1 0 2
0 2 1 2
 *
 */