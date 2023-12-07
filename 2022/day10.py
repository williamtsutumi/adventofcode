import sys

registrador = 1
cycles = 1
for s in sys.stdin:
    s = s.strip()

    op = s.split(' ')
    cycles += 1
    if (op[0] == "noop"):
        continue

    