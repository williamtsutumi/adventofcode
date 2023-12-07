from collections import defaultdict
import sys

alfa = defaultdict(int)
map1 = defaultdict(int)
map2 = defaultdict(int)

for s in sys.stdin:
    s = s.rstrip()

    for i in range(len(s) // 2):
        if (ord(s[i]) >= 65):
            map1[ord(s[i]) - ord('a') + 26] += 1

        if (ord(s[i + len(s) // 2]) < 65):
            map2[ord(s[i + len(s) // 2]) - ord('a')] += 1
            

output = 0
for k, v in map1.items():
    print("*************************")
    print(k)
    # print(map1[k])
    # print(map1[k])
    output += k * (min(map1[k], map2[k]))

print(output)
