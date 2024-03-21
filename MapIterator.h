#pragma once
#include "Map.h"

class MapIterator
{
	friend class Map;
private:
	const Map& map;
	unsigned int position;

	explicit MapIterator(const Map& m);
public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


