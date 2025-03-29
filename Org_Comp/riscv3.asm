	.data
	.align 0
str1:	.asciz "Hello World++!"
str2:	.asciz "Hello World--!"
	.text
	.align 2
	.globl main
	
main:	
    addi a7, zero, 5
	ecall
	add s0, a0, zero
	blt s0, zero, print_neg  # branch on less than = blt
	# imprimir srt1
	addi a7, zero, 4
	la, a0, str1
	ecall
	j the_end
	
print_neg: #imprimir str2
	addi a7, zero, 4
	la a0, str2
	ecall
the_end:
	addi,  a7, zero, 1
	add a0, s0, zero
	ecall
	addi a7, zero, 10
	ecall
	
# o que rais esse programa faz?????