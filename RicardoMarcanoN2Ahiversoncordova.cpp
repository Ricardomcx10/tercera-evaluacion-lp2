#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x,int y){  
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y = y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}  


void dibujar_hojas(int filas, int columna_inicial, int fila_inicial){
    for(int i=1; i<=filas; i++){
        
        for(int j=1; j<=filas-i; j++){
            gotoxy(columna_inicial+j-1, fila_inicial+i-1);
            cout << " ";
        }
        
        for(int k=1; k<=2*i-1; k++){
            gotoxy(columna_inicial+filas-i+k-1, fila_inicial+i-1);
            cout << "*";
        }
    }
}


void dibujar_tronco(int filas_hojas, int filas_tronco, int columna_inicial, int fila_inicial){
    int ancho_tronco = filas_hojas/3; 
    if(ancho_tronco<1) ancho_tronco=1;

    for(int i=1; i<=filas_tronco; i++){
       
        for(int j=1; j<=filas_hojas-ancho_tronco; j++){
            gotoxy(columna_inicial+j-1, fila_inicial+filas_hojas+i-1);
            cout << " ";
        }
     
        for(int k=1; k<=ancho_tronco*2-1; k++){
            gotoxy(columna_inicial+filas_hojas-ancho_tronco+k-1, fila_inicial+filas_hojas+i-1);
            cout << "*";
        }
    }
}

int main(){
	system("color 0A");
    int filas_hojas, filas_tronco;
    cout << "Ingrese numero de filas para las hojas: ";
    cin >> filas_hojas;
    cout << "Ingrese numero de filas para el tronco: ";
    cin >> filas_tronco;

    system("cls");

    int columna_inicial = 30; 
    int fila_inicial = 5;     

    dibujar_hojas(filas_hojas, columna_inicial, fila_inicial);
    dibujar_tronco(filas_hojas, filas_tronco, columna_inicial, fila_inicial);

    gotoxy(0, fila_inicial+filas_hojas+filas_tronco+2);
    cout << "FELIZ NAVIDAD" << endl;

    return 0;
}

