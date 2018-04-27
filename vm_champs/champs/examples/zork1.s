.name ""
.comment "fkff"

l2:		sti r1, %:live, %1
		and r2, %0, r2

live:	live %1
		zjmp %:live
