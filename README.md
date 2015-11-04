# NR Text Adventure
O jogo Text Adventure que fiz para concorrer no "NR Maníaco 2015".

# Comandos
Os comandos no jogo são bem ao estilo de jogos Text Adventure mesmo:

  ```olhar```   - Mosra as informações da sala atual.
  
  ```direção``` - Vai para a sala nessa direção. (Exemplo: ```norte```)
  
  ```sair, quit ou exit``` - Sai do jogo.

# Instruções
Aqui estão as instruções para baixar e jogar:

Primeiro, baixe o arquivo ```Binaries.zip``` da versão 1.0 do jogo, na aba ```Releases```, e abra-o. (Ou baixe diretamente por este link: https://github.com/DarkRyu550/nr-text-adventure/releases/download/v1.0/Binaries.zip)

Depois, abra e extraia o arquivo ```.zip``` que corresponde ao seu sistema para uma pasta de sua escolha. (```Win32.zip``` para Windows e ```Linux-x86_64.zip``` para Linux 64-bits)

Finalmente, abra o arquivo do jogo: ```Adventure.bat``` para Windows e ```Adventure``` para Linux.

Lembrando que o jogo só funcionará se a pasta ```Assets/``` estiver junto com o jogo!

# Instruções para usuários Windows
Se você jogar no Windows, e quiser que as letras acentuadas apareçam corretamente, você deve clicar com o botão direito na barra de título do Prompt de Comando e clicar em ```Propriedades```. Lá, você deve selecionar ```Lucida Console``` como a fonte padrão.

Depois disso, as letras acentuadas devem aparecer corretamente. (Só funcionará se você abrir o jogo pelo arquivo ```Adventure.bat```)

# Detalhes para compilação
Para vocês ~~com falta de sanidade~~ corajosos que querem compilar o jogo sozinhos:

O projeto utiliza CMake, portanto, deve compilar sem muito esforço na maioria dos sistemas operacionais, contudo, depende da seguinte biblioteca: ```jsoncpp```.

Em um terminal digite: ```cmake . -DCMAKE_BUILD_TYPE=Release```, seguido de ```make```.

Finalmente, para executar o jogo digite ```./Adventure``` em sistemas UNIX (Linux, Mac OSX e FreeBSD são exemplos) ou ```adventure``` no Windows, ou simplesmente abra o executável.
