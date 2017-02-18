# Passgen: Password Generator
Passgen is a basic password generator that attempts
to create random passwords to the user's specification. You can add the `Passgen`
exe file to your path (i.e. `/usr/local/bin`) so that you can use it as a command line tool.
NOTE: Passgen does NOT use rand() for random number generation.

## Basic Usage:
Compiling the code:
` make`

Generating a default Passgen password: `Passgen`

NOTE: The default password includes numbers and symbols, is 128 characters, and it only generates one. All of these can be changed at the top of main.cpp.

Short hand syntax:
```
$ Passgen 10 16
===========================
Generating 10 password(s).
Length: 16 characters.
Including Numbers
Including Symbols
===========================
=~Eo5YH,/>Bx//vH
0#cgHwcv~p3B/khc
osXUx*oB8BM*+Ug0
x"=,gYAPY8hwUw0s
PBU$M'/"Q/Bwck3{
wIhABBI{Qgp+U+AJ
ExH/QUMvB80BfB{3
{vMw4/0ZUXBHwBfw
<#"BkBg=kE<{k=Z{
,#+pB8BsYcBcpBkh
```

The above syntax is equivalent to:
```
$ Passgen -l 16 -c 10
===========================
Generating 10 password(s).
Length: 16 characters.
Including Numbers
Including Symbols
===========================
Y+8vYR8IBZA+='oA
/#=~Y=f'JBBMvMA,
YBwA'EBB="~P8A,~
8<'sY>=4fBf'0h4{
vnHnf8'E,hQEJYk#
A0X{>AIIY{nwJJ=4
cB~sBR<=Yw,RoI+f
ZY,P+pgMP{k0#Bn#
YA0'8EB=vAH#QAwp
<0*E8sgf/sURE'Mg
```

Passgen interactive mode:
```
$ Passgen -i
How many passwords should I write: 10
How long should each password be: 16
Should I include numbers [Y/n]: y
Should I include symbols [Y/n]: Y
===========================
Generating 10 password(s).
Length: 16 characters.
Including Numbers
Including Symbols
===========================
a|,dBv5kBRBgBF3)
7"bz$SZeMZQucH|Q
Ccb}dc9VJswJwCZB
)Biw#gBtRqQe~jbg
0wSXFBPBXiOS4Y(6
g4R{xTUzNFPW(0Sx
MEDouoc<9C{C7S#B
}dHWJs--(BYBnNB1
FQ+>g:'6MphdV{f#
Mzg$#B#B"8%JBzgY
```

Passgen help page: `Passgen -h`
```
Usage: Passgen [count] [length]
-b           A basic password with letters and numbers.
-c           The number of passwords to generate.
-i           Open Passgen in interactive mode.
-l           Length of the generated password.
-n           Include numbers in generated passwords.
-s           Include symbols in generated passwords.
```
