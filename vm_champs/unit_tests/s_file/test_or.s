.name "zork"
.comment "zork jfkal test"

		or r1, r1, r1
#		sti r1, %:rr1, %1
rr1:	live %1
#nb player

or		r2, %0, r2
#		sti r2, %:rr2, %1
rr2:	live %1
#0

		or r2, r1, r2
#		sti r2, %:rr3, %1
rr3:	live %1
#nb_player

		or r3, r4, r5
#		sti r4, %:rr4, %1
rr4:	live %1
#0

		or %1, %-1, r2
#		sti r2, %:rr5, %1
rr5:	live %1
#ffff

		or %1000, %1, r8
#		sti r8, %:rr6, %1
#rr6:	live %1
#1001

		or %0, %0, r9
#		sti r9, %:rr7, %1
rr7:	live %1
#0

zjmp %:rr7
