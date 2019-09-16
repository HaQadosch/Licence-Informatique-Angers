global main
extern printf
extern scanf
     
; ===== DATA SECTION =====
section .data

	x dd 1 ; x est un entier sur 32 bits
	y dd 2 ; y est un entier sur 32 bits
	
	msg_inf 	db "%d inferieur a %d", 10, 0
	msg_sup_egal 	db "%d superieur ou egal a %d", 10, 0
	
	saisir_x	db "saisir x? ", 0
	saisir_y	db "saisir y? ", 0
	msg_scanf	db "%d", 0
 
; ===== CODE SECTION =====
section .text
     
main:
	push	ebp		;entrée dans le sous-programme
   	mov 	ebp,esp			
    
    	pushad			;sauvegarde les 8 registres généraux
    	
    	;printf de X
    	push 	dword saisir_x
    	call 	printf
    	add	esp, 4
    	;scanf de X
    	push 	dword x
    	push 	dword msg_scanf
    	call 	scanf
    	add 	esp,8
    	
    	;printf de Y
    	push 	dword saisir_y
    	call 	printf
    	add	esp, 4
    	;scanf de Y
    	push 	dword y
    	push 	dword msg_scanf
    	call 	scanf
    	add 	esp,8
    	
.if:
   	;affectation
   	mov 	eax,[x]
    	mov 	ebx,[y]
    	;comparaison
    	cmp 	eax,ebx
	push	ebx		;[y]
	push	eax		;[x]
	
    	jge	.else		; va au .else si cmp est negatif
    
.then:
	;printf
	push	dword msg_inf
	call 	printf
	add	esp,12		;supprime le paramètre msg_inf en augmentant le sommet de pile
	jmp	.endif
	
.else: 
	;printf
	push	dword msg_sup_egal
	call 	printf
	add	esp,12
	
.endif:
    
    
    	popad
    
   	xor 	eax,eax			;mov eax, 0 -> équivalent au return EXIT_SUCCESS
    
  	mov esp,ebp			;sortie du sous-programme
	pop ebp
  	ret
     
     

