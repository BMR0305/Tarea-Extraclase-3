//
// Created by usuario on 6/8/21.
//

#ifndef TAREA_EXTRACLASE_3_PARITY_CHECKING_H
#define TAREA_EXTRACLASE_3_PARITY_CHECKING_H

#include <string>
/**
 * Clase COmprobacion de paridad
 */
using namespace std;
class Parity_Checking {
public:
    Parity_Checking();
    string even_parity_bit(string bit_data);

    bool valid_bit_data(string bit_data);

    string check_parity_even(string bit_data);
};


#endif //TAREA_EXTRACLASE_3_PARITY_CHECKING_H
