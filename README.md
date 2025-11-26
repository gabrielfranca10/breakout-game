nando101210
nando101210
Compartilhando tela

França — 05/10/2025 15:03
Resumão – Infraestrutura de Comunicação (Cola)
Protocolo

Regras de comunicação.

Exemplos:

Aplicação: HTTP, DNS, SMTP

Transporte: TCP, UDP

Rede: IP

DSL vs FTTH

DSL: usa cobre (linha telefônica).

FTTH: usa fibra óptica.

Desvantagens DSL: mais lento, perde qualidade com distância, interferência.

Comutação

Circuitos: caminho fixo, banda garantida, pouco eficiente.

Pacotes: divide em pacotes, mais eficiente, pode ter atraso/perda.

Atraso nodal

Fórmula:

𝐴
𝑡
𝑜
𝑡
𝑎
𝑙
=
𝐴
𝑝
𝑟
𝑜
𝑐
+
𝐴
𝑓
𝑖
𝑙
𝑎
+
𝐴
𝑡
𝑟
𝑎
𝑛
𝑠
+
𝐴
𝑝
𝑟
𝑜
𝑝
A
total
    ​

=A
proc
    ​

+A
fila
    ​

+A
trans
    ​

+A
prop
    ​


Valores: 10 ms + 5 ms + 1 ms + 4 ms = 20 ms. ✅


HTTP

Cliente-servidor, camada aplicação.

Mensagens: GET, POST, PUT, DELETE.

Usa TCP.

Correio eletrônico

SMTP = envio.

POP3/IMAP = recebimento.

HTTP/HTTPS = webmail.

QUIC

Baseado em UDP, mas confiável.

Rápido, seguro (TLS embutido).

Usado no HTTP/3, YouTube, Google.

DASH

Vídeo em segmentos, qualidade adaptativa.

Usado em streaming (Netflix, YouTube).

DNS

Iterativo: cliente faz várias consultas.

Recursivo: servidor resolve tudo.

Recursivo = fácil pro cliente, pesado pro servidor.

Cliente-servidor x P2P

Cliente-servidor: centralizado, fácil controle.

P2P: mais escalável (cada nó ajuda).

DDoS via DNS

Amplificação: invasor manda consulta falsificada → servidores mandam respostas enormes para a vítima.

Camada transporte / UDP

Função: comunicação fim a fim, multiplexação.

UDP: rápido, checksum, sem confiabilidade/fluxo/congestionamento.

TCP conexão

3-way handshake: SYN → SYN+ACK → ACK.

RTT TCP

Fórmula:

𝑅
𝑇
𝑇
𝑒
𝑠
𝑡
=
(
1
−
𝛼
)
𝑅
𝑇
𝑇
𝑒
𝑠
𝑡
+
𝛼
𝑅
𝑇
𝑇
𝑎
𝑚
𝑜
𝑠
𝑡
𝑟
𝑎
𝑑
𝑜
RTT
est
    ​

=(1−α)RTT
est
    ​

+αRTT
amostrado
    ​


Média móvel exponencial = suaviza valores.

TCP Fluxo x Congestionamento

Fluxo: protege receptor.

Congestionamento: protege a rede.

Prevenção de congestionamento

TCP usa slow start + congestion avoidance.

Aplica no início da conexão ou após perda.

Tahoe x Reno

Tahoe: perda → volta ao início (slow start).

Reno: usa Fast Retransmit + Fast Recovery, mais rápido na recuperação.

🔥
 Pronto, tá no jeito de enfiar no bolso da calça antes da prova kkkkk.
França — 05/10/2025 15:22
Imagem
Imagem
Imagem
Imagem
Imagem
Imagem
Imagem
Imagem
Imagem
França — 06/10/2025 18:22
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1,s2;
    int matriz, len1, len2, maxLen;
    s1 = malloc(51 * sizeof(char));
    s2 = malloc(51 * sizeof(char));

    while (fgets(s1, 51, stdin) != NULL && fgets(s2, 51, stdin) != NULL) {
        s1[strcspn(s1, "\n")] = 0;
        s2[strcspn(s2, "\n")] = 0;

        len1 = strlen(s1);
        len2 = strlen(s2);

        matriz = malloc((len1 + 1) * sizeof(int ));
        for (int i = 0; i <= len1; i++) {
            matriz[i] = malloc((len2 + 1) sizeof(int));
            for(int j = 0; j <= len2; j++){
                matriz[i][j];
            }
        }

        maxLen = 0;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    matriz[i][j] = matriz[i - 1][j - 1] + 1;
                    if (matriz[i][j] > maxLen) {
                        maxLen = matriz[i][j];
                    }
                }else{
                    matriz[i][j] = 0;
                }
            }
        }

        printf("%d\n", maxLen);

        for (int i = 0; i <= len1; i++){
            free(matriz[i]);
        }
        free(matriz);
    }
    free(s1);
    free(s2);
    return 0;
}
nando101210
 iniciou uma chamada que durou 15 minutos. — 06/10/2025 18:23
França — 06/10/2025 19:01
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas
typedef struct {
Expandir
message.txt
6 KB
França — 07/10/2025 11:34
Imagem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char codigo[10];
    char nome[50];
} Fornecedor;

typedef struct {
    char nome[50];
    float preco;
    Fornecedor fornecedor;
} Produto;

// Função para criar o catálogo (aloca dinamicamente)
Produto* criar_catalogo(int n) {
    Produto catalogo = (Produto) malloc(n * sizeof(Produto));
    if (catalogo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return catalogo;
}

// Função para adicionar produtos
void adicionar_produtos(Produto catalogo, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome do produto: ");
        fgets(catalogo[i].nome, 50, stdin);
        catalogo[i].nome[strcspn(catalogo[i].nome, "\n")] = '\0';

        printf("Preço: ");
        scanf("%f", &catalogo[i].preco);
        getchar(); // limpa o buffer

        printf("Código do fornecedor: ");
        fgets(catalogo[i].fornecedor.codigo, 10, stdin);
        catalogo[i].fornecedor.codigo[strcspn(catalogo[i].fornecedor.codigo, "\n")] = '\0';

        printf("Nome do fornecedor: ");
        fgets(catalogo[i].fornecedor.nome, 50, stdin);
        catalogo[i].fornecedor.nome[strcspn(catalogo[i].fornecedor.nome, "\n")] = '\0';
    }
}

// Função para exibir catálogo
void exibir_catalogo(Produtocatalogo, int n) {
    printf("\n=== CATÁLOGO DE PRODUTOS ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s\n", catalogo[i].nome);
        printf("Preço: %.2f\n", catalogo[i].preco);
        printf("Fornecedor: %s (Código: %s)\n", 
               catalogo[i].fornecedor.nome, 
               catalogo[i].fornecedor.codigo);
    }
}

int main() {
    int n;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); // limpar buffer

    Produto *catalogo = criar_catalogo(n);

    adicionar_produtos(catalogo, n);
    exibir_catalogo(catalogo, n);

    free(catalogo);
    return 0;
}
nando101210 — 07/10/2025 18:02
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int testes, quantidade;
    scanf("%d", &testes);

    for (int t = 0; t < testes; t++) {
        scanf("%d", &quantidade);

        char nomes = malloc(quantidade * sizeof(char *));
        char chamada = malloc(quantidade * sizeof(char )); 
        for (int i = 0; i < quantidade; i++) {
            nomes[i] = malloc(51);
            scanf("%s", nomes[i]);
        }
        for (int i = 0; i < quantidade; i++) {
            chamada[i] = malloc(101);
            scanf("%s", chamada[i]);
        }

        int primeiro = 1;
        for (int i = 0; i < quantidade; i++) {
            int p = 0, a = 0;
            for (int j = 0; j < strlen(chamada[i]); j++) {
                if (chamada[i][j] == 'P') p++;
                if (chamada[i][j] == 'A') a++;
            }
            int total = p + a;
            if (total > 0) {
                int presenca = (p 100) / total;
                if (presenca < 75) {
                    if (!primeiro) printf(" ");
                    printf("%s", nomes[i]);
                    primeiro = 0;
                }
            }
        }
        printf("\n");

        for (int i = 0; i < quantidade; i++) {
            free(nomes[i]);
            free(chamada[i]);
        }
        free(nomes);
        free(chamada);
    }
    return 0;
}
França — 07/10/2025 18:07
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[51];
    char frequencia;
}Aluno;

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        int N;
        scanf("%d", &N);
        Alunoalunos = (Aluno)malloc(N sizeof(Aluno));

        for(int i = 0; i < N; i++)
        {
            scanf("%50s", alunos[i].nome);
        }

        for(int i = 0; i < N; i++)
        {
            alunos[i].frequencia = (char)malloc(101 sizeof(char));
            scanf("%s", alunos[i].frequencia);
        }

        int primeiro = 1;

        for(int i = 0; i < N; i++)
        {
            int validos = 0;
            int presenca = 0;

            for(int j = 0; alunos[i].frequencia[j] != '\0'; j++)
            {
                if(alunos[i].frequencia[j] != 'M')
                {
                    validos++;
                    if(alunos[i].frequencia[j] == 'P')
                    {
                        presenca++;
                    }
                }
            }

            float percentual_faltas = 0.0;
            if(validos > 0)
            {
                percentual_faltas = (presenca * 100.0) / validos;
            }

            if(percentual_faltas < 75.0)
            {
                if(primeiro == 0)
                {
                    printf(" ");
                }
                printf("%s", alunos[i].nome);
                primeiro = 0;
            }
        }

        printf("\n");

        for(int i = 0; i < N; i++)
        {
            free(alunos[i].frequencia);
        }
        free(alunos);
    }

    return 0;

}
França — 10/10/2025 13:37
https://cesar.zoom.us/j/83095283177
Zoom
Join our Cloud HD Video Meeting
Zoom is the leader in modern enterprise cloud communications.
Join our Cloud HD Video Meeting
França
 iniciou uma chamada que durou 37 minutos. — 14/10/2025 17:49
nando101210
 iniciou uma chamada que durou uma hora. — 15/10/2025 13:58
França
 iniciou uma chamada que durou 10 minutos. — 15/10/2025 15:16
França — 16/10/2025 14:17
https://cesar.zoom.us/j/89855944701
Zoom
Join our Cloud HD Video Meeting
Zoom is the leader in modern enterprise cloud communications.
Join our Cloud HD Video Meeting
França — 17/10/2025 13:53
https://cesar.zoom.us/j/83095283177
Zoom
Join our Cloud HD Video Meeting
Zoom is the leader in modern enterprise cloud communications.
Join our Cloud HD Video Meeting
França — 20/10/2025 09:12
🎯
 Por que o Breakout é uma ótima escolha pro teu projeto:

Tem movimento e colisão (exigência do PDF).

Usa structs, ponteiros, malloc, listas e matrizes de forma natural:

Structs → bola, barra, bloco.

Lista encadeada → blocos ativos.

Matrizes → layout inicial dos blocos.

Ponteiros/malloc → criar blocos dinamicamente.

Arquivo → salvar o top score.

Fica lindo na Raylib — dá pra ter rebote suave e efeitos visuais simples.

Simples de expandir: múltiplas fases, power-ups, cores diferentes, etc.
nando101210 — 20/10/2025 09:21
Pong (2 jogadores ou 1 jogador com IA simples)

Descrição: Bola quica entre duas barras; objetivo é não deixar passar.

Mecânicas: colisão bola-barra, controle via teclado, placar.

Usa: structs (bola, barras), timer para movimento, arquivo para placar.

Vantagem: simples, bom para aprender o controle de tempo e atualização da tela.
França
 iniciou uma chamada que durou 3 horas. — 20/10/2025 16:31
nando101210 — 20/10/2025 17:22
Tipo de arquivo em anexo: unknown
image.png
643.03 KB
Tipo de arquivo em anexo: acrobat
Documento PDF.pdf
643.03 KB
França — 20/10/2025 18:10
cd ~/breakout-game
gcc src/*.c -Iinclude -o build/breakout-game -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
./build/breakout-game
França — 20/10/2025 18:19
https://releases.ubuntu.com/22.04/ubuntu-22.04.5-desktop-amd64.iso
França — 20/10/2025 18:31
Ubuntu Raylib 22.04
França — 20/10/2025 19:10
sudo apt install libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev -y
França — 20/10/2025 20:12
Tipo de arquivo em anexo: acrobat
atividade_mips_gfap.pdf
3.22 KB
França — 21/10/2025 15:48
Tipo de arquivo em anexo: acrobat
BREAKOUT-GAME.pdf
971.21 KB
França — 22/10/2025 10:20
🎮
 Projeto: Breakout em C (com Raylib)

👥
 Equipe
    •    Pessoa 1 — Gabriel: foco em lógica, física e mecânica do jogo
    •    Pessoa 2 — Bia: foco em interface, menus, pontuação e organização visual

⸻

🧭
 Fases do Desenvolvimento (e commits obrigatórios)

Fase 1 — Estrutura inicial do projeto

Objetivo: preparar o repositório, organização e Makefile.

Responsável: Ambos

Tarefas:
    •    Criar pastas src/, include/, build/.
    •    Criar arquivos vazios (main.c, game.c, menu.c, paddle.c, ball.c, brick.c e seus .h).
    •    Criar o Makefile e testar a compilação.
    •    Criar README.md explicando como compilar e rodar.

Commit:

feat: estrutura inicial do projeto e Makefile configurado

⸻

Fase 2 — Janela inicial e loop básico

Objetivo: abrir a janela Raylib e desenhar uma tela estática com título.

Responsável: Bia

Tarefas:
    •    Implementar main.c com InitWindow(), BeginDrawing() e DrawText().
    •    Criar screens.h para gerenciar estados (SCREEN_MENU, SCREEN_GAME, etc.).
    •    Fazer tela de menu com opção “Começar” (sem lógica ainda).

Commit:

feat: adiciona tela inicial do jogo e loop principal Raylib

⸻

Fase 3 — Entidades principais

Objetivo: criar a estrutura base do jogo.

Responsável: Gabriel

Tarefas:
    •    Criar structs:
    •    Ball (posição, raio, velocidade, cor)
    •    Paddle (posição, tamanho, velocidade, cor)
    •    Brick (posição, ativo/inativo)
    •    Criar funções em game.c:
    •    InitGame(), UpdateGame(), DrawGame().

Commit:

feat: adiciona entidades Ball, Paddle e Brick e funções principais do jogo

⸻

Fase 4 — Mecânica de colisão e pontuação

Objetivo: fazer o jogo realmente jogar.

Responsável: Gabriel

Tarefas:
    •    Implementar movimento da bola e colisão com paredes, paddle e blocos.
    •    Implementar pontuação (cada bloco destruído = +10 pontos).
    •    Reiniciar bola se cair abaixo da tela.
    •    Mostrar pontuação e vidas na tela.

Commit:

feat: adiciona física da bola, colisões e sistema de pontuação

⸻

Fase 5 — Interface e sistema de menus

Objetivo: interligar as telas e permitir voltar ao menu.

Responsável: Bia

Tarefas:
    •    Implementar menu inicial com botões:
    •    “Começar Jogo”
    •    “Ver Pontuações”
    •    “Sair”
    •    Criar tela de pontuação (scores.txt para salvar).
    •    Exibir “Game Over” e opção de voltar ao menu.

Commit:

feat: implementa menus, pontuação e salvamento de recordes

⸻

Fase 6 — Fases e dificuldade

Objetivo: adicionar progressão.

Responsável: Gabriel

Tarefas:
    •    Adicionar níveis (fases) com layouts de blocos diferentes.
    •    Aumentar velocidade da bola a cada fase.
    •    Resetar nível quando todos os blocos forem destruídos.

Commit:

feat: adiciona sistema de fases e aumento progressivo de dificuldade

⸻

Fase 7 — Polimento e extras

Objetivo: deixar o jogo mais apresentável.

Responsável: Bia

Tarefas:
    •    Adicionar sons (rebate, destruição, game over).
    •    Alterar cores, fundo, textos e fontes.
    •    Adicionar ícone e título personalizados.
    •    Criar vídeo de gameplay curto e subir no README.

Commit:

feat: adiciona sons, efeitos visuais e vídeo de demonstração

⸻

📦
 Entrega final

No GitHub:
    •    src/ e include/ com código completo
    •    build/ (compilado opcional)
    •    Makefile
    •    README.md com instruções e link do vídeo
    •    scores.txt (pode começar vazio)
França — 23/10/2025 11:37
Usar obrigatoriamente os seguintes conceitos no jogo:
○ Estruturas (structs);
○ Ponteiros;
○ Alocação dinâmica de memória;
○ Listas encadeadas;
○ Matrizes
○ Escrita e leitura em arquivo (top scores, por ex.);
nando101210 — 23/10/2025 15:57
inserir ordenado
inserir no final
inserir no inicio
remover no final
remover no inicio
remover duplicado
buscar
exibir
contar
liberar 
inseriri no meio
França — 23/10/2025 18:50
Crie uma lista e insira 5 números digitados pelo usuário, depois exiba-os na ordem de inserção.

Exiba os números da lista em ordem inversa sem alterar a lista (use recursão).

Conte quantos elementos há na lista sem usar variável global.

Encontre o maior e o menor elemento da lista.

Busque um número informado pelo usuário e diga se ele está ou não presente.

Remova o primeiro e o último elemento da lista.

Remova todos os elementos ímpares da lista.

Some todos os elementos da lista e mostre o resultado.
nando101210
 iniciou uma chamada que durou uma hora. — 27/10/2025 15:37
França — 27/10/2025 17:35
ei manda tua 1 dps como ficou
nando101210
 iniciou uma chamada que durou poucos segundos. — 27/10/2025 18:02
nando101210 — 27/10/2025 18:02
blz
vou começar agr
França — 27/10/2025 18:58
a minha achei q ficou mt de boa
França — 31/10/2025 11:39
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No{
    int notas;
    struct No* prox;
}No;

void addfinal(No head, int notas)
{
    No* novoNo = (No)malloc(sizeof(No));
    if(novoNo == NULL)
    {
        return;
    }

    novoNo->notas = notas;
    novoNo->prox = NULL;

    if(head == NULL)
    {
        head = novoNo;
        return;
    }

    No atual = head;
    while(atual->prox != NULL)
    {
        atual = atual->prox;
    }
    atual->prox = novoNo;
}

void copiarlista(Nooriginal, No copia)
{
    while(original != NULL)
    {
        addfinal(copia, original->notas);
        original = original->prox;
    }
}

void ordenarlista(No head)
{
    Noi = head;
    No j;
    while(i != NULL)
    {
        int temp;
        j = i->prox;
        while(j != NULL)
        {
            if(j->notas > i->notas)
            {
                temp = i->notas;
                i->notas = j->notas;
                j->notas = temp;
            }
            j = j->prox;
        }
        i = i->prox;
    }
}

int contariguais(Nooriginal, No copia)
{
    int cont = 0;
    No p1 = original;
    No* p2 = copia;

    while(p1 != NULL)
    {
        if(p1->notas == p2->notas)
        {
            cont++;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }
    return cont;
}

void liberarlista(No *head)
{
    No temp;
    while(head != NULL)
    {
        temp =head;
        head = (head)->prox;
        free(temp);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int k = 0; k < N; k++)
    {
        int M, notas;
        scanf("%d", &M);
        No* original = NULL;
        No* copia = NULL;

        for(int i = 0; i < M; i++)
        {
            scanf("%d", &notas);
            addfinal(&original, notas);
        }
        copiarlista(original, &copia);
        ordenarlista(copia);

        int iguais = contariguais(original, copia);
        printf("%d\n", iguais);

        liberarlista(&original);
        liberarlista(&copia);
    }

    return 0;
}
nando101210
 iniciou uma chamada que durou 43 minutos. — 31/10/2025 12:07
nando101210
 iniciou uma chamada que durou uma hora. — 10/11/2025 18:34
nando101210
 iniciou uma chamada que durou poucos segundos. — 12/11/2025 16:22
França
 iniciou uma chamada que durou 4 horas. — 12/11/2025 16:22
nando101210
 iniciou uma chamada que durou poucos segundos. — 17/11/2025 14:49
França
 iniciou uma chamada que durou 5 horas. — 17/11/2025 14:58
França — 18/11/2025 17:37
#include <stdio.h>

int fat[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int conta(int N)
{
    if(N == 0)
        return 0;

    int i = 9;
    while(fat[i] > N)
        i--;

    return 1 + conta(N - fat[i]);
}

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", conta(N));
    return 0;
}
----------------------------
#include <stdio.h>

int fatorial(int n)
{
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

int maiorFat(int n, int i)
{
    if (i == 0) return 1;

    int f = fatorial(i);

    if (f <= n)
        return f;

    return maiorFat(n, i - 1);
}

int conta(int n)
{
    if (n == 0)
        return 0;

    int f = maiorFat(n, 9);
    return 1 + conta(n - f);
}

int main()
{
    int N;
    scanf("%d", &N);

    printf("%d\n", conta(N));
    return 0;
}
França — Ontem às 19:26
https://www.canva.com/design/DAGl9oDItTA/czAjUKksZqC44ttbDm5qhw/edit
Tipo de arquivo em anexo: acrobat
Flappy-Bird-Game-PIF.pdf
19.30 MB
França — 02:59
🟨 BREAKOUT GAME\
Projeto desenvolvido como prática de programação em C, utilizando a
biblioteca Raylib, recriando o clássico Breakout com um visual mais
moderno, fundo personalizado e física aprimorada.

📚 Descrição\
Expandir
README.md
4 KB
França — 13:36
https://cesar.zoom.us/j/83095283177
Zoom
Join our Cloud HD Video Meeting
Zoom is the leader in modern enterprise cloud communications.
Join our Cloud HD Video Meeting
﻿
França
franca0764
 
 
 
 
:nike_7:
🟨 BREAKOUT GAME\
Projeto desenvolvido como prática de programação em C, utilizando a
biblioteca Raylib, recriando o clássico Breakout com um visual mais
moderno, fundo personalizado e física aprimorada.

📚 Descrição\
O jogo consiste em controlar uma barra (paddle) para rebater a bola e
destruir todos os tijolos.\
O projeto aplica princípios fundamentais da programação estruturada,
modularização e uso da biblioteca gráfica Raylib.

👨‍💻 Autores - Fernando Soares da Silva - Gabriel França de Albuquerque
Pernambuco - Lucas Canto

🎥 Assista ao screencast do jogo

------------------------------------------------------------------------

# 🚀 Como Rodar o Jogo

## ✅ Pré-requisitos

Para compilar e executar o Breakout Game, você precisa ter:

-   Compilador C (GCC recomendado)\
-   Biblioteca Raylib → https://www.raylib.com/\
-   Git para clonar o repositório

------------------------------------------------------------------------

# 🔥 Passo inicial (para todos os sistemas)

Clone o repositório:

``` bash
git clone https://github.com/gabrielfranca10/breakout-game.git
cd breakout-game
```

------------------------------------------------------------------------

# 🐧 Instruções para Linux

### 1 Instalar dependências:

``` bash
sudo apt update
sudo apt install build-essential gcc make git
sudo apt install libraylib-dev
```

### Caso **libraylib-dev** não esteja disponível

Instale manualmente (instruções oficiais da
**[Raylib](https://www.raylib.com/)**):

``` bash
cd ~
git clone https://github.com/raysan5/raylib.git
cd raylib
mkdir build
cd build
cmake ..
sudo make install
sudo ldconfig

OBS: CASO DER ERRO AO RODAR "cmake ..", SEU CMAKE PROVAVELMENTE É ANTIGO.
Instale dependências necessárias e use o cmake do Snap:

sudo apt install libxinerama-dev libxcursor-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libasound2-dev libpulse-dev
/snap/bin/cmake ..
make
sudo make install
sudo ldconfig
```

### (Com o repositório do jogo clonado) 2 - Compilar o jogo:

``` bash
cd breakout-game
make
```

### 3 - Rodar:

``` bash
make run
```

(Opcional) Limpar arquivos gerados:

``` bash
make clean
```

------------------------------------------------------------------------

# 🍎 Instruções para macOS

### Instalar dependências:

``` bash
brew install raylib
brew install make gcc
```

### Compilar:

``` bash
make
```

### Rodar:

``` bash
make run
```

(Opcional) Limpar:

``` bash
make clean
```

------------------------------------------------------------------------

# 🪟 Instruções para Windows (via MSYS2)

### Instalar MSYS2

Baixe em: https://www.msys2.org/

Abra **MSYS2 MinGW 64-bit**

### Atualizar o sistema e instalar dependências:

``` bash
pacman -Syu
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-raylib git
```

### Navegar até a pasta do projeto:

``` bash
cd /c/Caminho/Para/Seu/breakout-game
```

### Compilar:

``` bash
make
```

### Rodar:

``` bash
./breakout-game.exe
```

(Opcional) limpar:

``` bash
make clean
```

------------------------------------------------------------------------

# ⚠️ Erros Comuns e Soluções

### ❗ raylib not found

Certifique-se de que a Raylib está instalada corretamente e que está no
caminho da sua toolchain.

### ❗ Permission denied (Linux/macOS):

``` bash
chmod +x build/breakout-game
./build/breakout-game
```

### ❗ No Windows: "command not found" ao usar make

Abra **MSYS2 MinGW 64-bit**, não use o MSYS padrão.

------------------------------------------------------------------------

# 🎮 Divirta-se jogando!

Se curtir o projeto, ⭐ deixe uma estrela no repositório!
README.md
4 KB
