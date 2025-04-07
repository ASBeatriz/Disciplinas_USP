# invertendo string
		.data
str_src: .space 50  #limita a string a 50 caractere
str_dst: .space 50
	.align 0
texto:	.asciz "Algo"
	.text
	.align 2
	.globl main
main:
	# le a entrada do usuário
	li a7, 8
	la a0, str_src
	li a1, 50 # qtde max de caracteres a ser lido
	ecall
	
	la s0, str_src # s0 = endereço de string origem
	li t1, 0	# contador
	
# loop para calcular o tamanho da string
loop_tam:
	lb t0, 0(s0)
	addi s0, s0, 1
	addi t1, t1, 1 
	bnez t0, loop_tam	
	
	addi t3, t1, -2  # t3 = tam da string sem o /0 e /n
	addi t0, t3, -1	# t0 = contador da string origem 
	
	la s0 str_src # s0 = endereço de string origem
	la s1 str_dst # s1 = endereço da string destino
	
# loop para copiar a string invertida
loop_copia:
	blt t0, zero, fim_loop_copia
	add s2, s0, t0 # s2 = endereço do caractere a ser copiado
	lb s3, 0(s2) # s3 = caractere copiado da string origem
	
	sb s3, 0(s1)	# copia o caractere
	addi s1, s1, 1	# incrementa o endereço da string destino	

	addi t0, t0, -1
	j loop_copia
fim_loop_copia:
	
	# adiciona \0 no fim da string
	sb, zero, 0(s1)		# é necessário?
	
	# imprime a destino 
	li a7, 4
	la a0, str_dst
	ecall
	
	# encerra programa
	li a7, 10
	ecall
