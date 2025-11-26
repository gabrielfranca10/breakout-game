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
