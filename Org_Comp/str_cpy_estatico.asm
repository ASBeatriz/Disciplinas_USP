# Meu str_cpy estático

	.data
	.align 0
str_src: 
	.asciz "Minha string! muito grande"
str_dst:
	.space 50   # reserva 50 bytes na parte de dados estáticos
	
	.text
	.align 2
	.globl main
main:
	# salva os endereços (primerio byte) das strings origem e destino nos registradores s0 e s1
	la s0, str_src
	la s1, str_dst
	
loop:
	lb t0, 0(s0) # pega o conteudo da memória de endereço s0+0 e coloca em t0
	sb t0, 0(s1) # escreve t0 na memória de endereço s1+0
	
	# incrementa os ponteiros (posição da memória)
	addi s0, s0, 1
	addi s1, s1, 1

	# branch if not equal zero	
	bnez t0, loop	# só para o loop após copiar o \0 da string, ou seja, após t0 ser zero
	# bne t0, zero, loop # (outra opção)
	
	# imprime a string copiada
	addi a7, zero, 4
	la a0, str_dst
	ecall
	
	# encerrar o programa (!!)
	addi a7, zero, 10
	ecall
	
# Operações aprendidas:
# load byte - lê um byte da memória e carrega no registrador
# lb destino, deslocamento(base)

# store byte - lê um byte (o menos significativo) do registrador e escreve na memória
# sb origem, deslocamento(base)
