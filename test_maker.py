import random

mxntt=2e5

print(1)

def random_num(mn,mx):
	return random.randint(mn,mx)

mnn=1
mxn=1e5
n=random_num(mnn,mxn)
m=random_num(mnn,mxn)
print(n,m)
mna=1
mxa=1e9
for i in range(n):
	print(random_num(mna,mxa),end=" ")
print()

mnq=1
mxq=30
for i in range(m):
	print(random_num(mnq,mxq),end=" ")
print()

