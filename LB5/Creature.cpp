#include "Creature.h"

#include <iostream>
#include <vcruntime_typeinfo.h>

Creature::Creature(int x, int y, int d, int s, int id)
{
	this->x = x;
	this->y = y;
	this->dir = d;
	this->stepsBeforeChange = s;
    this->satiety=0;
    this->step=0;
    this->id=id;
    this->dead=false;
}


void Creature::doStep()
{
    if (!dead){
    move();
    eat();
    multiply();
    }
}

int Creature::steps_before_change() const
{
return stepsBeforeChange;
}

int Creature::get_dir() const
{
	return dir;
}

int Creature::get_x() const
	{
		return x;
	}

	int Creature::get_y() const
	{
		return y;
	}

	bool Creature::get_dead() const
	{
		return dead;
	}

	void Creature::set_dead(bool dead)
	{
		this->dead = dead;
	}

int Creature::get_id() const
{
	return id;
}


Predator::Predator(int x1, int y1, int d, int s, int id) : Creature(x1,y1,d,s, id){}

void Predator::eat()
{
    for (int i=0; i < Creatures::Instance().herbivores_vector().size();i++){
	    if (x == Creatures::Instance().herbivores_vector()[i].get_x() && y == Creatures::Instance().herbivores_vector()[i].get_y())
	    {
		    Creatures::Instance().herbivores_vector()[i].set_dead(true);
            Creatures::Instance().updateh(Creatures::Instance().herbivores_vector()[i]);
            satiety++;
            Creatures::Instance().updatep(*this);
        }
    }
}
void Predator::move()
{
    if (step%5==0 && step!=0)
    {
	    set_dead(true);
    }
    switch(dir)
    {
    case 0:
        y=(y+1)%Creatures::Instance().field_h();
        eat();
        y=(y+1)%Creatures::Instance().field_h();
        break;
    case 1:
        x=(x+1)%Creatures::Instance().field_w();
        eat();
        x=(x+1)%Creatures::Instance().field_h();
        break;
    case 2:
        y=(y-1)%Creatures::Instance().field_h();
        eat();
        y=(y-1)%Creatures::Instance().field_h();
        break;
    case 3:
        x=(x-1)%Creatures::Instance().field_w();
        eat();
        x=(x-1)%Creatures::Instance().field_h();
        break;
    }
    step++;
    if (step%stepsBeforeChange==0)
    {
	    dir++;
    }
    Creatures::Instance().updatep(*this);
}
void Predator::multiply()
{
	if (satiety%2==0 && satiety!=0)
	{
		Creatures::Instance().addp(*new Predator(get_x(),get_y(),get_dir(),steps_before_change(),get_id()));
	}
}



Herbivore::Herbivore(int x1, int y1, int d, int s, int id) : Creature(x1,y1,d,s,id){}

void Herbivore::eat()
{
	satiety++;
    Creatures::Instance().updateh(*this);
}
void Herbivore::move()
{
    switch(dir)
    {
    case 0:
        y=(y+1)%Creatures::Instance().field_h();
        break;
    case 1:
        x=(x+1)%Creatures::Instance().field_w();
        break;
    case 2:
        y=(y-1)%Creatures::Instance().field_h();
        break;
    case 3:
        x=(x-1)%Creatures::Instance().field_w();
        break;
    }
    step++;
    if (step%stepsBeforeChange==0)
    {
	    dir++;
    }
    Creatures::Instance().updateh(*this);
}
void Herbivore::multiply()
{
	if (satiety%5==0 && satiety!=0)
	{
		Creatures::Instance().addh(*new Herbivore(get_x(),get_y(),get_dir(),steps_before_change(),get_id()));
	}
    satiety++;
    Creatures::Instance().updateh(*this);
}