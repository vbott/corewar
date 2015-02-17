.name		"42"
.comment	"Just a basic Winner Program"


lab_1:	live	%42
	fork	%:lab_2
	ld	%0,r5
	zjmp	%:lab_10

lab_2:	sti	r1,%:lab_5,%1
	ld	%2304,r10
	ld	%1,r5
	ld	%0,r11
	ld	%4,r3

lab_3:	live	%42
	fork	%:lab_4
	live	%742
	sub	r3,r5,r3
	zjmp	%:lab_13
	ld	%0,r11
	fork	%:lab_9
	live	%42
	sti	r10,%-510,%0
	sti	r10,%-404,%0
	sti	r10,%-303,%0
	sti	r10,%-202,%0
	ld	%0,r11
	zjmp	%:lab_3

lab_4:	ld	%368,r2
	ld	%0,r3
	ld	%4,r4

lab_5:	live	%1
	sti	r10,%-510,r2
	sti	r10,%-510,r3
	add	r4,r5,r4
	add	r3,r4,r3
	sub	r2,r4,r2
	zjmp	%:lab_4
	ld	%0,r11
	zjmp	%:lab_5
	zjmp	%:lab_14

lab_6:	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

lab_7:	sub	r6,r4,r6
	add	r6,r6,r11
	ldi	%:lab_6,r6,r7
	sti	r7,%-510,r11

lab_8:	live	%1
	ld	%0,r10
	sti	r7,%-250,r6
	zjmp	%-192

lab_9:	zjmp	%:lab_29

lab_10:	sti	r1,%:lab_27,%2
	ldi	%:lab_27,%3,r2
	sti	r2,%:lab_1,%-4
	ldi	%:lab_27,%-1,r2
	sti	r2,%:lab_1,%-8
	sti	r1,%:lab_8,%1
	sti	r1,%:lab_11,%1
	ld	%0,r2
	ld	%8,r3
	ld	%1,r4
	ld	%0,r6

lab_11:	live	%1
	sub	r3,r4,r3
	zjmp	%:lab_28
	fork	%:lab_12
	st	r5,r2
	xor	r10,r10,r10
	add	r10,r10,r10
	add	r6,r6,r6
	ld	%0,r10
	zjmp	%:lab_11

lab_12:	add	r2,r4,r2
	add	r6,r6,r6
	add	r6,r4,r6
	ld	%0,r10
	zjmp	%:lab_11

lab_13:	live	%42
	ld	%9,r3
	sti	r3,%:lab_6,%-6
	ld	%2,r3
	sti	r3,%:lab_6,%-16
	ld	%0,r3
	zjmp	%:lab_30

lab_14:	sti	r1,%:lab_15,%1
	sti	r1,%:lab_16,%1
	sti	r1,%:lab_17,%1
	sti	r1,%:lab_18,%1
	sti	r1,%:lab_19,%1
	sti	r1,%:lab_20,%1
	sti	r1,%:lab_21,%1
	sti	r1,%:lab_22,%1
	sti	r1,%:lab_23,%1
	sti	r1,%:lab_24,%1
	sti	r1,%:lab_25,%1

lab_15:	live	%1

lab_16:	live	%1

lab_17:	live	%1

lab_18:	live	%1

lab_19:	live	%1

lab_20:	live	%1

lab_21:	live	%1

lab_22:	live	%1

lab_23:	live	%1

lab_24:	live	%1

lab_25:	live	%1
	zjmp	%:lab_15

lab_26:	zjmp	%:lab_14
	live	%0

lab_27:	ld	%1,r1

lab_28:	sti	r1,%:lab_34,%1
	or	r2,r2,r2
	zjmp	%:lab_32
	sub	r2,r4,r2
	zjmp	%:lab_7
	ld	%0,r2
	zjmp	%:lab_14

lab_29:	zjmp	%:lab_35

lab_30:	ld	%9,r3
	sti	r3,%:lab_37,%-6
	ld	%2,r3
	sti	r3,%:lab_37,%-16
	ld	%0,r3
	zjmp	%:lab_14

lab_31:	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

lab_32:	ld	%10,r8
	sub	r6,r8,r6
	and	r6,%-2147483648,r8
	zjmp	%:lab_33
	ld	%118,r8
	add	r6,r8,r6

lab_33:	add	r6,r6,r6
	ld	%272,r8
	ld	%29,r9
	ldi	%:lab_31,r6,r7
	sti	r7,r8,r6
	sti	r7,r9,r6

lab_34:	live	%1
	ld	%0,r10
	zjmp	%186

lab_35:	ld	%425,r2
	ld	%0,r3
	ld	%4,r4

lab_36:	live	%42
	sti	r10,%:lab_37,r2
	sti	r10,%:lab_37,r3
	add	r4,r5,r4
	add	r3,r4,r3
	sub	r2,r4,r2
	zjmp	%:lab_35
	ld	%0,r11
	zjmp	%:lab_36
	zjmp	%:lab_26

lab_37:	live	%633
