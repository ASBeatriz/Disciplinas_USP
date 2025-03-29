                # imprime numeros de um a 5
                
                .data   
                .text   
                .globl main

main:           .align 2
		li t0, 0
		li t1, 5
		
loop: 		beq t0, t1, fim_loop	# condição do loop
		addi t0, t0, 1 # incrementa contador
		
		li a7, 1
		mv a0, t0
		ecall	#imprime
		
		j loop # volta pro loop
		
fim_loop:
		li a7, 10 # encerra o programa
		ecall

                
               