.name "theft"
.comment "stolen lol"

ld %64, r7		#r7 = 64
ld %32, r6		#r6 = 32
ld %16, r5		#r5 = 16
ld %8, r4		#r4 = 8
ld %4, r3		#r3 = 4

st r1, 424		#remplacement du code par des 0000000 et des ffffffff
st r16, -4
st r1, 432
st r16, -4
st r1, 440
st r16, -4
st r1, 448
st r16, -4
st r1, 376
st r16, -4
st r1,  73
st r16, -4
st r1,  55
st r16, -4

ld %0, r10		#r10 = 0

st r1, 468
st r16, -4
st r1, 463
st r16, -4

fork %:fork1

ld %0, r2		#r2 = 0
ld %0, r16		#r16 = 0

fork6: live %42
fork %:fork6
live %4902343

st r2, 65503	#Barriere de protection avec des 0 | 270 octets
st r2, 65494
st r2, 65485
st r2, 65476
st r2, 65467
st r2, 65458
st r2, 65449
st r2, 65440
st r2, 65431
st r2, 65422
st r2, 65413
st r2, 65404
st r2, 65395
st r2, 65386
st r2, 65377
st r2, 65368
st r2, 65359
st r2, 65350
st r2, 65341
st r2, 65332
st r2, 65323
st r2, 65314
st r2, 65305
st r2, 65296
st r2, 65287
st r2, 65278
st r2, 65269
st r2, 65260
st r2, 65251
st r2, 65242
st r2, 65233
st r2, 65224
st r2, 65215
st r2, 65206
st r2, 65197
st r2, 65188
st r2, 65179
st r2, 65170
st r2, 65161
st r2, 65152
st r2, 65143
st r2, 65134
st r2, 65125
st r2, 65116
st r2, 65107
st r2, 65098
st r2, 65089
st r2, 65080
st r2, 65071
st r2, 65062
st r2, 65053
st r2, 65044
st r2, 65035
st r2, 65026

zjmp %-275
zjmp %23
fork2: zjmp %38
fork3: zjmp %53
fork4: zjmp %68
fork5: zjmp %83

fork1: live %1
fork %:fork1

live %1
fork %:fork2

add r2, r6, r2		#r2 += 32
add r16, r16, r16	#r16 *= 2

live %1
fork %:fork3

add r2, r5, r2		#r2 += 16
add r16, r16, r16	#r16 *= 2

live %1
fork %:fork4

add r2, r4, r2		#r2 += 8
add r16, r16, r16	#r16 *= 2

live %1
fork %:fork5

add r2, r3, r2		#r2 += 4
add r16, r16, r16	#r16 *= 2

ldi %13, r2, r16	#r16 = data[r2 + 13]
ld %0, r10			#r10 = 0

sti r16, %64, r2	#data[r16 +  64] = r2
sti r16, %122, r2	#data[r16 + 122] = r2
sti r16, %180, r2	#data[r16 + 180] = r2
sti r16, %238, r2	#data[r16 + 238] = r2
sti r16, %296, r2	#data[r16 + 296] = r2
sti r16, %354, r2	#data[r16 + 354] = r2

live %42
live %42

sti r16, %402, r2	#data[r16 + 402] = r2
sti r16, %448, r2	#data[r16 + 448] = r2

zjmp %442

live %42
