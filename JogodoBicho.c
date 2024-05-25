#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define NUM_ANIMAIS 25 
#define NUM_NUMEROS 4
#define MAX_APOSTAS 100

const char* animais[NUM_ANIMAIS] = {
    "Avestruz", "Águia", "Burro", "Borboleta", "Cachorro", 
    "Cabra", "Carneiro", "Camelo", "Cobra", "Coelho", 
    "Cavalo", "Elefante", "Galo", "Gato", "Jacaré", 
    "Leão", "Macaco", "Porco", "Pavão", "Peru", 
    "Touro", "Tigre", "Urso", "Veado", "Vaca"
};


int numeros[NUM_ANIMAIS][NUM_NUMEROS] = {
    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16},
    {17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32},
    {33, 34, 35, 36}, {37, 38, 39, 40}, {41, 42, 43, 44}, {45, 46, 47, 48},
    {49, 50, 51, 52}, {53, 54, 55, 56}, {57, 58, 59, 60}, {61, 62, 63, 64},
    {65, 66, 67, 68}, {69, 70, 71, 72}, {73, 74, 75, 76}, {77, 78, 79, 80},
    {81, 82, 83, 84}, {85, 86, 87, 88}, {89, 90, 91, 92}, {93, 94, 95, 96},
    {97, 98, 99, 100}
};

bool verificar_aposta(const char* animal_aposta, int numero_aposta) {
    for (int i = 0; i < NUM_ANIMAIS; i++) {
        if (strcmp(animais[i], animal_aposta) == 0) {
            for (int j = 0; j < NUM_NUMEROS; j++) {
                if (numeros[i][j] == numero_aposta) {
                    return true; 
                }
            }
        } 
    }
    return false; 
}
int realizar_sorteio() {
    return rand() % 100 + 1; 
}

int main() {
    srand(time(NULL));      
    char animal_aposta[MAX_APOSTAS][20];
    int numero_aposta[MAX_APOSTAS];
    int total_apostas = 0;    
    int apostas_vencedoras = 0; 
    char opcao;

    do {
  
        printf("Digite o nome do animal da sua aposta: ");
        scanf("%s", animal_aposta[total_apostas]);
        printf("Digite o número associado a sua aposta: ");
        scanf("%d", &numero_aposta[total_apostas]);

        total_apostas++; 
        printf("Deseja fazer outra aposta? (s/n): ");
        scanf(" %c", &opcao);
    } while ((opcao == 's' || opcao == 'S') && total_apostas < MAX_APOSTAS);

    int numero_sorteado = realizar_sorteio();
    printf("Número sorteado: %d\n", numero_sorteado);
    
    for (int i = 0; i < total_apostas; i++) {
        if (verificar_aposta(animal_aposta[i], numero_sorteado)) {
            printf("Parabéns! Sua aposta no animal %s com o número %d foi vencedora!\n", animal_aposta[i], numero_sorteado);
            apostas_vencedoras++; 
        } else {
            printf("Que pena! Sua aposta no animal %s com o número %d não foi vencedora.\n", animal_aposta[i], numero_sorteado);
        }
    }
    printf("Total de apostas: %d\n", total_apostas);
    printf("Apostas vencedoras: %d\n", apostas_vencedoras);

    return 0;
}
