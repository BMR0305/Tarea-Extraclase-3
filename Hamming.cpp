//
// Created by usuario on 6/9/21.
//

#include "Hamming.h"
#include<iostream>
using namespace std;
/**
 * Metodo hamming para deteccion de errores para cadenas de bits de largo 4
 */
Hamming::Hamming() {
    int data_send[10];
    int data_rec[10],c,c1,c2,c3;
    string data_string;
    cout<<"Ingrese 4 bits de data: "<<endl;
    cin>>data_string;
    data_send [0]= stoi(string(1, data_string[0])) ;
    data_send[1]= stoi(string(1, data_string[1]));
    data_send[2]= stoi(string(1, data_string[2]));
    data_send[4]= stoi(string(1, data_string[3]));

    Parity(data_send);
    cout<< endl;

    cout<<"EL código de hamming es: "<<endl;
    Code(data_send);
    cout<< endl;

    cout<<"Ingrese el codigo recibido como receptor"<<endl;
    string data_recieve;
    cin>>data_recieve;
    for(int i=0;i<7;i++){
        data_rec[i]=stoi(string(1, data_recieve[i]));
    }

    Calulate_error(data_rec, &c, &c1, &c2, &c3);

    if(c==0) {
        cout<<"No se encontraron errores"<<endl;
    }
    else {
        cout<<"Error encontrado"<<endl;
    }
}
/**
 * Metodo de paridad para el hamming
 */
void Hamming::Parity(int *data_send) {
    data_send[6]= data_send[0] ^ data_send[2] ^ data_send[4];
    data_send[5]= data_send[0] ^ data_send[1] ^ data_send[4];
    data_send[3]= data_send[0] ^ data_send[1] ^ data_send[2];
}
/**
 * Metodo para mostrar el codigo de hamming
 */
void Hamming::Code(int *data_send) {
    for(int i=0;i<7;i++){
        cout << data_send[i];
    }
}
/**
 * Metodo para calcular errores en el hamming
 */
void Hamming::Calulate_error(int *data_rec, int *c, int *c1, int *c2, int *c3) {
    *c1= data_rec[6] ^ data_rec[4] ^ data_rec[2] ^ data_rec[0];
    *c2= data_rec[5] ^ data_rec[4] ^ data_rec[1] ^ data_rec[0];
    *c3= data_rec[3] ^ data_rec[2] ^ data_rec[1] ^ data_rec[0];
    *c= *c3*4 + *c2*2 + *c1 ;
}
