log = open('../log.txt')
lines = log.readlines()
log.close()

for i in lines:
    if "C4 01 C1" in i:
        print(i)