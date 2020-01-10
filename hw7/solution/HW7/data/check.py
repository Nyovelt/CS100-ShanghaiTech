import sys
f_stu = open(sys.argv[1])
f_ref = open(sys.argv[2])
c_stu = f_stu.read().split("\n")
c_ref = f_ref.read().split("\n")
f_stu.close()
f_ref.close()

if (len(c_stu) != len(c_ref)):
    exit(1)

for i in range(len(c_stu)):
    nums_stu = [ float(item) for item in c_stu[i].split(" ") ]
    nums_ref = [ float(item) for item in c_ref[i].split(" ") ]
    if (len(nums_stu) != len(nums_ref)):
        exit(1)
    for j in range(len(nums_stu)):
        if abs(nums_stu[j] - nums_ref[j]) > 0.0001:
            exit(1)
exit(0)


