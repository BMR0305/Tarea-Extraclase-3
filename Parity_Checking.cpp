//
// Created by usuario on 6/8/21.
//

#include "Parity_Checking.h"

Parity_Checking::Parity_Checking() {}
/**
 * Metodo que construye el bit de paridad par
 * @param bit_data Cadena de bits a la que se le desea crear el bit de paridad
 * @return cadena de bits con su respectivo bit de paridad
 */
string Parity_Checking::even_parity_bit(string bit_data) {
    if (valid_bit_data(bit_data)){
        int count;
        for (int i=0; i < bit_data.size(); i++){
            if (bit_data[i]=='1'){
                count+=1;
            }
        }
        if (count%2==0){
            return bit_data+"0";
        }
        else{
            return bit_data+"1";
        }
    }
    else{
        return "Ingrese una cadena de bits válida";
    }
}

/**
 * Revisa si el string puede ser utilizado como una cadena de bits
 * @param bit_data string a revisar
 * @return true si es valido, false si no
 */

bool Parity_Checking::valid_bit_data(string bit_data){

    for (int i=0; i < bit_data.size(); i++){
        if (bit_data[i] == '1' || bit_data[i] =='0'){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
/**
 * Revisa si la cadena de bits tiene un errro por medio de la combrobacion de paridad par
 * @param bit_data cadena de bits a revisar
 * @return un mensaje indicando si se encontraron errores o no
 */
string Parity_Checking::check_parity_even(string bit_data) {
    string temp = bit_data;
    bit_data.pop_back();
    string comp = even_parity_bit(bit_data);
    if (temp.at(temp.size()-1) == comp.at(comp.size()-1)){
        return "No se enconro errores paridad par";
    }
    else{
        return "Error encontrado en paridad par";
    }
}