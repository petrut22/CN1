#include <iostream>
//regula 1
bool RULE1(bool Stg, bool D, bool S, bool J, int *rule) {

	if(Stg == 0 || D == 0) {
		return 0;
	}

	*rule = 1;
	return 1;
}

//regula 2
bool RULE2(bool Stg, bool D, bool S, bool J, int *rule) {

	if((Stg == 0 && D == 0) || (Stg == 1 && D == 1))  {
		return 0;
	}

	if(S == 1 && J == 1) {
		return 0;
	}

	*rule = 2;
	return 1;
}

//regula 3
bool RULE3(bool Stg, bool D, bool S, bool J, int *rule) {

	if(Stg == 1 && D == 1) {
		return 0;
	}

	if(S == 0 || J == 0) {
		return 0;
	}

	*rule = 3;
	return 1;
}

//regula 4
bool RULE4(bool Stg, bool D, bool S, bool J, int *rule) {

	if(Stg == 1 || D == 1) {
		return 0;
	}

	if((S == 0 && J == 0) || (S == 1 && J == 1)) {
		return 0;
	}

	*rule = 4;
	return 1;
}

//regula 5
bool RULE5(bool Stg, bool D, bool S, bool J, int *rule) {

	if(Stg == 1 || D == 1 || S == 1 || J == 1) {
		return 0;
	}

	*rule = 5;
	return 1;
}

//functie care combina rezultatele de la regulile 1 2 si 5
bool RULE_A(bool Stg, bool D, bool S, bool J, int *rule) {

	return (RULE1(Stg, D,  S,  J, rule) || RULE2(Stg, D,  S,  J, rule) || RULE5(Stg, D,  S,  J, rule));
}

//functie care combina rezultatele de la regulile 3 si 4
bool RULE_B(bool Stg, bool D, bool S, bool J, int *rule) {

	return (RULE3(Stg, D,  S,  J, rule) || RULE4(Stg, D,  S,  J, rule));
}





void ci(bool Stg, bool D, bool S, bool J, bool *EW, bool *NS, int *rule) {
#pragma HLS INTERFACE mode=ap_ctrl_none port=return
#pragma HLS INTERFACE mode=ap_none port=Stg
#pragma HLS INTERFACE mode=ap_none port=D
#pragma HLS INTERFACE mode=ap_none port=S
#pragma HLS INTERFACE mode=ap_none port=J

	//pe baza celor doua functii, obtin valorile pentru cele doua semafoare
	//la final dupa ce o sa le obtin, o sa stiu si ce regula respecta
	*EW = RULE_A(Stg, D, S, J, rule);
	*NS = RULE_B(Stg, D, S, J, rule);



}


