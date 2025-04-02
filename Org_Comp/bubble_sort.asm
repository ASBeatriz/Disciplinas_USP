# Bubble sort

	.data	# DADOS
	.align 2
vetor:	.word 4, 2, 5, 1, 3, 12, 10, 7  # vetor de elementos de 4 bytes
MAX:	.word 8		# tam do vetor
	
	.align 0
quebra_lin: .asciz "\n"
espaco: .asciz " "
msg_ordenado: .asciz "\n vetor ordenado: \n"

	.text	# TEXTO
	.globl main
main:
	li s0, 0	# s0 = contador do loop 1
	la t0, MAX	# utiliza t0 como auxiliar para acessar MAX
	lw s1, 0(t0)
	addi s1, s1, -1	# s1 = contador do loop 2 (tam do vetor - 1)
	
	add s2, s1, zero # s2 = tam do vetor - 1
	la s3, vetor	# s3 = armazena o endereço do vetor
	li t0, 4	# t0 = qtde de bytes de cada elemento
	
loop_1: bgt s0, s2, fim_loop_1
	
loop_2: ble s1, s0, fim_loop_2
	mul t1, s1, t0	# offset para a posição s1
	
	add t1, s3, t1	# t1 = endereço do elemento na posição s1
	lw t2, 0(t1)	# t2 = elemento na pos s1
	
	addi t3, t1, -4	# t3 = endereço do elemento na posição s1-1
	lw t4, 0(t3)	# t4 = elemento na pos s1-1
	
	ble t4, t2, nao_troca
	# troca os elementos
	sw t2, 0(t3)
	sw t4, 0(t1)
	
nao_troca:		
	addi s1, s1, -1
	
	j loop_2
fim_loop_2:
	li s1, 4	# s1 = tam do vetor - 1
	
	addi s0, s0, 1
	j loop_1	
fim_loop_1:

	 li t0, 4 	# qtde de bytes
	 li t1, 0 	# contador
	# imprime msg ordenado
	 li a7, 4
	 la a0, msg_ordenado
	 ecall
loop_imprime:	bgt t1, s2, fim_loop_imprime
	mul t2, t1, t0 
	add t2, s3, t2
	
	
	li a7, 1
	lw a0, 0(t2)
	ecall
	
	li a7, 4
	la a0, espaco
	ecall
	
	addi t1, t1, 1	# incrementa o contador
	j loop_imprime
fim_loop_imprime:

	# encerra o programa
	li a7, 10
	ecall