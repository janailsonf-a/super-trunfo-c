#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[30];
    int populacao;
    int area;
    int densidade;
    int pib;
} Carta;


void mostrarMenu(int ignorar) {
    printf("\nEscolha um atributo:\n");
    if (ignorar != 1) printf("1. População\n");
    if (ignorar != 2) printf("2. Área\n");
    if (ignorar != 3) printf("3. Densidade Demográfica\n");
    if (ignorar != 4) printf("4. PIB\n");
}


int obterAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.densidade;
        case 4: return carta.pib;
        default: return 0;
    }
}


const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "Densidade Demográfica";
        case 4: return "PIB";
        default: return "Desconhecido";
    }
}


int main() {

    Carta carta1 = {"Brasil", 213000000, 8516000, 25, 2200};
    Carta carta2 = {"Canadá", 38000000, 9985000, 4, 1900};

    int escolha1 = 0, escolha2 = 0;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
    printf("Comparando: %s vs %s\n", carta1.nome, carta2.nome);


    do {
        mostrarMenu(0);
        printf("Escolha o 1º atributo: ");
        scanf("%d", &escolha1);
        if (escolha1 < 1 || escolha1 > 4) {
            printf("Opção inválida!\n");
            escolha1 = 0;
        }
    } while (escolha1 == 0);


    do {
        mostrarMenu(escolha1);
        printf("Escolha o 2º atributo (diferente do primeiro): ");
        scanf("%d", &escolha2);
        if (escolha2 < 1 || escolha2 > 4 || escolha2 == escolha1) {
            printf("Opção inválida!\n");
            escolha2 = 0;
        }
    } while (escolha2 == 0);


    int valor1_c1 = obterAtributo(carta1, escolha1);
    int valor1_c2 = obterAtributo(carta2, escolha1);
    int valor2_c1 = obterAtributo(carta1, escolha2);
    int valor2_c2 = obterAtributo(carta2, escolha2);


    int ponto_c1 = 0, ponto_c2 = 0;


    if (escolha1 == 3) {

        ponto_c1 += (valor1_c1 < valor1_c2) ? 1 : 0;
        ponto_c2 += (valor1_c2 < valor1_c1) ? 1 : 0;
    } else {
        ponto_c1 += (valor1_c1 > valor1_c2) ? 1 : 0;
        ponto_c2 += (valor1_c2 > valor1_c1) ? 1 : 0;
    }


    if (escolha2 == 3) {
        ponto_c1 += (valor2_c1 < valor2_c2) ? 1 : 0;
        ponto_c2 += (valor2_c2 < valor2_c1) ? 1 : 0;
    } else {
        ponto_c1 += (valor2_c1 > valor2_c2) ? 1 : 0;
        ponto_c2 += (valor2_c2 > valor2_c1) ? 1 : 0;
    }


    int soma_c1 = valor1_c1 + valor2_c1;
    int soma_c2 = valor1_c2 + valor2_c2;


    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("País 1: %s\n", carta1.nome);
    printf("%s: %d\n", nomeAtributo(escolha1), valor1_c1);
    printf("%s: %d\n", nomeAtributo(escolha2), valor2_c1);
    printf("Soma dos atributos: %d\n", soma_c1);

    printf("\nPaís 2: %s\n", carta2.nome);
    printf("%s: %d\n", nomeAtributo(escolha1), valor1_c2);
    printf("%s: %d\n", nomeAtributo(escolha2), valor2_c2);
    printf("Soma dos atributos: %d\n", soma_c2);

    if (soma_c1 > soma_c2) {
        printf("\n🏆 Vencedor: %s\n", carta1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("\n🏆 Vencedor: %s\n", carta2.nome);
    } else {
        printf("\n🤝 Empate!\n");
    }

    return 0;
}
