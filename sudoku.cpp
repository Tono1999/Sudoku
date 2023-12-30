/********************************************************************
Programa para resolver un sudoku

By
Angel Antonio Mendez Hernandez
********************************************************************/

#include <iostream>
using namespace std;

const int N=9; 

void imprimirTablero(int tablero[N][N]) {
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) 
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}

//para verificar que se vale escribir cierto valor en cierta posicion
bool sevale(int tablero[N][N], int fila, int columna, int num){
    //buscamos en la fila y la columna para ver que aun no exista ese
    //valor
    for(int i=0; i<N; i++){
        if(tablero[fila][i]==num || tablero[i][columna]==num) 
                    return false;
    }
    //revisamos el subcuadro
    //nos ubicamos en el "inicio" del subcuadro
    int sFila=fila-fila%3;
    int sColumna=columna-columna%3;
    //recorremos todo el subcuadro
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tablero[sFila+i][sColumna+j]==num) 
                return false;
        }
    }
    return true;
}

bool resolver(int tablero[N][N]){
    int fila, columna;
    //buscamos celdas vacias
    bool vacias=true;
    for(int i=0; i<81; i++){
        if(*(*tablero+i)==0){
            fila=i/9;
            columna=i%9;
            vacias=false;
            break;
        }
    }
    //si todo esta lleno, el sudoku esta resuelto
    if(vacias)
        return true;
    //probamos en la celda cada valor entre 1 y 9
    for(int num=1; num<=9; num++){
        if(sevale(tablero, fila, columna, num)){
            tablero[fila][columna]=num;
            //vemos si se puede continuar...
            if(resolver(tablero)) 
                return true;
            //en caso que el valor probado no jale
            tablero[fila][columna]=0;
        }
    }
    //si no hay solucion
    return false;
}

int main() {
    int tablero[N][N] = {0};
    cout << "Ingresa el Sudoku (usa 0 para representar celdas vacías):" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<"Entrada ("<<i+1<<","<<j+1<<"): ";
            cin>>tablero[i][j];
        }
    }
    if(resolver(tablero)){
        cout<<"Solucion del Sudoku:"<<endl;
        imprimirTablero(tablero);
    } 
    else
        cout << "No hay solucion valida para el Sudoku ingresado." << endl;

    return 0;
}
