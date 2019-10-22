global main
extern scanf
extern printf

section .data
	a	dd
	b	dd
	c	dd
	delta	dd
	x1	dd
	x2	dd
	quatre	dd	4.0
	deux	dd	2.0
	msgin 	"%f%f%f"
	msgout	"%f"
section .text

main:
	push 	ebp
	mov	ebp,esp
	
	;scanf
	push	c
	push	b
	push	a
	push	dword msgin
	call	scanf
	add	esp,16

	;calcul discriminant
	fld	dword [b]
	fld	dword [b]
	fmulp	st1,st0
	fild	dword [quatre]
	fld	dword [a]
	fmulp	st1,st0
	fld	dword [c]
	fmulp	st1,st0
	fstp	dword [delta]

	;comparaison entre delta et 0
	fcomip	[delta],0.0
	jl	.end	
	neg	[b]
	je	.equ

	;deux solutions si delta>0
	;(-b+sqrt(delta))/2a
	fld	dword [b]
	fchs
	fld	dword [delta]
	fsqrt
	faddp	st1,st0
	fld	dword [deux]
	fld	dword [a]
	fmulp	st1,st0
	fdivp	st1,st0
	fstp	[x1]

	;affichage de x1
	sub	esp,8
	fst	qword,[esp]
	push 	dword,msgout
	call	printf
	add	esp,12

.equ:	;une seule solution si delta=0
	fld	dword [b]
	fchs
	fld	dword [delta]
	fsqrt
	fchs
	faddp	st1,st0
	fld	dword [deux]
	fld	dword [a]
	fmulp	st1,st0
	fdivp	st1,st0
	fstp	[x2]

	;affichage de x2
	sub	esp,8
	fst	qword [esp]
	push 	dword msgout
	call	printf
	add	esp,12

.end:	;aucune solution si delta<0

;affichage d'un float :
;	sub	esp,8
;	fst	qword,[esp]
;	push 	dword,msg
;	call	printf
;	add	esp,12
