.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD, :DWORD, :DWORD, :DWORD

.STACK 4096

.CONST

.DATA
first byte 4
second byte 5
third DB "Результат сложения= ", 0
four DB "Окно", 0
HW DD ?
.CODE

main PROC
mov al, first
add al, second
add al, 30h ; добавляем для того, чтобы преобразовать в символ
mov third + 19, al
INVOKE MessageBoxA, HW, OFFSET third, OFFSET four, 0
push 0
CALL ExitProcess
main ENDP
end main