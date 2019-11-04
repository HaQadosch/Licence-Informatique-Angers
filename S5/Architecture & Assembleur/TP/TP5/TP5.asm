global ps_x87
global ps_sse
global ps_sse_u4

; x= esi
; y= edi
; sz= eax
; i= ecx
; sum= st0

ps_x87:
  push  ebp
  mov   ebp,esp
  push  esi
  push  edi

  mov   esi,[ebp+8]
  mov   edi,[ebp+12]
  mov   eax,[ebp+16]

;  fldz  ;sum=st0=0
  pxor  xmm0,xmm0 ;sum[0:3]=0
  xor   ecx,ecx

.fori:
  cmp   ecx,eax
  jge   .endfori
  ;sum += ...
  fld   dword [esi + ecx*4]
  fmul  dword [edi + ecx * 4]
  faddp st1,st0
  inc   ecx
  jmp   .fori
.endfori:

  pop   edi
  pop   esi
  mov   esp,ebp
  pop   ebp
  ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

ps_sse:
  push  ebp
  mov   ebp, esp

  push  esi
  push  edi

  mov   esi, [ebp+8]
  mov   edi, [ebp+12]
  mov   eax, [ebp+16]

  pxor  xmm0, xmm0
  xor   ecx, ecx

.for:
  cmp   ecx, eax
  jpe   .endfor
  ;sum[0:3] +=...
  movaps xmm1, [esi+ecx*4]
  movaps xmm2, [edi+ecx*4]
  mulps xmm1, xmm2
  addps xmm0, xmm1
  add ecx, 4
  jmp .for
.endfor:

  haddps xmm0,xmm0
  haddps xmm0,xmm0
  sub   esp, 4
  movss [esp], xmm0
  fld   dword [esp]
  add   esp, 4


  pop edi
  pop esi
  mov esp,ebp
  pop ebp
  ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ps_sse_u4:
  push  ebp
  mov   ebp, esp

  push  esi
  push  edi

  mov   esi, [ebp+8]
  mov   edi, [ebp+12]
  mov   eax, [ebp+16]

  pxor  xmm0, xmm0 ;sum[4:7]
  pxor  xmm4, xmm4 ;sum[4:7]
  xor   ecx, ecx

.for:
  cmp   ecx, eax
  jpe   .endfor
  ;sum[0:3] +=...
  movaps xmm1, [esi+ecx*4]
  movaps xmm2, [edi+ecx*4]
  mulps xmm1, xmm2
  addps xmm0, xmm1

  movaps xmm1, [esi+ecx*4+16]
  movaps xmm2, [edi+ecx*4+16]
  mulps xmm5, xmm6
  addps xmm4, xmm5
  add ecx,8
  jmp .for
.endfor:

  haddps xmm0,xmm0
  haddps xmm0,xmm0
  haddps xmm4,xmm4
  haddps xmm4,xmm4

  addps xmm0,xmm4

  sub   esp, 4
  movss [esp], xmm0
  fld   dword [esp]
  add   esp, 4

  pop edi
  pop esi
  mov esp,ebp
  pop ebp
  ret
