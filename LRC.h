//
// Created by usuario on 6/8/21.
//

#ifndef TAREA_EXTRACLASE_3_LRC_H
#define TAREA_EXTRACLASE_3_LRC_H

#include <string>
#include <vector>
using namespace std;
/**
 * Clase LRC (Comprobacion longitudinal redundante)
 */
class LRC {
public:
    LRC();
    vector<string> lrc(vector<string> bit_block);
    bool same_size(vector<string> bit_block);

    bool valid_bit_block(vector<string> bit_block);

    string check_lrc(vector<string> bit_block);
};


#endif //TAREA_EXTRACLASE_3_LRC_H
