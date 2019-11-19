section .data

section .text

;exercice 1
un:
	push	ebp
	mov		ebp,esp

	mov		eax,1
	mov		ecx,2
	cmp		eax,ecx
	jg		.else

.if:
	;i1
	jmp		.endif
.else:
	;i2
.endif:
	mov		esp,ebp
	pop		ebp
	ret

;exercice 2
