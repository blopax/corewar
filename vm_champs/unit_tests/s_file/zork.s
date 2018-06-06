.name "zork"
.comment "I'M ALIIIIVE"
l1:		sti r1,%:l2,%1

l2:		sti r1,%:live,%1
		sti r1,%:live,%1

live:	live %1
		zjmp %:live
