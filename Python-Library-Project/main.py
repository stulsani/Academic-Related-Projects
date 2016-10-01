#Sumeet Tulsani
from searchengine import Searchengine
from media import Media

def main():
    choice = 'y'
    matches = list()
    while(choice == 'Y' or choice == 'y'):
        print ("What type of search would you like to do::");
        print (" 1. Search by Title\n 2. Search by Call Number\n 3. Search by Subject\n 4. Search by Other\n 5. Exit");
        searchby = input();
        choice = 'n'
        if searchby < "1" or searchby > "5":
            print("Invalid Choice, Please enter a valid choice");
        if searchby >= "1" and searchby <= "4":
            print ("Enter the string you would like to search");
            searchthis = input();
        if searchby == "1":
            obj = Searchengine()
            matches = obj.search_by_title(searchthis)
            i = 0
            size = len(matches)
            while i != size:
                matches[i].display()
                i = i + 1
            print("--------TOTAL SEARCHES-------\n Total number of searches: ");
            print (len(matches))
        if searchby == "2":
            obj = Searchengine()
            matches = obj.search_by_call_number(searchthis)
            i = 0
            size = len(matches)
            while i != size:
                matches[i].display()
                i = i + 1
            print("--------TOTAL SEARCHES-------\n Total number of searches: ");
            print (len(matches))
        if searchby == "3":
            obj = Searchengine()
            matches = obj.search_by_subjects(searchthis)
            i = 0
            size = len(matches)
            while i != size:
                matches[i].display()
                i = i + 1
            print("--------TOTAL SEARCHES-------\n Total number of searches: ");
            print (len(matches))
        if searchby == "4":
            obj = Searchengine()
            matches = obj.search_by_other(searchthis)
            i = 0
            size = len(matches)
            while i != size:
                matches[i].display()
                i = i + 1
            print("--------TOTAL SEARCHES-------\n Total number of searches: ");
            print (len(matches))
        if searchby == "5":
            quit()
        print("Would you like to continue(y/n)????");
        choice = input();
main()
