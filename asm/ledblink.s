org 0xf800

start:
	mov.w #0x5a80,&0x0120
	mov.b #1,&0x022
	mov.b #1,&0x021
l1:
	mov.w #0xffff,R7
	xor.w #0x1,0x021
l2:
	sub.w #1,R7
	jnz l2
	jmp l1
loop:
	jmp loop
	org 0xfffe
	dw start
