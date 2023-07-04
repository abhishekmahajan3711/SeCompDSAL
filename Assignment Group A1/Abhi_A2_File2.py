# Consider telephone book database of N clients. Make use of a hash table 
# implementation to quickly look up client‘s telephone number. Make use of two collision 
# handling techniques and compare them using number of comparisons required to find a 
# set of telephone numbers

#Main Menu
import Abhi_A2_File1
import Abhi_A2_File3
obj2=Abhi_A2_File3
import Abhi_A2_File4


while True:
   print("\tMENU")
   print("\tEnter 1 : For Linear Probing ")
   print("\tEnter 2 : For Double Hashing ")
   print("\tEnter 3 : To exit")

   p=int(input("\nEnter your choice : "))

   #linear probing 
   if(p==1):
    obj1=Abhi_A2_File1.HashTable()
    while True:
     print("\tLinear Probing")
     print("\tEnter 1 : For inserting ")
     print("\tEnter 2 : For searching ")
     print("\tEnter 3 : For displaying ")
     print("\tEnter 4 : To exit")
    
     i=int(input("\nEnter your choice : "))
     
     if(i==1):
       for r in range(obj1.size):
          element=obj2.get_element()
          n=obj1.insert(element)
          if(n==1):
            print("Table is full ")
            break
          elif(n==2):
            print("Element inserted successfully")
          else:
            print("Element can't be inserted ")
    
     elif(i==2):
         element=obj2.get_key()
         obj1.search(element)
 
     elif(i==3):
        obj1.display()
        
     elif(i==4):
        break
 
     else:
        print("Invalid choice !!") 
        
        
   elif(p==2): 
    obj3=Abhi_A2_File4.double_hashing()
    while True:
     print("\tDouble Hashing")
     print("\tEnter 1 : For inserting ")
     print("\tEnter 2 : For searching ")
     print("\tEnter 3 : For displaying ")
     print("\tEnter 4 : To exit")
    
     i=int(input("\nEnter your choice : "))
    
     if(i==1):
       for r in range(obj3.size):
          element=obj2.get_element()
          n=obj3.insert(element)
          if(n==1):
            print("Table is full ")
            break
          elif(n==2):
            print("Element inserted successfully")
          elif(n==3):
            print("Element can't be inserted ")
    
     elif(i==2):
        element=obj2.get_key()
        obj3.search(element)

     elif(i==3):
        obj3.display()

     elif(i==4):
        break

     else:
        print("Invalid choice !!") 

   elif(i==3):
    quit(0)

   else:
     print("Invalid choice !! ")
