	.file	"5-9.c"
	.globl	day_tab
	.bss
	.align 8
	.type	day_tab, @object
	.size	day_tab, 8
day_tab:
	.zero	8
	.text
	.globl	day_of_the_year
	.type	day_of_the_year, @function
day_of_the_year:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movl	%edi, -28(%rbp)
	movl	%esi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	-28(%rbp), %eax
	andl	$3, %eax
	testl	%eax, %eax
	jne	.L2
	movl	-28(%rbp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	imull	$100, %eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L3
.L2:
	movl	-28(%rbp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$7, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	imull	$400, %eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L4
.L3:
	movl	$1, %eax
	jmp	.L5
.L4:
	movl	$0, %eax
.L5:
	movl	%eax, -16(%rbp)
	movl	$1, -12(%rbp)
	jmp	.L6
.L7:
	movq	day_tab(%rip), %rcx
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	addl	%eax, -36(%rbp)
	addl	$1, -12(%rbp)
.L6:
	movl	-12(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jle	.L7
	movl	-36(%rbp), %eax
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	day_of_the_year, .-day_of_the_year
	.globl	month_and_day
	.type	month_and_day, @function
month_and_day:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movl	%edi, -28(%rbp)
	movl	%esi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movl	-28(%rbp), %eax
	andl	$3, %eax
	testl	%eax, %eax
	jne	.L10
	movl	-28(%rbp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	imull	$100, %eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L11
.L10:
	movl	-28(%rbp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$7, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	imull	$400, %eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L12
.L11:
	movl	$1, %eax
	jmp	.L13
.L12:
	movl	$0, %eax
.L13:
	movl	%eax, -16(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L14
.L15:
	movq	day_tab(%rip), %rcx
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	subl	%eax, -32(%rbp)
	addl	$1, -12(%rbp)
.L14:
	movq	day_tab(%rip), %rcx
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	-32(%rbp), %eax
	jle	.L15
	movq	-40(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	movq	-48(%rbp), %rax
	movl	-32(%rbp), %edx
	movl	%edx, (%rax)
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	month_and_day, .-month_and_day
	.section	.rodata
.LC0:
	.string	"day of the year is %d\n"
.LC1:
	.string	"month = %d, day = %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1, %edx
	movl	$2, %esi
	movl	$2012, %edi
	call	day_of_the_year
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-12(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rax, %rdx
	movl	$32, %esi
	movl	$2012, %edi
	call	month_and_day
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.7.2 20120921 (Red Hat 4.7.2-2)"
	.section	.note.GNU-stack,"",@progbits
