.586P
.MODEL FLAT, STDCALL
includelib kernal32.lib

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD, :DWORD, :DWORD, :DWORD

.STACK 4096

.CONST

.DATA
myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
myDoubles DWORD 1, 2, 3, 4, 5, 6, 7
myPointer DWORD myDoubles
.CODE

main PROC
mov esi, OFFSET myBytes ;
mov eax, 0h
mov ah, [esi + 1] ; 20
mov al, [esi + 3] ; 40
; в регистре eax будет 00002040

mov eax, 0
mov ecx, lengthof myDoubles
mov esi, OFFSET myDoubles
forsum:
	add eax, [esi]
	mov edx, [esi]
	cmp edx, 0
	je label_zero
	not_zero:
	add esi, type myDoubles
loop forsum
	cmp ebx, 0
	je ex
	mov ebx, 1
	jmp ex
label_zero:
	mov ebx, 0
	cmp ecx, 0
	jne not_zero
ex:
INVOKE ExitProcess, 0
main ENDP
end main