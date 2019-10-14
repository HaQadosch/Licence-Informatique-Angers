global main

; ===============================================
; DATA
; ===============================================
section .data
N	eque 131072 ;2¹⁷
x	dd	0
y	dd	0
z	dd	0
method	dd	1
max_iter	dd	100

; ===============================================
; CODE
; ===============================================
section .text

main:
	push	ebp
	mov	ebp, esp
	pushad

	mov	eax,[ebp+12]
	push	[eax+8]
	call 	atoi
	add	esp,4
	mov	[method],eax
	mov	eax,[ebp+12]
	push	[eax+4]
	call atoi
	add	esp,4
	mov	[max_iter],eax

	mov	eax,N
	shl	eax,2
	push	eax
	push	dword	16
	push	dword	x
	call posix_memalign
	add	esp,12

	mov esp,ebp
	pop ebp
	ret
