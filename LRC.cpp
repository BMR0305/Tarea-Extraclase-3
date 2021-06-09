//
// Created by usuario on 6/8/21.
//

#include "LRC.h"
#include "Parity_Checking.h"
#include <iostream>
LRC::LRC() {}

/**
 * Metodo que construye el lrc
 * @param bit_block vector que contiene cadenas de bits
 * @return vector ccon las cadenas destrings entrantes y la resultante del lrc
 */
vector<string> LRC::lrc(vector<string> bit_block) {
    string column= "";
    vector<string> result;
    string result_string = "";
    for (int i=0; i< bit_block.size(); i++){result.push_back(bit_block[i]);}
    Parity_Checking *parityChecking = new Parity_Checking();
    if (same_size(bit_block) && valid_bit_block(bit_block)){
        for (int i=0; i < bit_block.at(0).size(); i++){
            for(int j=0; j < bit_block.size(); j++){
                column+=bit_block.at(j)[i];
            }
            result_string+=parityChecking->even_parity_bit(column)[bit_block.size()];
            column ="";
        }
        result.push_back(result_string);
        return result;
    }
    else{
        vector<string> error={"Error"};
        return error;
    }
}
/**
 * Revisa si todas las cadenas son del mismo tamaño
 * @param bit_block vector con cadenas a revisar
 * @return true si son del mismo tamaño, false si no
 */
bool LRC::same_size(vector<string> bit_block) {
    int size = bit_block.at(0).size();
    for (int i=1; i < bit_block.size(); i++){
        if (size != bit_block.at(i).size()){
            return false;
        }
    }
    return true;
}
/**
 * Revisa si todas las cadenas de bits son validas
 * @param bit_block vector que contiene las cadenas a revisar
 * @return
 */
bool LRC::valid_bit_block(vector<string> bit_block){
    Parity_Checking *parityChecking = new Parity_Checking();
    for (int i=0; i < bit_block.size(); i++){
        if (parityChecking->valid_bit_data(bit_block.at(i))){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
/**
 * Revisa si las cadenas de bits tiene un errror por medio de lrc
 * @param bit_bloc vector con las  cadenas de bits a revisar
 * @return un mensaje indicando si se encontraron errores o no
 */
string LRC::check_lrc(vector<string> bit_block){
    vector<string> temp = bit_block;
    bit_block.pop_back();
    vector<string> comp = lrc(bit_block);
    if (temp.at(temp.size()-1) == comp.at(comp.size()-1)){
        return "No se enconro errores en LRC";
    }
    else{
        return "Error encontrado en LRC";
    }
}