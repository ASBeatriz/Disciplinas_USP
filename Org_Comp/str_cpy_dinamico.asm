# meu str_cpy dinamico 
	.data		# DADOS
	.align 0	# alinha a memória em caractere
	
str_src: .asciz "Minha string copiada dinamicamente!"	# string origem

	.align 2	# alinha a memória em caractere
pont:	.word		# ponteiro para a string destino

	.text		# TEXTO
	.globl main
main:
	# t0 = contador
	li t0, 0
	# s0 = end. string origem
	la s0, str_src

# loop para calcular o tamanho da string origem
loop_tam:
	# t1 recebe os caracteres da string
	lb t1, 0(s0)
	# incrementa contador e o ponteiro da string origem
	addi t0, t0, 1
	addi s0, s0, 1
	
	bne t1, zero, loop_tam	# condição de permanência no loop: t1 != 0
	
	# imprime o tamanho da string
	li a7, 1
	add a0, t0, zero
	ecall
	
	# agora que eu sei o tamanho, eu posso alocar na heap
	li a7, 9	# código 9 = alocação dinâmica na heap
	add a0, zero, t0
	ecall
	# após a chamada do sistema, a0 recebe o endereço do primeiro byte armazenado na heap
	
	# agora, eu consigo definir o conteúdo do ponteiro pont
	la t2, pont	# registrador t2 armazena o endereço de pont
	sw a0, 0(t2)	# escreve o conteúdo de a0 no endereço armazenado por t2 (pont = a0)
	# ou seja, pont = end. da string destino
	
	# fui no endereço que t2 armazena e copiei o conteúdo para s1 
	lw s1, 0(t2) # s1 = endereço da string destino
	la s0, str_src	# redefine o valor de s0 para usar no próx loop

# loop para copiar a string 	
loop_cpy:
	# copia byte a byte da string (t1 como intermediador)
	lb t1, 0(s0)
	sb t1, 0(s1)
	
	# avança na string
	addi s0, s0, 1
	addi s1, s1, 1
	
	bne t1, zero, loop_cpy	# condição de parada do loop: t1 == zero
	
	# imprime string destino
	li a7, 4
	lw a0, 0(t2)
	ecall
	
	# encerra o programa
	li a7, 10
	ecall
	