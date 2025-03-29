                # fatorial
                
                .data   # diretiva que indica o início do segmento de dados
                .text   # diretiva que indica o início do segmento de texto
                .globl main

main:           .align 2
		
		li a7, 5	# Ler inteiro
		ecall		# Chamada do programa
		mv s0, a0	# Registrador s0 recebe valor lido
		
		jal fatorial	# chama função fatorial
		
		# após a função:
		mv s1, a0	# armazena o resultado do fatorial (a0) em s1
		
		li a7, 1	# Imprime um inteiro
		ecall		# chamada do programa
		
		li a7, 10 	# encerrar o programa


# Função fatorial, recebe como parâmetro o a0 e retorna o a0 como resultado do fatorial	
fatorial: 	
		mv t0, a0	# armazena o número a para calcular o fatorial em t0 (contador)
		li t1, 1	# armazena o resultado do fatorial
		
loop:		beq t0, zero, fim_loop	# condição de parada do loop
		mul t1, t1, t0		# calcula o resultado (n  = n*(n-1) ...)
		addi t0, t0, -1		# decrementa o contador
		j loop		# volta para o loop
		
# fim do loop, volta para a função main
fim_loop:
		mv a0, t1 # armazena em a0 o resultado do fatorial
		ret	# volta para a função main após a sua chamada
               