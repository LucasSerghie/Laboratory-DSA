#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
    if(this->map.isEmpty() == 1) {
        this->position = -1;
    }else
        this->position = 0;
}
//Theta(1)


void MapIterator::first() {
	if(this->map.isEmpty() == 1){
        this->position = -1;
    }else
        this->position = 0;
}
//Theta(1)


void MapIterator::next() {
    if(position >= this->map.nrElem)
        throw exception();
    position++;
}
//Theta(1)


TElem MapIterator::getCurrent(){
    if(this->valid() == 0)
        throw exception();
	return this->map.data[position];
}
//Theta(1)


bool MapIterator::valid() const {
	return (position < this->map.nrElem && position >= 0);
}
//Theta(1)
