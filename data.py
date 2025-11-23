import random

with open("./OI/njupt/E.in", "w") as f:
    q = random.randint(1,2*10**5)
    f.write(f"{q}\n")
    for i in range(q):
        op = random.randint(1, 4)
        if (op == 1):
            s = ""
            l = random.randint(1, 100)
            for j in range(l):
                s+= random.choice("qwertyuiopasdfghjkzxcvbnm")
            w = random.randint(1, 10**9)
            f.write(f"ADD {s} {w}\n")
        elif op == 2:
            s = ""
            l = random.randint(1, 100)
            for j in range(l):
                s+= random.choice("qwertyuiopasdfghjkzxcvbnm")
            f.write(f"QUERY {s}\n")
        elif op == 3:
            s = ""
            l = random.randint(1, 100)
            for j in range(l):
                s+= random.choice("qwertyuiopasdfghjkzxcvbnm")
            f.write(f"DEL {s}\n")
