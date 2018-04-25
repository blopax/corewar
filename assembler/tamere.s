.name "
OK OK OK
KO KO KO"
.comment "salut ca marche bien ou pas?"

live %2147483647
live %1
live %1
ld 9898,r1
ld %2147483647,r2
st r1,r2
st r1,2147483647
and r1,r2,r3
sub r1,r2,r3