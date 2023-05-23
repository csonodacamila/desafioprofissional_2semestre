#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3

typedef struct {
    char nome[50];
    char email[50];
    char senha[20];
} Usuario;

int fazerCadastro(Usuario *usuario) {
    printf("===== Cadastro =====\n");
    printf("Nome: ");
    fgets(usuario->nome, sizeof(usuario->nome), stdin);
    usuario->nome[strcspn(usuario->nome, "\n")] = '\0';

    printf("Email: ");
    fgets(usuario->email, sizeof(usuario->email), stdin);
    usuario->email[strcspn(usuario->email, "\n")] = '\0';

    printf("Senha: ");
    fgets(usuario->senha, sizeof(usuario->senha), stdin);
    usuario->senha[strcspn(usuario->senha, "\n")] = '\0';

    printf("Cadastro realizado com sucesso!\n\n");

    return 1;
}

int fazerLogin(Usuario usuario) {
    char email[50];
    char senha[20];

    printf("===== Login =====\n");

    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("Email: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0'; 

        printf("Senha: ");
        fgets(senha, sizeof(senha), stdin);
        senha[strcspn(senha, "\n")] = '\0';

        if (strcmp(email, usuario.email) == 0 && strcmp(senha, usuario.senha) == 0) {
            printf("Login realizado com sucesso!\n");
            return 1;
        } else {
            printf("Email ou senha incorretos. Tente novamente.\n");
        }
    }

    printf("Voce excedeu o numero maximo de tentativas. Saindo...\n");
    return 0;
}

int main() {
    Usuario usuario;
    int opcao;

    printf("===== Tela de Cadastro e Login =====\n");

    printf("Opcoes:\n");
    printf("1 - Fazer Cadastro\n");
    printf("2 - Fazer Login\n");
    printf("0 - Sair\n");

    while (1) {
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                fazerCadastro(&usuario);
                break;
            case 2:
                if (fazerLogin(usuario))
                    return 0;
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("opcao inválida. Tente novamente.\n");
        }
    }

    return 0;
}
