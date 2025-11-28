#include <iostream>
#include <windows.h> 
#include <math.h>
using namespace std;
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  

void LineaSimple(int x1, int y1, int x2, int y2){
    int pasos = max(abs(x2 - x1), abs(y2 - y1));
    for(int i = 0; i <= pasos; i++){
        float t = (float)i / pasos; 
        int x = round(x1 + t * (x2 - x1));
        int y = round(y1 + t * (y2 - y1));
        gotoxy(x, y);
        cout << "*";
    }
}
 int main(){  

	int x1 = 0; int x2 = 0 ; int y1 = 0 ; int y2 = 0;
	int Lineax = 0; int Lineay = 0; char repetir = 'H';
do{

	cout<<"Ingresa los valores del punto A: ";
	cin>>x1; cin>>y1;
	cout<<"Ingresa los valores del punto B: ";
	cin>>x2; cin>>y2;

	(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
    ? [&](){ cout << "No esta permitido ingresar numeros negativos \a" << endl; }()
    : [&](){ 
        float distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); 
        system("cls");
        LineaSimple(x1, y1, x2, y2);
        gotoxy(x1, y1);
        cout << "A";
        gotoxy(x2, y2);
        cout << "B";
        gotoxy(0, 20);
        cout << "\nLa distancia entre A y B es: " << distancia << endl;
    }();
	
   
	cout<<"Desea usar el programa otra vez(y/n): ";
	cin>>repetir;
	system("cls");
 }while(repetir == 'y' || repetir == 'Y');
}
