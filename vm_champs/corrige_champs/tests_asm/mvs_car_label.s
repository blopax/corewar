.name "zork"
.comment "I'M ALIIIIVE"
l1:		sti r1, %:live, %1
		and r2, r2, r2

lIve:	live r1
		zjmp %:lIve
