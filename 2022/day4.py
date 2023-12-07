import sys

output = 0
for s in sys.stdin:
    s = s.strip()

    intervals = s.split(',')

    interval1 = intervals[0].split('-')
    interval2 = intervals[1].split('-')

    x1 = int(interval1[0])
    y1 = int(interval1[1])
    x2 = int(interval2[0])
    y2 = int(interval2[1])

    overlap = min(y1, y2) - max(x1, x2)  + 1
    if (y2 < x1 or x2 > y1):
        continue
    elif (overlap > 0):
        output += 1
print(output)