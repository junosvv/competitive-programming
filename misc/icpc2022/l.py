m = {"U" : 0, "D" : 1}
uds = [m[i] for i in input()]

us = 0
ds = 0
changes = 0
current = uds[0]

for i in range(len(uds)):
    if uds[i] == 1:
        ds += 1
    else:
        us += 1
    if uds[i] != current:
        changes += 1
    current = uds[i]

one = 2 * ds
two = 2 * us
three = changes + uds[0]
four = changes + 1 - uds[0]

print(one, two, three, four)