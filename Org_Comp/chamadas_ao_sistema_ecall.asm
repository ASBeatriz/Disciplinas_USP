                .data   # inicio do seg de dados
                .align 2 # alinha a memória para armazenas inteiro
vlr_inteiro:    .word 157
                .align 0   # alinha a memoria para armazenar caractere
string:         .asciz "Hello World"

                .text   # inicio do seg de texto (começa o código executável)
                .globl main    # usar rotulo em outro programa

main:           # rotulo para ponto de entrada no procersso
                .align 2   # alinha a memória ára armazenar as instruções
                addi a7, x0, 4  # armazena o código de serviço de sistema (ecall) 4 (imorimir string) no registrador a7 (a7 = 0 + 4)
                la a0, string # o registrador a0 recebe o endereço do primeiro byte da string 
                ecall # chama o sistema operacional para executar a impressão

                addi a7, x0, 10 # a7 armazena o código do serviço 10 = encerrar
                ecall # chama o sistema operacional para terminar o programa

# addi =  add immediate
# adiciona um valor imediato a um registrador e armazena o resultado em outro.
#       addi reg_dest reg_orig valor_imed

# ECALL = Environment Call
# É uma instrução espacial do Assembly Risc-V que faz uma chamada ao sistema operacional para executar operações
# privilegiadas, como entrada e saída da dados ou encerramento do programa. Delega a tarefa ao sistema operacional.

    # REGISTRADORES (convenção)
    # a7 = recebe o código do serviço a ser executado
    # a0 = recebe o primeiro argumento necessário para o serviço
    # a1, a2, ... = outros argumentos, se necessário


# (tabela dos serviços no slide da aula 4 e 5: 
# https://edisciplinas.usp.br/pluginfile.php/8805679/mod_resource/content/4/4e5aulas%20-%20Assembly%20RISC-V.pdf)