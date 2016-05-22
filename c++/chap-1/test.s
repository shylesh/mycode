	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"%zu"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %eax
	call	hi_print
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.ascii	"Hellokfsdf;lksadf;slkdjfsa"
	.string	";dlfkjas;dflkjasd;lfkjsd;flkjsad;fkajsd;flksajdf;lsakdjfsa;ldfkjsa;lfkjsad;lfkjasd;flkjasdf;lksdf;lsakdfn;asldkfnasd;lfknasd;lfknasd;flnasd;lkfnas;dlkfnas;dklfnasd;lkfnasd;lkfnasl;dkfnasd;lkfnas;lkfnsadlkfnas;dlkfnas;lkdfnas;lkfna;kldfns;lkdfnasl;kdfaskdnf"
	.text
	.globl	hi_print
	.type	hi_print, @function
hi_print:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC1, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	hi_print, .-hi_print
	.ident	"GCC: (GNU) 4.9.2 20150212 (Red Hat 4.9.2-6)"
	.section	.note.GNU-stack,"",@progbits
