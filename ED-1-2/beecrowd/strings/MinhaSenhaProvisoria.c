#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Função para validar o RA e encontrar o índice inicial da senha
bool validar_ra(const char *ra, int *indice_inicio) {
    // 1. Verifica se tem exatamente 20 caracteres
    if (strlen(ra) != 20) {
        return false;
    }
    
    // 2. Verifica se começa com "RA"
    if (ra[0] != 'R' || ra[1] != 'A') {
        return false;
    }
    
    bool apenas_zeros = true;
    int primeiro_nao_zero = -1;
    
    // 3. Verifica os 18 caracteres seguintes
    for (int i = 2; i < 20; i++) {
        // Se algum não for dígito, é inválido
        if (!isdigit(ra[i])) {
            return false;
        }
        // Identifica o primeiro dígito diferente de zero
        if (ra[i] != '0' && primeiro_nao_zero == -1) {
            primeiro_nao_zero = i;
            apenas_zeros = false;
        }
    }
    
    // De acordo com as regras, Z <= 17 (não pode ter 18 zeros)
    if (apenas_zeros) {
        return false;
    }
    
    // Armazena a posição do primeiro dígito válido da senha
    *indice_inicio = primeiro_nao_zero;
    return true;
}

int main() {
    int n;
    
    // Lê a quantidade de casos de teste
    if (scanf("%d", &n) != 1) return 0;
    
    char ra[105]; // Buffer de tamanho suficiente para suportar as strings da entrada
    
    for (int i = 0; i < n; i++) {
        scanf("%s", ra);
        
        int indice_inicio;
        
        // Verifica se o RA é válido e, em caso afirmativo, imprime a partir da posição inicial da senha
        if (validar_ra(ra, &indice_inicio)) {
            // Imprime a substring que constitui a senha
            printf("%s\n", &ra[indice_inicio]);
        } else {
            // Caso falhe nas regras de formação
            printf("INVALID DATA\n");
        }
    }
    
    return 0;
}