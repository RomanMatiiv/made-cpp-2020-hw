.text
.global count_det

count_det:
        //a11 a12 a13
        //a21 a22 a23
        //a31 a32 a33

        push {r4}

        // a11 * a22 * a33
        ldr r2, [r0, #4 * 0]
        ldr r3, [r0, #4 * 4]
        ldr r4, [r0, #4 * 8]
        mul r2, r2,r3
        mul r2, r2, r4

        add r1, r2

        // a12 * a23 * a31
        ldr r2, [r0, #4 * 1]
        ldr r3, [r0, #4 * 5]
        ldr r4, [r0, #4 * 6]
        mul r2, r2,r3
        mul r2, r2, r4

        add r1, r2

        // a13 * a21 * a32
        ldr r2, [r0, #4 * 2]
        ldr r3, [r0, #4 * 3]
        ldr r4, [r0, #4 * 7]
        mul r2, r2,r3
        mul r2, r2, r4

        add r1, r2

        // a13 * a22 * a31
        ldr r2, [r0, #4 * 2]
        ldr r3, [r0, #4 * 4]
        ldr r4, [r0, #4 * 6]
        mul r2, r2,r3
        mul r2, r2, r4

        sub r1, r2

        // a12 * a21 * a33
        ldr r2, [r0, #4 * 1]
        ldr r3, [r0, #4 * 3]
        ldr r4, [r0, #4 * 8]
        mul r2, r2,r3
        mul r2, r2, r4

        sub r1, r2

        // a11 * a23 * a32
        ldr r2, [r0, #4 * 0]
        ldr r3, [r0, #4 * 5]
        ldr r4, [r0, #4 * 7]
        mul r2, r2,r3
        mul r2, r2, r4

        sub r1, r2

        mov r0, r1

        pop {r4}

        bx lr
