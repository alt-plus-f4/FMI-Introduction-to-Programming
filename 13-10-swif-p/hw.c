int main(){
    int i = 0;

    if(!i)
        return 0;
    
    switch(i){
        case 0:
            return 0;
    }

    return 0;
}

// ASM : switch and if are equal as long as the if is small enough

// main:
//         push    rbp
//         mov     rbp, rsp
//         mov     DWORD PTR [rbp-4], 0
//         cmp     DWORD PTR [rbp-4], 0
//         jne     .L2
//         mov     eax, 0
//         jmp     .L3
// .L2:
//         mov     eax, 0
// .L3:
//         pop     rbp
//         ret