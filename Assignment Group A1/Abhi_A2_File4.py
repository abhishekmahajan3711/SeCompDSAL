import Abhi_A2_File3
obj2=Abhi_A2_File3
#double hashing 

class double_hashing:

    def __init__(self):
        self.size=int(input("Enter the size of hash table : "))
        self.table=list(None for i in range (self.size))
        self.eleCount=0
        self.prime=self.prime_find()
        print("Prime number is ",self.prime)


    def prime(self,i):
        for j in range(2,i):
                if(i%j==0):
                    return False
        return True

    #finding prime number
    def prime_find(self):
        cp=2
        for i in range(2,self.size):
            if(self.prime(i)):
                cp=i
        return cp

    def hash1(self,element):
        return element%self.size
        
    def isFull(self):
        if(self.eleCount==self.size):
            return True
        else:
            return False
            
    def hash2(self,element):
        return self.prime-(element % self.prime)
    
    #hash function use for inserting
    def hash_function(self,ele,i):
        #self.i=self.i+1
        return ((self.hash1(ele) + (i * self.hash2(ele))) % self.size)


        
    def insert(self,element):
        if(self.isFull()):
            Stored=False
            return 1
        else:
            position=self.hash1(element)
            if(self.table[position]==None):
                self.table[position]=element
                Stored=True
                self.eleCount+=1
            else:
                i=1
                while i<self.size:
                  position=self.hash_function(i,element)
                  if(self.table[position]==None):
                   self.table[position]=element
                   Stored=True
                   self.eleCount+=1
                   break
                  else:
                    i+=1
                    Stored=False
        if(Stored==True):
            return 2
        else:
            return 3
            
    def search(self,ele):
        found=False
        index=self.hash1(ele)
        noOfComp=1
        if(self.table[index]==ele):
            found=True
        elif(self.table[index]==None):
            found=False     
        else:
            n=0
            h=1
            while(h<=self.size):
                index=self.hash_function(ele,h)
                noOfComp+=1
                if(self.table[index]==ele):
                  found=True
                  break
                h+=1


        if(found):
            print("Number of comparisons made are ",noOfComp)
            print("Element found at index ",index)
        else:
            print("Element not found ")

    def display(self):
        print("\tElements are- ","\n")
        for i in self.table:
            print(i,"\n")


