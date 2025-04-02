	.data
vetor:  .word 10, 20, 30, 40, 50  # vetor de palavras (4 bytes)
# vetor = {10, 20, 30, 40, 50} 

	.text
	.globl main
main:
	la t0, vetor    # Carrega o endereço base do vetor em t0
	lw t1, 0(t0)    # Carrega vetor[0] em t1  (10)
	lw t2, 4(t0)    # Carrega vetor[1] em t2  (20)
	lw t3, 8(t0)    # Carrega vetor[2] em t3  (30)
	
	# Imprime os elementos
	li a7, 1
	add a0, t1, zero
	ecall
	
	li a7, 1
	add a0, t2, zero
	ecall
	
	li a7, 1
	add a0, t3, zero
	ecall

	li a7, 10       # Finaliza o programa
	ecall
