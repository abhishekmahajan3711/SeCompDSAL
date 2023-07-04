
class Set_operations:

    def Print_ele(self,S_one):
          for i in S_one:
              print(i)     
                     
    def Create(self,n,S1):
          for i in range(n):
             ele=int(input("Enter the number : "))
             S1.add(ele)
          
    def Add(self,ele,S_one):
            S_one.add(ele)
       
    def Remove_ele(self,ele,S_one):
            S_one.remove(ele)
      
    def Find_Union(self, S1 ,S2):
            print("Union set")
            global S3
            S3=set()
            for j in S1:
                  S3.add(j)
            for s in S2:
                    if s not in S3:
                        S3.add(s) 
            self.Print_ele(S3)

              
    def Find_Intersection(self, S1,S2):
         print("Intersection set")
         S3=set()
         for p in S1:
           if p in S2:
              S3.add(p)
         self.Print_ele(S3)
         
    def Find_Difference(self,S1,S2):
        print("Difference set")
        S3=set()
        for m in S1:
            if m not in S2:
                S3.add(m)
        self.Print_ele(S3)
         
    def contain_or_not(self,S1):
        e=int(input("Enter element which you want to know whether present or not : "))
        if e in S1:
           print("Element present ")
        else:
           print("Element absent ")		
          
    def return_size(self, S1):
      b=len(S1)
      print("Length of the set is : " ,b)
      
      
    def subset_or_not(self,S1):
        S3=set()
        n=int(input("Enter number of elements in subset "))
        for i in range(n):
            t=int(input("Enter element " ))
            S3.add(t)
        v=0
        for j in S3:
            if j in S1:
                v+=1
            else:
                v=0
                break
        if (v!=0 and len(S3)<=len(S1)):
               print("It is a subset ")
        else:
               print("It is not a subset ")
          
    def symmetirc_difference(self,S1,S2):
        print("Symmetric difference set")
        S4=set()
        S5=set()
        #finding union
        for j in S1:
                  S4.add(j)
        for s in S2:
                if s not in S4:
                  S4.add(s)
        #finding intersection
        for p in S1:
           if p in S2:
              S5.add(p)
        #union minus intersection
        S6=set()
        for k in S4:
                if k not in S5:
                          S6.add(k)
        self.Print_ele(S6)   
      
                   
         
