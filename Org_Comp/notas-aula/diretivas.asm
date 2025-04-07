# DIRETIVAS

                .data # diretiva p/ início do seg de dados
                
                .align 0 # diretiva alinhar a memória em caractere
string:         .asciz “Hello World” # diretiva para definir uma string

                .align 2 # diretiva alinhar a memória em inteiro
vlr_inteiro:    .word 157 # diretiva para definir um inteiro

                .text # diretiva p/ início do seg. de texto
                .globl main # diretiva p/ usar rotulo em outro prog.

main:           # rótulo para ponto de entrada no processo
                # código fonte