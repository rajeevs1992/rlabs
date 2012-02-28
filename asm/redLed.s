org 0xf800
start:
	mov.b #1,&0x22
	mov.b #1,&0x21
loop:
	jmp loop
	org 0xfffe
	dw start
