.name		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
.comment	"It is a comment"

l2:	sti r1,%:live,%1
	and r1,%12,r1
live:	live %1
		zjmp %:live
