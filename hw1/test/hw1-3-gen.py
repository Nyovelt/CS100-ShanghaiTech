import random
import os 

# max_samples = 10
# max_time_per_lecture = 120
# start = 480
# end = 1320
# curr = start    
os.system('mkdir hw1-1-cases')
os.chdir('hw1-1-cases')
def gen():
    os.system('mkdir in')
    max_x , max_y = 10000, 10000
    for i in range(10):
        f = open('./in/' + str(i+1) + '.in', 'w')
        rn = random.randint(1, 1000)
        f.write('{}\n'.format(rn))
        for _ in range(rn):
            f.write("%.1f\n" % (random.randint(-10000, 10000) + random.random()) )
        # print("================================================================")
        f.close()

def test():
    # os.mkdir('out')
    for file in os.listdir('./in/'):
        if (file == '.DS_Store'): 
            continue
        ans = os.popen('cat ./in/{} | ../1-1'.format(file)).read()
        outf = open('./out/' + file.replace('in', 'out'), 'w')
        outf.write(ans)
        outf.close()
        
# gen()
test()


# def time2hm(curr):
#     return (curr//60, curr%60)

# num_samples = random.randint(1, max_samples)
# curr += random.randint(1, max_time_per_lecture)

# print(num_samples)
# for _ in range(num_samples):
#     print("{}:{}-".format( time2hm(curr)[0], time2hm(curr)[1]), end="")
#     curr += random.randint(1, max_time_per_lecture)
#     if (curr > end):
#         break
#     print( "{}:{}".format( time2hm(curr)[0], time2hm(curr)[1]) )
#     curr += random.randint(1, max_time_per_lecture)
#     if (curr > end):
#         break




# f = open("hw3-cases", "r")

# os.chdir("hw1-3-cases")
# os.system("mkdir out")
# con = f.read().split("\n\n")
# j = 1
# for case in con:
#     c = case.split("\n")[-1]
#     cs = open('./out/' + str(j)+'.out', "w")
#     if ('dead' in c):
#         cs.write("Gezi Wang has fainted and is in hospital.\n")
#     else:
#         num = c.split(': ')[-1][:-1]
#         cs.write("His mood level is {} at the end of the day.\n".format(num))
#     cs.close()  
#     j += 1
# f.close()


