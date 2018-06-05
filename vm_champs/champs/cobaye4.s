.name "zork"
.comment "I'M ALIIIIVE"

#		ld %-1, r9
#		add r9, r5, r3
#		st r3, 40
#		sub r9, r5, r3
		ld %0, r10
		ldi 4, %0, r4
#		st r4, -128
		sti r4, r10, %32769
		ld %2049, r1
		live %1
