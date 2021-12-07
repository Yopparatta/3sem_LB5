#pragma once
#include "Creatures.h"

class  Creature
{
protected:
	int x;
	int y;
	int dir;
	int stepsBeforeChange;
	int step;
	int satiety;
	int id;
	bool dead;

public:
    virtual void move()=0;
    virtual void eat()=0;
	virtual void multiply()=0;

	Creature(int x, int y, int d, int s, int id);
    void doStep();

	virtual int steps_before_change() const;

	int get_x() const;

	int get_y() const;

	int get_dir() const;

	bool get_dead() const;

	void set_dead(bool dead);

	int get_id() const;
};

class Herbivore : public Creature
{
public:
	Herbivore(int x1, int y1, int d, int s, int id);
	void eat() override;
	void move() override;
	void multiply() override;
};

class Predator : public Creature
{
public:
	Predator(int x1, int y1, int d, int s, int id);
	void eat() override;
    void move() override;
	void multiply() override;
};
