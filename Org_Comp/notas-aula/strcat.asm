# meu strcat - concatenar strings
	.data
	.align 0
string1: .asciz "ola"
string2: .asciz "beatriz!"

    .align 2
pont:  .word
    .text
    .globl main

main:
    # endereço das strings
    la s0, string1
    la s1, string2

    # tamanhos das strings
    li t1, 3    # str1
    li t2, 8    # str2

    add t3, t1, t2  # qtde total de caracteres

    # alocação dinamica
    li a7, 9
    addi t3, t3, 1
    add a0, zero, t3

    la s2, pont     # s2 recebe o endereço da ponteiro
    sw a0, 0(s2)    # o ponteiro agora recebe o endereço da memória alocado
    lw s3, 0(s2)    # s3 = o valor no endereço s2, ou seja, o valor no endereço pont, ou seja, o endereço da mem alocada
    add t5, s3, zero # ponteiro para a string destino

    li t0, 0    # contador loop

# loop para concatenar as strings
loop:   
    bgt t0, t3, fim_loop

    blt t0, t1, copia_str1
    bge t0, t1, copia_str2

copia_str1:
    lb t4, 0(s0)    # t4 = caractere a ser copiado
    beq t4, zero, fim_copias # ignora \0
    sb t4, 0(t5)    
    addi t5, t5, 1
    addi s0, s0, 1
    j fim_copias
 
copia_str2:
    lb t4, 0(s1)    # t4 = caractere a ser copiado
    beq t4, zero, fim_copias
    sb t4, 0(t5)    
    addi t5, t5, 1
    addi s1, s1, 1
 
fim_copias:
    addi t0, t0, 1
    j loop

fim_loop:
    sb zero, 0(t5)
    lw t5, 0(s2)
    # imprime a string concatenada
    li a7, 4
    add a0, t5, zero
    ecall

