.name "zork_nojump"
.comment "I'M ALIIIIVE no jump"
l1:		sti r1, %:live, %1

live:	live %1
		zjmp %:live
