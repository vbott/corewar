.name		"42"
.comment	"Just a basic Winner Program"

#	gtmd	r7
#	sub	r3,r4,r5
#	ld	%42,r6
#	aff	r7
	ld	%42,r5
#l0:	live	%1
#	sti	r1,%:l1,%1
	st	r5,r8
	aff	r8
#	sub	r3,r4,r5
#	st	r3,r5
#	aff	r3
#	sti	r1,%:l0,%1
#	sti	r1,%:l1,%1
#	fork    %:l0
#	sti	r1,%:live1,%1
#	st	r3,300
#	st	r3,310
#	st	r3,320
#	st	r3,330
#	st	r3,340
#	st	r3,350
#	st	r3,360
#	st	r3,r8
#	st	r3,380
#	st	r3,390
#	st	r3,300
#	st	r3,310
#	st	r3,320
#	st	r3,330
#	st	r3,340
#	st	r3,350
#	st	r3,360
#	st	r3,370
#	st	r3,380
#	st	r3,390
	
l1:	live	%1
#	fork	%:l0
#	zjmp	%:l0

#test:	live	%1
#	zjmp	%:test
