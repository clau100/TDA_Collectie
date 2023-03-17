#include <cstdio>
#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	frecventa = 0;
    pozitie = 0;
}

TElem IteratorColectie::element() const{
	if (not valid()){
        perror("Iteratorul nu e valid!");
    }
    return col.elemente[pozitie];
}

bool IteratorColectie::valid() const {
	return pozitie < col.nr_elem and frecventa <= col.frecv[pozitie];
}

void IteratorColectie::urmator() {
	if ( not valid()){
        perror("Iterator nevalid!");
        return;
    }
    frecventa++;
    if (frecventa > col.frecv[pozitie]){
        pozitie++;
        frecventa = 0;
    }

}

void IteratorColectie::prim() {
	frecventa = 0;
    pozitie = 0;
}
