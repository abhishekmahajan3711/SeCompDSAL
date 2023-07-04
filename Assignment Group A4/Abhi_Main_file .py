# To create ADT that implement the "set" concept. 
# a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the 
# value 
# c. Contains (element) Return true if element is in collection, d. Size () Return number of 
# values in collection Iterator () Return an iterator used to loop over collection, e. 
# Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset

# Main Menu
import Abhi_File1
h=Abhi_File1.Set_operations()

S_one=set()
print("Create a Set 1")
n1=int(input("Enter number of elements : "))
h.Create(n1,S_one)

S_two=set()
print("Create a Set 2")
n2=int(input("Enter number of elements : "))
h.Create(n2,S_two)

print("\tMENU")
print("Enter 1 : Add a element" )
print("Enter 2 : Remove a element" )
print("Enter 3 : Contains or not" )
print("Enter 4 : Find number of elements in set" )
print("Enter 5 : Find a union" )
print("Enter 6 : Find a intersection" )
print("Enter 7 : Find a  difference" )
print("Enter 8 : Check whether subset or not ")
print("Enter 9 : More functions")
print("Enter 10: To exit the program")

while True:
    print("\n")
    d=int(input("Enter your choice : " ))
    if (d==1):
        e=int(input("Enter the element : "))
        h.Add(e,S_one)
        print("Element add successfully")

    elif(d==2):
        e=int(input("Enter the element which you want to remove: "))
        h.Remove_ele(e,S_one)
        print("Element removed successfully")
        
    elif(d==3):
        h.contain_or_not(S_one)

    elif(d==4):
        h.return_size(S_one)

    elif(d==5):
        h.Find_Union( S_one ,S_two)
        
    elif(d==6):
        h.Find_Intersection( S_one ,S_two)

    elif(d==7):
        h.Find_Difference(S_one ,S_two)
        
    elif(d==8):
        h.subset_or_not(S_one)
        
    
    elif(d==9):
       print("\tEnter 1 : Print original set" )
       print("\tEnter 2 : Find symmetic difference ")
       print("\tEnter 3 : To go back")
       while True:
        d=int(input("Enter your choice : " ))
        if(d==1):
           h.Print_ele(S_one)
        
        elif(d==2):
           h.symmetirc_difference(S_one,S_two)

        elif(d==3):
            break
        else:
          print("Invalid choice")

    elif(d==10):
        exit(0)
    else:
        print("Invalid choice")


