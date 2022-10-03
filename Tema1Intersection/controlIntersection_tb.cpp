#include "controlIntersection_tb.h"
#include <iostream>

int main() {

	bool a, b, c, d;
	//in cei 2 vectori retin valorile pentru semafoare
	//valoarea 1 -> verde, valoarea 0 -> rosu
	bool semaphore_NS[16], semaphore_EW[16];

	//vectori cu valorile corecte pentru semafoare cu scop de verificare
	bool EW_golden[16] = { 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1};
	bool NS_golden[16] = { 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0};
	int rule_golden[16] = { 5, 4, 4, 3, 2, 2, 2, 3, 2, 2, 2, 3, 1, 1, 1, 1};

	//in rule retin regulile
	int rule[16], k = 0;
	int status  = 0;

	//calculez toate valorile pentru cei 4 senzori, iar pe baza lor
	//voi obtine valorile pentru semafoare
	for(int ia = 0; ia < 2; ia++) {
		for(int ib = 0; ib < 2; ib++) {
			for(int ic = 0; ic < 2; ic++) {
				for(int id = 0; id < 2; id++) {
					a = (bool) ia;
					b = (bool) ib;
					c = (bool) ic;
					d = (bool) id;
					//apelez functia necesara ca sa obtin valorile pentru cele doua semafoare si regula
					ci(a, b, c, d, &semaphore_EW[k], &semaphore_NS[k], &rule[k]);

					k++;
				}
			}
		}
	}

	//verific daca rezultatele sunt corecte
	for(int i = 0; i < 16; i++) {
		if(semaphore_EW[i] != EW_golden[i]) {
			status = -1;
			std::cout << "Eroare la semaforul EW la linia " << i << ": valoare corecta: " << EW_golden[i] << " valoare primita: " << semaphore_EW[i] << std::endl;
		}

		if(semaphore_NS[i] != NS_golden[i]) {
			status = -1;
			std::cout << "Eroare la semaforul NS la linia " << i << ": valoare corecta: " << NS_golden[i] << " valoare primita: " << semaphore_NS[i] << std::endl;
		}

		if(rule[i] != rule_golden[i]) {
			status = -1;
			std::cout << "Eroare la regula de pe linia " << i << ": valoare corecta: " << rule_golden[i] << " valoare primita: " << rule[i] << std::endl;
		}
	}

	//pe baza lui 'status' verific daca testarea s-a realizat corect
	//iar daca rezultatul este unul bun, afisez regula aplicata + valorile semafoarelor
	if(status == 0) {
		std::cout << "Regula   EW NS" << std::endl;
		for(int i = 0; i < 16; i++) {
			std::cout << rule[i] << "         " << semaphore_EW[i] << " " << semaphore_NS[i] << std::endl;
		}

		std::cout << "Testarea incheiata cu succes !" << std::endl;
	} else {
		std::cout << "Testarea incheiata cu insucces !" << std::endl;
	}


	return 0;
}
