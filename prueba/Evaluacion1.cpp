#include <iostream>


// Función que registra los puntajes de cada jugador
void totalPoints(int points[5][3]) {
    for (int i = 0; i < 5; i++) {
        std::cout << "Players points " << i + 1 << ": ";
        for (int j = 0; j < 3; j++) {
            std::cout << "Trows " << j + 1 << ": ";
            std::cin >> points[i][j];
        }
    }
}
// Función que calcula el total de puntajes de cada jugador
void totalCalculation(int points[5][3], int total[5]) {
    for (int i = 0; i < 5; i++) {
        total[i] = 0;
        for (int j = 0; j < 3; j++) {
            total[i] += points[i][j];
        }
    }
}

// Función para encontrar al ganador
int findWinner(int total[5]) {
    int maxPoints = total[0];
    int winner = 0;
    for (int i = 1; i < 5; i++) {
        if (total[i] > maxPoints) {
            maxPoints = total[i];
            winner = i;
        }
    }
    return winner;
}

// Función que muestra los resultados
void showResults(int points[5][3], int total[5]) {
    std::cout << " Result: ";
    for (int i = 0; i < 5; i++) {
        std::cout << "Player " << i + 1 << ": ";
        for (int j = 0; j < 3; j++) {
            std::cout << points[i][j] << " ";
        }
        std::cout << "  Total: " << total[i] << std::endl;
    }
}

int main() {
    const int numPlayers = 5;
    const int numTrows = 3;
    
    int points[numPlayers][numTrows];
    int total[numPlayers];
    
    totalPoints(points);
    totalCalculation(points, total);
    
    int winner = findWinner(total);
    
    showResults(points, total);
    std::cout << " The winner is  " << winner + 1 << " with a total of  " << total[winner] << " points. ";
    
    return 0;
}
