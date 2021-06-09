#include <iostream>
#include "Parity_Checking.h"
#include "LRC.h"
#include "Hamming.h"

using namespace std;

int main(){
    cout  <<"------------Calculo del trasmisor------------"<<endl;
    string bit_data = "0001101";
    vector<string> bit_block = {"10111", "10110", "10010"};
    string bit_b="";
    for (int i=0; i< bit_block.size(); i++){bit_b+=bit_block[i]+" ";}

    Parity_Checking *parityChecking = new Parity_Checking();
    LRC *lrc = new LRC();

    string lrc_string=""; vector<string> bit_block_lrc = lrc->lrc(bit_block);
    string bit_parity = parityChecking->even_parity_bit(bit_data);

    cout <<"Paridad par de: "+bit_data+" / "<< bit_parity<<endl;
    for (int j=0; j< bit_block_lrc.size(); j++){lrc_string += bit_block_lrc.at(j)+" ";}
    cout <<"LRC de: "+ bit_b+" / "<< lrc_string  <<endl;
    cout <<endl;

    //No se encuentran errores
    cout  <<"------------Deteccion de errores del receptor------------"<<endl;
    cout << parityChecking->check_parity_even(bit_parity) <<endl;
    cout << lrc->check_lrc(bit_block_lrc) <<endl;
    cout <<endl;

    //Errores forzados
    cout <<"-------------Errores forzados en el receptor------------"<< endl;
    cout << parityChecking->check_parity_even("001101") <<endl;
    cout << lrc->check_lrc( {"10111", "10110", "10010", "10011"}) <<endl;
    cout <<endl;

    //Hamming
    cout <<"-------------Hamming Code------------"<< endl;
    Hamming *hamming = new Hamming();
    return 0;
}
