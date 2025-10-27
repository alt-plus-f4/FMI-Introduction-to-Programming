	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	wzr, [sp, #12]
	str	wzr, [sp, #8]
	ldr	w8, [sp, #8]
	cbnz	w8, LBB0_2
	b	LBB0_1
LBB0_1:
	str	wzr, [sp, #12]
	b	LBB0_5
LBB0_2:
	ldr	w8, [sp, #8]
	cbnz	w8, LBB0_4
	b	LBB0_3
LBB0_3:
	str	wzr, [sp, #12]
	b	LBB0_5
LBB0_4:
	str	wzr, [sp, #12]
	b	LBB0_5
LBB0_5:
	ldr	w0, [sp, #12]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
