# fatorial com mensagem 
                
	.data   # diretiva que indica o início do segmento de dados
	.align 0
msg1: 	.asciz "O fatorial de \n"
msg2:	.asciz " eh \n"

        .text   # diretiva que indica o início do segmento de texto
	.globl main

main:   .align 2
		
	li a7, 5	# Ler inteiro
	ecall		# Chamada do programa
	add s0, a0, zero  # Registrador s0 recebe valor lido
	
	jal fatorial	# chama função fatorial
	
	# após a função:
	add s1, a0, zero  # armazena o resultado do fatorial (a0) em s1
	
	# imprime msg1
	li a7, 4
	la a0, msg1
	ecall
	
	# imprime o número
	li a7, 1
	add a0, s0, zero
	ecall
	
	# imprime msg2
	li a7, 4
	la a0, msg2
	ecall
	
	# imprime o resultado
	li a7, 1
	add a0, s1, zero
	ecall
	
	li a7, 10 	# encerrar o programa
	ecall


# Função fatorial, recebe como parâmetro o a0 e retorna o a0 como resultado do fatorial	
fatorial: 	
	mv t0, a0	# armazena o número a para calcular o fatorial em t0 (contador)
	li t1, 1	# armazena o resultado do fatorial
		
loop:	
	beq t0, zero, fim_loop	# condição de parada do loop
	mul t1, t1, t0		# calcula o resultado (n  = n*(n-1) ...)
	addi t0, t0, -1		# decrementa o contador
	j loop		# volta para o loop
		
# fim do loop, volta para a função main
fim_loop:
	mv a0, t1 # armazena em a0 o resultado do fatorial
	ret	# volta para a função main após a sua chamada
               
