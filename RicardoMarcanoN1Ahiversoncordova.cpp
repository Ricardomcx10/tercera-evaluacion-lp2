#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//ventana20x20
const int width=20;
const int heigth=20;

//serpiente de 4 puntos
int s1x, s1y;
int s2x, s2y;
int s3x, s3y;
int s4x, s4y;

int objx=15, objy=15;

//direccion en la que inicia moviendose
char direccion =' ';

int obs1x=5, obs1y=5;
int obs2x=12, obs2y=8;

void gotoxy(int x,int y){  
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}  

void dibujarbordes(){
    for(int i=0;i<=width;i++){
        gotoxy(i,0); cout<<"#";
        gotoxy(i,heigth); cout<<"#";
    }
    for(int j=0;j<=heigth;j++){
        gotoxy(0,j); cout<<"#";
        gotoxy(width,j); cout<<"#";
    }
}

void dibujarmeta(){
    gotoxy(objx,objy);
    cout<<"X";
}
 
void dibujarobstaculos(){
    gotoxy(obs1x,obs1y);
    cout<<"O";
    gotoxy(obs2x,obs2y);
    cout<<"O";
}

void dibujarserpiente(){
    gotoxy(s1x,s1y); cout<<"8";
    gotoxy(s2x,s2y); cout<<"8";
    gotoxy(s3x,s3y); cout<<"8";
    gotoxy(s4x,s4y); cout<<"8";
}

void borrarserpiente(){
    gotoxy(s1x,s1y); cout<<" ";
    gotoxy(s2x,s2y); cout<<" ";
    gotoxy(s3x,s3y); cout<<" ";
    gotoxy(s4x,s4y); cout<<" ";
}

//mover la serpiente segun la tecla
void mover(char tecla){
    s4x=s3x; s4y=s3y;
    s3x=s2x; s3y=s2y;
    s2x=s1x; s2y=s1y;

    if(tecla=='w') s1y--;
    else if(tecla=='s') s1y++;
    else if(tecla=='a') s1x--;
    else if(tecla=='d') s1x++;
}

bool colision(){
    if(s1x<=0||s1x>=width||s1y<=0||s1y>=heigth)
        return true;
  
    if((s1x==obs1x && s1y==obs1y) ||
       (s1x==obs2x && s1y==obs2y))
        return true;
    return false;
}

bool llegometa(){
    return(s1x == objx && s1y==objy);
}

int main(){
    system("Color 0A");
    char repetir;

    do{
       
        s1x=10; s1y=10;
        s2x=9;  s2y=10;
        s3x=8;  s3y=10;
        s4x=7;  s4y=10;
        direccion=' ';

        system("cls");
        bool gameover=false, win=false;
        dibujarbordes();
        dibujarmeta();
        dibujarobstaculos();
        dibujarserpiente();

        // Esperar tecla inicial para empezar
        gotoxy(0,heigth+1);
        cout<<"Presione W, A, S o D para iniciar...";
        do{
            direccion=_getch();
        }while(direccion!='w' && direccion!='a' && direccion!='s' && direccion!='d');

        system("cls");
        dibujarbordes();
        dibujarmeta();
        dibujarobstaculos();

        while(!gameover && !win){
            if(_kbhit()){
                char tecla = _getch();
                if(tecla=='w'||tecla=='s'||tecla=='a'||tecla=='d')
                    direccion = tecla;
            }

            borrarserpiente();
            mover(direccion);   
            dibujarserpiente();

            if(colision()) gameover=true;
            if(llegometa()) win=true;

            Sleep(100);
        }

        gotoxy(0,heigth+2);
        if(gameover) cout<<"GAME OVER"<<endl;
        if(win) cout<<"YOU WIN"<<endl;

        cout<<"¿Desea jugar otra vez? (s/n): ";
        cin>>repetir;

    }while(repetir=='s' || repetir=='S');

    return 0;
}

