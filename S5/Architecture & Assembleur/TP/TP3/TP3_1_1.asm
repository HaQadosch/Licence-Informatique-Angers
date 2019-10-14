global main

; ===============================================
; DATA
; ===============================================
section .data

; ===============================================
; CODE
; ===============================================
section .text

main:
	push	ebp
	mov	ebp, esp
	push esi
	push edi
	push ebx

	mov esi,[ebp+8]
	mov edi,[ebp+12]
	mov ebx,[ebp+16]
	mov edx,[ebp+20]
	xor ecx,ecx

.for:
	cmp ecx,edx
	jge .endfor
	mov eax,[esi+ecx*4]
	add eax,[edi+ecx*4]
	mov[ebx+ecx*4]
	inc ecx
	jmp for
.endfor:

	pop	ebx
	pop edi
	pop esi
	mov esp,ebp
	pop ebp
	ret
