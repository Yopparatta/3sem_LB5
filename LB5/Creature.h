#pragma once
#include <iostream>
#include <vector>



using namespace std;

enum DIRECTION
{
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3
};

class Animals
{
public:
	virtual void move(const int& Width, const int& Height, const int& Turn) {};
	virtual void eat() {};
	virtual void addyear() { age++; };
	virtual bool reproduction() { return 0; };
	virtual void death() {};

	virtual int getx() { return x; };
	virtual int gety() { return y; };
	virtual int getd() { return d; };
	virtual int getk() { return k; };
	virtual int getdead() { return dead; };
	virtual int getbirth() { return birth; };
	virtual void setbirth(bool birth_i) { birth = birth_i; };
protected:
	int x, y, d, k, age = 0;
	bool dead = false, birth;
};

class Predator : public Animals
{
public:
	Predator(int x_i, int y_i, int d_i, int k_i, bool birth_i);
	void move(const int& Width, const int& Height, const int& Turn) override;
	void eat() override;
	bool reproduction() override;
	void death() override;
protected:
	int satiety;
};

class Herbivore : public Animals
{
public:
	Herbivore(int x_i, int y_i, int d_i, int k_i, bool birth_i);
	void move(const int& Width, const int& Height, const int& Turn) override;
	void eat() override;
	bool reproduction() override;
	void death() override;
};
