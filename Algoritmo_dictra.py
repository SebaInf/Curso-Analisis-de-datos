from __future__ import print_function
from numpy import array

def A_D(num): #algoritmo de dictra
    a = [int(a) for a in str(num)] #numero original
    s=[int(s) for s in str(num)] #numero final
    b=len(a) #cantidad digitos 
    v=[0,0,0,0] #guarda numeros a permutar 1
    n=[0,0,0,0] #posicion de numeros a permutar 1
    m= array(range(b))*0 # numeros mayores que el primer numero a permutar
    u=[0,0]
    o=0
    p=1
    
    for x in range (0,b-1):
        #print(a[x+1],a[x])
        if a[x+1]<a[x]:
            v[o]=a[x+1]
            n[o]=x+1
            o=o+1
    #print(a,v,n)
    o=0
    for x in range (n[0],b-1):
        if a[n[0]]<a[x+1]:
            m[o]=a[x+1]
            o=o+1
    
    menor=10
    for x in range (0,o):
        if m[x]<menor:
            menor=m[x]
    for x in range (n[0],b):
        if a[x]==menor:
            n[p]=x
            p=p+1
            



    p=2
    o=2
    
    #debido a que la clase se cortaba no me quedo claro esto
    
    for x in range (0,b):
        
        
        if n[0]==x:
        
            s[x]= a[n[1]]
           
        if n[1]==x:
            s[x]=a[n[0]]
    u=[s[b-2],s[b-1]]
    
    
    
    if u[1]<u[0]: 
        
        s[b-2]=u[1]
        s[b-1]=u[0]
        
    if u[0]<u[1]:   
        
        s[b-2]=u[0]
        s[b-1]=u[1]
    
    g=0  
    for x in range (0,b):
        g=g+s[x]*(10**(b-x-1))
        
    print("____________________")
    print("")
    print("El numero a permutar es",num)
    print("Su permutacion en orden lexicografico es",g)
    print("____________________")
    

print("Ingrese numero")
ab=int(input())
A_D(ab)