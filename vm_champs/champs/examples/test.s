.name "zork"
.comment "zork jfkal test"

		and r1, r1, r1
		sti r1, %:rr1, %1
rr1:	live %1
#ffff nb player

and r2, r2, r2
		sti r2, %:rr2, %1
rr2:	live %1
#0

		and r2, r1, r2
		sti r2, %:rr3, %1
rr3:	live %1
#0

		and r2, r3, r4
		sti r4, %:rr4, %1
rr4:	live %1
#0

		and %1, %-1, r2
		sti r2, %:rr5, %1
rr5:	live %1
#1
		live %1
		live %1


		and %1000, %-1, r2
		sti r2, %:rr6, %1
rr6:	live %1
#1000

		and %1000000000000000000000000000, %0, r2
		sti r2, %:rr7, %1
rr7:	live %1
#0

zjmp %:rr7
