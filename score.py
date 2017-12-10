#!/usr/bin/python
import re
p = re.compile("\w+'\w+") 
lines = [line.rstrip('\n') for line in open('/usr/share/dict/words')]
f = open('hundred','w')
i = 0
for line in lines:
   s = sum([(ord(c)-ord('a')+1) for c in line.lower()])
   if s == 100 and not p.match(line) :
      f.write(line + '\n')
      i += 1
print(i)
f.close()
