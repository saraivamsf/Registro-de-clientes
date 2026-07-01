#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct que cria todos os atributos para o cliente
typedef struct{
    int id;
    char nome[50];
    int idade;
    char telefone[20];
    char email[50];
}Cliente;

//Identifica o ID do ultimo cliente registrado e determina que o do proximo sera o sucessor deste numero
int proximoID() {
    FILE *arq = fopen("registro.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int id, idade;
    int ultimoID = 0;
    char nome[50], telefone[20], email[50];

    while (fscanf(arq, "%d;%49[^;];%d;%19[^;];%49[^\n]\n",
                  &id, nome, &idade, telefone, email) == 5) {
        ultimoID = id;
    }

    fclose(arq);

    return ultimoID + 1;
}   

//registra o cliente no arquivo de texto
void registrarCliente(Cliente c){   
    printf("Nome do cliente: ");
    fgets(c.nome, sizeof(c.nome), stdin);
    printf("Telefone do cliente: ");
    fgets(c.telefone, sizeof(c.telefone), stdin);
    printf("Idade do cliente: ");
    scanf("%d", &c.idade);
    getchar();
    printf("Email do cliente: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.id = proximoID();

    //remove os \n dos strings
    c.nome[strcspn(c.nome, "\n")] = '\0';
    c.telefone[strcspn(c.telefone, "\n")] = '\0';
    c.email[strcspn(c.email, "\n")] = '\0';

    FILE *arq = fopen("registro.txt", "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    //escreve as informaçoes no arquivo de texto
    fprintf(arq, "%d;%s;%d;%s;%s\n",
        c.id,
        c.nome,
        c.idade,
        c.telefone,
        c.email);
    printf("Cliente gravado com sucesso!\n");

    fclose(arq);
}

//busca pelo ID do cliente no arquivo e retorna suas informaçoes
//incompleto ainda...
//futuramente, sera necessario uma senha para acessar tais informaçoes 
void lerCliente(){
    printf("Digite o ID do cliente: \n");
}

int main(){
    int desejo=0;
    Cliente c;

    while(desejo==0){
        printf("O que deseja fazer?\n");
        printf("1- Registrar novo usuario\n2- Ver usuario registrado\n3- Sair\n");
        scanf("%d", &desejo);

        if(desejo==1){
            getchar();
            registrarCliente(c);
            desejo = 0;
        }

        if(desejo==2){
            getchar();
            lerCliente();
            desejo=0;
        } else break;
    }

    return 0;
}