#include "Creature.h"

Predator::Predator(int x_i, int y_i, int d_i, int k_i, bool birth_i)
{
	x = x_i;
	y = y_i;
	d = d_i;
	k = k_i;
	age = 0;
	satiety = 0;
	dead = false;
	birth = birth_i;
}

void Predator::move(const int& Width, const int& Height, const int& Turn)
{
	if ((Turn % k == 0) && (Turn != 0))
		d++;
	if (d == 4)
		d = 0;
	switch (d)
	{
	case UP:
		y -= 2;
		if (y < 0)
			y += Width;
		break;
	case RIGHT:
		x += 2;
		if (x >= Width)
			x -= Width;
		break;
	case DOWN:
		y += 2;
		if (y >= Height)
			y -= Height;
		break;
	case LEFT:
		x -= 2;
		if (x < 0)
			x += Height;
		break;
	}
}

void Predator::eat()
{
	satiety++;
}

bool Predator::reproduction()
{
	if (satiety == 2)
	{
		cout << "У нас пополнение среди волков!" << endl;
		satiety = 0;
		return true;
	}
	return false;
}

void Predator::death()
{
	if (age == 10)
	{
		cout << "Волк умер от старости. Навсегда в наших серждцах." << endl;
		dead = true;
	}
}

Herbivore::Herbivore(int x_i, int y_i, int d_i, int k_i, bool birth_i)
{
	x = x_i;
	y = y_i;
	d = d_i;
	k = k_i;
	age = 0;
	dead = false;
	birth = birth_i;
}

void Herbivore::move(const int& Width, const int& Height, const int& Turn)
{
	if ((Turn % k == 0) && (Turn != 0))
		d++;
	if (d == 4)
		d = 0;
	switch (d)
	{
	case UP:
		y--;
		if (y < 0)
			y += Height;
		break;
	case RIGHT:
		x++;
		if (x >= Width)
			x -= Width;
		break;
	case DOWN:
		y++;
		if (y >= Height)
			y -= Height;
		break;
	case LEFT:
		x--;
		if (x < 0)
			x += Width;
		break;
	}
}

void Herbivore::eat()
{
	dead = true;
	cout << "Волк съел кролика" << endl;
}

bool Herbivore::reproduction()
{
	if (age%5==0 && age!=0)
	{
		return true;
	}
	return false;
}

void Herbivore::death()
{
	if (age == 15)
	{
		dead = true;
	}
}
