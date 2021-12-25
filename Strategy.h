#pragma once
#include "Creature.h"

class Strategy
{
public:
	virtual ~Strategy(){}
	virtual void move(Creature _c) const = 0;
};

class Dumb_Move : public Strategy
{
public:
	Dumb_Move();
	~Dumb_Move();
	
	void move() const override;
};

class Smart_Move : public Strategy
{
public:
	Smart_Move();
	~Smart_Move();
	
	void move() const override;
};
