.name "zork"
.comment "zork jfkal test"

#		ld %888, r1
#		and r1, r1, r1
#888

#and r2, r2, r2
#0

	ld	%68, r2
		aff r2

	ld	%48, r2
		aff r2

		and 4, 2, r2
#0

		and r2, r3, r4
#0

		and %1, %-1, r2
#1

		and %1000, %-1, r2
#1000

		and %1000000000000000000000000000, %0, r2
#0

