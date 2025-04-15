#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrarCidade(Cidade *cidade) {
    printf("Digite o estado: ");
    scanf("%s", cidade->estado);
    printf("Digite o código da carta: ");
    scanf("%d", &cidade->codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", cidade->nome);
    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB: ");
    scanf("%f", &cidade->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);
}

void compararCidades(Cidade cidade1, Cidade cidade2, int atributo) {
    switch (atributo) {
        case 1: // População
            if (cidade1.populacao > cidade2.populacao) {
                printf("A cidade %s venceu com população de %d.\n", cidade1.nome, cidade1.populacao);
            } else {
                printf("A cidade %s venceu com população de %d.\n", cidade2.nome, cidade2.populacao);
            }
            break;
        case 2: // Área
            if (cidade1.area > cidade2.area) {
                printf("A cidade %s venceu com área de %.2f km².\n", cidade1.nome, cidade1.area);
            } else {
                printf("A cidade %s venceu com área de %.2f km².\n", cidade2.nome, cidade2.area);
            }
            break;
        case 3: // PIB
            if (cidade1.pib > cidade2.pib) {
                printf("A cidade %s venceu com PIB de %.2f.\n", cidade1.nome, cidade1.pib);
            } else {
                printf("A cidade %s venceu com PIB de %.2f.\n", cidade2.nome, cidade2.pib);
            }
            break;
        case 4: // Densidade populacional
            float densidade1 = (float)cidade1.populacao / cidade1.area;
            float densidade2 = (float)cidade2.populacao / cidade2.area;
            if (densidade1 < densidade2) {
                printf("A cidade %s venceu com densidade populacional de %.2f.\n", cidade1.nome, densidade1);
            } else {
                printf("A cidade %s venceu com densidade populacional de %.2f.\n", cidade2.nome, densidade2);
            }
            break;
        default:
            printf("Atributo inválido para comparação.\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int atributo;

    printf("Cadastro da primeira cidade:\n");
    cadastrarCidade(&cidade1);
    printf("Cadastro da segunda cidade:\n");
    cadastrarCidade(&cidade2);

    printf("Escolha o atributo para comparação (1: População, 2: Área, 3: PIB, 4: Densidade populacional): ");
    scanf("%d", &atributo);

    compararCidades(cidade1, cidade2, atributo);

    return 0;
}

