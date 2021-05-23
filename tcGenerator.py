import random;
test=1
n=512
d=1
inf=999999
def ran():
    
    return random.randint(0,1000)
def gen():
    rand=ran();
    prob=random.random()<0.00001
    if(rand>500):
        return inf;
    else:
        if(rand==-1):
            if(prob):
                return rand;
            return rand+2;
        return rand;
print(test)
for i in range(test):
    print(n,d)
    for j in range(n):
        for k in range(n):
            if j!=k:
                r=gen();
                print(r,end=" ")
            else:
                print(0,end=" ")
        print("")
