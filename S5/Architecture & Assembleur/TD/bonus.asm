;ENONCE
;lire deux entiers aux clavier,
;les comparer et afficher le plus grand
;affiche "ils sont égaux" s'ils le sont.

global main
extern printf
extern scanf

section .data
	saisie	db	"entrez deux nombre ",0
	attrib	db	"%i",0
	var1	dw	1;32 bits integer = dword
	var2	dw	2
	retourG	db	"le plus grand est : %i",10,0
	retourE	db	"ils sont égaux",0

section .text
main:
	push	ebp
	mov		ebp,esp

	push 	dword saisie
	call	printf
	add 	esp,4

	;lecture du premier entier
	push	dword var1
	push	dword attrib
	call	scanf

	add		esp,8

	;lecture du deuxieme entier
	push	dword var2
	push	dword attrib
	call	scanf

	add		esp,8

	;comparaison de ceux-ci
	mov		ebx,dword [var1]
	mov		ecx,dword [var2]
	cmp		ebx,ecx
	jl		.else
	je		.eq


.if: ;cas ou var1>var2
	push	ebx
	push	dword retourG
	call	printf

	add		esp,8
	;pop		ebx

	jmp		.endif

.else: ;cas ou var1<var2
	push	ecx
	push	dword retourG
	call 	printf

	add		esp,8
	;pop		ecx

	jmp		.endif

.eq: ;cas ou var1==var2
	push	dword retourE
	call	printf

	add		esp,4

.endif:

	mov		esp,ebp
	pop		ebp
	ret
