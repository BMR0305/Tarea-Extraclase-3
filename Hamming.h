//
// Created by usuario on 6/9/21.
//

#ifndef TAREA_EXTRACLASE_3_HAMMING_H
#define TAREA_EXTRACLASE_3_HAMMING_H

/**
 * Clase Hamming
 */
class Hamming {
public:
    Hamming();
    void Parity(int *data_send);
    void Code (int *data_send);
    void Calulate_error(int *data_rec, int *c, int *c1, int *c2, int *c3);
};


#endif //TAREA_EXTRACLASE_3_HAMMING_H


