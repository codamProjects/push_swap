import random
import sys

n = int(sys.argv[1])
MAX_INT = 10000
MIN_INT = -10000
my_list = random.sample(range(MIN_INT, MAX_INT), n)
print(" ".join(str(x) for x in my_list))

#./push_swap $(python my_num_list.py RANGE)
#500 = 11500 10000 8500 7000 5500
#100 = 1500 1300 1100 900 700
#5 = 12 8
#3 = 3
