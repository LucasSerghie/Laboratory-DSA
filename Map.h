#pragma once
#include <utility>


typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE (-111111)
#define NULL_TELEM std::pair<TKey, TValue>(-111111, -111111)
class MapIterator;


class Map {
	friend class MapIterator;

	private:
		int cap;
        int nrElem;
        TElem *data;
        void resize();

	public:

	Map();

	TValue add(TKey c, TValue v);

	TValue search(TKey c) const;

	TValue remove(TKey c);

	int size() const;

	bool isEmpty() const;

	MapIterator iterator() const;

	~Map();

};



