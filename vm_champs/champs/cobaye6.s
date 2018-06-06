.name "zork"
.comment "I'M ALIIIIVE"

#		ld %-1, r9
#		add r9, r5, r3
#		st r3, 40
#		sub r9, r5, r3
		ld 513, r10
		fork 513
		lfork 513
		zjump -40
