global main

section .data

section .text

puissance:
	push	ebp
	mov	ebp,esp
	fld1
	mov	exc,[ebp+12]
.while:
	cmp	ec,0
	jle	.endwhile
	
	fmul	dword [ebp+8]
	dec	ecx
	jmp	.while

.endwhile:
	mov	esp,ebp
	pop	ebp
	ret

main:	
	push	ebp
	mov	ebp,esp
	
	xor	ecx,ecx
		
.for:
	cmp	ecx,[n]
	jge	.endfor
	
	push	x
	push	i
	call	puissance
	add	esp,12

	add	[sum]
.endfor:
