Graded 100/100

Task:
Implement a TRIE tree which contains translations of words. Word in original language and its translation will not be longer than 16 characters and will contain only lower case lettters.
The following commands should be supported:
+ s t
add a word s with the translation t
? s
query about a word s – write a translation of s or - (minus sign) if it has not been added
* s
Write all translations of words such that s is a prefix of the word (including word s, if its contained in the tree). Translations should be written in alphabetical order of original words (see * d in example). Write - (minus sign) if no such word exists

Example:
Input
+ dog pies
+ cat kot
+ do robic
+ doggie piesek
+ doggies pieski
+ dolphin delfin
+ ant mrowka
+ zzz xxx
? dog
? cat
? do
? doggie
? dolphin
? ant
? zzz
? d
? dot
? dom
? dogg
? dol
? dolp
? dolph
? dolphi
? dolphine
* a
* d
* do
* dog
* dogg
* doggie
* doggies
* z
* b
* dot
* dolphen
* doggiess


Output
pies
kot
robic
piesek
delfin
mrowka
xxx
-
-
-
-
-
-
-
-
-
mrowka
robic
pies
piesek
pieski
delfin
robic
pies
piesek
pieski
delfin
pies
piesek
pieski
piesek
pieski
piesek
pieski
pieski
xxx
-
-
-
-