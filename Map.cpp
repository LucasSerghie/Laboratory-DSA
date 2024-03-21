#include "Map.h"
#include "MapIterator.h"


void Map::resize() {
    this->cap = 2 * cap;

    auto* newData = new TElem[cap]();

    for (unsigned int it = 0; it < nrElem; it++) {
        newData[it] = this->data[it];
    }

    delete[] this->data;
    this->data = newData;
}
//Theta(n)

Map::Map() {
	nrElem=0;
    cap = 10;
    data = new TElem [cap]();
}
//Theta(1)

Map::~Map() {
    delete[] data;
}
//Theta(1)

TValue Map::add(TKey c, TValue v){
    if(this->nrElem == this->cap - 1)
        this->resize(); //Theta(n)
    if(this->isEmpty() != 1)
        if (this->search(c) != NULL_TVALUE)  //bc: Theta(1)  /  wc: Theta(n)
            for (int i = 0; i < this->nrElem; i++)
                if (this->data[i].first == c) {
                    TValue old = this->data[i].second;
                    this->data[i] = TElem (c, v);
                    return old;
                }
    this->data[nrElem] = TElem (c, v);
    nrElem++;
    return NULL_TVALUE;
}
//bc: Theta(1)
//wc: Theta(n)

TValue Map::search(TKey c) const{
    if(this->isEmpty() != 1)
        for (int i = 0; i < this->nrElem; i++)
            if (this->data[i].first == c)
                return this->data[i].second;
    return NULL_TVALUE;
}
//bc: Theta(1)
//wc: Theta(n)

TValue Map::remove(TKey c){
    if(this->isEmpty() != 1)
        if (this->search(c) != NULL_TVALUE)
            for (int i = 0; i < this->nrElem; i++)
                if (this->data[i].first == c) {
                    TValue old = this->data[i].second;
                    for (int j = i; j < this->nrElem; j++)
                        this->data[j] = this->data[j + 1];
                    this->nrElem--;
                    return old;
                }
	return NULL_TVALUE;
}
//Theta(n)

int Map::size() const {
	return this->nrElem;
}
//Theta(1)

bool Map::isEmpty() const{
	return nrElem == 0;
}
//Theta(1)

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
//Theta(1)
