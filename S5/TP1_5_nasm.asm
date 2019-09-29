global main
extern printf

; ===== DATA SECTION =====
section .data

	MAXI	EQU	20
	tab	times	MAXI dd 0
	msg	db "la somme est %d",10,0
	
 
; ===== CODE SECTION =====
section .text
   
calc_sum:
	push	ebp
	mov	ebp,esp			;début sous-programme
	push 	ebx
	
	mov 	ebx, [ebp+8]		; parametres de la fonction à +8, puis +4 +4 +4 +4
	mov	edx, [ebp+12]
						;on n'attribue pas sur ebx, esi, edi et ebp!
	mov	eax, 0
	mov	ecx, 0

.for:
	cmp	ecx, edx
	jge	.endfor
	
		add	eax, [ebx + ecx * 4]	;sum += t[i]
	
	
	inc	ecx
	jmp	.for
	
.endfor:	
	pop	ebx
   	mov 	esp,ebp			;sortie du sous-programme
	pop 	ebp
  	ret
   
     
main:
	push	ebp		;entrée dans le sous-programme
   	mov 	ebp,esp			
    
    	pushad			;sauvegarde les 8 registres généraux
    	
    	mov 	eax, 0
	mov 	ebx, 15
	mov	ecx, 0

.for:   
	cmp 	ecx,ebx		;i <,=,> n ?
	jge	.endfor
	
	;corps de la boucle
	add	eax, ecx
	
	add	ecx, 1		; inc ecx
	jmp	.for
	 
.endfor:    
	push 	eax
	push 	dword msg
	call	printf
	add	esp,8	
	
	
    	popad
    
   	xor 	eax,eax			;mov eax, 0 -> équivalent au return EXIT_SUCCESS
    
  	mov 	esp,ebp			;sortie du sous-programme
	pop 	ebp
  	ret
     
     
; a mettre à jour, placer code qui suit :
;.for i:
;	cmp	ecx,MAXI
;	jge	.endfor
;		mov	eax,ecx
;		shl	eax,1
;		
;		mov	[ebx + ecx * 4], eax
;	
;	inc	ecx
;	jmp	.for_i
;	
;.endfor_i:
