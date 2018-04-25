.name "zork"
.comment "I'M ALIIIIVE"

l2:		lld 4096, r2
		sti r2, %:live, %1

live:	live %1
