import random


def random_num(mn,mx):
	return random.randint(mn,mx)


print(1)

mnn=1
mxn=100
n=random_num(mnn,mxn)
m=random_num(mnn,n*(n-1))
s=random_num(1,n)
e=random_num(1,n)
mnf=1
mxf=1e2
f=random_num(mnf,mxf)
print(n,m,s,e,f)

mp=[[0]*(n+5)]*(n+5)
for i in range(m):
	a=0
	b=0
	while(a==b or mp[a][b]==1 or mp[b][a]==1):
		a=random_num(1,n)
		b=random_num(1,n)
	c=random_num(1,50216)
	d=random_num(1,mxf)
	c2=random_num(1,c)
	print(a,b,c,d,c2)








print(n)




'''
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
'''
