//  Victor Simão de Matos   RA:2760482221023
//  Iago Campanhol de Lima  RA:2760482221036

/*
*Objetivo:
    Dada uma senha digitada pelo usuário, verificar se esta satisfaz as normas descritas abaixo:
-Deve conter pelo menos 8 caracteres;
-Deve conter pelo menos uma letra maiúscula;
-Deve conter pelo menos uma letra minúscula;
-Deve conter pelo menos um número;
-Deve conter pelo menos um dos seguintes símbolos: !, ?, #, @, $;
-Não pode ser um palíndromo, i.e., revertendo-se os caracteres não podemos obter a mesma senha;
-Não pode conter nenhuma palavra reservada de um dicionário;
*Entrada:
    entrada é composta por um inteiro n, seguido por n palavras, que compõem o dicionário de palavras reservadas.
Todas as palavras do dicionário estão em minúsculas. Por fim, temos a senha digitada pelo usuário.
Você pode assumir que 0 ≤ n ≤ 50 e que cada palavra reservada não possui mais do que 20 caracteres.
A senha digitada pelo usuário possui entre 1 e 50 caracteres. Você pode assumir que não há caracteres acentuados.
*Saída:
    A saída deve conter "OK" se a senha digitada satisfaz as normas para uma senha, ou um subconjunto das mensagens
contidas nas normas descrevendo todos os erros encontrados.
.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se a senha é um palíndromo
int eh_palindromo(const char *str) {
    int tam = strlen(str);
    for (int i = 0; i < tam / 2; i++) {
        if (str[i] != str[tam - i - 1]) {
            return 0; // Não é palíndromo
        }
    }
    return 1; // É palíndromo
}

// Função para verificar se a senha contém uma letra maiúscula
int tem_maiuscula(const char *str) {
    while (*str) {
        if (isupper(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

// Função para verificar se a senha contém uma letra minúscula
int tem_minuscula(const char *str) {
    while (*str) {
        if (islower(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

// Função para verificar se a senha contém um número
int tem_numero(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

// Função para verificar se a senha contém um dos símbolos especificados
int tem_simbolo(const char *str) {
    const char *simbolos = "!?#@$";
    while (*str) {
        if (strchr(simbolos, *str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

// Função para verificar se a senha contém uma palavra do dicionário
int contem_palavra_reservada(const char *senha, const char **dicionario, int n) {
    for (int i = 0; i < n; i++) {
        if (strstr(senha, dicionario[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    char dicionario[50][21]; // máximo de 50 palavras, cada uma com até 20 caracteres
    for (int i = 0; i < n; i++) {
        scanf("%20s", dicionario[i]);
    }

    char senha[51]; // Senha do usuário, até 50 caracteres
    scanf("%50s", senha);

    int erros = 0;

    if (strlen(senha) < 8) {
        printf("Senha deve conter pelo menos 8 caracteres.\n");
        erros++;
    }

    if (!tem_maiuscula(senha)) {
        printf("Senha deve conter pelo menos uma letra maiúscula.\n");
        erros++;
    }

    if (!tem_minuscula(senha)) {
        printf("Senha deve conter pelo menos uma letra minúscula.\n");
        erros++;
    }

    if (!tem_numero(senha)) {
        printf("Senha deve conter pelo menos um número.\n");
        erros++;
    }

    if (!tem_simbolo(senha)) {
        printf("Senha deve conter pelo menos um dos seguintes símbolos: !, ?, #, @, $.\n");
        erros++;
    }

    if (eh_palindromo(senha)) {
        printf("Senha não pode ser um palíndromo.\n");
        erros++;
    }

    if (contem_palavra_reservada(senha, (const char **)dicionario, n)) {
        printf("Senha não pode conter palavras reservadas do dicionário.\n");
        erros++;
    }

    if (erros == 0) {
        printf("OK\n");
    }

    return 0;
}
