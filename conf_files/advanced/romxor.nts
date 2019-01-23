# Admiral Business Machines 1954-2042
# Rom xor dumping on terminal

#                                                      _TERMINAL_
#                   +---------------------------------[WR        ]
#                   |                ___ROM___        [          ]
# (dmp)-+-|>o-------(---------------[/OE      ]       [          ]
#       |           |  ___4040___   [         ]=[ = ]=[          ]
#       +--->[ & ]>-+-[CLK       ]==[         ]=[ = ]=[          ]
# (clk)----->[ & ]    [       OUT]==[AX     OX]=[ = ]=[IX        ]
# (rst)---------------[MR        ]==[         ]=[ = ]=[          ]
#                     [__________]==[_________]       [__________]
#
# Note that the XOR gate schematic is incomplete, there is 8 xor gate
# Components 4040 8 first outputs takes one to one the 8 output of ROM and
# XOR them before sending the result on the terminal component.

.chipsets:
# CLK DMP RST - OUT
#  X   X   1  - Display nothing
#  X   0   0  - Display nothing
#  /   1   0  - Dump character on terminal

input			dump
clock			clock
input			reset
false			gnd

4069			no
4040			counter
2716			rom(xorrom.bin)
4081			and

4030			xor0
4030			xor1

# Terminal pin 1 to 8 are data
# Terminal pin 9 is WR for "write request"
# Working on /
terminal		out

.links:

################################
dump:1			and:1
dump:1			no:1
clock:1			and:2
and:3			counter:10
reset:1			counter:11
no:2			rom:20
gnd:1			rom:18
gnd:1			rom:20

################################
counter:9		rom:8
counter:7		rom:7
counter:6		rom:6
counter:5		rom:5
counter:3		rom:4
counter:2		rom:3
counter:4		rom:2
counter:13		rom:1
counter:12		rom:23
counter:14		rom:22
counter:15		rom:19

################################
rom:9			xor0:1
rom:10			xor0:5
rom:11			xor0:8
rom:13			xor0:12

counter:9		xor0:2
counter:7		xor0:6
counter:6		xor0:9
counter:5		xor0:13

################################
rom:14			xor1:1
rom:15			xor1:5
rom:16			xor1:8
rom:17			xor1:12

counter:3		xor1:2
counter:2		xor1:6
counter:4		xor1:9
counter:13		xor1:13

################################
xor0:3			out:1
xor0:4			out:2
xor0:10			out:3
xor0:11			out:4
xor1:3			out:5
xor1:4			out:6
xor1:10			out:7
xor1:11			out:8

clock:1			out:9

