.name "zork"
.comment "I'M ALIIIIVE"
l1:		ld %48, r3
		and r2, r2, r2

live:	aff r3
		zjmp %:live
