		.data
		# Dados do programa
hello_msg:	.asciz "Hello World"

		.text
		# Código do programa
		.globl main # Entrada do código
main:		
		li a7, 4 # load immediate (= addi a7, x0, 4)
		la a0, hello_msg
		ecall
		li a7, 10
		ecall
		# ta faltando uns comentarios!!
		
		
			