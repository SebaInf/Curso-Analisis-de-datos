from __future__ import print_function
from numpy import array

def PL(num,num2,n):
    global g #numero de salida
    global c1 #control 1
    global c2 #control 2
    global z  #Cantidad maxima
    e =[int(e) for e in str(num2)] #numero inicial
    a = [int(a) for a in str(num)] #numero original
    s =[int(s) for s in str(num)] #numero final
    j =[int(j) for j in str(num)]
    b=len(a) # cantidad digitos 
    v=[0,0] # numeros a permutar 
    n=[0,0] # posicion de numeros a permutar 
    m1= array(range(b))*0 # primer numero a permutar
    m2= array(range(b))*0 # segundo numero a permutar
    o=0 #contador 1
    p=0 #contador 2
    
##########################################################
    
    c1=g 

##################################################### paso 1
    
    for x in range (0,b-1):
        if a[x]<a[x+1]:
            v[0]=a[x]
            n[0]=x
            o=o+1
    
            
        
##################################################### paso 2
    for x in range (o,b):
        if a[x]>v[0]:
            m2[p]=a[x]
            v[1]=a[x]
            n[1]=x
            

    #for x in range (0,b):
    #        if v[1]==a[x]:
    #            n[1]=x
            
##############################################
    
    s[n[0]]=v[1]
    s[n[1]]=v[0]
    
    
################################################
    c=b-n[0]-1
    m3= array(range(c))*0
    
    o=0
    for x in range (n[0]+1,b):
        m3[o]=s[x]
        o=o+1
    
    o=0
    for x in range (n[0]+1,b):
        
        s[x]=m3[c-o-1]
        o=o+1
    
    
    g=0
    for x in range (0,b):
        g=g+s[x]*(10**(b-x-1))
        j[x]=e[b-x-1]
    l=0
    for x in range (0,b):
        l=l+j[x]*(10**(b-x-1))
        
        
    c2=g
    if c1<c2:
        print("Esta es la permutacion numero",z+1,":")
        print(s)
        z=z+1
    if c2<=c1:
        z=n
        print("El programa se detuvo porque ya se alcanzo la maxima permutacion lexico grafica")
        
##################################
        
        
print("Ingrese el numero inicial para permutar")
g=int(input())


##################################


print("Ingrese cantidad de permutaciones (si alcanza el maximo el programa se detendra)")
n=int(input())

#####################################


#g=1234
e=g
a = [int(a) for a in str(g)]
print("El numero inicial es", g)

print(a)

print("______________")
T=1
c1=1
c2=2
z=0
while c1<c2 and z<n:

    PL(g,e,n)