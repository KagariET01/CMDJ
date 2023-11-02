import random

def random_num(mn,mx):
	return random.randint(mn,mx)
mnn=100
mxn=100000
n=random_num(mnn,mxn)
print(n)
mxa=n
for i in range(n):
	print(random_num(1,mxa),end=" ")
mnq=100
mxq=1000000
mnlr=1
mxlr=n
q=random_num(mnq,mxq)
for i in range(q):
	l=random_num(mnlr,mxlr)
	r=random_num(l,mxlr)
	print(l,r)
