from __future__ import print_function
from numpy import array


def mcd(a,b): #maximo comun divisor

    i=0
    o=0
    u=0
    r=a
    t=b
    if a==b:
        c=a
        d=b
        v = array(range(a+1))
        k =v*0
        j =v*0 
    if a != b:
        if a>b:
            c=a
            d=b
            v = array(range(a+1))
            k =v*0
            j =v*0
        if b>a:
            c=b
            d=a
            v = array(range(b+1))
            k =v*0
            j =v*0
            
    for x in range (1,c+2):
  
        a=c/x
        b=d/x
        q=a-int(a)
        w=b-int(b)
        if q==0:
            k[i]=a
            i=i+1
        
        if w==0:
            j[o]=b
            o=o+1
    m=v*0
    
        
    for p in range (0,i+o+2):
        for y in range (0,i+o+2):
            if k[p]==j[y]:
                m[u]=k[p]
                u=u+1
    k = [i for n, i in enumerate(k) if i not in k[:n]]
    j = [i for n, i in enumerate(j) if i not in j[:n]]
    print(k)
    print(j)
    print("El maximo comun divisor entre", r, "y" ,t ,"es" ,m[0],)

print("ingrese un numero")
a=int(input())
print("ingrese otro numero")
b=int(input())

mcd(a,b)
