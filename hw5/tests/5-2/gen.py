from random import *


def randStr(length):
    s = "qwertyuiopasdfghjklzxcvbnm"
    l = [ s[randint(0, 25)] for _ in range(length) ]
    return "".join(l)
    

for t in range(10):
    f = open(str(t+1) + ".in", "w")
    m = randint(4, 100) lines
    n = randint(5, 100) cols
    sopt = randint(0, n-1)
    f.write("{} {} {}\n".format(n, m,sopt))
    for _ in range(m):
        f.write("{} ".format(randStr(randint(2, 25))))
        for i in range(n-1):
            if i != n-2:
                if (randint(0,100) % 2):
                    f.write("{} ".format(randint(0, 10000)))
                else:
                    f.write("{} ".format(randStr(randint(2, 40))))
            else:
                f.write("{}\n".format(randint(0, 10000)))
    f.close()