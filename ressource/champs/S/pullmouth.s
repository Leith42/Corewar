.name "Pullmouth"
.comment "Les pullmouths cohabitent paisiblement avec les mamouths, les chevalmouths et les vermouths"

l2:		st r1, 17
		fork %:out
		and r4, %0, r3

live:	live %1
		zjmp %:live

out:    st r1, 14
        and r4, %0, r3
        live %1
        fork %11

live2:  live %1
        zjmp %:live2
