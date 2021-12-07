#include "Creatures.h"
#include "Creature.h"

using namespace std;
	Creatures::Creatures()
	{
	}
	void Creatures::addh(Herbivore &animal)
	{
		Creatures::herbivoresVector.push_back(animal);
	}
	void Creatures::addp(Predator &animal)
	{
		Creatures::predatorsVector.push_back(animal);
	}

	int Creatures::field_w() const
    {
        return fieldW;
    }

    void Creatures::set_field_w(int field_w)
    {
        fieldW = field_w;
    }

    int Creatures::field_h() const
    {
        return fieldH;
    }

    void Creatures::set_field_h(int field_h)
    {
        fieldH = field_h;
    }

    std::vector<Herbivore> Creatures::herbivores_vector() const
    {
        return herbivoresVector;
    }
	std::vector<Predator> Creatures::predators_vector() const
    {
        return predatorsVector;
    }

	void Creatures::updateh(Herbivore herb)
	{
		Instance().herbivoresVector.erase(Instance().herbivoresVector.begin()+herb.get_id());
        Instance().herbivoresVector.emplace(Instance().herbivoresVector.begin()+herb.get_id(),herb);
	}
	void Creatures::updatep(Predator pred)
	{
		Instance().predatorsVector.erase(Instance().predatorsVector.begin()+pred.get_id());
        Instance().predatorsVector.emplace(Instance().predatorsVector.begin()+pred.get_id(),pred);
	}

