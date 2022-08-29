#ifndef PRIMERKLASA_H
#define PRIMERKLASA_H

class primerKlasa {
	std::string ime;
	std::string prezime;
	std::string rank;
	int godini;

	void copyPrimerKlasa(const primerKlasa& pk);
public:
	

	primerKlasa(std::string ime = "", std::string prezime = "", int godini=0, std::string rank ="");

	primerKlasa(const primerKlasa& pk) {
		copyPrimerKlasa(pk);
	}

	friend std::istream& operator>>(std::istream& in_ref,primerKlasa& ref_pk);

	friend std::ostream& operator<<(std::ostream& out_ref, const primerKlasa& ref_pk);
	
	primerKlasa &operator=(const primerKlasa& pk);
	
	void poVozrasen(const primerKlasa& pk, const primerKlasa& pk2);
	void pecatiPrimerKlasa();

};

#endif