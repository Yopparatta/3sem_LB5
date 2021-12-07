#pragma once
#include <vector>

#include "Creature.h"

class Herbivore;
class Predator;

class Creatures
{
public:
        static Creatures& Instance()
{
    static Creatures theSingleInstance;
    return theSingleInstance;
}
	void addh(Herbivore &animal);
    void addp(Predator &animal);

        int field_w() const;

        void set_field_w(int field_w);

        int field_h() const;

        void set_field_h(int field_h);

        std::vector<Herbivore> herbivores_vector() const;
		std::vector<Predator> predators_vector() const;
    void updateh(Herbivore herb);
    void updatep(Predator pred);

    private:        
    Creatures();
	Creatures& operator=(const Creatures&) = delete;
	Creatures(const Creatures& root) = delete;
    std::vector<Herbivore> herbivoresVector={};
    std::vector<Predator> predatorsVector={};
    int fieldW;
    int fieldH;
};
