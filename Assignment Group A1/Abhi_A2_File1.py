
#Linear Probing
class HashTable:

    def __init__(self):
        self.size=int(input("Enter the size of hash table : "))
        self.table=list(None for i in range (self.size))
        self.eleCount=0
       
        
    def isFull(self):
        if(self.eleCount==self.size):
            return True
        else:
            return False
            
    def hashFunction(self,element):
        return element % self.size
        
    def insert(self,element):
        if(self.isFull()):
            print("Hash table is full")
            return 1
        else:
            position=self.hashFunction(element)
            Stored=False
        
            if(self.table[position]==None):
                self.table[position]=element
                Stored=True
                self.eleCount+=1

            else:
                while (self.table[position]!=None):
                    position+=1
                    if(position>=self.size):
                        position=0
                    
                self.table[position]=element	
                Stored=True
                self.eleCount+=1
                        
            if(Stored):
                return 2
            else:
                return 3
            


    def search(self,ele):
        index=self.hashFunction(ele)
        noOfComp=1
        if(self.table[index]==ele):
            found=True
        elif(self.table[index]==None):
            found=False
            
        else:
            n=0
            while(self.table[index]!=ele and n<=self.size):
                index+=1
                n+=1
                noOfComp+=1
                if (index>=self.size):
                    index=0
            if(n<self.size):
                found=True
            else:
                found=False

        if(found):
            print("Number of comparisons made are ",noOfComp)
            print("Element found at index ",index)
        else:
            print("Element not found ")
            
            
    def display(self):
        print("\tElements are- ","\n")
        for i in self.table:
            print(i,"\n")

            
