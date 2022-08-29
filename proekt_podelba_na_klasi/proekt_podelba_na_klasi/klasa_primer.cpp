#include<iostream>
#include<string.h>
#include"klasa_primer.h"

void primerKlasa::copyPrimerKlasa(const primerKlasa& pk) {
	this->ime = pk.ime;
	this->prezime = pk.prezime;
	this->godini = pk.godini;
	this->rank = pk.rank;
}

primerKlasa::primerKlasa(std::string ime, std::string prezime, int godini, std::string rank) {
	this->ime = ime;
	this->prezime = prezime;
	this->godini = godini;
	this->rank = rank;
}

std::istream& operator>>(std::istream& in_ref, primerKlasa& ref_pk)
{
	in_ref >> ref_pk.ime;
	in_ref >> ref_pk.prezime;
	in_ref >> ref_pk.godini;
	in_ref >> ref_pk.rank;
	return in_ref;
}

std::ostream& operator<<(std::ostream& ou_ref, const primerKlasa& ref_pk) {
	ou_ref << "Ime:" << ref_pk.ime<<std::endl;
	ou_ref << "Prezime:" << ref_pk.prezime << std::endl;
	ou_ref << "Godini: " << ref_pk.godini << std::endl;
	ou_ref << "Rank: " << ref_pk.rank << std::endl;
	return ou_ref;
}

primerKlasa& primerKlasa::operator=(const primerKlasa& pk)
{
	if (this != &pk) {
		primerKlasa::copyPrimerKlasa(pk);
	}
	return *this;
}

void primerKlasa::poVozrasen(const primerKlasa &pk, const primerKlasa& pk2) {
	if (pk.godini > pk2.godini) {
		std::cout << pk.ime << " e povozrasen/na od: " << pk2.ime<<std::endl;
	}
	else if (pk.godini < pk2.godini) {
		std::cout << pk2.ime << " e povozrasen/na od " << pk.ime << std::endl;	
	}
	else { 
		std::cout << pk.ime << " i " << pk2.ime << " se ednakvi vo vozrast. " << std::endl;
	}

}

void primerKlasa::pecatiPrimerKlasa() {
	std::cout << "Ime: " << ime << std::endl;
	std::cout << "Prezime: " << prezime << std::endl;
	std::cout << "Godini: " << godini << std::endl;
	std::cout << "Rank: " << rank << std::endl;
}