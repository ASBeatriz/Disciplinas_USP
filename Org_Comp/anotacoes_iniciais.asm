# Estrutura de um programa Assembly:
#     Segmento de texto (.text)
#     Segmento de dados (.data)

                .data # diretiva que indica o início do segmento de dados
                # variáveis estáticas
vlr_inteiro:    .word 157
string:         .asciz "Hello World"
                
                .text # diretiva que indica o início do segmento de texto (começa código executável)
                # código fonte

                .globl main # diretiva p/ usar rótulo em outro programa
main:           # rótulo para ponto de entrada no processo

loop:           beq t0, t1, fim_loop    # se t0 = t1 go fim_loop
                # código interno ao loop

                j loop  # retorne ao inicio do loop

fim_loop:       # primeira instrução fora do loop

