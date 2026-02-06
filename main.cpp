#include<iostream>
#include<ctime>
using namespace std;

//Prototipo de funciones
void dibujarTablero(char tablero[]);
void turnoJugador1(char tablero[], int posicion);
void turnoJugador2(char tablero[], int posicion);
void turnoComputadora(char tablero[], int posicion);
void comprobar_ganador(char tablero[], bool* prtPartida);
void comprobar_empate(char tablero[], bool* prtPartida); 

int main() {
    char tablero[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int posicion = 0;
    int elegirModo = 0;
    bool estadoPartida = true;
    bool* prtPartida = &estadoPartida;
    
    dibujarTablero(tablero);
    cout<<"¡¡¡Bienvenido al juego Tic Tac Toe, o tambien conocido como Tres en Raya o Gato!!!"<<endl<<endl;
    do{
        cout<<" A continuación estas son las modalidades a elegir:"<<endl;
        cout<<"    1. Jugar contra la computadora \n    2. Jugar contra otro jugador \n    3. Salir del programa"<<endl;
        cout<<" Digite aqui el numero que correspona a su decisión: "; cin>>elegirModo;
    }while((!(elegirModo == 1)) && (!(elegirModo == 2)) && (!(elegirModo == 3)));
    cout<<endl;
    
    switch(elegirModo) {
        case 1:
            while(*prtPartida){
                turnoJugador1(tablero, posicion);
                comprobar_ganador(tablero, prtPartida);
                if(*prtPartida == false){
                    break;
                }
                comprobar_empate(tablero, prtPartida);
                if(*prtPartida == false){
                    break;
                }
                
                turnoComputadora(tablero, posicion);
                comprobar_ganador(tablero, prtPartida);
                if(*prtPartida == false){
                    break;
                }
                comprobar_empate(tablero, prtPartida);
            }
            break;
        case 2:
            while(*prtPartida){
                turnoJugador1(tablero, posicion);
                comprobar_ganador(tablero, prtPartida);
                if(*prtPartida == false){
                    break;
                }
                comprobar_empate(tablero, prtPartida);
                if(*prtPartida == false){
                    break;
                }
                
                turnoJugador2(tablero, posicion);
                comprobar_ganador(tablero, prtPartida);
                if(*prtPartida == false){
                    break;
                }
                comprobar_empate(tablero, prtPartida);
            }
            
            break;
        case 3:
            
            
            break;
    }
    
    return 0;
}

void dibujarTablero(char tablero[]) {
    cout<<endl;
    cout<<"       |     |     "<<endl;
    cout<<"     "<<tablero[0]<<" |  "<<tablero[1]<<"  |  "<<tablero[2]<<"  "<<endl;
    cout<<"  _____|_____|_____"<<endl;
    cout<<"       |     |     "<<endl;
    cout<<"     "<<tablero[3]<<" |  "<<tablero[4]<<"  |  "<<tablero[5]<<"  "<<endl;
    cout<<"  _____|_____|_____"<<endl;
    cout<<"       |     |     "<<endl;
    cout<<"     "<<tablero[6]<<" |  "<<tablero[7]<<"  |  "<<tablero[8]<<"  "<<endl;
    cout<<"       |     |     "<<endl;
    cout<<endl;
}

void turnoJugador1 (char tablero[], int posicion) {
    do{
        cout<<"Jugador 1. Digite el número que corresponada a la casilla que desea jugar \nteniendo en cuenta que es del 1-9: "; cin>>posicion;
    }while((posicion < 1 || posicion > 9) || (tablero[posicion-1] != ' '));
    tablero[posicion - 1] = 'X';
    dibujarTablero(tablero);
    
}

void turnoJugador2 (char tablero[], int posicion) {
    do{
        cout<<"Jugador 2. Digite el número que corresponada a la casilla que desea jugar \nteniendo en cuenta que es del 1-9: "; cin>>posicion;
    }while((posicion < 1 || posicion > 9) || (tablero[posicion-1] != ' '));
    tablero[posicion - 1] = 'O';
    dibujarTablero(tablero);
    
}

void turnoComputadora (char tablero[], int posicion) {
    srand(time(NULL));
    do {
        posicion = rand() % 9; // Genera número aleatorio entre 0 y 8
    } while (tablero[posicion] != ' ');
    tablero[posicion] = 'O';
    dibujarTablero(tablero);
}

void comprobar_ganador(char tablero[], bool* prtPartida) {
    //Condición horizontales
    if(((tablero[0] == tablero[1]) && tablero[0] == tablero[2]) && tablero[1] == 'X'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 1!!! Felicidades! :D"<<endl;
    }else if(((tablero[3] == tablero[4]) && tablero[3] == tablero[5]) && tablero[4] == 'X'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 1!!! Felicidades! :D"<<endl;
    }else if(((tablero[6] == tablero[7]) && tablero[6] == tablero[8]) && tablero[7] == 'X'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 1!!! Felicidades! :D"<<endl;
    }else if(((tablero[0] == tablero[1]) && tablero[0] == tablero[2]) && tablero[1] == 'O'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 2!!! Felicidades! :D"<<endl;
    }else if(((tablero[3] == tablero[4]) && tablero[3] == tablero[5]) && tablero[4] == 'O'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 2!!! Felicidades! :D"<<endl;
    }else if(((tablero[6] == tablero[7]) && tablero[6] == tablero[8]) && tablero[7] == 'O'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 2!!! Felicidades! :D"<<endl;
    }
    
    //Condición Verticales
    if(((tablero[0] == tablero[3]) && tablero[0] == tablero[6]) && tablero[3] == 'X'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 1!!! Felicidades! :D"<<endl;
    }else if(((tablero[1] == tablero[4]) && tablero[1] == tablero[7]) && tablero[4] == 'X'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 1!!! Felicidades! :D"<<endl;
    }else if(((tablero[2] == tablero[5]) && tablero[2] == tablero[8]) && tablero[5] == 'X'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 1!!! Felicidades! :D"<<endl;
    }else if(((tablero[0] == tablero[3]) && tablero[0] == tablero[6]) && tablero[3] == 'O'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 2!!! Felicidades! :D"<<endl;
    }else if(((tablero[1] == tablero[4]) && tablero[1] == tablero[7]) && tablero[4] == 'O'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 2!!! Felicidades! :D"<<endl;
    }else if(((tablero[2] == tablero[5]) && tablero[2] == tablero[8]) && tablero[5] == 'O'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 2!!! Felicidades! :D"<<endl;
    }
    
    //Condición diagonales
    if(((tablero[0] == tablero[4]) && tablero[0] == tablero[8]) && tablero[4] == 'X'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 1!!! Felicidades! :D"<<endl;
    }else if(((tablero[6] == tablero[4]) && tablero[6] == tablero[2]) && tablero[4] == 'X'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 1!!! Felicidades! :D"<<endl;
    }else if(((tablero[0] == tablero[4]) && tablero[0] == tablero[8]) && tablero[4] == 'O'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 2!!! Felicidades! :D"<<endl;
    }else if(((tablero[6] == tablero[4]) && tablero[6] == tablero[2]) && tablero[4] == 'O'){
        *prtPartida = false;
        cout<<"¡¡¡Gana Jugador 2!!! Felicidades! :D"<<endl;
    }
}

void comprobar_empate(char tablero[], bool* prtPartida) {
    int contador = 0;
    for(int i=0; i<9; i++){
        if(tablero[i] == ' '){
            contador++;
        }
    }
    if(contador == 0){
        *prtPartida = false;
        cout<<"Esta partida no puede seguir más pues ya no quedan espacios disponibles... Pueden jugar de nuevo :b"<<endl;
    }
}
