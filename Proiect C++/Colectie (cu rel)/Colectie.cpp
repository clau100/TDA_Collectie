#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>
#include <cstring>

using namespace std;

bool rel(TElem e1, TElem e2) {
	return e1 <= e2;
}

Colectie::Colectie() {
    nr_elem = 0;
    dimensiune = 0;
    elemente = nullptr;
    frecv = nullptr;
}

void Colectie::adauga(TElem e) {
    // daca il gasim, incrementam frecventa
    if (cauta(e)){
        for (int i=0; i<nr_elem; ++i){
            if (e == elemente[i]){
                frecv[i] ++;
                dimensiune++;
            }
        }
        return;
    }
    int check = nr_elem + 1;
    while(check % 2 == 0){
        check /= 2;
    }
    if (check == 1){
        // alocam memorie pentru noua destinatie
        auto* new_elem = (TElem*) malloc((nr_elem + 1) * 2 * sizeof(TElem));
        // copiem vechile elemente in noul spatiu alocat
        memcpy(new_elem, elemente, nr_elem * sizeof(TElem));
        // eliberam vechiul spatiu
        free(elemente);
        // retinem noua locatie a elementelor
        elemente = new_elem;

        auto* new_frecv = (int*) malloc((nr_elem + 1) * 2 * sizeof(int));
        memcpy(new_frecv, frecv, nr_elem * sizeof(int));
        free(frecv);
        frecv = new_frecv;
    }
    int st = 0, dr = nr_elem;
    while (st < dr){
        int mij = (st + dr)/2;
        if (rel(e, elemente[mij])){
            if (dr == mij)
                break;
            dr = mij;
        }else{
            if (st == mij)
                break;
            st = mij;
        }
    }
    // facem loc pentru elementul nou
    for (int i=nr_elem; i>dr; --i){
        elemente[i] = elemente[i-1];
        frecv[i] = frecv[i-1];
    }
    elemente[dr] = e;
    frecv[dr] = 1;
    nr_elem++;
    dimensiune++;
}


bool Colectie::sterge(TElem e) {
	if (not cauta(e)) return false;
    int ind = 0;
    for (int i = 0; i<nr_elem; ++i){
        if (elemente[i] == e){
            ind = i;
            if (frecv[i] > 1){
                frecv[i]--;
                dimensiune--;
                return true;
            }
        }
    }
    for(int i = ind; i<nr_elem-1; ++i){
        elemente[i] = elemente[i+1];
        frecv[i] = frecv[i+1];
    }
    nr_elem--;
    dimensiune--;
	return true;
}


bool Colectie::cauta(TElem elem) const {
    int st = 0, dr = nr_elem;
    while (st < dr){
        int mij = (st + dr) / 2;
        if (elemente[mij] == elem)
            return true;
        if (rel(elemente[mij], elem)){
            if (st == mij)
                return false;
            st = mij;
        }else{
            if (dr == mij)
                return false;
            dr = mij;
        }
    }
    return false;
}


int Colectie::nrAparitii(TElem elem) const {
	for(int i = 0; i < nr_elem; ++i){
        if (elem == elemente[i]) return frecv[i];
    }
	return 0;
}


int Colectie::dim() const {
	return dimensiune;
}


bool Colectie::vida() const {
	return nr_elem == 0;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	free(elemente);
    free(frecv);
}
