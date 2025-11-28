#include <iostream>
#include <windows.h>
#include <limits>  
using namespace std;


void mover_cursor(int columna, int fila){
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicion; 
    posicion.X = columna; 
    posicion.Y = fila;
    SetConsoleCursorPosition(consola, posicion);
}


void dibujar_digito(char digito, int columna, int fila){
    for(int fila_bloque=0; fila_bloque<5; fila_bloque++){
        for(int col_bloque=0; col_bloque<5; col_bloque++){
            bool pintar = false;

            switch(digito){
                case '0': pintar = (fila_bloque==0||fila_bloque==4||col_bloque==0||col_bloque==4); break;
                case '1': pintar = (col_bloque==2); break;
                case '2': pintar = (fila_bloque==0||fila_bloque==2||fila_bloque==4|| (fila_bloque<2 && col_bloque==4) || (fila_bloque>2 && col_bloque==0)); break;
                case '3': pintar = (fila_bloque==0||fila_bloque==2||fila_bloque==4||col_bloque==4); break;
                case '4': pintar = (col_bloque==4||fila_bloque==2|| (col_bloque==0 && fila_bloque<3)); break;
                case '5': pintar = (fila_bloque==0||fila_bloque==2||fila_bloque==4|| (fila_bloque<2 && col_bloque==0) || (fila_bloque>2 && col_bloque==4)); break;
                case '6': pintar = (fila_bloque==0||fila_bloque==2||fila_bloque==4||col_bloque==0|| (fila_bloque>2 && col_bloque==4)); break;
                case '7': pintar = (fila_bloque==0||col_bloque==4); break;
                case '8': pintar = (fila_bloque==0||fila_bloque==2||fila_bloque==4||col_bloque==0||col_bloque==4); break;
                case '9': pintar = (fila_bloque==0||fila_bloque==2||col_bloque==4|| (fila_bloque<2 && col_bloque==0)); break;
            }

            if(pintar){
                mover_cursor(columna+col_bloque, fila+fila_bloque);
                cout << "*";
            }
        }
    }
}


void dibujar_barra(int columna, int fila){
    mover_cursor(columna, fila); cout << "*";
    mover_cursor(columna+1, fila+1); cout << "*";
    mover_cursor(columna+2, fila+2); cout << "*";
    mover_cursor(columna+3, fila+3); cout << "*";
    mover_cursor(columna+4, fila+4); cout << "*";
}


int leer_numero(string mensaje){
    int valor;
    while(true){
        cout << mensaje;
        cin >> valor;
        if(cin.fail()){ 
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrada invalida. Por favor ingrese un numero.\n";
        }else{
            return valor;
        }
    }
}

int main(){
    char repetir;

    do{
        int dia = leer_numero("Ingrese dia: ");
        int mes = leer_numero("Ingrese mes: ");
        int anio = leer_numero("Ingrese anio: ");

        system("cls");

        
        int dia_decena= dia / 10;
        int dia_unidad= dia % 10;
        int mes_decena= mes / 10;
        int mes_unidad= mes % 10;
        int anio_mil= anio / 1000;
        int anio_cent= (anio / 100) % 10;
        int anio_dec= (anio / 10) % 10;
        int anio_uni= anio % 10;

       
        int columna_inicial = 10, fila_inicial = 5;
        dibujar_digito('0' + dia_decena, columna_inicial, fila_inicial);
        dibujar_digito('0' + dia_unidad, columna_inicial+6, fila_inicial);
        dibujar_barra(columna_inicial+12, fila_inicial);

        dibujar_digito('0' + mes_decena, columna_inicial+18, fila_inicial);
        dibujar_digito('0' + mes_unidad, columna_inicial+24, fila_inicial);
        dibujar_barra(columna_inicial+30, fila_inicial);

        dibujar_digito('0' + anio_mil, columna_inicial+36, fila_inicial);
        dibujar_digito('0' + anio_cent, columna_inicial+42, fila_inicial);
        dibujar_digito('0' + anio_dec, columna_inicial+48, fila_inicial);
        dibujar_digito('0' + anio_uni, columna_inicial+54, fila_inicial);

        cout << "\n\nDesea ingresar otra fecha (s/n): "<<endl;
        cin >> repetir;

        system("cls");

    }while(repetir=='s' || repetir=='S');

    return 0;
}

