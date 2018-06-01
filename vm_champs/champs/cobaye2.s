.name "zork"
.comment "I'M ALIIIIVE"

		ld %2147483647, r10
		ld %-1, r9
		ld %1, r5
		st r10, -128
		add r9, r5, r3
		st r3, 40
		sub r9, r5, r3
		st r3, 40
		ldi 3, %0, r6
		st r6, 12

live:	live %1
