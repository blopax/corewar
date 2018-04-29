.name "
OK OK OK
KO KO KO"
.comment "salut ca marche bien ou pas?"

live:	live %2147483647
		live %:live
		live %1
		live %1
		ld 9898,r1
		ld %2147483647,r2
		st	r1,		r2
		st	r1, 2147483647
		add	r1,r2,r3 ##
		sub	r1,r2,r3
		and %281,r2,r3 
		zjmp %:live
		ldi r1,%:live,r3
		ldi r2,%123,r3
		ldi	123,%:live,r4
		ldi %123,%123,r5
		ldi %:live,%1234,r5
		sti r2,r2,%12
		fork %:live
		fork %1234
		lfork %:live
		lfork %1234
		lld	 %:live,r2
		lld	 %123,r3
		lld	 123,r4
		lldi r1,%:live,r3
		lldi r2,%123,r3
		lldi 123,%:live,r4
		lldi %123,%123,r5
		lldi %:live,%1234,r5
		aff r2
		sti	r10,%-510,r2
		fork %:label00		# 3, 0, 281