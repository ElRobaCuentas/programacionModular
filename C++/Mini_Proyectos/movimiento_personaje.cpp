#include <iostream>

//TODO SOLO DERECAH E IZQUIERDA (1 DIMENSION)
/*
Voy a crear un vector de 5 caracteres, en el cual se va a poder mover mi personaje "Mapa del Juego", que será en H.
La posicion de mi personaje estara dentro de las posiciones que me brinda el vector, los cuales son 0,1,2,3,4.
Entonces, con un for voy a recorrer mi vector, dentro del for pondre un if, el cual mi condicion sera que si 
la posicion de mi personaje coincide con la posicion que me brinda el vector entonces con un caracter 'd' avance a la
derecha y con el caracter 'a' avance a la izquierda.
*/

// void charMov(char gameMap[5], int characterPos);

// int main() {

//     char gameMap[5] = {'1', '1', '1', '1', '1'};
//     int characterPos = 0;
//     char input = ' ';
//     charMov(gameMap, characterPos); //PRIMERO VOY A MOSTRAR MI MAPA, ESTO NO PUEDE ESTAR DEBAJO DE MI INPUT. DESPUES DE MOSTARME ME VA A PEDIR QUE PRESIONE UNA TECLA

//     std::cin>>input;
    
//     while (input != 'p') {
        
//         // std::cin>>input; //si el input lo pongo aca, despues de poner d o i, me va a decir que ponga otra vez d o i. No va ahi, va abajo
//         //Una vez que el usuario mete una tecla, el bucle entra… pero nunca vuelve a pedir otro input, y eso crea un bucle infinito o estático.

//         if(input == 'd') {
//             characterPos = characterPos + 1;
//         } else if (input == 'a') {
//             characterPos = characterPos - 1;
//         } 

//         charMov(gameMap, characterPos); //COMO ES VARIABLE, LO LLAMO OTRA VEZ CON LOS CAMBIOS QUE LE HE HECHO, EN ESTE CASO MOVER A LA D o I. ACTUALIZA EL MAPA
//         std::cin>>input;
//     }


//     //cuando llamo a la funcion fuera del bucle, no estoy redibujando el mapa en cada movimiento
    
//     return 0;
// }

// void charMov(char gameMap[5], int characterPos) {
//     for (int i=0; i<5; i++) {
//         if (i != characterPos) { //yo no quiero gameMap[i] que es 1, yp quiero la posicion, que es 0, osea i
//             std::cout<<gameMap[i];
//         } else {
//             std::cout<<'H';
//         }
//     }
// }

//TODO DERECHA, IZQUIERDA, ARRIBA Y ABAJO (2 DIMENSIONES) 

void charPos(int posX, int posY, char gameMap[5][5]);

int main() {

    char gameMap[5][5] = {
        {'1', '1', '1', '1', '1'}, 
        {'1', '1', '1', '1', '1'}, 
        {'1', '1', '1', '1', '1'}, 
        {'1', '1', '1', '1', '1'}, 
        {'1', '1', '1', '1', '1'}
    };
    int posX = 0; 
    int posY = 0;

    charPos(posX, posY, gameMap); //MAPA INCIAL

    char input = ' ';
    std::cout<<"presiona 'd' (derecha), 'a' (izquiera), 'w' (arriba), 's' (abajo)";
    std::cin>>input;

    while(input != 'p') {

        if (input == 'd') {
            posY += 1; //ponte que esta en la posicion 0,0; entonces voy a moverlo a la derecha, la nueva posicion seria 0,1. Esto quiero decir que afecta al j (posY).
        } else if (input == 'a') {
            posY -= 1;
        } else if (input == 'w') {
            posX -= 1;
        } else if (input == 's') {
            posX += 1;
        }

        charPos(posX, posY, gameMap); //MAPA CON LA NUEVA POSICION DEL PERSONAJE
        std::cout<<"sigue presionandp 'd' (derecha), 'a' (izquiera), 'w' (arriba), 's' (abajo); si presionas 'p' se acaba el juego";
        std::cin>>input;
    }   

    std::cout<<std::endl;
    std::cout<<"JUEGO TERMINADO! \n";

    charPos(posX, posY, gameMap); //MAPA LUEGO DE PERDER

    return 0;
}

void charPos(int posX, int posY, char gameMap[5][5]) {

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) { 
            if( i == posX && j == posY ) {
                std::cout<<'H'<< ' ';
            } else {
                std::cout<<gameMap[i][j]<< ' ';
            }
        }
        std::cout<<std::endl;
    }
}