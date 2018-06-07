.name "zork"
.comment "I'M ALIIIIVE"

		ld %2, r1
		sti r1, %:live, %1
		and r2, r2, r2
		

live:	live %1
		zjmp %:live
